// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkVolumeReader.h"

// Construct object with nullptr file prefix; file pattern "%s.%d"; image range
// set to (1,1);
VTK_ABI_NAMESPACE_BEGIN
vtkVolumeReader::vtkVolumeReader()
{
  this->FilePrefix = nullptr;
  this->FilePattern = new char[strlen("%s.%d") + 1];
  strcpy(this->FilePattern, "%s.%d");
  this->ImageRange[0] = this->ImageRange[1] = 1;
  this->DataOrigin[0] = this->DataOrigin[1] = this->DataOrigin[2] = 0.0;
  this->DataSpacing[0] = this->DataSpacing[1] = this->DataSpacing[2] = 1.0;
  this->SetNumberOfInputPorts(0);
}

vtkVolumeReader::~vtkVolumeReader()
{
  delete[] this->FilePrefix;
  delete[] this->FilePattern;
}

void vtkVolumeReader::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Data Origin: (" << this->DataOrigin[0] << ", " << this->DataOrigin[1] << ", "
     << this->DataOrigin[2] << ")\n";
  os << indent << "Data Spacing: (" << this->DataSpacing[0] << ", " << this->DataSpacing[1] << ", "
     << this->DataSpacing[2] << ")\n";
  os << indent << "FilePrefix: " << (this->FilePrefix ? this->FilePrefix : "(none)") << "\n";
  os << indent << "FilePattern: " << (this->FilePattern ? this->FilePattern : "(none)") << "\n";
  os << indent << "Image Range: (" << this->ImageRange[0] << ", " << this->ImageRange[1] << ")\n";
}
VTK_ABI_NAMESPACE_END
