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
include IO/Movie/CMakeFiles/IOMovie.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include IO/Movie/CMakeFiles/IOMovie.dir/compiler_depend.make

# Include the progress variables for this target.
include IO/Movie/CMakeFiles/IOMovie.dir/progress.make

# Include the compile flags for this target's objects.
include IO/Movie/CMakeFiles/IOMovie.dir/flags.make

IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o: IO/Movie/CMakeFiles/IOMovie.dir/flags.make
IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Movie/vtkGenericMovieWriter.cxx
IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o: IO/Movie/CMakeFiles/IOMovie.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o -MF CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o.d -o CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Movie/vtkGenericMovieWriter.cxx

IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Movie/vtkGenericMovieWriter.cxx > CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.i

IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Movie/vtkGenericMovieWriter.cxx -o CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.s

# Object files for target IOMovie
IOMovie_OBJECTS = \
"CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o"

# External object files for target IOMovie
IOMovie_EXTERNAL_OBJECTS =

lib/libvtkIOMovie-9.3.9.3.dylib: IO/Movie/CMakeFiles/IOMovie.dir/vtkGenericMovieWriter.cxx.o
lib/libvtkIOMovie-9.3.9.3.dylib: IO/Movie/CMakeFiles/IOMovie.dir/build.make
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkCommonExecutionModel-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkCommonDataModel-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkCommonMisc-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkCommonSystem-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkCommonTransforms-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkCommonMath-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkkissfft-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtkCommonCore-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: lib/libvtksys-9.3.9.3.dylib
lib/libvtkIOMovie-9.3.9.3.dylib: IO/Movie/CMakeFiles/IOMovie.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libvtkIOMovie-9.3.dylib"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IOMovie.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libvtkIOMovie-9.3.9.3.dylib ../../lib/libvtkIOMovie-9.3.1.dylib ../../lib/libvtkIOMovie-9.3.dylib

lib/libvtkIOMovie-9.3.1.dylib: lib/libvtkIOMovie-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkIOMovie-9.3.1.dylib

lib/libvtkIOMovie-9.3.dylib: lib/libvtkIOMovie-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkIOMovie-9.3.dylib

# Rule to build all files generated by this target.
IO/Movie/CMakeFiles/IOMovie.dir/build: lib/libvtkIOMovie-9.3.dylib
.PHONY : IO/Movie/CMakeFiles/IOMovie.dir/build

IO/Movie/CMakeFiles/IOMovie.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie && $(CMAKE_COMMAND) -P CMakeFiles/IOMovie.dir/cmake_clean.cmake
.PHONY : IO/Movie/CMakeFiles/IOMovie.dir/clean

IO/Movie/CMakeFiles/IOMovie.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Movie /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie /Users/mauricioapaza/Desktop/Build_octree/build/IO/Movie/CMakeFiles/IOMovie.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : IO/Movie/CMakeFiles/IOMovie.dir/depend

