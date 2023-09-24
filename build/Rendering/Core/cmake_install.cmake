# Install script for directory: /Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core

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
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGPUInfoListArray.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPythagoreanQuadruples.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRayCastStructures.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderingCoreEnums.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkStateStorage.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/Core/vtkTDxConfigure.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTDxMotionEventInfo.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractHyperTreeGridMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractMapper3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractVolumeMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkActor2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkActor2DCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkActorCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAssembly.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAvatar.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkBackgroundColorMonitor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkBillboardTextActor3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCamera.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCameraActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCameraInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCellCenterDepthSort.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCellGridMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkColorTransferFunction.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCompositeDataDisplayAttributes.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCompositeDataDisplayAttributesLegacy.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCompositePolyDataMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCompositePolyDataMapperDelegator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCoordinate.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCuller.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCullerCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkDataSetMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkDiscretizableColorTransferFunction.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkDistanceToCamera.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkFXAAOptions.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkFlagpoleLabel.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkFollower.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkFrameBufferObjectBase.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkFrustumCoverageCuller.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGPUInfo.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGPUInfoList.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGenericVertexAttributeMapping.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGlyph3DMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGraphMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGraphToGlyphs.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkGraphicsFactory.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkHardwarePicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkHardwareSelector.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkHardwareWindow.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkHierarchicalPolyDataMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkImageActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkImageMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkImageMapper3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkImageProperty.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkImageSlice.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkImageSliceMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkInteractorEventRecorder.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkInteractorObserver.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLabeledContourMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLight.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLightActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLightCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLightKit.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLogLookupTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLookupTableWithEnabling.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkMapArrayValues.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkMapper2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkMapperCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkObserverMediator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPointGaussianMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPolyDataMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPolyDataMapper2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkProp.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkProp3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkProp3DCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkProp3DFollower.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPropAssembly.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPropCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkProperty.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkProperty2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderPass.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderState.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderTimerLog.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderWindow.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderWindowCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderWindowInteractor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderWindowInteractor3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRendererCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRendererDelegate.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRendererSource.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkResizingWindowToImageFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkSelectVisiblePoints.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkShaderProperty.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkSkybox.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkStereoCompositor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTextActor.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTextActor3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTexture.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTexturedActor2D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTransformCoordinateSystems.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTransformInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTupleInterpolator.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkUniforms.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkViewDependentErrorMetric.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkViewport.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkVisibilitySort.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkVolume.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkVolumeCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkVolumeProperty.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkWindowLevelLookupTable.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkWindowToImageFilter.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAssemblyNode.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAssemblyPath.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAssemblyPaths.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAreaPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractPropPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkLODProp3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPropPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPickingManager.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkWorldPointPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCellPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkPointPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderedAreaPicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkScenePicker.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkInteractorStyle.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkInteractorStyle3D.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkInteractorStyleSwitchBase.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTDxInteractorStyle.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTDxInteractorStyleCamera.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTDxInteractorStyleSettings.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkStringToImage.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTextMapper.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTextProperty.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTextPropertyCollection.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkTextRenderer.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractInteractionDevice.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkAbstractRenderDevice.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkRenderWidget.h"
    "/Users/mauricioapaza/Desktop/Build_octree/build/Rendering/Core/vtkRenderingCoreModule.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkNoise200x200.h"
    "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/vtkCIEDE2000.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vtk-9.3/hierarchy/VTK" TYPE FILE RENAME "vtkRenderingCore-hierarchy.txt" FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/vtk-9.3/hierarchy/VTK/vtkRenderingCore-hierarchy.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingCore-9.3.9.3.dylib"
    "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingCore-9.3.1.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.3.9.3.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libvtkRenderingCore-9.3.1.dylib"
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/mauricioapaza/Desktop/Build_octree/build/lib/libvtkRenderingCore-9.3.dylib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "licenses" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/VTK/vtkRenderingCore" TYPE FILE FILES "/Users/mauricioapaza/Desktop/Build_octree/VTK-9.3.0.rc1/Rendering/Core/LICENSE")
endif()

