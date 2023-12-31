// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright (c) Sandia Corporation
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkDSPFilterDefinition.h"
#include "vtkObjectFactory.h"

#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkDSPFilterDefinition);

class vtkDSPFilterDefinitionVectorDoubleSTLCloak
{
public:
  std::vector<double> m_vector;
};
class vtkDSPFilterDefinitionStringSTLCloak
{
public:
  std::string m_string;
};

//------------------------------------------------------------------------------
vtkDSPFilterDefinition::vtkDSPFilterDefinition()
{
  // printf("    in vtkDSPFilterDefinition::vtkDSPFilterDefinition()\n");
  this->NumeratorWeights = new vtkDSPFilterDefinitionVectorDoubleSTLCloak;
  this->ForwardNumeratorWeights = new vtkDSPFilterDefinitionVectorDoubleSTLCloak;
  this->DenominatorWeights = new vtkDSPFilterDefinitionVectorDoubleSTLCloak;
  this->InputVariableName = new vtkDSPFilterDefinitionStringSTLCloak;
  this->OutputVariableName = new vtkDSPFilterDefinitionStringSTLCloak;

  this->NumeratorWeights->m_vector.resize(0);
  this->ForwardNumeratorWeights->m_vector.resize(0);
  this->DenominatorWeights->m_vector.resize(0);
  this->InputVariableName->m_string = "";
  this->OutputVariableName->m_string = "";
}
//------------------------------------------------------------------------------
vtkDSPFilterDefinition::vtkDSPFilterDefinition(vtkDSPFilterDefinition* other)
{
  // printf("    in vtkDSPFilterDefinition::vtkDSPFilterDefinition(vtkDSPFilterDefinition
  // *other)\n");
  this->NumeratorWeights = new vtkDSPFilterDefinitionVectorDoubleSTLCloak;
  this->ForwardNumeratorWeights = new vtkDSPFilterDefinitionVectorDoubleSTLCloak;
  this->DenominatorWeights = new vtkDSPFilterDefinitionVectorDoubleSTLCloak;
  this->InputVariableName = new vtkDSPFilterDefinitionStringSTLCloak;
  this->OutputVariableName = new vtkDSPFilterDefinitionStringSTLCloak;

  this->NumeratorWeights->m_vector = other->NumeratorWeights->m_vector;
  this->ForwardNumeratorWeights->m_vector = other->ForwardNumeratorWeights->m_vector;
  this->DenominatorWeights->m_vector = other->DenominatorWeights->m_vector;
  this->InputVariableName->m_string = other->InputVariableName->m_string;
  this->OutputVariableName->m_string = other->OutputVariableName->m_string;
}
//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::Copy(vtkDSPFilterDefinition* other)
{
  // printf("    in vtkDSPFilterDefinition::Copy(vtkDSPFilterDefinition *other)\n");
  this->NumeratorWeights->m_vector = other->NumeratorWeights->m_vector;
  this->ForwardNumeratorWeights->m_vector = other->ForwardNumeratorWeights->m_vector;
  this->DenominatorWeights->m_vector = other->DenominatorWeights->m_vector;
  this->InputVariableName->m_string = other->InputVariableName->m_string;
  this->OutputVariableName->m_string = other->OutputVariableName->m_string;
}
//------------------------------------------------------------------------------
vtkDSPFilterDefinition::~vtkDSPFilterDefinition()
{
  this->NumeratorWeights->m_vector.resize(0);
  this->ForwardNumeratorWeights->m_vector.resize(0);
  this->DenominatorWeights->m_vector.resize(0);
  this->InputVariableName->m_string = "";
  this->OutputVariableName->m_string = "";

  delete this->NumeratorWeights;
  delete this->ForwardNumeratorWeights;
  delete this->DenominatorWeights;
  delete this->InputVariableName;
  delete this->OutputVariableName;
}
//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::Clear()
{
  this->NumeratorWeights->m_vector.resize(0);
  this->ForwardNumeratorWeights->m_vector.resize(0);
  this->DenominatorWeights->m_vector.resize(0);
  this->InputVariableName->m_string = "";
  this->OutputVariableName->m_string = "";
}
//------------------------------------------------------------------------------
bool vtkDSPFilterDefinition::IsThisInputVariableInstanceNeeded(int a_timestep, int a_outputTimestep)
{
  if (a_outputTimestep < a_timestep)
  {
    int l_index = a_timestep - a_outputTimestep;
    if ((int)(this->ForwardNumeratorWeights->m_vector.size()) >= l_index)
    {
      // the filter does use this future input
      // printf("FILTER USES FUTURE INPUT %d for output %d\n",a_timestep,a_outputTimestep);
      return (true);
    }
    else
    {
      // future inputs not used for 1d filter
      // printf("FILTER doesn't use FUTURE INPUT %d for output %d\n",a_timestep,a_outputTimestep);
      return (false);
    }
  }
  if (this->DenominatorWeights->m_vector.size() > 1)
  {
    // with an iir filter, all prev outputs since the beginning of time are used,
    // therefore all prev inputs are used as well
    return (true);
  }

  // For an fir filter, only a certain number of past inputs are needed
  if (a_timestep < a_outputTimestep - ((int)(this->NumeratorWeights->m_vector.size()) - 1))
  {
    // this input is too far in the past
    return (false);
  }
  return (true);
}

//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::PushBackNumeratorWeight(double a_value)
{
  this->NumeratorWeights->m_vector.push_back(a_value);
}
//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::PushBackDenominatorWeight(double a_value)
{
  this->DenominatorWeights->m_vector.push_back(a_value);
}
//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::PushBackForwardNumeratorWeight(double a_value)
{
  this->ForwardNumeratorWeights->m_vector.push_back(a_value);
}

//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::SetInputVariableName(const char* a_value)
{
  this->InputVariableName->m_string = a_value;
}
//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::SetOutputVariableName(const char* a_value)
{
  this->OutputVariableName->m_string = a_value;
}

//------------------------------------------------------------------------------
const char* vtkDSPFilterDefinition::GetInputVariableName()
{
  return this->InputVariableName->m_string.c_str();
}
//------------------------------------------------------------------------------
const char* vtkDSPFilterDefinition::GetOutputVariableName()
{
  return this->OutputVariableName->m_string.c_str();
}

//------------------------------------------------------------------------------
int vtkDSPFilterDefinition::GetNumNumeratorWeights()
{
  return static_cast<int>(this->NumeratorWeights->m_vector.size());
}
//------------------------------------------------------------------------------
int vtkDSPFilterDefinition::GetNumDenominatorWeights()
{
  return static_cast<int>(this->DenominatorWeights->m_vector.size());
}
//------------------------------------------------------------------------------
int vtkDSPFilterDefinition::GetNumForwardNumeratorWeights()
{
  return static_cast<int>(this->ForwardNumeratorWeights->m_vector.size());
}

//------------------------------------------------------------------------------
double vtkDSPFilterDefinition::GetNumeratorWeight(int a_which)
{
  return this->NumeratorWeights->m_vector[a_which];
}
//------------------------------------------------------------------------------
double vtkDSPFilterDefinition::GetDenominatorWeight(int a_which)
{
  return this->DenominatorWeights->m_vector[a_which];
}
//------------------------------------------------------------------------------
double vtkDSPFilterDefinition::GetForwardNumeratorWeight(int a_which)
{
  return this->ForwardNumeratorWeights->m_vector[a_which];
}

//------------------------------------------------------------------------------
void vtkDSPFilterDefinition::PrintSelf(ostream& os, vtkIndent indent)
{

  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
