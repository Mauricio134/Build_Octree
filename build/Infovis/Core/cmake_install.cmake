# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkAddMembershipArray.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkAdjacencyMatrixToEdgeTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkArrayNorm.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkArrayToTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkCollapseGraph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkCollapseVerticesByArray.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkContinuousScatterplot.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkDataObjectToTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkDotProductSimilarity.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkEdgeCenters.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkExpandSelectedGraph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkExtractSelectedGraph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkExtractSelectedTree.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkGenerateIndexArray.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkGraphHierarchicalBundleEdges.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkGroupLeafVertices.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkKCoreDecomposition.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkMergeColumns.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkMergeGraphs.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkMergeTables.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkMutableGraphHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkNetworkHierarchy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkPipelineGraphSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkPruneTreeFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkRandomGraphSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkReduceTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkRemoveHiddenData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkRemoveIsolatedVertices.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkSparseArrayToTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkStreamGraph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkStringToCategory.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkStringToNumeric.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTableToArray.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTableToGraph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTableToSparseArray.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTableToTreeFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkThresholdGraph.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkThresholdTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTransferAttributes.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTransposeMatrix.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTreeDifferenceFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTreeFieldAggregator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkTreeLevelsFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkVertexDegree.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/vtkWordCloud.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Infovis/Core/vtkInfovisCoreModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkInfovisCore-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkInfovisCore-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkInfovisCore-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkInfovisCore-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkInfovisCore-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkInfovisCore-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkInfovisCore" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Infovis/Core/LICENSE")
endif()

