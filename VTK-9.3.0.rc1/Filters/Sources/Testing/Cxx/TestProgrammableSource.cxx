// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include <vtkMolecule.h>
#include <vtkNew.h>
#include <vtkPolyData.h>
#include <vtkProgrammableSource.h>
#include <vtkRectilinearGrid.h>
#include <vtkStructuredGrid.h>
#include <vtkStructuredPoints.h>
#include <vtkTable.h>
#include <vtkUnstructuredGrid.h>

#define EXECUTE_METHOD(_type)                                                                      \
  void _type##ExecuteMethod(void* args)                                                            \
  {                                                                                                \
    vtkProgrammableSource* self = reinterpret_cast<vtkProgrammableSource*>(args);                  \
    vtk##_type* output = self->Get##_type##Output();                                               \
    if (!output)                                                                                   \
    {                                                                                              \
      std::cerr << "Output type is not of type " #_type "!" << std::endl;                          \
      exit(EXIT_FAILURE);                                                                          \
    }                                                                                              \
  }

EXECUTE_METHOD(PolyData);
EXECUTE_METHOD(StructuredPoints);
EXECUTE_METHOD(StructuredGrid);
EXECUTE_METHOD(UnstructuredGrid);
EXECUTE_METHOD(RectilinearGrid);
EXECUTE_METHOD(Molecule);
EXECUTE_METHOD(Table);

#define TEST_PROGRAMMABLE_SOURCE(_type)                                                            \
  do                                                                                               \
  {                                                                                                \
    vtkNew<vtkProgrammableSource> ps;                                                              \
    ps->SetExecuteMethod(&_type##ExecuteMethod, ps.Get());                                         \
    ps->Update();                                                                                  \
    vtk##_type* output = ps->Get##_type##Output();                                                 \
    if (!output)                                                                                   \
    {                                                                                              \
      std::cerr << "Source output type is not of type " #_type "!" << std::endl;                   \
      return EXIT_FAILURE;                                                                         \
    }                                                                                              \
  } while (false)

int TestProgrammableSource(int vtkNotUsed(argc), char* vtkNotUsed(argv)[])
{
  TEST_PROGRAMMABLE_SOURCE(PolyData);
  TEST_PROGRAMMABLE_SOURCE(StructuredPoints);
  TEST_PROGRAMMABLE_SOURCE(StructuredGrid);
  TEST_PROGRAMMABLE_SOURCE(UnstructuredGrid);
  TEST_PROGRAMMABLE_SOURCE(RectilinearGrid);
  TEST_PROGRAMMABLE_SOURCE(Molecule);
  TEST_PROGRAMMABLE_SOURCE(Table);
  return EXIT_SUCCESS;
}
