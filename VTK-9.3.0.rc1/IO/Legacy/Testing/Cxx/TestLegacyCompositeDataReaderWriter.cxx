// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkAMRGaussianPulseSource.h"
#include "vtkGenericDataObjectReader.h"
#include "vtkGenericDataObjectWriter.h"
#include "vtkNew.h"
#include "vtkOverlappingAMR.h"
#include "vtkTesting.h"

#define TEST_SUCCESS 0
#define TEST_FAILED 1

#define vtk_assert(x)                                                                              \
  do                                                                                               \
  {                                                                                                \
    if (!(x))                                                                                      \
    {                                                                                              \
      cerr << "ERROR: Condition FAILED!! : " << #x << endl;                                        \
      return TEST_FAILED;                                                                          \
    }                                                                                              \
  } while (false)

int Validate(vtkOverlappingAMR* input, vtkOverlappingAMR* result)
{
  vtk_assert(input->GetNumberOfLevels() == result->GetNumberOfLevels());
  vtk_assert(input->GetOrigin()[0] == result->GetOrigin()[0]);
  vtk_assert(input->GetOrigin()[1] == result->GetOrigin()[1]);
  vtk_assert(input->GetOrigin()[2] == result->GetOrigin()[2]);

  for (unsigned int level = 0; level < input->GetNumberOfLevels(); level++)
  {
    vtk_assert(input->GetNumberOfDataSets(level) == result->GetNumberOfDataSets(level));
  }

  cout << "Audit Input" << endl;
  input->Audit();
  cout << "Audit Output" << endl;
  result->Audit();
  return TEST_SUCCESS;
}

int TestLegacyCompositeDataReaderWriter(int argc, char* argv[])
{
  vtkNew<vtkTesting> testing;
  testing->AddArguments(argc, argv);

  vtkNew<vtkAMRGaussianPulseSource> source;

  std::string filename = testing->GetTempDirectory();
  filename += "/amr_data.vtk";
  vtkNew<vtkGenericDataObjectWriter> writer;
  writer->SetFileName(filename.c_str());
  writer->SetFileTypeToASCII();
  writer->SetInputConnection(source->GetOutputPort());
  writer->Write();

  vtkNew<vtkGenericDataObjectReader> reader;
  reader->SetFileName(filename.c_str());
  reader->Update();

  // now valid the input and output datasets.
  vtkOverlappingAMR* input = vtkOverlappingAMR::SafeDownCast(source->GetOutputDataObject(0));
  vtkOverlappingAMR* result = vtkOverlappingAMR::SafeDownCast(reader->GetOutputDataObject(0));
  if (Validate(input, result) == TEST_FAILED)
  {
    return TEST_FAILED;
  }

  cout << "Test Binary IO" << endl;

  writer->SetFileTypeToBinary();
  writer->Write();

  reader->SetFileName(nullptr);
  reader->SetFileName(filename.c_str());
  reader->Update();
  return Validate(input, vtkOverlappingAMR::SafeDownCast(reader->GetOutputDataObject(0)));
}
