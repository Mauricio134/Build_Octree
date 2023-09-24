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

# Utility rule file for vtkFiltersGeometryPreview-hierarchy.

# Include any custom commands dependencies for this target.
include Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/compiler_depend.make

# Include the progress variables for this target.
include Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/progress.make

Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt
Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy: bin/vtkWrapHierarchy-9.3

lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/GeometryPreview/vtkOctreeImageToPointSetFilter.h
lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/GeometryPreview/vtkPointSetToOctreeImageFilter.h
lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/GeometryPreview/vtkPointSetStreamer.h
lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt: Filters/GeometryPreview/vtkFiltersGeometryPreviewModule.h
lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt: Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.Debug.args
lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt: Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.data
lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt: Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.depends.args
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating the wrap hierarchy for VTK::FiltersGeometryPreview"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Filters/GeometryPreview && ../../bin/vtkWrapHierarchy-9.3 @/Users/mauricioapaza/Desktop/Build_octree/build/Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.Debug.args -o /Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt /Users/mauricioapaza/Desktop/Build_octree/build/Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.data @/Users/mauricioapaza/Desktop/Build_octree/build/Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.depends.args

vtkFiltersGeometryPreview-hierarchy: Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy
vtkFiltersGeometryPreview-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkFiltersGeometryPreview-hierarchy.txt
vtkFiltersGeometryPreview-hierarchy: Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/build.make
.PHONY : vtkFiltersGeometryPreview-hierarchy

# Rule to build all files generated by this target.
Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/build: vtkFiltersGeometryPreview-hierarchy
.PHONY : Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/build

Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Filters/GeometryPreview && $(CMAKE_COMMAND) -P CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/cmake_clean.cmake
.PHONY : Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/clean

Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/GeometryPreview /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/Filters/GeometryPreview /Users/mauricioapaza/Desktop/Build_octree/build/Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Filters/GeometryPreview/CMakeFiles/vtkFiltersGeometryPreview-hierarchy.dir/depend

