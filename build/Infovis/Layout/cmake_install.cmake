# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkArcParallelEdgeStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkAreaLayout.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkAreaLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkAssignCoordinates.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkAssignCoordinatesLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkAttributeClustering2DLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkBoxLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkCirclePackFrontChainLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkCirclePackLayout.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkCirclePackLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkCirclePackToPolyData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkCircularLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkClustering2DLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkCommunity2DLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkConeLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkConstrained2DLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkCosmicTreeLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkEdgeLayout.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkEdgeLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkFast2DLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkForceDirectedLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkGeoEdgeStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkGeoMath.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkGraphLayout.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkGraphLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkIncrementalForceLayout.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkKCoreLayout.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkPassThroughEdgeStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkPassThroughLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkPerturbCoincidentVertices.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkRandomLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkSimple2DLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkSimple3DCirclesStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkSliceAndDiceLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkSpanTreeLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkSplineGraphEdges.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkSquarifyLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkStackedTreeLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkTreeLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkTreeMapLayout.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkTreeMapLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkTreeMapToPolyData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkTreeOrbitLayoutStrategy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/vtkTreeRingToPolyData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Infovis/Layout/vtkInfovisLayoutModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkInfovisLayout-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkInfovisLayout-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkInfovisLayout-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkInfovisLayout-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisLayout-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkInfovisLayout-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkInfovisLayout" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Layout/LICENSE")
endif()

