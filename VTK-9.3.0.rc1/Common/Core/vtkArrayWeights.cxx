// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov

#include "vtkArrayWeights.h"
#include <vector>

VTK_ABI_NAMESPACE_BEGIN
class vtkArrayWeightsStorage
{
public:
  vtkArrayWeightsStorage(size_t size)
    : Storage(size)
  {
  }
  std::vector<double> Storage;
};

vtkArrayWeights::vtkArrayWeights()
{
  this->Storage = new vtkArrayWeightsStorage(0);
}

vtkArrayWeights::vtkArrayWeights(double i)
{
  this->Storage = new vtkArrayWeightsStorage(1);
  this->Storage->Storage[0] = i;
}

vtkArrayWeights::vtkArrayWeights(double i, double j)
{
  this->Storage = new vtkArrayWeightsStorage(2);
  this->Storage->Storage[0] = i;
  this->Storage->Storage[1] = j;
}

vtkArrayWeights::vtkArrayWeights(double i, double j, double k)
{
  this->Storage = new vtkArrayWeightsStorage(3);
  this->Storage->Storage[0] = i;
  this->Storage->Storage[1] = j;
  this->Storage->Storage[2] = k;
}

vtkArrayWeights::vtkArrayWeights(double i, double j, double k, double l)
{
  this->Storage = new vtkArrayWeightsStorage(4);
  this->Storage->Storage[0] = i;
  this->Storage->Storage[1] = j;
  this->Storage->Storage[2] = k;
  this->Storage->Storage[3] = l;
}

vtkArrayWeights::vtkArrayWeights(const vtkArrayWeights& other)
{
  this->Storage = new vtkArrayWeightsStorage(*other.Storage);
}

//------------------------------------------------------------------------------
vtkArrayWeights::~vtkArrayWeights()
{
  delete this->Storage;
}

//------------------------------------------------------------------------------
vtkIdType vtkArrayWeights::GetCount() const
{
  return static_cast<vtkIdType>(this->Storage->Storage.size());
}

void vtkArrayWeights::SetCount(vtkIdType count)
{
  this->Storage->Storage.assign(static_cast<size_t>(count), 0.0);
}

double& vtkArrayWeights::operator[](vtkIdType i)
{
  return this->Storage->Storage[static_cast<size_t>(i)];
}

const double& vtkArrayWeights::operator[](vtkIdType i) const
{
  return this->Storage->Storage[static_cast<size_t>(i)];
}

vtkArrayWeights& vtkArrayWeights::operator=(const vtkArrayWeights& other)
{
  if (this == &other)
  {
    return *this;
  }

  *this->Storage = *other.Storage;
  return *this;
}
VTK_ABI_NAMESPACE_END
