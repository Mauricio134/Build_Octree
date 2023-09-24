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

# Utility rule file for vtkIOSegY-hierarchy.

# Include any custom commands dependencies for this target.
include IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/compiler_depend.make

# Include the progress variables for this target.
include IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/progress.make

IO/SegY/CMakeFiles/vtkIOSegY-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt
IO/SegY/CMakeFiles/vtkIOSegY-hierarchy: bin/vtkWrapHierarchy-9.3

lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/SegY/vtkSegYReader.h
lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt: IO/SegY/vtkIOSegYModule.h
lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt: IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.Debug.args
lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt: IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.data
lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt: IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.depends.args
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating the wrap hierarchy for VTK::IOSegY"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/SegY && ../../bin/vtkWrapHierarchy-9.3 @/Users/mauricioapaza/Desktop/Build_octree/build/IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.Debug.args -o /Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt /Users/mauricioapaza/Desktop/Build_octree/build/IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.data @/Users/mauricioapaza/Desktop/Build_octree/build/IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.depends.args

vtkIOSegY-hierarchy: IO/SegY/CMakeFiles/vtkIOSegY-hierarchy
vtkIOSegY-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkIOSegY-hierarchy.txt
vtkIOSegY-hierarchy: IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/build.make
.PHONY : vtkIOSegY-hierarchy

# Rule to build all files generated by this target.
IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/build: vtkIOSegY-hierarchy
.PHONY : IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/build

IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/SegY && $(CMAKE_COMMAND) -P CMakeFiles/vtkIOSegY-hierarchy.dir/cmake_clean.cmake
.PHONY : IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/clean

IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/SegY /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/IO/SegY /Users/mauricioapaza/Desktop/Build_octree/build/IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : IO/SegY/CMakeFiles/vtkIOSegY-hierarchy.dir/depend

