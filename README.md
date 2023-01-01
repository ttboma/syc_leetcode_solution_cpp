# Table of Contents
<!-- vim-markdown-toc GFM -->

* [Introduction](#introduction)
* [Structure of this Project](#structure-of-this-project)
* [Necessaries and Dependencies](#necessaries-and-dependencies)
* [Two ways to build this project](#two-ways-to-build-this-project)
  * [Method1: Build this Project with *Makefile* (Suggested)](#method1-build-this-project-with-makefile-suggested)
  * [Method2: Build this Project with *CMakeLists.txt*](#method2-build-this-project-with-cmakeliststxt)
* [Developer Notes](#developer-notes)
  * [How to push commits to this repository on github](#how-to-push-commits-to-this-repository-on-github)
  * [TODO](#todo)

<!-- vim-markdown-toc -->

## Introduction

This project is a collection of
LeetCode solutions written in **C++**. The purpose of the project
is to practice using **C++17**, manage building with **Make/CMake**, and
track progress using **Git**.

-- ***Yueh-chang Shieh*** 2022-12-4

## Structure of this Project

```txt
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
  
## Necessaries and Dependencies

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
  
## Two ways to build this project
  
### Method1: Build this Project with *Makefile* (Suggested)

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
then use command `bear --` before the above commands.
For example,

* `$ bear -- make debug -j16`
* `$ bear -- make test -j16`

### Method2: Build this Project with *CMakeLists.txt*

* `$ cmake . -B target`: To generate *Makefile* under the *target*
  directory
* `$ make -C target`: Compile all source files and generate
  *libsolution.a* under the *target/lib* directory using
  *Makefile* under the *target* directory
* `$ make test -C target`: Compile all unit-test source files
  and output to the *target/tests* directory using *Makefile*
  under the *target* directory
* `$ make cleanall -C target`: Remove the *target* directories

## Developer Notes
  
### How to push commits to this repository on github

1. First login your github account:
2. click `Settings` -> `Developer settings` -> `Personal access token`
   -> `Tokens(classic)`
3. Generate new token or revoke the **syc_push_repo_from_mac**
   personal access token (PAC)
4. Then use git commands from your local. For example, `git push -u origin main`

### TODO

* [x] Reference to the *CMakeLists.txt* old project
      and create one for this project, so that there
	    will be two ways to build this project. Then,
      add the demonstration of **cmake** way to this *README.md*
* [x] Fix `Solution::longestPalindrome` methods to
      pass its unit-tests
* [ ] Consider to add `free()` function to free the
      resources used by `TreeNode *` and `ListNode *`.
	    And add memory leak check g++ flag to the *Makefile*
* [ ] Try google test: **gtest** using **cmake** to build
