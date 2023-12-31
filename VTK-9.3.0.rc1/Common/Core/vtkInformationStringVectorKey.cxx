// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkInformationStringVectorKey.h"

#include "vtkInformation.h" // For vtkErrorWithObjectMacro

#include <algorithm>
#include <vector>

//------------------------------------------------------------------------------
VTK_ABI_NAMESPACE_BEGIN
vtkInformationStringVectorKey ::vtkInformationStringVectorKey(
  const char* name, const char* location, int length)
  : vtkInformationKey(name, location)
  , RequiredLength(length)
{
  vtkCommonInformationKeyManager::Register(this);
}

//------------------------------------------------------------------------------
vtkInformationStringVectorKey::~vtkInformationStringVectorKey() = default;

//------------------------------------------------------------------------------
void vtkInformationStringVectorKey::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//------------------------------------------------------------------------------
class vtkInformationStringVectorValue : public vtkObjectBase
{
public:
  vtkBaseTypeMacro(vtkInformationStringVectorValue, vtkObjectBase);
  std::vector<std::string> Value;
};

//------------------------------------------------------------------------------
void vtkInformationStringVectorKey::Append(vtkInformation* info, const char* value)
{
  vtkInformationStringVectorValue* v =
    static_cast<vtkInformationStringVectorValue*>(this->GetAsObjectBase(info));
  if (v)
  {
    v->Value.emplace_back(value);
  }
  else
  {
    this->Set(info, value, 0);
  }
}

//------------------------------------------------------------------------------
void vtkInformationStringVectorKey::Set(vtkInformation* info, const char* value, int index)
{
  vtkInformationStringVectorValue* oldv =
    static_cast<vtkInformationStringVectorValue*>(this->GetAsObjectBase(info));
  if (oldv)
  {
    if ((static_cast<int>(oldv->Value.size()) <= index) || (oldv->Value[index] != value))
    {
      while (static_cast<int>(oldv->Value.size()) <= index)
      {
        oldv->Value.emplace_back("");
      }
      oldv->Value[index] = value;
      // Since this sets a value without call SetAsObjectBase(),
      // the info has to be modified here (instead of
      // vtkInformation::SetAsObjectBase()
      info->Modified(this);
    }
  }
  else
  {
    vtkInformationStringVectorValue* v = new vtkInformationStringVectorValue;
    v->InitializeObjectBase();
    while (static_cast<int>(v->Value.size()) <= index)
    {
      v->Value.emplace_back("");
    }
    v->Value[index] = value;
    this->SetAsObjectBase(info, v);
    v->Delete();
  }
}

//------------------------------------------------------------------------------
void vtkInformationStringVectorKey::Append(vtkInformation* info, const std::string& value)
{
  this->Append(info, value.c_str());
}

//------------------------------------------------------------------------------
void vtkInformationStringVectorKey::Set(vtkInformation* info, const std::string& value, int idx)
{
  this->Set(info, value.c_str(), idx);
}

//------------------------------------------------------------------------------
const char* vtkInformationStringVectorKey::Get(vtkInformation* info, int idx)
{
  if (idx < 0 || idx >= this->Length(info))
  {
    return nullptr;
  }
  vtkInformationStringVectorValue* v =
    static_cast<vtkInformationStringVectorValue*>(this->GetAsObjectBase(info));
  return v->Value[idx].c_str();
}

//------------------------------------------------------------------------------
int vtkInformationStringVectorKey::Length(vtkInformation* info)
{
  vtkInformationStringVectorValue* v =
    static_cast<vtkInformationStringVectorValue*>(this->GetAsObjectBase(info));
  return v ? static_cast<int>(v->Value.size()) : 0;
}

//------------------------------------------------------------------------------
void vtkInformationStringVectorKey::ShallowCopy(vtkInformation* from, vtkInformation* to)
{
  int length = this->Length(from);
  for (int i = 0; i < length; ++i)
  {
    this->Set(to, this->Get(from, i), i);
  }
}

//------------------------------------------------------------------------------
void vtkInformationStringVectorKey::Print(ostream& os, vtkInformation* info)
{
  // Print the value.
  if (this->Has(info))
  {
    int length = this->Length(info);
    const char* sep = "";
    for (int i = 0; i < length; ++i)
    {
      os << sep << this->Get(info, i);
      sep = " ";
    }
  }
}
VTK_ABI_NAMESPACE_END
