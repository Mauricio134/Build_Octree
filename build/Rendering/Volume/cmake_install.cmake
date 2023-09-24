# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkBlockSortHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkDirectionEncoder.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkEncodedGradientEstimator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkEncodedGradientShader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFiniteDifferenceGradientEstimator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointRayCastImage.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeGOHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeGOShadeHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeShadeHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointVolumeRayCastHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointVolumeRayCastMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkFixedPointVolumeRayCastMIPHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkGPUVolumeRayCastMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkMultiVolume.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkOSPRayVolumeInterface.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkProjectedTetrahedraMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkRayCastImageDisplayHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkRecursiveSphereDirectionEncoder.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkSphericalDirectionEncoder.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridBunykRayCastFunction.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridHomogeneousRayIntegrator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridLinearRayIntegrator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridPartialPreIntegration.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridPreIntegration.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridVolumeMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridVolumeRayCastFunction.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridVolumeRayCastIterator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridVolumeRayCastMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridVolumeRayIntegrator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkUnstructuredGridVolumeZSweepMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkVolumeMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkVolumeOutlineSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkVolumePicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/vtkVolumeRayCastSpaceLeapingImageFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/Volume/vtkRenderingVolumeModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkRenderingVolume-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkRenderingVolume-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingVolume-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingVolume-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingVolume-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingVolume-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingVolume-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkRenderingVolume" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Volume/LICENSE")
endif()

