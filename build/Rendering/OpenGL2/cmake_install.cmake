# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2

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
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/OpenGL2/vtkOpenGLError.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/OpenGL2/vtkRenderingOpenGLConfigure.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkCocoaRenderWindow.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkCameraPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkClearRGBPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkClearZPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkCompositePolyDataMapper2.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkDataTransferHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkDefaultPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkDepthImageProcessingPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkDepthOfFieldPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkDepthPeelingPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkDualDepthPeelingPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkEDLShading.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkEquirectangularToCubeMapTexture.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkFramebufferPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkGaussianBlurPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkGenericOpenGLRenderWindow.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkHiddenLineRemovalPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkImageProcessingPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkLightingMapPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkLightsPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpaquePass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLBatchedPolyDataMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLBillboardTextActor3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLBufferObject.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLCamera.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLCellToVTKCellMap.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLCompositePolyDataMapperDelegator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLFXAAFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLFXAAPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLFluidMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLFramebufferObject.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLGL2PSHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLGlyph3DHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLGlyph3DMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLHardwareSelector.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLHyperTreeGridMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLImageAlgorithmHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLImageMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLImageSliceMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLIndexBufferObject.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLInstanceCulling.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLLabeledContourMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLLight.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLPointGaussianMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLPolyDataMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLPolyDataMapper2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLProperty.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLQuadHelper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLRenderPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLRenderTimer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLRenderTimerLog.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLRenderUtilities.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLRenderWindow.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLRenderer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLShaderCache.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLShaderProperty.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLSkybox.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLSphereMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLState.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLStickMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLTextActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLTextActor3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLTextMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLTexture.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLUniforms.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLVertexArrayObject.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLVertexBufferObject.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLVertexBufferObjectCache.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOpenGLVertexBufferObjectGroup.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOrderIndependentTranslucentPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOutlineGlowPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkOverlayPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkPBRIrradianceTexture.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkPBRLUTTexture.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkPBRPrefilterTexture.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkPanoramicProjectionPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkPixelBufferObject.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkPointFillPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkRenderPassCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkRenderStepsPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkRenderbuffer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkSSAAPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkSSAOPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkSequencePass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkShader.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkShaderProgram.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkShadowMapBakerPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkShadowMapPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkSimpleMotionBlurPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkSobelGradientMagnitudePass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkTextureObject.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkTextureUnitManager.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkToneMappingPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkTransformFeedback.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkTranslucentPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkValuePass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkVolumetricPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkDummyGPUInfoList.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/OpenGL2/vtkRenderingOpenGL2Module.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkCompositeMapperHelper2.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/OpenGL2/vtkTextureObjectVS.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/OpenGL2/vtkCocoaGLView.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkRenderingOpenGL2-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkRenderingOpenGL2-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingOpenGL2-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingOpenGL2-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingOpenGL2-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingOpenGL2-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/Users/mauricioapaza/Desktop/Build_octree/build/bin/vtkProbeOpenGLVersion-9.3")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.3")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/mauricioapaza/Desktop/Build_octree/build/lib"
      -add_rpath "@executable_path/../lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.3")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -u -r "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/vtkProbeOpenGLVersion-9.3")
    endif()
  endif()
endif()

