// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
/**
 * @class   vtkSimple2DLayoutStrategy
 * @brief   a simple 2D graph layout
 *
 *
 * This class is an implementation of the work presented in:
 * Fruchterman & Reingold "Graph Drawing by Force-directed Placement"
 * Software-Practice and Experience 21(11) 1991).
 * The class includes some optimizations but nothing too fancy.
 *
 * @par Thanks:
 * Thanks to Brian Wylie from Sandia National Laboratories for creating this
 * class.
 */

#ifndef vtkSimple2DLayoutStrategy_h
#define vtkSimple2DLayoutStrategy_h

#include "vtkGraphLayoutStrategy.h"
#include "vtkInfovisLayoutModule.h" // For export macro

VTK_ABI_NAMESPACE_BEGIN
class vtkFloatArray;

class VTKINFOVISLAYOUT_EXPORT vtkSimple2DLayoutStrategy : public vtkGraphLayoutStrategy
{
public:
  static vtkSimple2DLayoutStrategy* New();

  vtkTypeMacro(vtkSimple2DLayoutStrategy, vtkGraphLayoutStrategy);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  ///@{
  /**
   * Seed the random number generator used to jitter point positions.
   * This has a significant effect on their final positions when
   * the layout is complete.
   */
  vtkSetClampMacro(RandomSeed, int, 0, VTK_INT_MAX);
  vtkGetMacro(RandomSeed, int);
  ///@}

  ///@{
  /**
   * Set/Get the maximum number of iterations to be used.
   * The higher this number, the more iterations through the algorithm
   * is possible, and thus, the more the graph gets modified.
   * The default is '100' for no particular reason
   * Note: The strong recommendation is that you do not change
   * this parameter. :)
   */
  vtkSetClampMacro(MaxNumberOfIterations, int, 0, VTK_INT_MAX);
  vtkGetMacro(MaxNumberOfIterations, int);
  ///@}

  ///@{
  /**
   * Set/Get the number of iterations per layout.
   * The only use for this ivar is for the application
   * to do visualizations of the layout before it's complete.
   * The default is '100' to match the default 'MaxNumberOfIterations'
   * Note: Changing this parameter is just fine :)
   */
  vtkSetClampMacro(IterationsPerLayout, int, 0, VTK_INT_MAX);
  vtkGetMacro(IterationsPerLayout, int);
  ///@}

  ///@{
  /**
   * Set the initial temperature.  The temperature default is '5'
   * for no particular reason
   * Note: The strong recommendation is that you do not change
   * this parameter. :)
   */
  vtkSetClampMacro(InitialTemperature, float, 0.0, VTK_FLOAT_MAX);
  vtkGetMacro(InitialTemperature, float);
  ///@}

  ///@{
  /**
   * Set/Get the Cool-down rate.
   * The higher this number is, the longer it will take to "cool-down",
   * and thus, the more the graph will be modified. The default is '10'
   * for no particular reason.
   * Note: The strong recommendation is that you do not change
   * this parameter. :)
   */
  vtkSetClampMacro(CoolDownRate, double, 0.01, VTK_DOUBLE_MAX);
  vtkGetMacro(CoolDownRate, double);
  ///@}

  ///@{
  /**
   * Set Random jitter of the nodes at initialization
   * to on or off.
   * Note: It's strongly recommendation to have jitter ON
   * even if you have initial coordinates in your graph.
   * Default is ON
   */
  vtkSetMacro(Jitter, bool);
  vtkGetMacro(Jitter, bool);
  ///@}

  ///@{
  /**
   * Manually set the resting distance. Otherwise the
   * distance is computed automatically.
   */
  vtkSetMacro(RestDistance, float);
  vtkGetMacro(RestDistance, float);
  ///@}

  /**
   * This strategy sets up some data structures
   * for faster processing of each Layout() call
   */
  void Initialize() override;

  /**
   * This is the layout method where the graph that was
   * set in SetGraph() is laid out. The method can either
   * entirely layout the graph or iteratively lay out the
   * graph. If you have an iterative layout please implement
   * the IsLayoutComplete() method.
   */
  void Layout() override;

  /**
   * I'm an iterative layout so this method lets the caller
   * know if I'm done laying out the graph
   */
  int IsLayoutComplete() override { return this->LayoutComplete; }

protected:
  vtkSimple2DLayoutStrategy();
  ~vtkSimple2DLayoutStrategy() override;

  int MaxNumberOfIterations; // Maximum number of iterations.
  float InitialTemperature;
  float CoolDownRate; // Cool-down rate.  Note:  Higher # = Slower rate.

private:
  // An edge consists of two vertices joined together.
  // This struct acts as a "pointer" to those two vertices.
  struct vtkLayoutEdge_t
  {
    vtkIdType from;
    vtkIdType to;
    float weight;
  };
  using vtkLayoutEdge = struct vtkLayoutEdge_t;

  // These are for storage of repulsion and attraction
  vtkFloatArray* RepulsionArray;
  vtkFloatArray* AttractionArray;
  vtkLayoutEdge* EdgeArray;

  int RandomSeed;
  int IterationsPerLayout;
  int TotalIterations;
  int LayoutComplete;
  float Temp;
  float RestDistance;
  bool Jitter;

  vtkSimple2DLayoutStrategy(const vtkSimple2DLayoutStrategy&) = delete;
  void operator=(const vtkSimple2DLayoutStrategy&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
