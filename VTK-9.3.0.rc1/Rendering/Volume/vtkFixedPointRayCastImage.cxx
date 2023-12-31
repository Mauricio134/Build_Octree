// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkFixedPointRayCastImage.h"
#include "vtkObjectFactory.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkFixedPointRayCastImage);

// Construct a new vtkFixedPointRayCastImage with default values
vtkFixedPointRayCastImage::vtkFixedPointRayCastImage()
{
  this->ImageViewportSize[0] = 0;
  this->ImageViewportSize[1] = 0;

  this->ImageMemorySize[0] = 0;
  this->ImageMemorySize[1] = 0;

  this->ImageInUseSize[0] = 0;
  this->ImageInUseSize[1] = 0;

  this->ImageOrigin[0] = 0;
  this->ImageOrigin[1] = 0;

  this->ImageSampleDistance = 0;

  this->ZBufferMemorySize = 0;

  this->ZBufferSize[0] = 0;
  this->ZBufferSize[1] = 0;

  this->ZBufferOrigin[0] = 0;
  this->ZBufferOrigin[1] = 0;

  this->UseZBuffer = 0;

  this->Image = nullptr;
  this->ZBuffer = nullptr;
}

// Destruct a vtkFixedPointRayCastImage - clean up any memory used
vtkFixedPointRayCastImage::~vtkFixedPointRayCastImage()
{
  delete[] this->Image;
  delete[] this->ZBuffer;
}

// Allocate memory
void vtkFixedPointRayCastImage::AllocateImage()
{
  delete[] this->Image;
  this->Image = nullptr;

  if (this->ImageMemorySize[0] > 0 && this->ImageMemorySize[1] > 0)
  {
    this->Image = new unsigned short[(4 * this->ImageMemorySize[0] * this->ImageMemorySize[1])];
  }
}

// Clear image to 0
void vtkFixedPointRayCastImage::ClearImage()
{
  unsigned short* ucptr = this->Image;

  for (int i = 0; i < this->ImageMemorySize[0] * this->ImageMemorySize[1]; i++)
  {
    *(ucptr++) = 0;
    *(ucptr++) = 0;
    *(ucptr++) = 0;
    *(ucptr++) = 0;
  }
}

void vtkFixedPointRayCastImage::AllocateZBuffer()
{
  // If we already have a buffer big enough, don't
  // bother to do anything
  if (this->ZBufferSize[0] * this->ZBufferSize[1] > this->ZBufferMemorySize)
  {
    // If our current buffer is not large enough, delete it
    delete[] this->ZBuffer;
    this->ZBuffer = nullptr;

    // Try out a size equal to the viewport in pixels
    this->ZBufferMemorySize = this->ImageViewportSize[0] * this->ImageViewportSize[1];

    // This shouldn't ever happen, but just in case....
    // If this happens it means that somehow our viewport
    // size in pixels is smaller than the zbuffer we are
    // requesting - which will probably not make OpenGL
    // very happy.
    if (this->ZBufferMemorySize < this->ZBufferSize[0] * this->ZBufferSize[1])
    {
      this->ZBufferMemorySize = this->ZBufferSize[0] * this->ZBufferSize[1];
    }

    // Allocate the memory
    this->ZBuffer = new float[this->ZBufferMemorySize];
  }
}

float vtkFixedPointRayCastImage::GetZBufferValue(int x, int y)
{
  if (!this->UseZBuffer)
  {
    return 1.0;
  }

  int xPos, yPos;

  xPos = static_cast<int>(static_cast<float>(x) * this->ImageSampleDistance);
  yPos = static_cast<int>(static_cast<float>(y) * this->ImageSampleDistance);

  xPos = (xPos >= this->ZBufferSize[0]) ? (this->ZBufferSize[0] - 1) : (xPos);
  yPos = (yPos >= this->ZBufferSize[1]) ? (this->ZBufferSize[1] - 1) : (yPos);

  return *(this->ZBuffer + yPos * this->ZBufferSize[0] + xPos);
}

void vtkFixedPointRayCastImage::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Image Viewport Size: " << this->ImageViewportSize[0] << " "
     << this->ImageViewportSize[1] << endl;

  os << indent << "Image Memory Size: " << this->ImageMemorySize[0] << " "
     << this->ImageMemorySize[1] << endl;

  os << indent << "Image In Use Size: " << this->ImageInUseSize[0] << " " << this->ImageInUseSize[1]
     << endl;

  os << indent << "Image Origin: " << this->ImageOrigin[0] << " " << this->ImageOrigin[1] << endl;

  os << indent << "Image Sample Distance: " << this->ImageSampleDistance << endl;

  os << indent << "Use ZBuffer: " << (this->UseZBuffer ? "On" : "Off") << endl;

  os << indent << "ZBuffer Origin: " << this->ZBufferOrigin[0] << " " << this->ZBufferOrigin[1]
     << endl;

  os << indent << "ZBuffer Size: " << this->ZBufferSize[0] << " " << this->ZBufferSize[1] << endl;
}
VTK_ABI_NAMESPACE_END
