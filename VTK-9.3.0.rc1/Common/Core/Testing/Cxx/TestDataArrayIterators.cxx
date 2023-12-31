// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkFloatArray.h"
#include "vtkNew.h"
#include "vtkTimerLog.h"
#include "vtkTypedDataArray.h"
#include "vtkTypedDataArrayIterator.h"

#include <cassert>
#include <iostream>

// undefine this to print benchmark results:
#define SILENT

// Create a subclass of vtkTypedDataArray:
namespace
{
class MyArray : public vtkTypedDataArray<float>
{
  vtkFloatArray* Data;

public:
  static MyArray* New() { VTK_STANDARD_NEW_BODY(MyArray); }
  void Init(vtkFloatArray* array)
  {
    this->Data = array;
    this->NumberOfComponents = array->GetNumberOfComponents();
    this->MaxId = array->GetMaxId();
  }
  ValueType& GetValueReference(vtkIdType idx) override { return *this->Data->GetPointer(idx); }

  // These pure virtuals are no-op -- all we care about is GetValueReference
  // to test the iterator.
  void SetTypedTuple(vtkIdType, const ValueType*) override {}
  void InsertTypedTuple(vtkIdType, const ValueType*) override {}
  vtkIdType InsertNextTypedTuple(const ValueType*) override { return 0; }
  vtkIdType LookupTypedValue(ValueType) override { return 0; }
  void LookupTypedValue(ValueType, vtkIdList*) override {}
  ValueType GetValue(vtkIdType) const override { return 0; }
  void SetValue(vtkIdType, ValueType) override {}
  void GetTypedTuple(vtkIdType, ValueType*) const override {}
  vtkIdType InsertNextValue(ValueType) override { return 0; }
  void InsertValue(vtkIdType, ValueType) override {}
  vtkTypeBool Allocate(vtkIdType, vtkIdType) override { return 0; }
  vtkTypeBool Resize(vtkIdType) override { return 0; }
};
}

int TestDataArrayIterators(int, char*[])
{
  vtkIdType numComps = 4;
  vtkIdType numValues = 100000000; // 10 million
  assert(numValues % numComps == 0);
  vtkIdType numTuples = numValues / numComps;

  vtkNew<vtkFloatArray> arrayContainer;
  vtkFloatArray* array = arrayContainer;
  array->SetNumberOfComponents(numComps);
  array->SetNumberOfTuples(numTuples);
  for (vtkIdType i = 0; i < numValues; ++i)
  {
    // Just fill with consistent data
    array->SetValue(i, i % 97);
  }

  // Create the vtkTypedDataArray testing implementation:
  vtkNew<MyArray> tdaContainer;
  MyArray* tda = tdaContainer;
  tda->Init(array);

  // should be vtkAOSDataArrayTemplate<float>::Iterator (float*):
  vtkFloatArray::Iterator datBegin = array->Begin();
  vtkFloatArray::Iterator datIter = array->Begin();
  if (typeid(datBegin) != typeid(float*))
  {
    std::cerr << "Error: vtkFloatArray::Iterator is not a float*.";
    return EXIT_FAILURE;
  }

  // should be vtkTypedDataArrayIterator<float>:
  vtkTypedDataArray<float>::Iterator tdaBegin =
    vtkTypedDataArray<float>::FastDownCast(tda)->Begin();
  vtkTypedDataArray<float>::Iterator tdaIter = vtkTypedDataArray<float>::FastDownCast(tda)->Begin();
  if (typeid(tdaBegin) != typeid(vtkTypedDataArrayIterator<float>))
  {
    std::cerr << "Error: vtkTypedDataArray<float>::Iterator is not a "
                 "vtkTypedDataArrayIterator<float>.";
    return EXIT_FAILURE;
  }

  // Validate that the iterators return the same values from operator[] and
  // operator* as GetValue;
  for (vtkIdType i = 0; i < numValues; ++i)
  {
    float lookup = array->GetValue(i);
    if (lookup != datBegin[i] || lookup != tdaBegin[i] || lookup != *datIter || lookup != *tdaIter)
    {
      std::cerr << "Mismatch at " << i << ":"
                << " GetValue(i)=" << lookup << " datBegin[i]=" << datBegin[i]
                << " tdaBegin[i]=" << tdaBegin[i] << " *datIter=" << *datIter
                << " *tdaIter=" << *tdaIter << std::endl;
      return EXIT_FAILURE;
    }
    ++datIter;
    ++tdaIter;
  }

#ifndef SILENT
  // Iterator timings.
  vtkNew<vtkTimerLog> timer;

  // Lookup:
  float lookupSum = 0.f;
  timer->StartTimer();
  for (vtkIdType i = 0; i < numValues; ++i)
  {
    lookupSum += *array->GetPointer(i);
  }
  timer->StopTimer();
  double lookupTime = timer->GetElapsedTime();

  // Scalar iterator:
  float datSum = 0.f;
  timer->StartTimer();
  vtkFloatArray::Iterator datEnd = array->End();
  while (datBegin != datEnd)
  {
    datSum += *datBegin++;
  }
  timer->StopTimer();
  double datTime = timer->GetElapsedTime();

  // vtkTypedDataArrayIterator:
  vtkTypedDataArray<float>::Iterator tdaEnd = tda->End();
  float tdaSum = 0.f;
  timer->StartTimer();
  while (tdaBegin != tdaEnd)
  {
    tdaSum += *tdaBegin++;
  }
  timer->StopTimer();
  double tdaTime = timer->GetElapsedTime();

  std::cout << "GetValue time, sum: " << lookupTime << ", " << lookupSum << std::endl;
  std::cout << "dat time, sum:      " << datTime << ", " << datSum << std::endl;
  std::cout << "tda time, sum:      " << tdaTime << ", " << tdaSum << std::endl;
#endif

  return EXIT_SUCCESS;
}
