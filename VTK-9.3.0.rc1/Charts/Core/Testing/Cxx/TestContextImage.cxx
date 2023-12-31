// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkContextScene.h"
#include "vtkContextView.h"
#include "vtkImageData.h"
#include "vtkImageItem.h"
#include "vtkNew.h"
#include "vtkObjectFactory.h"
#include "vtkPNGReader.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSmartPointer.h"

#include "vtkRegressionTestImage.h"
#include "vtkTestUtilities.h"

//------------------------------------------------------------------------------
int TestContextImage(int argc, char* argv[])
{
  char* logo = vtkTestUtilities::ExpandDataFileName(argc, argv, "Data/vtk.png");

  // Set up a 2D context view, context test object and add it to the scene
  vtkNew<vtkContextView> view;
  view->GetRenderWindow()->SetSize(320, 181);
  vtkNew<vtkImageItem> item;
  view->GetScene()->AddItem(item);

  vtkNew<vtkPNGReader> reader;
  reader->SetFileName(logo);
  reader->Update();
  item->SetImage(vtkImageData::SafeDownCast(reader->GetOutput()));
  item->SetPosition(25, 30);

  view->GetRenderWindow()->SetMultiSamples(0);
  view->GetInteractor()->Initialize();
  view->GetInteractor()->Start();

  delete[] logo;
  return EXIT_SUCCESS;
}
