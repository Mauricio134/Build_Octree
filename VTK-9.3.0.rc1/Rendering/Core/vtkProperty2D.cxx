// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkProperty2D.h"
#include "vtkObjectFactory.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkProperty2D);

// Creates a vtkProperty2D with the following default values:
// Opacity 1, Color (1,0,0), CompositingOperator VTK_SRC
vtkProperty2D::vtkProperty2D()
{
  this->Opacity = 1.0;
  this->PointSize = 1.0;
  this->LineWidth = 1.0;
  this->LineStipplePattern = 0xFFFF;
  this->LineStippleRepeatFactor = 1;
  this->Color[0] = 1.0;
  this->Color[1] = 1.0;
  this->Color[2] = 1.0;
  this->DisplayLocation = VTK_FOREGROUND_LOCATION;
}

vtkProperty2D::~vtkProperty2D() = default;

// Assign one property to another.
void vtkProperty2D::DeepCopy(vtkProperty2D* p)
{
  if (p != nullptr)
  {
    this->SetColor(p->GetColor());
    this->SetOpacity(p->GetOpacity());
    this->SetPointSize(p->GetPointSize());
    this->SetLineWidth(p->GetLineWidth());
    this->SetLineStipplePattern(p->GetLineStipplePattern());
    this->SetLineStippleRepeatFactor(p->GetLineStippleRepeatFactor());
    this->SetDisplayLocation(p->GetDisplayLocation());
  }
}

void vtkProperty2D::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Opacity: " << this->Opacity << "\n";
  os << indent << "Color: (" << this->Color[0] << ", " << this->Color[1] << ", " << this->Color[2]
     << ")\n";
  os << indent << "Point size: " << this->PointSize << "\n";
  os << indent << "Line width: " << this->LineWidth << "\n";
  os << indent << "Line stipple pattern: " << this->LineStipplePattern << "\n";
  os << indent << "Line stipple repeat factor: " << this->LineStippleRepeatFactor << "\n";
  switch (this->DisplayLocation)
  {
    case VTK_FOREGROUND_LOCATION:
      os << indent << "Display location: foreground\n";
      break;
    case VTK_BACKGROUND_LOCATION:
      os << indent << "Display location: background\n";
      break;
    default:
      os << indent << "Display location: invalid\n";
      break;
  }
}
VTK_ABI_NAMESPACE_END
