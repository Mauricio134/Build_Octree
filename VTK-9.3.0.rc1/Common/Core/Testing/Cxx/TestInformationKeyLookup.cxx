// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkInformationKeyLookup.h"

#include "vtkAbstractArray.h"
#include "vtkDataArray.h"
#include "vtkInformationDoubleVectorKey.h"
#include "vtkInformationInformationVectorKey.h"
#include "vtkInformationIntegerKey.h"
#include "vtkInformationVariantVectorKey.h"

// Lookup a key and test that it matches what it should.
namespace
{
bool VerifyKey(const std::string& name, const std::string& location, vtkInformationKey* key)
{
  return vtkInformationKeyLookup::Find(name, location) == key;
}
} // end anon namespace

#define VERIFY_KEY(name, location)                                                                 \
  if (!VerifyKey(#name, #location, location::name()))                                              \
  {                                                                                                \
    std::cerr << "Error finding key: " << #location << "::" << #name << "\n";                      \
    return EXIT_FAILURE;                                                                           \
  }

int TestInformationKeyLookup(int, char*[])
{
  // Test some keys in vtkAbstractArray and vtkDataArray (those are currently
  // the only ones available to this test, since the lookup only knows about
  // keys in currently linked modules).
  VERIFY_KEY(DISCRETE_VALUES, vtkAbstractArray)
  VERIFY_KEY(DISCRETE_VALUE_SAMPLE_PARAMETERS, vtkAbstractArray)
  VERIFY_KEY(GUI_HIDE, vtkAbstractArray)
  VERIFY_KEY(PER_COMPONENT, vtkAbstractArray)
  VERIFY_KEY(COMPONENT_RANGE, vtkDataArray)
  VERIFY_KEY(L2_NORM_RANGE, vtkDataArray)

  return EXIT_SUCCESS;
}
