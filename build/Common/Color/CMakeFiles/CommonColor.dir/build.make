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
include Common/Color/CMakeFiles/CommonColor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Common/Color/CMakeFiles/CommonColor.dir/compiler_depend.make

# Include the progress variables for this target.
include Common/Color/CMakeFiles/CommonColor.dir/progress.make

# Include the compile flags for this target's objects.
include Common/Color/CMakeFiles/CommonColor.dir/flags.make

Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o: Common/Color/CMakeFiles/CommonColor.dir/flags.make
Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkColorSeries.cxx
Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o: Common/Color/CMakeFiles/CommonColor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o -MF CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o.d -o CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkColorSeries.cxx

Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkColorSeries.cxx > CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.i

Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkColorSeries.cxx -o CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.s

Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o: Common/Color/CMakeFiles/CommonColor.dir/flags.make
Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkNamedColors.cxx
Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o: Common/Color/CMakeFiles/CommonColor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o -MF CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o.d -o CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkNamedColors.cxx

Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkNamedColors.cxx > CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.i

Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color/vtkNamedColors.cxx -o CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.s

# Object files for target CommonColor
CommonColor_OBJECTS = \
"CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o" \
"CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o"

# External object files for target CommonColor
CommonColor_EXTERNAL_OBJECTS =

lib/libvtkCommonColor-9.3.9.3.dylib: Common/Color/CMakeFiles/CommonColor.dir/vtkColorSeries.cxx.o
lib/libvtkCommonColor-9.3.9.3.dylib: Common/Color/CMakeFiles/CommonColor.dir/vtkNamedColors.cxx.o
lib/libvtkCommonColor-9.3.9.3.dylib: Common/Color/CMakeFiles/CommonColor.dir/build.make
lib/libvtkCommonColor-9.3.9.3.dylib: lib/libvtkCommonDataModel-9.3.9.3.dylib
lib/libvtkCommonColor-9.3.9.3.dylib: lib/libvtkCommonTransforms-9.3.9.3.dylib
lib/libvtkCommonColor-9.3.9.3.dylib: lib/libvtkCommonMath-9.3.9.3.dylib
lib/libvtkCommonColor-9.3.9.3.dylib: lib/libvtkkissfft-9.3.9.3.dylib
lib/libvtkCommonColor-9.3.9.3.dylib: lib/libvtkCommonCore-9.3.9.3.dylib
lib/libvtkCommonColor-9.3.9.3.dylib: lib/libvtksys-9.3.9.3.dylib
lib/libvtkCommonColor-9.3.9.3.dylib: Common/Color/CMakeFiles/CommonColor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../lib/libvtkCommonColor-9.3.dylib"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CommonColor.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libvtkCommonColor-9.3.9.3.dylib ../../lib/libvtkCommonColor-9.3.1.dylib ../../lib/libvtkCommonColor-9.3.dylib

lib/libvtkCommonColor-9.3.1.dylib: lib/libvtkCommonColor-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkCommonColor-9.3.1.dylib

lib/libvtkCommonColor-9.3.dylib: lib/libvtkCommonColor-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkCommonColor-9.3.dylib

# Rule to build all files generated by this target.
Common/Color/CMakeFiles/CommonColor.dir/build: lib/libvtkCommonColor-9.3.dylib
.PHONY : Common/Color/CMakeFiles/CommonColor.dir/build

Common/Color/CMakeFiles/CommonColor.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color && $(CMAKE_COMMAND) -P CMakeFiles/CommonColor.dir/cmake_clean.cmake
.PHONY : Common/Color/CMakeFiles/CommonColor.dir/clean

Common/Color/CMakeFiles/CommonColor.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/Color /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color /Users/mauricioapaza/Desktop/Build_octree/build/Common/Color/CMakeFiles/CommonColor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Common/Color/CMakeFiles/CommonColor.dir/depend

