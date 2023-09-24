# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkAxis.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkAxisExtended.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkCategoryLegend.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChart.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartBox.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartHistogram2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartLegend.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartMatrix.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartParallelCoordinates.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartPie.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartXY.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkChartXYZ.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkColorLegend.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkColorTransferControlPointsItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkColorTransferFunctionItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkCompositeControlPointsItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkCompositeTransferFunctionItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkContextArea.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkContextPolygon.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkControlPointsItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkInteractiveArea.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkLookupTableItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPiecewiseControlPointsItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPiecewiseFunctionItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPiecewisePointHandleItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlot.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlot3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotArea.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotBag.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotBar.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotBarRangeHandlesItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotBox.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotFunctionalBag.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotGrid.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotHistogram2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotLine.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotLine3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotParallelCoordinates.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotPie.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotPoints.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotPoints3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotRangeHandlesItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotStacked.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkPlotSurface.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkRangeHandlesItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkScalarsToColorsItem.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Charts/Core/vtkScatterPlotMatrix.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Charts/Core/vtkChartsCoreModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkChartsCore-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkChartsCore-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkChartsCore-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkChartsCore-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkChartsCore-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkChartsCore-9.3.dylib")
endif()

