# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/vtkfmt" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/args.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/chrono.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/color.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/compile.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/core.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/format.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/format-inl.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/os.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/ostream.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/printf.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/ranges.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/std.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fmt/vtkfmt/vtkfmt/xchar.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkfmt-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkfmt-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkfmt-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkfmt-9.3.1.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND /usr/bin/install_name_tool
        -add_rpath "@loader_path"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkfmt-9.3.dylib")
endif()

