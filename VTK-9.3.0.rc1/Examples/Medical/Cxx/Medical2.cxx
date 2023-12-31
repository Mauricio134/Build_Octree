// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
//
// This example reads a volume dataset, extracts two isosurfaces that
// represent the skin and bone, and then displays them.
//

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkContourFilter.h>
#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyDataNormals.h>
#include <vtkProperty.h>
#include <vtkRegressionTestImage.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkStripper.h>
#include <vtkVolume16Reader.h>

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    cout << "Usage: " << argv[0] << " DATADIR/headsq/quarter" << endl;
    return EXIT_FAILURE;
  }

  // Create the renderer, the render window, and the interactor. The renderer
  // draws into the render window, the interactor enables mouse- and
  // keyboard-based interaction with the data within the render window.
  //
  vtkSmartPointer<vtkRenderer> aRenderer = vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renWin = vtkSmartPointer<vtkRenderWindow>::New();
  renWin->AddRenderer(aRenderer);

  vtkSmartPointer<vtkRenderWindowInteractor> iren =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  iren->SetRenderWindow(renWin);

  // The following reader is used to read a series of 2D slices (images)
  // that compose the volume. The slice dimensions are set, and the
  // pixel spacing. The data Endianness must also be specified. The reader
  // usese the FilePrefix in combination with the slice number to construct
  // filenames using the format FilePrefix.%d. (In this case the FilePrefix
  // is the root name of the file: quarter.)
  vtkSmartPointer<vtkVolume16Reader> v16 = vtkSmartPointer<vtkVolume16Reader>::New();
  v16->SetDataDimensions(64, 64);
  v16->SetDataByteOrderToLittleEndian();
  v16->SetFilePrefix(argv[1]);
  v16->SetImageRange(1, 93);
  v16->SetDataSpacing(3.2, 3.2, 1.5);

  // An isosurface, or contour value of 500 is known to correspond to the
  // skin of the patient. Once generated, a vtkPolyDataNormals filter is
  // is used to create normals for smooth surface shading during rendering.
  // The triangle stripper is used to create triangle strips from the
  // isosurface; these render much faster on many systems.
  vtkSmartPointer<vtkContourFilter> skinExtractor = vtkSmartPointer<vtkContourFilter>::New();
  skinExtractor->SetInputConnection(v16->GetOutputPort());
  skinExtractor->SetValue(0, 500);

  vtkSmartPointer<vtkPolyDataNormals> skinNormals = vtkSmartPointer<vtkPolyDataNormals>::New();
  skinNormals->SetInputConnection(skinExtractor->GetOutputPort());
  skinNormals->SetFeatureAngle(60.0);

  vtkSmartPointer<vtkStripper> skinStripper = vtkSmartPointer<vtkStripper>::New();
  skinStripper->SetInputConnection(skinNormals->GetOutputPort());

  vtkSmartPointer<vtkPolyDataMapper> skinMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  skinMapper->SetInputConnection(skinStripper->GetOutputPort());
  skinMapper->ScalarVisibilityOff();

  vtkSmartPointer<vtkActor> skin = vtkSmartPointer<vtkActor>::New();
  skin->SetMapper(skinMapper);
  skin->GetProperty()->SetDiffuseColor(1, .49, .25);
  skin->GetProperty()->SetSpecular(.3);
  skin->GetProperty()->SetSpecularPower(20);
  skin->GetProperty()->SetOpacity(.5);

  // An isosurface, or contour value of 1150 is known to correspond to the
  // skin of the patient. Once generated, a vtkPolyDataNormals filter is
  // is used to create normals for smooth surface shading during rendering.
  // The triangle stripper is used to create triangle strips from the
  // isosurface; these render much faster on may systems.
  vtkSmartPointer<vtkContourFilter> boneExtractor = vtkSmartPointer<vtkContourFilter>::New();
  boneExtractor->SetInputConnection(v16->GetOutputPort());
  boneExtractor->SetValue(0, 1150);

  vtkSmartPointer<vtkPolyDataNormals> boneNormals = vtkSmartPointer<vtkPolyDataNormals>::New();
  boneNormals->SetInputConnection(boneExtractor->GetOutputPort());
  boneNormals->SetFeatureAngle(60.0);

  vtkSmartPointer<vtkStripper> boneStripper = vtkSmartPointer<vtkStripper>::New();
  boneStripper->SetInputConnection(boneNormals->GetOutputPort());

  vtkSmartPointer<vtkPolyDataMapper> boneMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  boneMapper->SetInputConnection(boneStripper->GetOutputPort());
  boneMapper->ScalarVisibilityOff();

  vtkSmartPointer<vtkActor> bone = vtkSmartPointer<vtkActor>::New();
  bone->SetMapper(boneMapper);
  bone->GetProperty()->SetDiffuseColor(1, 1, .9412);

  // An outline provides context around the data.
  //
  vtkSmartPointer<vtkOutlineFilter> outlineData = vtkSmartPointer<vtkOutlineFilter>::New();
  outlineData->SetInputConnection(v16->GetOutputPort());

  vtkSmartPointer<vtkPolyDataMapper> mapOutline = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapOutline->SetInputConnection(outlineData->GetOutputPort());

  vtkSmartPointer<vtkActor> outline = vtkSmartPointer<vtkActor>::New();
  outline->SetMapper(mapOutline);
  outline->GetProperty()->SetColor(0, 0, 0);

  // It is convenient to create an initial view of the data. The FocalPoint
  // and Position form a vector direction. Later on (ResetCamera() method)
  // this vector is used to position the camera to look at the data in
  // this direction.
  vtkSmartPointer<vtkCamera> aCamera = vtkSmartPointer<vtkCamera>::New();
  aCamera->SetViewUp(0, 0, -1);
  aCamera->SetPosition(0, 1, 0);
  aCamera->SetFocalPoint(0, 0, 0);
  aCamera->ComputeViewPlaneNormal();
  aCamera->Azimuth(30.0);
  aCamera->Elevation(30.0);

  // Actors are added to the renderer. An initial camera view is created.
  // The Dolly() method moves the camera towards the FocalPoint,
  // thereby enlarging the image.
  aRenderer->AddActor(outline);
  aRenderer->AddActor(skin);
  aRenderer->AddActor(bone);
  aRenderer->SetActiveCamera(aCamera);
  aRenderer->ResetCamera();
  aCamera->Dolly(1.5);

  // Set a background color for the renderer and set the size of the
  // render window (expressed in pixels).
  aRenderer->SetBackground(.2, .3, .4);
  renWin->SetSize(640, 480);

  // Note that when camera movement occurs (as it does in the Dolly()
  // method), the clipping planes often need adjusting. Clipping planes
  // consist of two planes: near and far along the view direction. The
  // near plane clips out objects in front of the plane; the far plane
  // clips out objects behind the plane. This way only what is drawn
  // between the planes is actually rendered.
  aRenderer->ResetCameraClippingRange();

  // For testing, check if "-V" is used to provide a regression test image
  if (argc >= 4 && strcmp(argv[2], "-V") == 0)
  {
    renWin->Render();
    int retVal = vtkRegressionTestImage(renWin);

    if (retVal == vtkTesting::FAILED)
    {
      return EXIT_FAILURE;
    }
    else if (retVal != vtkTesting::DO_INTERACTOR)
    {
      return EXIT_SUCCESS;
    }
  }

  // Initialize the event loop and then start it.
  iren->Initialize();
  iren->Start();

  return EXIT_SUCCESS;
}
