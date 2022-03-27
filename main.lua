local args = #arg
local cli = require("cli")
local generator = require("generator")
local ssg = require("ssg")

if args == 0 then
  cli.printHelp()
  os.exit(1)
end
if args == 1 and arg[1] == "init" or arg[1] == "i" then
  generator.generateNew()
end

if args == 1 and arg[1] == "build" or arg[1] == "b" then
  ssg.buildSite() 
end
