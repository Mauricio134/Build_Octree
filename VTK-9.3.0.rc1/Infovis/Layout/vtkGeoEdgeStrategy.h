// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
/**
 * @class   vtkGeoEdgeStrategy
 * @brief   Layout graph edges on a globe as arcs.
 *
 *
 * vtkGeoEdgeStrategy produces arcs for each edge in the input graph.
 * This is useful for viewing lines on a sphere (e.g. the earth).
 * The arcs may "jump" above the sphere's surface using ExplodeFactor.
 */

#ifndef vtkGeoEdgeStrategy_h
#define vtkGeoEdgeStrategy_h

#include "vtkEdgeLayoutStrategy.h"
#include "vtkInfovisLayoutModule.h" // For export macro

VTK_ABI_NAMESPACE_BEGIN
class VTKINFOVISLAYOUT_EXPORT vtkGeoEdgeStrategy : public vtkEdgeLayoutStrategy
{
public:
  static vtkGeoEdgeStrategy* New();
  vtkTypeMacro(vtkGeoEdgeStrategy, vtkEdgeLayoutStrategy);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * The base radius used to determine the earth's surface.
   * Default is the earth's radius in meters.
   * TODO: Change this to take in a vtkGeoTerrain to get altitude.
   */
  vtkSetMacro(GlobeRadius, double);
  vtkGetMacro(GlobeRadius, double);
  ///@}

  ///@{
  /**
   * Factor on which to "explode" the arcs away from the surface.
   * A value of 0.0 keeps the values on the surface.
   * Values larger than 0.0 push the arcs away from the surface by a distance
   * proportional to the distance between the points.
   * The default is 0.2.
   */
  vtkSetMacro(ExplodeFactor, double);
  vtkGetMacro(ExplodeFactor, double);
  ///@}

  ///@{
  /**
   * The number of subdivisions in the arc.
   * The default is 20.
   */
  vtkSetMacro(NumberOfSubdivisions, int);
  vtkGetMacro(NumberOfSubdivisions, int);
  ///@}

  /**
   * Perform the layout.
   */
  void Layout() override;

protected:
  vtkGeoEdgeStrategy();
  ~vtkGeoEdgeStrategy() override = default;

  double GlobeRadius;
  double ExplodeFactor;
  int NumberOfSubdivisions;

private:
  vtkGeoEdgeStrategy(const vtkGeoEdgeStrategy&) = delete;
  void operator=(const vtkGeoEdgeStrategy&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
