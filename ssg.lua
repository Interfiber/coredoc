local mod = {}

function exists(file)
   local ok, err, code = os.rename(file, file)
   if not ok then
      if code == 13 then
         -- Permission denied, but it exists
         return true
      end
   end
   return ok, err
end


mod.buildSite = function ()
  print("building site...")

  -- lowdown is the markdown to html converter
  print("checking for lowdown...")
  if exists("/usr/local/bin/lowdown") then
    print("found lowdown")
  else
    print("failed to find lowdown at /usr/local/bin/lowdown")
    os.exit(1)
  end
  print("loading file coredoc_files.list...")
  if not exists("coredoc_files.list") then
    print("Failed to find coredoc_files.list, aborting")
    os.exit(1)
  end
  local coredocFiles = io.open("coredoc_files.list", "r")
  FileTicker = 0
  for line in coredocFiles:lines() do
      FileTicker = FileTicker + 1
      print("compiling file "..line.."...")
      if not exists(line) then
        print("skipping file "..line..", as it does not exist") 
      else
        mod.buildFile(line, "dst/"..line:gsub(".md", ".html"))
        print("compiled file to "..line:gsub(".md", ".html"))
      end
  end
  if FileTicker == 0 or FileTicker == 1 then
    print("built "..FileTicker.." file")
  else
    print("built "..FileTicker.." files")
  end
end

mod.getFooterHtml = function ()
  local footerName = "coredoc_footer.html"
  if exists(footerName) then
    local footerFile = io.open(footerName, "r")
    local footerData = footerFile:read("*all")
    footerFile:close()
    return footerData
  else
    return "<p></p>"
  end
end

mod.getHeaderHtml = function ()
  local headerName = "coredoc_header.html"
  if exists(headerName) then
    local headerFile = io.open(headerName, "r") 
    local headerData = headerFile:read("*all")
    headerFile:close()
    return headerData
  else
    return "<p></p>"
  end
end

mod.buildFile = function (inputFile, outputFile)
  -- build the file to markdown
  os.execute("lowdown "..inputFile.." > "..outputFile)
  -- read header and footer
  local footerData = mod.getFooterHtml()
  local headerData = mod.getHeaderHtml()
  -- format it
  local htmlFile = io.open(outputFile, "r")
  local htmlRaw = htmlFile:read("*all")
  htmlFile:close()

  local htmlFormatTop = "<!DOCTYPE html>\n<html>\n<head>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"coredoc_styles.css\">\n</head>\n<body>\n"..headerData.."\n"
  local htmlFormatBottom = "\n"..footerData.."\n</body>\n</html>\n"
  local formatedRaw = htmlFormatTop..htmlRaw..htmlFormatBottom
  local newHtmlFile = io.open(outputFile, "w")

  newHtmlFile:write(formatedRaw)
  newHtmlFile:close()
end

return mod
