// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkMathTextUtilities.h"

#include "vtkDebugLeaks.h" // Must be included before any singletons
#include "vtkMath.h"
#include "vtkObjectFactory.h"
#include "vtkTextActor.h"
#include "vtkTextProperty.h"
#include "vtkViewport.h"
#include "vtkWindow.h"

#include <algorithm>

//------------------------------------------------------------------------------
// The singleton, and the singleton cleanup
VTK_ABI_NAMESPACE_BEGIN
vtkMathTextUtilities* vtkMathTextUtilities::Instance = nullptr;
vtkMathTextUtilitiesCleanup vtkMathTextUtilities::Cleanup;

//------------------------------------------------------------------------------
// Create the singleton cleanup
// Register our singleton cleanup callback against the FTLibrary so that
// it might be called before the FTLibrary singleton is destroyed.
vtkMathTextUtilitiesCleanup::vtkMathTextUtilitiesCleanup() = default;

//------------------------------------------------------------------------------
// Delete the singleton cleanup
vtkMathTextUtilitiesCleanup::~vtkMathTextUtilitiesCleanup()
{
  vtkMathTextUtilities::SetInstance(nullptr);
}

//------------------------------------------------------------------------------
vtkMathTextUtilities* vtkMathTextUtilities::GetInstance()
{
  if (!vtkMathTextUtilities::Instance)
  {
    vtkMathTextUtilities::Instance =
      static_cast<vtkMathTextUtilities*>(vtkObjectFactory::CreateInstance("vtkMathTextUtilities"));
  }

  return vtkMathTextUtilities::Instance;
}

//------------------------------------------------------------------------------
void vtkMathTextUtilities::SetInstance(vtkMathTextUtilities* instance)
{
  if (vtkMathTextUtilities::Instance == instance)
  {
    return;
  }

  if (vtkMathTextUtilities::Instance)
  {
    vtkMathTextUtilities::Instance->Delete();
  }

  vtkMathTextUtilities::Instance = instance;

  // User will call ->Delete() after setting instance
  if (instance)
  {
    instance->Register(nullptr);
  }
}

//------------------------------------------------------------------------------
int vtkMathTextUtilities::GetConstrainedFontSize(
  const char* str, vtkTextProperty* tprop, int targetWidth, int targetHeight, int dpi)
{
  if (str == nullptr || str[0] == '\0' || targetWidth == 0 || targetHeight == 0 || tprop == nullptr)
  {
    return 0;
  }

  // Use the current font size as a first guess
  int bbox[4];
  double fontSize = tprop->GetFontSize();
  if (!this->GetBoundingBox(tprop, str, dpi, bbox))
  {
    return -1;
  }
  int width = bbox[1] - bbox[0];
  int height = bbox[3] - bbox[2];

  // Bad assumption but better than nothing -- assume the bbox grows linearly
  // with the font size:
  if (width != 0 && height != 0)
  {
    fontSize *= std::min(static_cast<double>(targetWidth) / static_cast<double>(width),
      static_cast<double>(targetHeight) / static_cast<double>(height));
    tprop->SetFontSize(static_cast<int>(fontSize));
    if (!this->GetBoundingBox(tprop, str, dpi, bbox))
    {
      return -1;
    }
    width = bbox[1] - bbox[0];
    height = bbox[3] - bbox[2];
  }

  // Now just step up/down until the bbox matches the target.
  while ((width < targetWidth || height < targetHeight) && fontSize < 200)
  {
    fontSize += 1.;
    tprop->SetFontSize(fontSize);
    if (!this->GetBoundingBox(tprop, str, dpi, bbox))
    {
      return -1;
    }
    width = bbox[1] - bbox[0];
    height = bbox[3] - bbox[2];
  }

  while ((width > targetWidth || height > targetHeight) && fontSize > 0)
  {
    fontSize -= 1.;
    tprop->SetFontSize(fontSize);
    if (!this->GetBoundingBox(tprop, str, dpi, bbox))
    {
      return -1;
    }
    width = bbox[1] - bbox[0];
    height = bbox[3] - bbox[2];
  }

  return fontSize;
}

//------------------------------------------------------------------------------
vtkMathTextUtilities* vtkMathTextUtilities::New()
{
  vtkMathTextUtilities* ret = vtkMathTextUtilities::GetInstance();
  if (ret)
  {
    ret->Register(nullptr);
  }
  return ret;
}

//------------------------------------------------------------------------------
vtkMathTextUtilities::vtkMathTextUtilities() = default;

//------------------------------------------------------------------------------
vtkMathTextUtilities::~vtkMathTextUtilities() = default;

//------------------------------------------------------------------------------
void vtkMathTextUtilities::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Instance: " << vtkMathTextUtilities::Instance << endl;
}
VTK_ABI_NAMESPACE_END
