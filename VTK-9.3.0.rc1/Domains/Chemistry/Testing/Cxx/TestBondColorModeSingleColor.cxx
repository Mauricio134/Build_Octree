// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkRegressionTestImage.h"
#include "vtkTestUtilities.h"

#include "vtkActor.h"
#include "vtkCamera.h"
#include "vtkMolecule.h"
#include "vtkMoleculeMapper.h"
#include "vtkNew.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"

int TestBondColorModeSingleColor(int, char*[])
{
  vtkNew<vtkMolecule> mol;

  mol->Initialize();

  vtkAtom O1 = mol->AppendAtom(8, 3.0088731969, 1.1344098673, 0.9985902874);
  vtkAtom O2 = mol->AppendAtom(8, -0.2616286966, 2.7806709534, 0.7027800226);
  vtkAtom C1 = mol->AppendAtom(6, -2.0738607910, 1.2298524695, 0.3421802228);
  vtkAtom C2 = mol->AppendAtom(6, -1.4140240045, 0.1045928523, 0.0352265378);
  vtkAtom C3 = mol->AppendAtom(6, 0.0000000000, 0.0000000000, 0.0000000000);
  vtkAtom C4 = mol->AppendAtom(6, 1.2001889412, 0.0000000000, 0.0000000000);
  vtkAtom C5 = mol->AppendAtom(6, -1.4612030913, 2.5403617582, 0.6885503164);
  vtkAtom C6 = mol->AppendAtom(6, 2.6528126498, 0.1432895796, 0.0427014196);
  vtkAtom H1 = mol->AppendAtom(1, -3.1589178142, 1.2268537165, 0.3536340040);
  vtkAtom H2 = mol->AppendAtom(1, -1.9782163251, -0.7930325394, -0.1986937306);
  vtkAtom H3 = mol->AppendAtom(1, 3.0459155564, 0.4511167867, -0.9307386568);
  vtkAtom H4 = mol->AppendAtom(1, 3.1371551056, -0.7952192984, 0.3266426961);
  vtkAtom H5 = mol->AppendAtom(1, 2.3344947615, 1.8381683043, 0.9310726537);
  vtkAtom H6 = mol->AppendAtom(1, -2.1991803919, 3.3206134015, 0.9413825084);

  mol->AppendBond(C1, C5, 1);
  mol->AppendBond(C1, C2, 2);
  mol->AppendBond(C2, C3, 1);
  mol->AppendBond(C3, C4, 3);
  mol->AppendBond(C4, C6, 1);
  mol->AppendBond(C5, O2, 2);
  mol->AppendBond(C6, O1, 1);
  mol->AppendBond(C5, H6, 1);
  mol->AppendBond(C1, H1, 1);
  mol->AppendBond(C2, H2, 1);
  mol->AppendBond(C6, H3, 1);
  mol->AppendBond(C6, H4, 1);
  mol->AppendBond(O1, H5, 1);

  vtkNew<vtkMoleculeMapper> molmapper;
  molmapper->SetInputData(mol);

  molmapper->UseBallAndStickSettings();
  molmapper->RenderAtomsOff();
  molmapper->SetBondColorModeToSingleColor();

  vtkNew<vtkActor> actor;
  actor->SetMapper(molmapper);

  vtkNew<vtkRenderer> ren;
  vtkNew<vtkRenderWindow> win;
  win->AddRenderer(ren);
  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetRenderWindow(win);

  ren->AddActor(actor);

  ren->SetBackground(0.0, 0.0, 0.0);
  win->SetSize(450, 450);
  win->Render();
  ren->GetActiveCamera()->Zoom(2.2);

  // Finally render the scene and compare the image to a reference image
  win->SetMultiSamples(0);
  win->GetInteractor()->Initialize();
  win->GetInteractor()->Start();

  return EXIT_SUCCESS;
}
