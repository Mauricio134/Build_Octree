// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkAMRGaussianPulseSource.h"
#include "vtkOverlappingAMR.h"
#include "vtkUniformGridAMRDataIterator.h"

#include <iostream>
#include <string>

//------------------------------------------------------------------------------
int TestAMRIterator(int, char*[])
{
  unsigned int expected[3][2] = { { 0, 0 }, { 1, 0 }, { 1, 1 } };

  int rc = 0;

  vtkAMRGaussianPulseSource* amrSource = vtkAMRGaussianPulseSource::New();
  amrSource->Update();
  vtkOverlappingAMR* amrData = vtkOverlappingAMR::SafeDownCast(amrSource->GetOutput());

  vtkUniformGridAMRDataIterator* iter =
    vtkUniformGridAMRDataIterator::SafeDownCast(amrData->NewIterator());
  iter->InitTraversal();
  for (int idx = 0; !iter->IsDoneWithTraversal(); iter->GoToNextItem(), ++idx)
  {
    unsigned int level = iter->GetCurrentLevel();
    unsigned int id = iter->GetCurrentIndex();
    cout << "Level: " << level << " Block: " << id;
    cout << endl;
    if (level != expected[idx][0])
    {
      ++rc;
    }
    if (id != expected[idx][1])
    {
      ++rc;
    }
  } // END for
  iter->Delete();

  amrSource->Delete();
  return (rc);
}
