# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkBilinearQuadIntersection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkCardinalSpline.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkKochanekSpline.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricBohemianDome.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricBour.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricBoy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricCatalanMinimal.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricConicSpiral.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricCrossCap.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricDini.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricEllipsoid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricEnneper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricFigure8Klein.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricFunction.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricHenneberg.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricKlein.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricKuen.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricMobius.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricPluckerConoid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricPseudosphere.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricRandomHills.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricRoman.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricSpline.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricSuperEllipsoid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricSuperToroid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Common/ComputationalGeometry/vtkParametricTorus.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Common/ComputationalGeometry/vtkCommonComputationalGeometryModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkCommonComputationalGeometry-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkCommonComputationalGeometry-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkCommonComputationalGeometry-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkCommonComputationalGeometry-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkCommonComputationalGeometry-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkCommonComputationalGeometry-9.3.dylib")
endif()

