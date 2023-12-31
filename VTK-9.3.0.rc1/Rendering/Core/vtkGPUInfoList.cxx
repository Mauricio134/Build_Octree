// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkGPUInfoList.h"

#include "vtkGPUInfo.h"
#include "vtkGraphicsFactory.h"
#include <cassert>

#include "vtkGPUInfoListArray.h"
#include <vector>

//------------------------------------------------------------------------------
VTK_ABI_NAMESPACE_BEGIN
vtkGPUInfoList* vtkGPUInfoList::New()
{
  vtkObject* ret = vtkGraphicsFactory::CreateInstance("vtkGPUInfoList");
  return static_cast<vtkGPUInfoList*>(ret);
}

//------------------------------------------------------------------------------
// Description:
// Tells if the operating system has been probed. Initial value is false.
bool vtkGPUInfoList::IsProbed()
{
  return this->Probed;
}

//------------------------------------------------------------------------------
// Description:
// Return the number of GPUs.
// \pre probed: IsProbed()
int vtkGPUInfoList::GetNumberOfGPUs()
{
  if (!this->IsProbed())
  {
    vtkErrorMacro("You must first call the Probe method");
    return 0;
  }

  return static_cast<int>(this->Array->v.size());
}

//------------------------------------------------------------------------------
// Description:
// Return information about GPU i.
// \pre probed: IsProbed()
// \pre valid_index: i>=0 && i<GetNumberOfGPUs()
// \post result_exists: result!=0
vtkGPUInfo* vtkGPUInfoList::GetGPUInfo(int i)
{
  assert("pre: probed" && this->IsProbed());
  assert("pre: valid_index" && i >= 0 && i < this->GetNumberOfGPUs());

  vtkGPUInfo* result = this->Array->v[static_cast<size_t>(i)];
  assert("post: result_exists" && result != nullptr);
  return result;
}

//------------------------------------------------------------------------------
// Description:
// Default constructor. Set Probed to false. Set Array to nullptr.
vtkGPUInfoList::vtkGPUInfoList()
{
  this->Probed = false;
  this->Array = nullptr;
}

//------------------------------------------------------------------------------
vtkGPUInfoList::~vtkGPUInfoList()
{
  if (this->Array != nullptr)
  {
    size_t c = this->Array->v.size();
    size_t i = 0;
    while (i < c)
    {
      this->Array->v[i]->Delete();
      ++i;
    }
    delete this->Array;
  }
}

//------------------------------------------------------------------------------
void vtkGPUInfoList::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "IsProbed: " << this->Probed << endl;
  if (this->Probed)
  {
    int c = this->GetNumberOfGPUs();
    os << indent << "Number of GPUs: " << c << endl;
    int i = 0;
    while (i < c)
    {
      os << indent << " GPU " << i;
      this->GetGPUInfo(i)->PrintSelf(os, indent);
      ++i;
    }
  }
}
VTK_ABI_NAMESPACE_END
