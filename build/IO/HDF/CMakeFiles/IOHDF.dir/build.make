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
include IO/HDF/CMakeFiles/IOHDF.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include IO/HDF/CMakeFiles/IOHDF.dir/compiler_depend.make

# Include the progress variables for this target.
include IO/HDF/CMakeFiles/IOHDF.dir/progress.make

# Include the compile flags for this target's objects.
include IO/HDF/CMakeFiles/IOHDF.dir/flags.make

IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o: IO/HDF/CMakeFiles/IOHDF.dir/flags.make
IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReader.cxx
IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o: IO/HDF/CMakeFiles/IOHDF.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o -MF CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o.d -o CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReader.cxx

IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReader.cxx > CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.i

IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReader.cxx -o CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.s

IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o: IO/HDF/CMakeFiles/IOHDF.dir/flags.make
IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReaderImplementation.cxx
IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o: IO/HDF/CMakeFiles/IOHDF.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o -MF CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o.d -o CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o -c /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReaderImplementation.cxx

IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.i"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReaderImplementation.cxx > CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.i

IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.s"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF/vtkHDFReaderImplementation.cxx -o CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.s

# Object files for target IOHDF
IOHDF_OBJECTS = \
"CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o" \
"CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o"

# External object files for target IOHDF
IOHDF_EXTERNAL_OBJECTS =

lib/libvtkIOHDF-9.3.9.3.dylib: IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReader.cxx.o
lib/libvtkIOHDF-9.3.9.3.dylib: IO/HDF/CMakeFiles/IOHDF.dir/vtkHDFReaderImplementation.cxx.o
lib/libvtkIOHDF-9.3.9.3.dylib: IO/HDF/CMakeFiles/IOHDF.dir/build.make
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkFiltersCore-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkIOCore-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkhdf5_hl-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkhdf5-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkCommonExecutionModel-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkCommonDataModel-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkCommonTransforms-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkCommonSystem-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkCommonMisc-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkCommonMath-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkCommonCore-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtksys-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: lib/libvtkkissfft-9.3.9.3.dylib
lib/libvtkIOHDF-9.3.9.3.dylib: IO/HDF/CMakeFiles/IOHDF.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mauricioapaza/Desktop/Build_octree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../lib/libvtkIOHDF-9.3.dylib"
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IOHDF.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && $(CMAKE_COMMAND) -E cmake_symlink_library ../../lib/libvtkIOHDF-9.3.9.3.dylib ../../lib/libvtkIOHDF-9.3.1.dylib ../../lib/libvtkIOHDF-9.3.dylib

lib/libvtkIOHDF-9.3.1.dylib: lib/libvtkIOHDF-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkIOHDF-9.3.1.dylib

lib/libvtkIOHDF-9.3.dylib: lib/libvtkIOHDF-9.3.9.3.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libvtkIOHDF-9.3.dylib

# Rule to build all files generated by this target.
IO/HDF/CMakeFiles/IOHDF.dir/build: lib/libvtkIOHDF-9.3.dylib
.PHONY : IO/HDF/CMakeFiles/IOHDF.dir/build

IO/HDF/CMakeFiles/IOHDF.dir/clean:
	cd /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF && $(CMAKE_COMMAND) -P CMakeFiles/IOHDF.dir/cmake_clean.cmake
.PHONY : IO/HDF/CMakeFiles/IOHDF.dir/clean

IO/HDF/CMakeFiles/IOHDF.dir/depend:
	cd /Users/mauricioapaza/Desktop/Build_octree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1 /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/HDF /Users/mauricioapaza/Desktop/Build_octree/build /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF /Users/mauricioapaza/Desktop/Build_octree/build/IO/HDF/CMakeFiles/IOHDF.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : IO/HDF/CMakeFiles/IOHDF.dir/depend

