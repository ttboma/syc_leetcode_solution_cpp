# README

This project is a collection of 
LeetCode solutions written in **C++**. The purpose of the project 
is to practice using **C++17**, manage building with **Make/CMake**, and 
track progress using **Git**.

-- ***Yueh-chang Shieh*** 2022-12-4

# Structure of this Project

```
syc_leetcode_solution_cpp
├── Makefile
├── README.md
├── inc
│   └── solution.h
└── src
    ├── fib.cpp
    └── tests
        └── test_fib.cpp
```

* *README.md*: this file
* *Makefile*: used to build this project, for all files 
  and directories generated by *make* will be placed 
  under the directory *target/*
* *inc/*: directory that contains the *solution.h* header 
  which all source files will include.
* *src/*: directory that contains all library source 
  files. For all methods for `Solution` class are kept in the
  cpp file with its corresponding problem name under *src/* 
  directory. For example, the implementation of 
  `int Solution::fib(int n)` method for `Solution` is 
  kept in *src/fib.cpp*
* *src/tests*: directories that contains all unit-test 
  source files. For each method implementation for 
  `Solution` class should have a corresponding unit-test 
  source with the its name prefixed with *'test_'* under 
  the directory *src/tests*. For example, there should be a 
  *src/tests/test_fib.cpp* contains the 
  unit-test code for `int Solution::fib(int n)` method.
* *doc/*: directory contains some documentation materials 
  
  
# Necessaries and Dependencies

Prerequisite:

* **C++17** compiler 
* **boost library**: you should provide the path to the 
  **boost library** in the *Makefile*. For example, set the 
  makefile variable  `BOOSTROOT` to the path to the 
  **boost library** in the *Makefile*: 
  `BOOSTROOT=/opt/homebrew/include/`, or set the makefile 
  variable along with the make command:  
  `make BOOSTROOT=/opt/homebrew/include/`
* **Make**/**Cmake**

Good to have these for your C++ IDE, trust me:

* [bear](https://github.com/rizsotto/Bear)
* [clangd](https://clangd.llvm.org)
  
# Two ways to build this project
  
## Method1: Build this Project with *Makefile* (Suggested)

To use the Makefile to build this project, use the following commands:

* `$ make`: Compile all source files in release mode 
  and to generate *libsolution.a* under the *target/lib* 
  directory and *libsolution.so* under the 
  *target/lib/local* directory
* `$ make debug`: Compile all source files in debug mode 
  and to generate *libsolution.a* under the *target/lib* 
  directory and *libsolution.so* under the 
  *target/lib/local* directory
* `$ make test`: Compile all boost unit-test source 
  files, generate all boost unit-test binaries under 
  the *target/tests* directory and execute each 
  boost unit-test binaries
* `$ make clean`: Remove all generated files and 
  directories by **make**. And also remove 
  *compile_commands.json* if if has been generated by 
  [bear](https://github.com/rizsotto/Bear)

Notes: 

If you edit source files with **LSP** server: **clangd**. 
You are suggested to install [bear](https://github.com/rizsotto/Bear), 
then use command `bear -- ` before the above commands. 
For example, 

* `$ bear -- make debug`    
* `$ bear -- make test`

[Makefile:](./Makefile)

```
# Configuration
# ------------- 
LIBNAME    := solution
BOOSTROOT  := /opt/homebrew/include/

INCDIR     := inc
TARDIR     := target

SRCDIR     := src
SRCOBJDIR  := $(TARDIR)/src
LIBTARDIR  := $(TARDIR)/lib
SRC        := $(wildcard $(SRCDIR)/*.cpp)  
SRCOBJ     := $(addprefix $(SRCOBJDIR)/,$(notdir $(patsubst %.cpp,%.o,$(SRC))))

TESTDIR    := $(SRCDIR)/tests
TESTTARDIR := $(TARDIR)/tests
TEST	   := $(wildcard $(TESTDIR)/*.cpp)
TESTBIN    := $(addprefix $(TESTTARDIR)/,$(notdir $(patsubst %.cpp,%.o,$(TEST))))

CC         := g++
INC        := -I$(BOOSTROOT) -I$(INCDIR)
LDFLAGS    := 
LIBS       :=
CXXFLAGS   := $(INC) -std=c++17
OPT        := -g -O0 -std=c++17 -Werror -pedantic-errors

.PHONY: all, test, clean


# Build and Test Commands
# -----------------------
debug: CXXFLAGS += -g -O0 -Werror -pedantic-errors
debug: lib 

release: CXXFLAGS += -O2
release: lib

lib: $(LIBTARDIR)/lib$(LIBNAME).a $(LIBTARDIR)/local/lib$(LIBNAME).so

test: $(basename $(TESTBIN)) 
	for unit_test in $(basename $(TESTBIN)); do ./$$unit_test; done

test_%: $(TESTTARDIR)/test_%
	$<

clean: 
	rm -rf $(TARDIR) compile_commands.json


# Compile Commands 
# ----------------
$(LIBTARDIR)/lib$(LIBNAME).a: $(SRCOBJ) | $(LIBTARDIR) 
	ar crsv $(LIBTARDIR)/lib$(LIBNAME).a $(SRCOBJ)

$(LIBTARDIR)/local/lib$(LIBNAME).so: $(SRCOBJ) | $(LIBTARDIR) $(LIBTARDIR)/local
	$(CC) $^ -shared -o $@ -fPIC $(CXXFLAGS)

$(TESTTARDIR)/test_%: $(TESTDIR)/test_%.cpp $(SRCOBJDIR)/%.o $(SRCOBJDIR)/solution.o | $(TESTTARDIR)
	$(CC) $^ -o $@ $(CXXFLAGS) $(LDFLAGS) $(LIBS)   

$(SRCOBJDIR)/%.o: $(SRCDIR)/%.cpp | $(SRCOBJDIR)
	$(CC) $^ -o $@ -c $(CXXFLAGS) $(LDFLAGS) $(LIBS)  


# Mkdir Commands 
# --------------
$(SRCOBJDIR):
	mkdir -p $(SRCOBJDIR)

$(LIBTARDIR):
	mkdir -p $(LIBTARDIR)

$(LIBTARDIR)/local:
	mkdir -p $(LIBTARDIR)/local

$(TESTTARDIR): 
	mkdir -p $(TESTTARDIR)
```

## Method2: Build this Project with *CMakeLists.txt*

* `$ cmake . -B target`: To generate *Makefile* under the *target* 
  directory
* `$ make -C target`: Compile all source files and generate 
  *libsolution.a* under the *target/lib* directory using 
  *Makefile* under the *target* directory
* `$ make test -C target`: Compile all unit-test source files 
  and output to the *target/tests* directory using *Makefile* 
  under the *target* directory
* `$ make cleanall -C target`: Remove the *target* directories

[CMakeLists.txt:](./CMakeLists.txt)

```
# Using the current cmake version as a reqiremnet.
# This version is somewhat arbitrary in this example. 
# But providing a version number allows for future support for your build environment. 
# Therefore, you should use the current version of CMake on your system. 
# You can find out the current verion of CMake by the shell command: `cmake --version`.
cmake_minimum_required( VERSION 3.20.3 )                                    

# Sets the name of the project, and stores it in the variable PROJECT_NAME. 
# When called from the top-level CMakeLists.txt also stores the project name in the variable CMAKE_PROJECT_NAME.
project( solution )													    

# 1. Specify debug flag, it's like -g option to gcc
#    By default, CMake is able to handle the following build types:
#    - Debug: Usually a classic debug build including debugging information, no optimization etc. 
#    - Release: Your typical release build with no debugging information and full optimization. 
#    - RelWithDebInfo: Same as Release, but with debugging information. 
#    - MinSizeRel: A special Release build optimized for size.
# 2. These will add the needed compile options on targets (e.g. -std=c++17 for gcc)
# 3. The version can be made a requirement by setting to ON the variables 
#    CMAKE_C_STANDARD_REQUIRED and CMAKE_CXX_STANDARD_REQUIRED respectively
# 4. Specify some other flags for gcc
# 5. Additional flags under debug mode
# 6. Additional flags under release mode
# 7. For clangd
# 8. To build CMake in a different directory, set default to "build" (NOT WORKING!!)
# ---------------------------------------------------------------------------------- {{{
set( CMAKE_BUILD_TYPE              Debug                          ) # (1)
set( CMAKE_CXX_STANDARD            17                             ) # (2)
set( CMAKE_CXX_STANDARD_REQUIRED   ON                             ) # (3)
set( CMAKE_CXX_COMPILER            "g++"                          ) 
set( CMAKE_CXX_FLAGS                                              ) # (4)	
set( CMAKE_CXX_FLAGS_DEBUG         "-O0 -Werror -pedantic-errors" ) # (5)  
set( CMAKE_CXX_FLAGS_RELEASE       "-O2 -DNDEBUG "                ) # (6) 
set( CMAKE_EXPORT_COMPILE_COMMANDS 1                              ) # (7)
set( CMAKE_BINARY_DIR              build                          ) # (8)
# }}}

# 1. Add the given directories to those the compiler uses to search for include files.
#    Relative paths are interpreted as relative to the current source directory
#    (like -I flag).
# 2. Adds the paths in which the linker should search for libraries. 
#    Relative paths given to this command are interpreted as relative to the current source directory
#    (like -L flag).
# ---------------------------------------------------------------------------------------------------- {{{
include_directories( ${PROJECT_SOURCE_DIR}/inc /opt/homebrew/include/ ) # (1)												
link_directories()                                                      # (2)
# }}}

# build libraries from sources
# 
# 1. Set my library name to be ${PROJECT_NAME} and store in the user-defined variable ${lib_name} 
# 2. The ARCHIVE_OUTPUT_DIRECTORY property specifies the directory into which archive target files should be built.
#    And the property is initialized by the value of the CMAKE_ARCHIVE_OUTPUT_DIRECTORY variable if it is set when a target is created.
# 3. The LIBRARY_OUTPUT_DIRECTORY property specifies the directory into which library target files should be built.
#    And the property is initialized by the value of the CMAKE_LIBRARY_OUTPUT_DIRECTORY variable if it is set when a target is created.
# -------------------------------------------- {{{
set( lib_name                       ${PROJECT_NAME}                  ) # (1)                   
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/target/lib ) # (2)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/target/lib ) # (3)
file( GLOB lib_src ${PROJECT_SOURCE_DIR}/src/*.cpp )
add_library( ${lib_name} STATIC ${lib_src} ) # static library
# }}} 

# Build each test 
#
# 1. The RUNTIME_OUTPUT_DIRECTORY specifies the directory into which runtime target files should be built. 
#    And the property is initialized by the value of the CMAKE_RUNTIME_OUTPUT_DIRECTORY variable if it is set when a target is created.
# ------------------------- {{{ 
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/target/tests ) # (1)	
file( GLOB test_src ${PROJECT_SOURCE_DIR}/src/tests/*.cpp )
foreach( item ${test_src} )
	get_filename_component( test ${item} NAME_WE )
	string( REPLACE test_ "" src ${test} )
	add_executable( ${test} src/tests/${test}.cpp src/${src}.cpp src/solution.cpp )
endforeach()
# }}}

add_custom_target( cleanall 
	COMMAND rm -rf ${PROJECT_SOURCE_DIR}/target/
)
```

# Developer Notes
  
## How to push commits to this repository on github

1. First login your github account: 
2. click `Settings` -> `Developer settings` -> `Personal access token` 
   -> `Tokens(classic)`
3. Generate new token or revoke the **syc_push_repo_from_mac** 
   personal access token (PAC)
4. Then use git commands from your local. For example, `git push -u origin main`

## TODO

* [x] Reference to the *CMakeLists.txt* old project 
      and create one for this project, so that there 
	  will be two ways to build this project. Then,
      add the demonstration of **cmake** way to 
	  this *README.md*
* [x] Fix `Solution::longestPalindrome` methods to 
      pass its unit-tests
* [ ] Consider to add `free()` function to free the 
      resources used by `TreeNode *` and `ListNode *`.
	  And add memory leak check g++ flag to the 
	  *Makefile*
* [ ] Try google test: **gtest** using **cmake** to build
