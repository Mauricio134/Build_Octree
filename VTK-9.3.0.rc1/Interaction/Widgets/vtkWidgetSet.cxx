// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkWidgetSet.h"

#include "vtkObjectFactory.h"
#include "vtkParallelopipedWidget.h" // REMOVE

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkWidgetSet);

//------------------------------------------------------------------------------
vtkWidgetSet::vtkWidgetSet() = default;

//------------------------------------------------------------------------------
vtkWidgetSet::~vtkWidgetSet()
{
  for (WidgetIteratorType it = this->Widget.begin(); it != this->Widget.end(); ++it)
  {
    (*it)->UnRegister(this);
  }
}

//------------------------------------------------------------------------------
void vtkWidgetSet::SetEnabled(vtkTypeBool enabling)
{
  for (WidgetIteratorType it = this->Widget.begin(); it != this->Widget.end(); ++it)
  {
    (*it)->SetEnabled(enabling);
  }
}

//------------------------------------------------------------------------------
void vtkWidgetSet::AddWidget(vtkAbstractWidget* w)
{
  for (unsigned int i = 0; i < this->Widget.size(); i++)
  {
    if (this->Widget[i] == w)
    {
      return;
    }
  }

  this->Widget.push_back(w);
  w->Register(this);

  // TODO : Won't be necessary if we move this to the AbstractWidget.. superclass
  static_cast<vtkParallelopipedWidget*>(w)->WidgetSet = this;
}

//------------------------------------------------------------------------------
void vtkWidgetSet::RemoveWidget(vtkAbstractWidget* w)
{
  for (WidgetIteratorType it = this->Widget.begin(); it != this->Widget.end(); ++it)
  {
    if (*it == w)
    {
      this->Widget.erase(it);
      static_cast<vtkParallelopipedWidget*>(w)->WidgetSet = nullptr;
      w->UnRegister(this);
      break;
    }
  }
}

//------------------------------------------------------------------------------
vtkAbstractWidget* vtkWidgetSet::GetNthWidget(unsigned int i)
{
  return this->Widget[i];
}

//------------------------------------------------------------------------------
unsigned int vtkWidgetSet::GetNumberOfWidgets()
{
  return static_cast<unsigned int>(this->Widget.size());
}

//------------------------------------------------------------------------------
void vtkWidgetSet::PrintSelf(ostream& os, vtkIndent indent)
{
  // Superclass typedef defined in vtkTypeMacro() found in vtkSetGet.h
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
