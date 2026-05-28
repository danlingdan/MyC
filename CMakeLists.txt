cmake_minimum_required (VERSION 3.12)

project ("HuaC")

# Add source to this project's executable.
add_executable (HuaC 
	"src/main.c" 
	"src/codegen.c" 
	"src/parse.c" 
	"src/tokenize.c")

set_property(TARGET HuaC PROPERTY C_STANDARD 23)
set_property(TARGET HuaC PROPERTY C_STANDARD_REQUIRED ON)
set_property(TARGET HuaC PROPERTY C_EXTENSIONS ON)
