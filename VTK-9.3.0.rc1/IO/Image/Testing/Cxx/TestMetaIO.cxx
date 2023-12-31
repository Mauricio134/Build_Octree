// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
// .NAME Test of vtkMetaIO / MetaImage
// .SECTION Description
//

#include "vtkDataObject.h"
#include "vtkImageData.h"
#include "vtkImageMathematics.h"
#include "vtkMetaImageReader.h"
#include "vtkMetaImageWriter.h"
#include "vtkObjectFactory.h"
#include "vtkOutputWindow.h"

#include <cmath>

int TestMetaIO(int argc, char* argv[])
{
  vtkOutputWindow::GetInstance()->PromptUserOn();
  if (argc <= 1)
  {
    cout << "Usage: " << argv[0] << " <meta image file>" << endl;
    return 1;
  }

  vtkMetaImageReader* reader = vtkMetaImageReader::New();
  reader->SetFileName(argv[1]);
  reader->Update();
  cout << "10, 10, 10 : (1) : " << reader->GetOutput()->GetScalarComponentAsFloat(10, 10, 10, 0)
       << endl;
  cout << "24, 37, 10 : (168) : " << reader->GetOutput()->GetScalarComponentAsFloat(24, 37, 10, 0)
       << endl;

  vtkMetaImageWriter* writer = vtkMetaImageWriter::New();
  writer->SetFileName("TestMetaIO.mha");
  writer->SetInputConnection(reader->GetOutputPort());
  writer->Write();

  reader->Delete();
  writer->Delete();

  vtkMetaImageReader* readerStd = vtkMetaImageReader::New();
  readerStd->SetFileName(argv[1]);
  readerStd->Update();

  vtkMetaImageReader* readerNew = vtkMetaImageReader::New();
  readerNew->SetFileName("TestMetaIO.mha");
  readerNew->Update();

  double error = 0;
  int* ext = readerStd->GetOutput()->GetExtent();
  for (int z = ext[4]; z <= ext[5]; z += 2)
  {
    for (int y = ext[2]; y <= ext[3]; y++)
    {
      for (int x = ext[0]; x <= ext[1]; x++)
      {
        error += fabs(readerStd->GetOutput()->GetScalarComponentAsFloat(x, y, z, 0) -
          readerNew->GetOutput()->GetScalarComponentAsFloat(x, y, z, 0));
      }
    }
  }

  readerStd->Delete();
  readerNew->Delete();

  if (error > 1)
  {
    cerr << "Error: Image difference on read/write = " << error << endl;
    return 1;
  }

  cout << "Success!  Error = " << error << endl;

  return 0;
}
