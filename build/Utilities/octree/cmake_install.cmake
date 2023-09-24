# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/octree" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_cursor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_iterator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_node.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_path.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree.txx"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_cursor.txx"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_iterator.txx"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_node.txx"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Utilities/octree/octree/octree_path.txx"
    )
endif()

