# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/mauricioapaza/Desktop/Build_Octree/cmake-3.27.6/Bootstrap.cmk/cmake

# The command to remove a file.
RM = /Users/mauricioapaza/Desktop/Build_Octree/cmake-3.27.6/Bootstrap.cmk/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6

# Include any dependencies generated for this target.
include Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/compiler_depend.make

# Include the progress variables for this target.
include Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/flags.make

Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.o: Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/flags.make
Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.o: Tests/CMakeLib/PseudoMemcheck/NoLog/ret0.c
Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.o: Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.o -MF CMakeFiles/pseudonl_BC.dir/ret0.c.o.d -o CMakeFiles/pseudonl_BC.dir/ret0.c.o -c /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog/ret0.c

Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/pseudonl_BC.dir/ret0.c.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog/ret0.c > CMakeFiles/pseudonl_BC.dir/ret0.c.i

Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/pseudonl_BC.dir/ret0.c.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog/ret0.c -o CMakeFiles/pseudonl_BC.dir/ret0.c.s

# Object files for target pseudonl_BC
pseudonl_BC_OBJECTS = \
"CMakeFiles/pseudonl_BC.dir/ret0.c.o"

# External object files for target pseudonl_BC
pseudonl_BC_EXTERNAL_OBJECTS =

Tests/CMakeLib/PseudoMemcheck/NoLog/BC: Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/ret0.c.o
Tests/CMakeLib/PseudoMemcheck/NoLog/BC: Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/build.make
Tests/CMakeLib/PseudoMemcheck/NoLog/BC: Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable BC"
	cd /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pseudonl_BC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/build: Tests/CMakeLib/PseudoMemcheck/NoLog/BC
.PHONY : Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/build

Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog && $(CMAKE_COMMAND) -P CMakeFiles/pseudonl_BC.dir/cmake_clean.cmake
.PHONY : Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/clean

Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6 /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6 /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog /Users/mauricioapaza/Desktop/Build_octree/cmake-3.27.6/Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Tests/CMakeLib/PseudoMemcheck/NoLog/CMakeFiles/pseudonl_BC.dir/depend

