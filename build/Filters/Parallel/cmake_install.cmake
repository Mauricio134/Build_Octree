# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkBlockDistribution.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkAdaptiveTemporalInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkAggregateDataSetFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkAlignImageDataSetFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkAngularPeriodicFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkCollectGraph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkCollectPolyData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkCollectTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkCutMaterial.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkDistributedDataFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkDuplicatePolyData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkExtractCTHPart.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkExtractPolyDataPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkExtractUnstructuredGridPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkExtractUserDefinedPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkGenerateProcessIds.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkHyperTreeGridGhostCellsGenerator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPHyperTreeGridProbeFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkIntegrateAttributes.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPeriodicFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPCellDataToPointData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPConvertToMultiBlockDataSet.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPExtractDataArraysOverTime.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPExtractExodusGlobalTemporalVariables.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPExtractSelectedArraysOverTime.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPieceRequestFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPieceScalars.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPipelineSize.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPKdTree.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPLinearExtrusionFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPMaskPoints.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPMergeArrays.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPOutlineCornerFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPOutlineFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPOutlineFilterInternals.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPPolyDataNormals.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPProbeFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPProjectSphereFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPReflectionFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPResampleFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPartitionBalancer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkProcessIdScalars.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPSphereSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPTextureMapToSphere.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkPYoungsMaterialInterface.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkRectilinearGridOutlineFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkRemoveGhosts.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkTransmitPolyDataPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkTransmitRectilinearGridPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkTransmitStructuredDataPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkTransmitStructuredGridPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Parallel/vtkTransmitUnstructuredGridPiece.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Filters/Parallel/vtkFiltersParallelModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkFiltersParallel-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkFiltersParallel-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkFiltersParallel-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkFiltersParallel-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersParallel-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkFiltersParallel-9.3.dylib")
endif()

