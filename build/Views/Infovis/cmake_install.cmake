# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkApplyColors.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkApplyIcons.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkDendrogramItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkGraphItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkGraphLayoutView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkHeatmapItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkHierarchicalGraphPipeline.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkHierarchicalGraphView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkIcicleView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkInteractorStyleAreaSelectHover.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkInteractorStyleTreeMapHover.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkParallelCoordinatesHistogramRepresentation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkParallelCoordinatesRepresentation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkParallelCoordinatesView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkRenderedGraphRepresentation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkRenderedHierarchyRepresentation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkRenderedRepresentation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkRenderedSurfaceRepresentation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkRenderedTreeAreaRepresentation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkRenderView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkSCurveSpline.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkTanglegramItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkTreeAreaView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkTreeHeatmapItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkTreeMapView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkTreeRingView.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/vtkViewUpdater.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Views/Infovis/vtkViewsInfovisModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkViewsInfovis-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkViewsInfovis-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkViewsInfovis-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkViewsInfovis-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkViewsInfovis-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkViewsInfovis-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkViewsInfovis" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Views/Infovis/LICENSE")
endif()

