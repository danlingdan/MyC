cmake_minimum_required (VERSION 3.12)

project ("HuaC")

# Add source to this project's executable.
add_executable (HuaC 
	"src/main.c" 
	"src/codegen.c" 
	"src/parse.c" 
	"src/tokenize.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HuaC PROPERTY C_STANDARD 23)
endif()

# TODO: Add tests and install targets if needed.
