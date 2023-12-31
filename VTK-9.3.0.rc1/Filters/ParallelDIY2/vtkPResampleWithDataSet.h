// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkPResampleWithDataSet
 * points from another dataset.
 *
 * vtkPResampleWithDataSet is the parallel version of vtkResampleWithDataSet
 * filter
 * @sa
 * vtkResampleWithDataSet vtkPResampleToImage
 */

#ifndef vtkPResampleWithDataSet_h
#define vtkPResampleWithDataSet_h

#include "vtkFiltersParallelDIY2Module.h" // For export macro
#include "vtkResampleWithDataSet.h"

VTK_ABI_NAMESPACE_BEGIN
class vtkMultiProcessController;

class VTKFILTERSPARALLELDIY2_EXPORT vtkPResampleWithDataSet : public vtkResampleWithDataSet
{
public:
  vtkTypeMacro(vtkPResampleWithDataSet, vtkResampleWithDataSet);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  static vtkPResampleWithDataSet* New();

  ///@{
  /**
   * By default this filter uses the global controller,
   * but this method can be used to set another instead.
   */
  virtual void SetController(vtkMultiProcessController*);
  vtkGetObjectMacro(Controller, vtkMultiProcessController);
  ///@}

  ///@{
  /**
   * Set/Get if the filter should use Balanced Partitioning for fast lookup of
   * the input points. Balanced Partitioning partitions the points into similar
   * sized bins. It takes logarithmic time to search for the candidate bins, but
   * search inside border bins takes constant time.
   * The default is to use Regular Partitioning which partitions the space of the
   * points into regular sized bins. Based on their distribution, the bins may
   * contain widely varying number of points. It takes constant time to search
   * for the candidate bins but search within border bins can vary.
   * For most cases, both techniques perform the same with Regular Partitioning
   * being slightly better. Balanced Partitioning may perform better when the
   * points distribution is highly skewed.
   */
  vtkSetMacro(UseBalancedPartitionForPointsLookup, bool);
  vtkGetMacro(UseBalancedPartitionForPointsLookup, bool);
  vtkBooleanMacro(UseBalancedPartitionForPointsLookup, bool);
  ///@}

protected:
  vtkPResampleWithDataSet();
  ~vtkPResampleWithDataSet() override;

  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;
  int RequestUpdateExtent(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  vtkMultiProcessController* Controller;
  bool UseBalancedPartitionForPointsLookup;

private:
  vtkPResampleWithDataSet(const vtkPResampleWithDataSet&) = delete;
  void operator=(const vtkPResampleWithDataSet&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif // vtkPResampleWithDataSet_h
