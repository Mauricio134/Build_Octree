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
include ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/compiler_depend.make

# Include the progress variables for this target.
include ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/progress.make

# Include the compile flags for this target's objects.
include ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/flags.make

ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.o: ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/flags.make
ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/hdf5/vtkhdf5/src/H5detect.c
ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.o: ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/hdf5/vtkhdf5/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.o -MF CMakeFiles/H5detect.dir/H5detect.c.o.d -o CMakeFiles/H5detect.dir/H5detect.c.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/hdf5/vtkhdf5/src/H5detect.c

ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/H5detect.dir/H5detect.c.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/hdf5/vtkhdf5/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/hdf5/vtkhdf5/src/H5detect.c > CMakeFiles/H5detect.dir/H5detect.c.i

ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/H5detect.dir/H5detect.c.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/hdf5/vtkhdf5/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/hdf5/vtkhdf5/src/H5detect.c -o CMakeFiles/H5detect.dir/H5detect.c.s

# Object files for target H5detect
H5detect_OBJECTS = \
"CMakeFiles/H5detect.dir/H5detect.c.o"

# External object files for target H5detect
H5detect_EXTERNAL_OBJECTS =

bin/vtkH5detect: ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/H5detect.c.o
bin/vtkH5detect: ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/build.make
bin/vtkH5detect: ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../../bin/vtkH5detect"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/hdf5/vtkhdf5/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/H5detect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/build: bin/vtkH5detect
.PHONY : ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/build

ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/hdf5/vtkhdf5/src && $(CMAKE_COMMAND) -P CMakeFiles/H5detect.dir/cmake_clean.cmake
.PHONY : ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/clean

ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/hdf5/vtkhdf5/src /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/hdf5/vtkhdf5/src /Users/mauricioapaza/Desktop/Build_octree/build/ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : ThirdParty/hdf5/vtkhdf5/src/CMakeFiles/H5detect.dir/depend

