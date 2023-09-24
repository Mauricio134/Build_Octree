# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkCompositeDataReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkCompositeDataWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkDataObjectReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkDataObjectWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkDataReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkDataSetReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkDataSetWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkDataWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkGenericDataObjectReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkGenericDataObjectWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkGraphReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkGraphWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkPixelExtentIO.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkPolyDataReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkPolyDataWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkRectilinearGridReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkRectilinearGridWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkSimplePointsReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkSimplePointsWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkStructuredGridReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkStructuredGridWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkStructuredPointsReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkStructuredPointsWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkTableReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkTableWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkTreeReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkTreeWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkUnstructuredGridReader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/IO/Legacy/vtkUnstructuredGridWriter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/IO/Legacy/vtkIOLegacyModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkIOLegacy-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkIOLegacy-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkIOLegacy-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkIOLegacy-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkIOLegacy-9.3.1.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND /usr/bin/install_name_tool
        -delete_rpath "/Users/mauricioapaza/Desktop/Build_octree/build/lib"
        -add_rpath "@loader_path"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkIOLegacy-9.3.dylib")
endif()

