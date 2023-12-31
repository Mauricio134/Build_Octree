// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkCriticalSection
 * @brief   Critical section locking class
 *
 * vtkCriticalSection allows the locking of variables which are accessed
 * through different threads.  This header file also defines
 * vtkSimpleCriticalSection which is not a subclass of vtkObject.
 * The API is identical to that of vtkMutexLock, and the behavior is
 * identical as well, except on Windows 9x/NT platforms. The only difference
 * on these platforms is that vtkMutexLock is more flexible, in that
 * it works across processes as well as across threads, but also costs
 * more, in that it evokes a 600-cycle x86 ring transition. The
 * vtkCriticalSection provides a higher-performance equivalent (on
 * Windows) but won't work across processes. Since it is unclear how,
 * in vtk, an object at the vtk level can be shared across processes
 * in the first place, one should use vtkCriticalSection unless one has
 * a very good reason to use vtkMutexLock. If higher-performance equivalents
 * for non-Windows platforms (Irix, SunOS, etc) are discovered, they
 * should replace the implementations in this class
 */

#ifndef vtkCriticalSection_h
#define vtkCriticalSection_h

#include "vtkCommonCoreModule.h" // For export macro
#include "vtkDeprecation.h"      // For VTK_DEPRECATED_IN_9_1_0
#include "vtkObject.h"
#include <mutex> // for std::mutex

VTK_ABI_NAMESPACE_BEGIN
// Remove with VTK_DEPRECATED_IN_9_2_0 because it was not actually deprecated
// in 9.1.0.
class VTK_DEPRECATED_IN_9_1_0("Use std::mutex instead") VTKCOMMONCORE_EXPORT vtkCriticalSection
  : public vtkObject
{
public:
  static vtkCriticalSection* New();

  vtkTypeMacro(vtkCriticalSection, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Lock the vtkCriticalSection
   */
  void Lock();

  /**
   * Unlock the vtkCriticalSection
   */
  void Unlock();

protected:
  std::mutex mtx;
  vtkCriticalSection() = default;
  ~vtkCriticalSection() override = default;

private:
  vtkCriticalSection(const vtkCriticalSection&) = delete;
  void operator=(const vtkCriticalSection&) = delete;
};

inline void vtkCriticalSection::Lock()
{
  this->mtx.lock();
}

inline void vtkCriticalSection::Unlock()
{
  this->mtx.unlock();
}

VTK_ABI_NAMESPACE_END
#endif

// VTK-HeaderTest-Exclude: vtkCriticalSection.h
