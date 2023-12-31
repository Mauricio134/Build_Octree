// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkPImageWriter
 * @brief   Writes images to files.
 *
 * vtkPImageWriter writes images to files with any data type. The data type of
 * the file is the same scalar type as the input.  The dimensionality
 * determines whether the data will be written in one or multiple files.
 * This class is used as the superclass of most image writing classes
 * such as vtkBMPWriter etc. It supports streaming.
 */

#ifndef vtkPImageWriter_h
#define vtkPImageWriter_h

#include "vtkIOParallelModule.h" // For export macro
#include "vtkImageWriter.h"
VTK_ABI_NAMESPACE_BEGIN
class vtkPipelineSize;

class VTKIOPARALLEL_EXPORT vtkPImageWriter : public vtkImageWriter
{
public:
  static vtkPImageWriter* New();
  vtkTypeMacro(vtkPImageWriter, vtkImageWriter);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * Set / Get the memory limit in kibibytes (1024 bytes). The writer will
   * stream to attempt to keep the pipeline size within this limit
   */
  vtkSetMacro(MemoryLimit, unsigned long);
  vtkGetMacro(MemoryLimit, unsigned long);
  ///@}

protected:
  vtkPImageWriter();
  ~vtkPImageWriter() override;

  unsigned long MemoryLimit;

  void RecursiveWrite(
    int dim, vtkImageData* region, vtkInformation* inInfo, ostream* file) override;
  void RecursiveWrite(int dim, vtkImageData* cache, vtkImageData* data, vtkInformation* inInfo,
    ostream* file) override
  {
    this->vtkImageWriter::RecursiveWrite(dim, cache, data, inInfo, file);
  }

  vtkPipelineSize* SizeEstimator;

private:
  vtkPImageWriter(const vtkPImageWriter&) = delete;
  void operator=(const vtkPImageWriter&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
