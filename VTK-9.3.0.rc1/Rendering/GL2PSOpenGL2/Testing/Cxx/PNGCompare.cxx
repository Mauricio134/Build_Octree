// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkNew.h"
#include "vtkTesting.h"
#include "vtkTestingInteractor.h"

#include <cstdio> // For remove
#include <string>

int PNGCompare(int argc, char* argv[])
{
  // Grab the test image
  std::string testImageFileName;
  for (int i = 0; i < argc; ++i)
  {
    if (i < argc - 1 && strcmp(argv[i], "--test-file") == 0)
    {
      testImageFileName = std::string(argv[i + 1]);
      break;
    }
  }

  if (testImageFileName.empty())
  {
    cout << "Error: No reference image specified (use --test-file <png file>)" << endl;
    return EXIT_FAILURE;
  }

  // Set up testing object (modeled after vtkTestingInteractor::Start())
  vtkNew<vtkTesting> testing;

  // Location of the temp directory for testing
  testing->AddArgument("-T");
  testing->AddArgument(vtkTestingInteractor::TempDirectory.c_str());

  // Location of the Data directory
  testing->AddArgument("-D");
  testing->AddArgument(vtkTestingInteractor::DataDirectory.c_str());

  // The name of the valid baseline image
  testing->AddArgument("-V");
  testing->AddArgument(vtkTestingInteractor::ValidBaseline.c_str());

  // Regression test the image
  int result = testing->RegressionTest(testImageFileName, vtkTestingInteractor::ErrorThreshold);

  vtkTestingInteractor::TestReturnStatus = result;

  if (result == vtkTesting::PASSED)
  {
    // Coverity complains that we don't check the result of remove(), but
    // we really don't care about it. Suppressing:
    // coverity[CHECKED_RETURN]
    remove(testImageFileName.c_str());
    return EXIT_SUCCESS;
  }
  else
  {
    return EXIT_FAILURE;
  }
}
