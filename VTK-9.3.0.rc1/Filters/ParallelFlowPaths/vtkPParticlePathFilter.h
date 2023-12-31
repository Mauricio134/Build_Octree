// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkPParticlePathFilter
 * @brief   A Parallel Particle tracer for unsteady vector fields
 *
 * vtkPParticlePathFilter is a filter that integrates a vector field to generate
 * path lines.
 *
 * @sa
 * vtkPParticlePathFilterBase has the details of the algorithms
 */

#ifndef vtkPParticlePathFilter_h
#define vtkPParticlePathFilter_h

#include "vtkPParticleTracerBase.h"
#include "vtkParticlePathFilter.h" //for utility

#include "vtkFiltersParallelFlowPathsModule.h" // For export macro
VTK_ABI_NAMESPACE_BEGIN
class VTKFILTERSPARALLELFLOWPATHS_EXPORT vtkPParticlePathFilter : public vtkPParticleTracerBase
{
public:
  vtkTypeMacro(vtkPParticlePathFilter, vtkPParticleTracerBase);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  static vtkPParticlePathFilter* New();

protected:
  vtkPParticlePathFilter();
  ~vtkPParticlePathFilter() override;

  void ResetCache() override;
  int OutputParticles(vtkPolyData* poly) override;
  void InitializeExtraPointDataArrays(vtkPointData* outputPD) override;
  void SetToExtraPointDataArrays(
    vtkIdType particleId, vtkParticleTracerBaseNamespace::ParticleInformation&) override;
  void Finalize() override;

  //
  // Store any information we need in the output and fetch what we can
  // from the input
  //
  int RequestInformation(vtkInformation* request, vtkInformationVector** inputVector,
    vtkInformationVector* outputVector) override;

  ParticlePathFilterInternal It;
  vtkDoubleArray* SimulationTime;
  vtkIntArray* SimulationTimeStep;

private:
  vtkPParticlePathFilter(const vtkPParticlePathFilter&) = delete;
  void operator=(const vtkPParticlePathFilter&) = delete;
};
VTK_ABI_NAMESPACE_END
#endif
