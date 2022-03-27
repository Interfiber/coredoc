local mod = {}

mod.generateNew = function ()
  print("creating directorys...")
  os.execute("mkdir dst") -- dest folder
  os.execute("mkdir src") -- source folder
  print("creating files...")
  local headerfile = io.open("coredoc_header.html", "w")
  headerfile:write("<p>my header</p>")
  headerfile:close()
  local footerfile = io.open("coredoc_footer.html", "w")
  footerfile:write("<p>my footer</p>")
  footerfile:close()
  local maindoc = io.open("src/index.md", "w")
  maindoc:write("# Hello, World!")
  maindoc:close()
  print("generated")
end

return mod
