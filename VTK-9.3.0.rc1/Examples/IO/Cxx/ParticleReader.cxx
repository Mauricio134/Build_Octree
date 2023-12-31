// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// Author: Andrew J. P. Maclean
#include <vtkParticleReader.h>
#include <vtkSmartPointer.h>
#include <vtkXMLPolyDataWriter.h>

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    cerr << "Usage: " << argv[0] << " InputFile(csv) OutputFile(vtp)." << endl;
    return EXIT_FAILURE;
  }

  std::string inputFileName = argv[1];
  std::string outputFileName = argv[2];

  vtkSmartPointer<vtkParticleReader> reader = vtkSmartPointer<vtkParticleReader>::New();
  reader->SetFileName(inputFileName.c_str());
  reader->Update();

  vtkSmartPointer<vtkXMLPolyDataWriter> writer = vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(reader->GetOutputPort());
  writer->SetFileName(outputFileName.c_str());
  writer->Write();

  return EXIT_SUCCESS;
}
