# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-9.3/vtkfast_float/vtkfast_float" TYPE FILE FILES
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/ascii_number.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/bigint.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/decimal_to_binary.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/digit_comparison.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/fast_float.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/fast_table.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/float_common.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/parse_number.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/simple_decimal_conversion.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/ThirdParty/fast_float/vtkfast_float/vtkfast_float/vtkfast_float_mangle.h"
    )
endif()

