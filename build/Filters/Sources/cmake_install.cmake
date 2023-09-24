# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkArcSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkArrowSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkButtonSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkCapsuleSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkCellTypeSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkConeSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkCubeSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkCylinderSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkDiagonalMatrixSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkDiskSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkEllipseArcSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkEllipticalButtonSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkFrustumSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkGlyphSource2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkGraphToPolyData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkHandleSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkHyperTreeGridPreConfiguredSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkHyperTreeGridSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkLineSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkOutlineCornerFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkOutlineCornerSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkOutlineSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkParametricFunctionSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPartitionedDataSetSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPartitionedDataSetCollectionSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPlaneSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPlatonicSolidSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPointHandleSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPointSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPolyLineSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkPolyPointSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkProgrammableDataObjectSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkProgrammableSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkRandomHyperTreeGridSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkRectangularButtonSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkRegularPolygonSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkSelectionSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkSphereSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkSuperquadricSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkTessellatedBoxSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkTextSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkTexturedSphereSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/vtkUniformHyperTreeGridSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Filters/Sources/vtkFiltersSourcesModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkFiltersSources-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkFiltersSources-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkFiltersSources-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkFiltersSources-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersSources-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkFiltersSources-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkFiltersSources-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkFiltersSources" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Filters/Sources/LICENSE")
endif()

