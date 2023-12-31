// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkTextRendererStringToImage.h"

#include "vtkImageData.h"
#include "vtkObjectFactory.h"
#include "vtkStdString.h"
#include "vtkTextProperty.h"
#include "vtkTextRenderer.h"
#include "vtkVector.h"

VTK_ABI_NAMESPACE_BEGIN
class vtkTextRendererStringToImage::Internals
{
public:
  Internals() { this->TextRenderer = vtkTextRenderer::GetInstance(); }
  vtkTextRenderer* TextRenderer;
};

//------------------------------------------------------------------------------
vtkStandardNewMacro(vtkTextRendererStringToImage);

//------------------------------------------------------------------------------
vtkTextRendererStringToImage::vtkTextRendererStringToImage()
{
  this->Implementation = new Internals;
}

//------------------------------------------------------------------------------
vtkTextRendererStringToImage::~vtkTextRendererStringToImage()
{
  delete this->Implementation;
}

//------------------------------------------------------------------------------
vtkVector2i vtkTextRendererStringToImage::GetBounds(
  vtkTextProperty* property, const vtkStdString& string, int dpi)
{
  vtkVector2i recti(0, 0);
  int tmp[4];
  if (!property || string.empty())
  {
    return recti;
  }

  this->Implementation->TextRenderer->GetBoundingBox(property, string, tmp, dpi);

  recti.Set(tmp[1] - tmp[0] + 1, tmp[3] - tmp[2] + 1);

  return recti;
}

//------------------------------------------------------------------------------
int vtkTextRendererStringToImage::RenderString(vtkTextProperty* property,
  const vtkStdString& string, int dpi, vtkImageData* data, int textDims[2])
{
  return this->Implementation->TextRenderer->RenderString(property, string, data, textDims, dpi);
}

//------------------------------------------------------------------------------
void vtkTextRendererStringToImage::SetScaleToPowerOfTwo(bool scale)
{
  this->vtkStringToImage::SetScaleToPowerOfTwo(scale);
  this->Implementation->TextRenderer->SetScaleToPowerOfTwo(scale);
}

//------------------------------------------------------------------------------
void vtkTextRendererStringToImage::DeepCopy(vtkTextRendererStringToImage*) {}

//------------------------------------------------------------------------------
void vtkTextRendererStringToImage::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
VTK_ABI_NAMESPACE_END
