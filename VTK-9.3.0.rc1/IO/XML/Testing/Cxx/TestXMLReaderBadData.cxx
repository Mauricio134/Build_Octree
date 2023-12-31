// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkTestErrorObserver.h"
#include <vtkSmartPointer.h>
#include <vtkXMLDataParser.h>
#include <vtkXMLGenericDataObjectReader.h>

int TestXMLReaderBadData(int argc, char* argv[])
{
  // Verify input arguments
  if (argc < 2)
  {
    std::cout << "Usage: " << argv[0] << " Filename" << std::endl;
    return EXIT_FAILURE;
  }

  std::string inputFilename = argv[1];

  // Observe errors
  vtkSmartPointer<vtkTest::ErrorObserver> errorObserver0 =
    vtkSmartPointer<vtkTest::ErrorObserver>::New();
  vtkSmartPointer<vtkTest::ErrorObserver> errorObserver1 =
    vtkSmartPointer<vtkTest::ErrorObserver>::New();
  vtkSmartPointer<vtkTest::ErrorObserver> errorObserver2 =
    vtkSmartPointer<vtkTest::ErrorObserver>::New();

  // Read the file
  vtkSmartPointer<vtkXMLGenericDataObjectReader> reader =
    vtkSmartPointer<vtkXMLGenericDataObjectReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->AddObserver(vtkCommand::ErrorEvent, errorObserver0);
  reader->SetReaderErrorObserver(errorObserver1);
  reader->SetParserErrorObserver(errorObserver2);
  reader->Update();
  int status = errorObserver2->CheckErrorMessage("vtkXMLDataParser");
  return status;
}
