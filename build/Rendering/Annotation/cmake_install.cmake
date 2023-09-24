# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkAnnotatedCubeActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkArcPlotter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkAxesActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkAxisActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkAxisActor2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkAxisFollower.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkBarChartActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkCaptionActor2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkConvexHull2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkCornerAnnotation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkCubeAxesActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkCubeAxesActor2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkGraphAnnotationLayersFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkLeaderActor2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkLegendBoxActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkLegendScaleActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkParallelCoordinatesActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkPieChartActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkPolarAxesActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkProp3DAxisFollower.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkScalarBarActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkSpiderPlotActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkXYPlotActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/Annotation/vtkRenderingAnnotationModule.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Annotation/vtkScalarBarActorInternal.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkRenderingAnnotation-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkRenderingAnnotation-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingAnnotation-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingAnnotation-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingAnnotation-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingAnnotation-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingAnnotation-9.3.dylib")
endif()

