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

# Utility rule file for vtkViewsContext2D-hierarchy.

# Include any custom commands dependencies for this target.
include Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/compiler_depend.make

# Include the progress variables for this target.
include Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/progress.make

Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt
Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy: bin/vtkWrapHierarchy-9.3

lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Context2D/vtkContextInteractorStyle.h
lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Context2D/vtkContextView.h
lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt: Views/Context2D/vtkViewsContext2DModule.h
lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt: Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.Debug.args
lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt: Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.data
lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt: Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.depends.args
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating the wrap hierarchy for VTK::ViewsContext2D"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Views/Context2D && ../../bin/vtkWrapHierarchy-9.3 @/Users/mauricioapaza/Desktop/Build_octree/build/Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.Debug.args -o /Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt /Users/mauricioapaza/Desktop/Build_octree/build/Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.data @/Users/mauricioapaza/Desktop/Build_octree/build/Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.depends.args

vtkViewsContext2D-hierarchy: Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy
vtkViewsContext2D-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkViewsContext2D-hierarchy.txt
vtkViewsContext2D-hierarchy: Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/build.make
.PHONY : vtkViewsContext2D-hierarchy

# Rule to build all files generated by this target.
Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/build: vtkViewsContext2D-hierarchy
.PHONY : Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/build

Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Views/Context2D && $(CMAKE_COMMAND) -P CMakeFiles/vtkViewsContext2D-hierarchy.dir/cmake_clean.cmake
.PHONY : Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/clean

Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Context2D /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/Views/Context2D /Users/mauricioapaza/Desktop/Build_octree/build/Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Views/Context2D/CMakeFiles/vtkViewsContext2D-hierarchy.dir/depend

