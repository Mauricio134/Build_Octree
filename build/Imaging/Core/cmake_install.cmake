# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkAbstractImageInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkExtractVOI.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkGenericImageInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageAppendComponents.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageBlend.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageBSplineCoefficients.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageBSplineInternals.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageBSplineInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageCacheFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageCast.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageChangeInformation.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageClip.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageConstantPad.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageDataStreamer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageDecomposeFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageDifference.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageExtractComponents.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageFlip.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageIterateFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageMagnify.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageMapToColors.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageMask.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageMirrorPad.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImagePadFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImagePermute.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImagePointDataIterator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImagePointIterator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageProbeFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageResample.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageResize.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageReslice.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageResliceToColors.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageShiftScale.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageShrink3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageSincInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageStencilAlgorithm.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageStencilData.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageStencilIterator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageStencilSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageThreshold.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageTranslateExtent.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkImageWrapPad.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/vtkRTAnalyticSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Imaging/Core/vtkImagingCoreModule.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkImagingCore-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkImagingCore-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkImagingCore-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkImagingCore-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkImagingCore-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkImagingCore-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkImagingCore-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkImagingCore" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Imaging/Core/LICENSE")
endif()

