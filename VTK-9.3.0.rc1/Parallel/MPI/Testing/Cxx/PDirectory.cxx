// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <vtk_mpi.h>

#include "vtkMPIController.h"
#include "vtkPDirectory.h"
#include "vtkPSystemTools.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

int PDirectory(int argc, char* argv[])
{
  // This is here to avoid false leak messages from vtkDebugLeaks when
  // using mpich. It appears that the root process which spawns all the
  // main processes waits in MPI_Init() and calls exit() when
  // the others are done, causing apparent memory leaks for any objects
  // created before MPI_Init().
  MPI_Init(&argc, &argv);

  VTK_CREATE(vtkMPIController, controller);

  controller->Initialize(&argc, &argv, 1);
  controller->SetGlobalController(controller);

  int retVal = 0; // success

  std::string str = vtkPSystemTools::GetCurrentWorkingDirectory();

  VTK_CREATE(vtkPDirectory, directory);

  if (!directory->Load(str))
  {
    vtkGenericWarningMacro("Could not load directory");
    retVal++;
  }

  if (directory->GetNumberOfFiles() < 3)
  {
    vtkGenericWarningMacro("Missing files");
    retVal++;
  }

  bool hasFile = false;
  for (vtkIdType i = 0; i < directory->GetNumberOfFiles(); i++)
  {
    hasFile = hasFile || (strcmp(directory->GetFile(i), "cmake_install.cmake") == 0);
  }
  if (!hasFile)
  {
    vtkGenericWarningMacro("Missing cmake_install.cmake");
    retVal++;
  }

  controller->SetGlobalController(nullptr);
  controller->Finalize();

  return retVal;
}
