// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

/**
 * @class   vtkArrayIterator
 * @brief   Abstract superclass to iterate over elements
 * in an vtkAbstractArray.
 *
 *
 * vtkArrayIterator is used to iterate over elements in any
 * vtkAbstractArray subclass.  The vtkArrayIteratorTemplateMacro is used
 * to centralize the set of types supported by Execute methods.  It also
 * avoids duplication of long switch statement case lists.
 *
 * Note that in this macro VTK_TT is defined to be the type of the
 * iterator for the given type of array. One must include the
 * vtkArrayIteratorIncludes.h header file to provide for extending of
 * this macro by addition of new iterators.
 *
 * Example usage:
 * \code
 * vtkArrayIter* iter = array->NewIterator();
 * switch(array->GetDataType())
 *   {
 *   vtkArrayIteratorTemplateMacro(myFunc(static_cast<VTK_TT*>(iter), arg2));
 *   }
 * iter->Delete();
 * \endcode
 */

#ifndef vtkArrayIterator_h
#define vtkArrayIterator_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkObject.h"
VTK_ABI_NAMESPACE_BEGIN
class vtkAbstractArray;
class VTKCOMMONCORE_EXPORT vtkArrayIterator : public vtkObject
{
public:
  vtkTypeMacro(vtkArrayIterator, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Set the array this iterator will iterate over.
   * After Initialize() has been called, the iterator is valid
   * so long as the Array has not been modified
   * (except using the iterator itself).
   * If the array is modified, the iterator must be re-initialized.
   */
  virtual void Initialize(vtkAbstractArray* array) = 0;

  /**
   * Get the data type from the underlying array. Returns 0 if
   * no underlying array is present.
   */
  virtual int GetDataType() const = 0;

protected:
  vtkArrayIterator();
  ~vtkArrayIterator() override;

private:
  vtkArrayIterator(const vtkArrayIterator&) = delete;
  void operator=(const vtkArrayIterator&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
