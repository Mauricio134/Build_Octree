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

# Utility rule file for vtkIOCesium3DTiles-hierarchy.

# Include any custom commands dependencies for this target.
include IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/compiler_depend.make

# Include the progress variables for this target.
include IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/progress.make

IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt
IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy: bin/vtkWrapHierarchy-9.3

lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Cesium3DTiles/vtkCesium3DTilesWriter.h
lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Cesium3DTiles/vtkCesiumPointCloudWriter.h
lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt: IO/Cesium3DTiles/vtkIOCesium3DTilesModule.h
lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt: IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.Debug.args
lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt: IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.data
lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt: IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.depends.args
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating the wrap hierarchy for VTK::IOCesium3DTiles"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Cesium3DTiles && ../../bin/vtkWrapHierarchy-9.3 @/Users/mauricioapaza/Desktop/Build_octree/build/IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.Debug.args -o /Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt /Users/mauricioapaza/Desktop/Build_octree/build/IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.data @/Users/mauricioapaza/Desktop/Build_octree/build/IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.depends.args

vtkIOCesium3DTiles-hierarchy: IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy
vtkIOCesium3DTiles-hierarchy: lib/vtk-9.3/hierarchy/VTK/vtkIOCesium3DTiles-hierarchy.txt
vtkIOCesium3DTiles-hierarchy: IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/build.make
.PHONY : vtkIOCesium3DTiles-hierarchy

# Rule to build all files generated by this target.
IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/build: vtkIOCesium3DTiles-hierarchy
.PHONY : IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/build

IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Cesium3DTiles && $(CMAKE_COMMAND) -P CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/cmake_clean.cmake
.PHONY : IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/clean

IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Cesium3DTiles /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/IO/Cesium3DTiles /Users/mauricioapaza/Desktop/Build_octree/build/IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : IO/Cesium3DTiles/CMakeFiles/vtkIOCesium3DTiles-hierarchy.dir/depend

