// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME Test to print system information useful for remote debugging.
// .SECTION Description
// Remote dashboard debugging often requires access to the
// CMakeCache.txt file.  This test will display the file.

#include "vtkDebugLeaks.h"
#include <string>
#include <vtksys/FStream.hxx>
#include <vtksys/SystemTools.hxx>

void vtkSystemInformationPrintFile(const char* name, ostream& os)
{
  os << "================================================================\n";
  vtksys::SystemTools::Stat_t fs;
  if (vtksys::SystemTools::Stat(name, &fs) != 0)
  {
    os << "The file \"" << name << "\" does not exist.\n";
    return;
  }

#ifdef _WIN32
  vtksys::ifstream fin(name, ios::in | ios::binary);
#else
  vtksys::ifstream fin(name, ios::in);
#endif

  if (fin)
  {
    os << "Contents of \"" << name << "\":\n";
    os << "----------------------------------------------------------------\n";
    const int bufferSize = 4096;
    char buffer[bufferSize];
    // This copy loop is very sensitive on certain platforms with
    // slightly broken stream libraries (like HPUX).  Normally, it is
    // incorrect to not check the error condition on the fin.read()
    // before using the data, but the fin.gcount() will be zero if an
    // error occurred.  Therefore, the loop should be safe everywhere.
    while (fin)
    {
      fin.read(buffer, bufferSize);
      if (fin.gcount())
      {
        os.write(buffer, fin.gcount());
      }
    }
    os.flush();
  }
  else
  {
    os << "Error opening \"" << name << "\" for reading.\n";
  }
}

int TestSystemInformation(int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "Usage: TestSystemInformation <top-of-build-tree>\n";
    return 1;
  }
  std::string build_dir = argv[1];
  build_dir += "/";

  const char* files[] = { "CMakeCache.txt", "CMakeFiles/CMakeError.log", "Common/Core/vtkBuild.h",
    "Common/Core/vtkConfigureDeprecated.h", "Common/Core/vtkDebug.h",
    "Common/Core/vtkDebugRangeIterators.h", "Common/Core/vtkEndian.h", "Common/Core/vtkFeatures.h",
    "Common/Core/vtkLegacy.h", "Common/Core/vtkOptions.h", "Common/Core/vtkPlatform.h",
    "Common/Core/vtkSMP.h", "Common/Core/vtkThreads.h", "VTKConfig.cmake",
    "Testing/Temporary/ConfigSummary.txt", nullptr };

  cout << "CTEST_FULL_OUTPUT (Avoid ctest truncation of output)" << endl;

  for (const char** f = files; *f; ++f)
  {
    std::string fname = build_dir + *f;
    vtkSystemInformationPrintFile(fname.c_str(), cout);
  }

  return 0;
}
