// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// This test volume renders the vase dataset with 4 dependent components the
// composite method with no shading.

#include "vtkCamera.h"
#include "vtkColorTransferFunction.h"
#include "vtkGPUVolumeRayCastMapper.h"
#include "vtkImageShiftScale.h"
#include "vtkPiecewiseFunction.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkTestUtilities.h"
#include "vtkTransform.h"
#include "vtkVolumeProperty.h"
#include "vtkXMLImageDataReader.h"

int TestGPURayCastFourComponentsComposite(int argc, char* argv[])
{
  cout << "CTEST_FULL_OUTPUT (Avoid ctest truncation of output)" << endl;
  char* cfname = vtkTestUtilities::ExpandDataFileName(argc, argv, "Data/vase_4comp.vti");

  vtkXMLImageDataReader* reader = vtkXMLImageDataReader::New();
  reader->SetFileName(cfname);
  delete[] cfname;

  vtkRenderer* ren1 = vtkRenderer::New();
  vtkRenderWindow* renWin = vtkRenderWindow::New();
  renWin->AddRenderer(ren1);
  renWin->SetSize(301, 300);
  vtkRenderWindowInteractor* iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  renWin->Render();

  vtkGPUVolumeRayCastMapper* volumeMapper;
  vtkVolumeProperty* volumeProperty;
  vtkVolume* volume;

  volumeMapper = vtkGPUVolumeRayCastMapper::New();
  volumeMapper->SetBlendModeToComposite();
  volumeMapper->SetInputConnection(reader->GetOutputPort());

  vtkPiecewiseFunction* opacity = vtkPiecewiseFunction::New();
  opacity->AddPoint(0, 0);
  opacity->AddPoint(255, 1);

  volumeProperty = vtkVolumeProperty::New();
  volumeProperty->IndependentComponentsOff();
  volumeProperty->ShadeOff();
  volumeProperty->SetScalarOpacity(opacity);

  volume = vtkVolume::New();
  volume->SetMapper(volumeMapper);
  volume->SetProperty(volumeProperty);
  ren1->AddViewProp(volume);

  int valid = volumeMapper->IsRenderSupported(renWin, volumeProperty);

  int retVal;
  if (valid)
  {
    iren->Initialize();
    ren1->SetBackground(0.1, 0.4, 0.2);
    ren1->ResetCamera();
    renWin->Render();
    retVal = vtkTesting::Test(argc, argv, renWin, 75);
    if (retVal == vtkRegressionTester::DO_INTERACTOR)
    {
      iren->Start();
    }
  }
  else
  {
    retVal = vtkTesting::PASSED;
    cout << "Required extensions not supported." << endl;
  }

  iren->Delete();
  renWin->Delete();
  ren1->Delete();
  volumeMapper->Delete();
  volumeProperty->Delete();
  volume->Delete();

  opacity->Delete();

  reader->Delete();

  if ((retVal == vtkTesting::PASSED) || (retVal == vtkTesting::DO_INTERACTOR))
  {
    return 0;
  }
  else
  {
    return 1;
  }
}
