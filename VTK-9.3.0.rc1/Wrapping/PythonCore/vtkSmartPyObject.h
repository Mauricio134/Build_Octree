// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

/**
 * @class   vtkSmartPyObject
 * @brief   The vtkSmartPyObject class serves as a smart pointer for PyObjects.
 */

#ifndef vtkSmartPyObject_h
#define vtkSmartPyObject_h

// this must be included first
#include "vtkABINamespace.h"
#include "vtkPython.h" // PyObject can't be forward declared

#include "vtkWrappingPythonCoreModule.h"

VTK_ABI_NAMESPACE_BEGIN
class VTKWRAPPINGPYTHONCORE_EXPORT vtkSmartPyObject
{
public:
  /**
   * Creates a new vtkSmartPyObject managing the existing reference
   * to the object given
   */
  vtkSmartPyObject(PyObject* obj = nullptr);
  /**
   * Creates a new vtkSmartPyObject to the object in the other smart
   * pointer and increments the reference count to the object
   */
  vtkSmartPyObject(const vtkSmartPyObject& other);
  /**
   * Decrements the reference count to the object
   */
  ~vtkSmartPyObject();

  /**
   * The internal pointer is copied from the other vtkSmartPyObject.
   * The reference count on the old object is decremented and the
   * reference count on the new object is incremented
   */
  vtkSmartPyObject& operator=(const vtkSmartPyObject& other);
  /**
   * Sets the internal pointer to the given PyObject.  The reference
   * count on the PyObject is incremented.  To take a reference without
   * incrementing the reference count use TakeReference.
   */
  vtkSmartPyObject& operator=(PyObject* obj);
  /**
   * Sets the internal pointer to the given PyObject without incrementing
   * the reference count
   */
  void TakeReference(PyObject* obj);

  /**
   * Provides normal pointer target member access using operator ->.
   */
  PyObject* operator->() const;
  /**
   * Get the contained pointer.
   */
  operator PyObject*() const;

  /**
   * Returns true if the internal pointer is to a valid PyObject.
   */
  operator bool() const;

  /**
   * Returns the pointer to a PyObject stored internally and clears the
   * internally stored pointer.  The caller is responsible for calling
   * Py_DECREF on the returned object when finished with it as this
   * does not change the reference count.
   */
  PyObject* ReleaseReference();
  /**
   * Returns the internal pointer to a PyObject with no effect on its
   * reference count
   */
  PyObject* GetPointer() const;
  /**
   * Returns the internal pointer to a PyObject and increments its reference
   * count
   */
  PyObject* GetAndIncreaseReferenceCount();

private:
  PyObject* Object;
};
VTK_ABI_NAMESPACE_END

#endif
// VTK-HeaderTest-Exclude: vtkSmartPyObject.h
