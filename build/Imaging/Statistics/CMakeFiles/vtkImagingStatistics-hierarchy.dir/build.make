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

# Utility rule file for vtkImagingStatistics-hierarchy.

# Include any custom commands dependencies for this target.
include Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/compiler_depend.make

# Include the progress variables for this target.
include Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/progress.make

Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt
Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy: bin/vtkWrapHierarchy-9.3

lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Statistics/vtkImageAccumulate.h
lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Statistics/vtkImageHistogram.h
lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Statistics/vtkImageHistogramStatistics.h
lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt: Imaging/Statistics/vtkImagingStatisticsModule.h
lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt: Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.Debug.args
lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt: Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.data
lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt: Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.depends.args
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating the wrap hierarchy for VTK::ImagingStatistics"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Statistics && ../../bin/vtkWrapHierarchy-9.3 @/Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.Debug.args -o /Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt /Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.data @/Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.depends.args

vtkImagingStatistics-hierarchy: Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy
vtkImagingStatistics-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkImagingStatistics-hierarchy.txt
vtkImagingStatistics-hierarchy: Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/build.make
.PHONY : vtkImagingStatistics-hierarchy

# Rule to build all files generated by this target.
Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/build: vtkImagingStatistics-hierarchy
.PHONY : Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/build

Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Statistics && $(CMAKE_COMMAND) -P CMakeFiles/vtkImagingStatistics-hierarchy.dir/cmake_clean.cmake
.PHONY : Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/clean

Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Statistics /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Statistics /Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Imaging/Statistics/CMakeFiles/vtkImagingStatistics-hierarchy.dir/depend

