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
include IO/OggTheora/CMakeFiles/IOOggTheora.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include IO/OggTheora/CMakeFiles/IOOggTheora.dir/compiler_depend.make

# Include the progress variables for this target.
include IO/OggTheora/CMakeFiles/IOOggTheora.dir/progress.make

# Include the compile flags for this target's objects.
include IO/OggTheora/CMakeFiles/IOOggTheora.dir/flags.make

IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o: IO/OggTheora/CMakeFiles/IOOggTheora.dir/flags.make
IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/OggTheora/vtkOggTheoraWriter.cxx
IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o: IO/OggTheora/CMakeFiles/IOOggTheora.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o -MF CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o.d -o CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/OggTheora/vtkOggTheoraWriter.cxx

IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/OggTheora/vtkOggTheoraWriter.cxx > CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.i

IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/OggTheora/vtkOggTheoraWriter.cxx -o CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.s

# Object files for target IOOggTheora
IOOggTheora_OBJECTS = \
"CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o"

# External object files for target IOOggTheora
IOOggTheora_EXTERNAL_OBJECTS =

lib/libvtkIOOggTheora-9.3.9.3.dylib: IO/OggTheora/CMakeFiles/IOOggTheora.dir/vtkOggTheoraWriter.cxx.o
lib/libvtkIOOggTheora-9.3.9.3.dylib: IO/OggTheora/CMakeFiles/IOOggTheora.dir/build.make
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkIOMovie-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtktheora-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkCommonExecutionModel-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkCommonDataModel-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkCommonTransforms-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkCommonMisc-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkCommonMath-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkkissfft-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkCommonSystem-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkCommonCore-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtksys-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: lib/libvtkogg-9.3.9.3.dylib
lib/libvtkIOOggTheora-9.3.9.3.dylib: IO/OggTheora/CMakeFiles/IOOggTheora.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/libvtkIOOggTheora-9.3.dylib"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IOOggTheora.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libvtkIOOggTheora-9.3.9.3.dylib ../../lib/libvtkIOOggTheora-9.3.1.dylib ../../lib/libvtkIOOggTheora-9.3.dylib

lib/libvtkIOOggTheora-9.3.1.dylib: lib/libvtkIOOggTheora-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkIOOggTheora-9.3.1.dylib

lib/libvtkIOOggTheora-9.3.dylib: lib/libvtkIOOggTheora-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkIOOggTheora-9.3.dylib

# Rule to build all files generated by this target.
IO/OggTheora/CMakeFiles/IOOggTheora.dir/build: lib/libvtkIOOggTheora-9.3.dylib
.PHONY : IO/OggTheora/CMakeFiles/IOOggTheora.dir/build

IO/OggTheora/CMakeFiles/IOOggTheora.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora && $(CMAKE_COMMAND) -P CMakeFiles/IOOggTheora.dir/cmake_clean.cmake
.PHONY : IO/OggTheora/CMakeFiles/IOOggTheora.dir/clean

IO/OggTheora/CMakeFiles/IOOggTheora.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/OggTheora /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora /Users/mauricioapaza/Desktop/Build_octree/build/IO/OggTheora/CMakeFiles/IOOggTheora.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : IO/OggTheora/CMakeFiles/IOOggTheora.dir/depend

