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
CMAKE_SOURCE_DIR = /Users/mauricioapaza/Desktop/Build_Octree/rtree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mauricioapaza/Desktop/Build_Octree/rtree

# Include any dependencies generated for this target.
include CMakeFiles/Rect.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Rect.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Rect.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Rect.dir/flags.make

CMakeFiles/Rect.dir/main.cpp.o: CMakeFiles/Rect.dir/flags.make
CMakeFiles/Rect.dir/main.cpp.o: main.cpp
CMakeFiles/Rect.dir/main.cpp.o: CMakeFiles/Rect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_Octree/rtree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Rect.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Rect.dir/main.cpp.o -MF CMakeFiles/Rect.dir/main.cpp.o.d -o CMakeFiles/Rect.dir/main.cpp.o -c /Users/mauricioapaza/Desktop/Build_Octree/rtree/main.cpp

CMakeFiles/Rect.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Rect.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_Octree/rtree/main.cpp > CMakeFiles/Rect.dir/main.cpp.i

CMakeFiles/Rect.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Rect.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_Octree/rtree/main.cpp -o CMakeFiles/Rect.dir/main.cpp.s

CMakeFiles/Rect.dir/RTree.cpp.o: CMakeFiles/Rect.dir/flags.make
CMakeFiles/Rect.dir/RTree.cpp.o: RTree.cpp
CMakeFiles/Rect.dir/RTree.cpp.o: CMakeFiles/Rect.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_Octree/rtree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Rect.dir/RTree.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Rect.dir/RTree.cpp.o -MF CMakeFiles/Rect.dir/RTree.cpp.o.d -o CMakeFiles/Rect.dir/RTree.cpp.o -c /Users/mauricioapaza/Desktop/Build_Octree/rtree/RTree.cpp

CMakeFiles/Rect.dir/RTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Rect.dir/RTree.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_Octree/rtree/RTree.cpp > CMakeFiles/Rect.dir/RTree.cpp.i

CMakeFiles/Rect.dir/RTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Rect.dir/RTree.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_Octree/rtree/RTree.cpp -o CMakeFiles/Rect.dir/RTree.cpp.s

# Object files for target Rect
Rect_OBJECTS = \
"CMakeFiles/Rect.dir/main.cpp.o" \
"CMakeFiles/Rect.dir/RTree.cpp.o"

# External object files for target Rect
Rect_EXTERNAL_OBJECTS =

Rect.app/Contents/MacOS/Rect: CMakeFiles/Rect.dir/main.cpp.o
Rect.app/Contents/MacOS/Rect: CMakeFiles/Rect.dir/RTree.cpp.o
Rect.app/Contents/MacOS/Rect: CMakeFiles/Rect.dir/build.make
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkInteractionStyle-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingContextOpenGL2-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingGL2PSOpenGL2-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingOpenGL2-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingContext2D-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingFreeType-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkfreetype-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /Library/Developer/CommandLineTools/SDKs/MacOSX13.3.sdk/usr/lib/libz.tbd
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingHyperTreeGrid-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingUI-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkRenderingCore-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkCommonColor-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkFiltersSources-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkFiltersGeneral-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkFiltersCore-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkCommonExecutionModel-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkCommonDataModel-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkCommonTransforms-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkCommonMisc-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libGLEW.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkCommonMath-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkCommonCore-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtksys-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: /usr/local/lib/libvtkkissfft-9.2.9.2.6.dylib
Rect.app/Contents/MacOS/Rect: CMakeFiles/Rect.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_Octree/rtree/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Rect.app/Contents/MacOS/Rect"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Rect.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Rect.dir/build: Rect.app/Contents/MacOS/Rect
.PHONY : CMakeFiles/Rect.dir/build

CMakeFiles/Rect.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Rect.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Rect.dir/clean

CMakeFiles/Rect.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_Octree/rtree && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_Octree/rtree /Users/mauricioapaza/Desktop/Build_Octree/rtree /Users/mauricioapaza/Desktop/Build_Octree/rtree /Users/mauricioapaza/Desktop/Build_Octree/rtree /Users/mauricioapaza/Desktop/Build_Octree/rtree/CMakeFiles/Rect.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Rect.dir/depend
