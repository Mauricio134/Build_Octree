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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.5/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mauricioapaza/Desktop/Build_octree/build

# Include any dependencies generated for this target.
include Wrapping/Tools/CMakeFiles/WrapJava.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Wrapping/Tools/CMakeFiles/WrapJava.dir/compiler_depend.make

# Include the progress variables for this target.
include Wrapping/Tools/CMakeFiles/WrapJava.dir/progress.make

# Include the compile flags for this target's objects.
include Wrapping/Tools/CMakeFiles/WrapJava.dir/flags.make

Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.o: Wrapping/Tools/CMakeFiles/WrapJava.dir/flags.make
Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Wrapping/Tools/vtkWrapJava.c
Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.o: Wrapping/Tools/CMakeFiles/WrapJava.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Wrapping/Tools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.o -MF CMakeFiles/WrapJava.dir/vtkWrapJava.c.o.d -o CMakeFiles/WrapJava.dir/vtkWrapJava.c.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Wrapping/Tools/vtkWrapJava.c

Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/WrapJava.dir/vtkWrapJava.c.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Wrapping/Tools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Wrapping/Tools/vtkWrapJava.c > CMakeFiles/WrapJava.dir/vtkWrapJava.c.i

Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/WrapJava.dir/vtkWrapJava.c.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Wrapping/Tools && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Wrapping/Tools/vtkWrapJava.c -o CMakeFiles/WrapJava.dir/vtkWrapJava.c.s

# Object files for target WrapJava
WrapJava_OBJECTS = \
"CMakeFiles/WrapJava.dir/vtkWrapJava.c.o"

# External object files for target WrapJava
WrapJava_EXTERNAL_OBJECTS =

bin/vtkWrapJava-9.3: Wrapping/Tools/CMakeFiles/WrapJava.dir/vtkWrapJava.c.o
bin/vtkWrapJava-9.3: Wrapping/Tools/CMakeFiles/WrapJava.dir/build.make
bin/vtkWrapJava-9.3: lib/libvtkWrappingTools-9.3.9.3.dylib
bin/vtkWrapJava-9.3: Wrapping/Tools/CMakeFiles/WrapJava.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/vtkWrapJava-9.3"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Wrapping/Tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/WrapJava.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Wrapping/Tools/CMakeFiles/WrapJava.dir/build: bin/vtkWrapJava-9.3
.PHONY : Wrapping/Tools/CMakeFiles/WrapJava.dir/build

Wrapping/Tools/CMakeFiles/WrapJava.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Wrapping/Tools && $(CMAKE_COMMAND) -P CMakeFiles/WrapJava.dir/cmake_clean.cmake
.PHONY : Wrapping/Tools/CMakeFiles/WrapJava.dir/clean

Wrapping/Tools/CMakeFiles/WrapJava.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Wrapping/Tools /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/Wrapping/Tools /Users/mauricioapaza/Desktop/Build_octree/build/Wrapping/Tools/CMakeFiles/WrapJava.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Wrapping/Tools/CMakeFiles/WrapJava.dir/depend
