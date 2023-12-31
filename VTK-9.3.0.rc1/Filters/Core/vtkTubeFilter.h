// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
/**
 * @class   vtkTubeFilter
 * @brief   filter that generates tubes around lines
 *
 * vtkTubeFilter is a filter that generates a tube around each input line.
 * The tubes are made up of triangle strips and rotate around the tube with
 * the rotation of the line normals. (If no normals are present, they are
 * computed automatically.) The radius of the tube can be set to vary with
 * scalar or vector value. If the radius varies with scalar value the radius
 * is linearly adjusted. If the radius varies by vector, a mass flux preserving
 * variation is used. If the radius varies by vector norm, the radius is
 * linearly adjusted to its norm. The number of sides for the tube also
 * can be specified. You can also specify which of the sides are visible. This
 * is useful for generating interesting striping effects. Other options
 * include the ability to cap the tube and generate texture coordinates.
 * Texture coordinates can be used with an associated texture map to create
 * interesting effects such as marking the tube with stripes corresponding
 * to length or time.
 *
 * This filter is typically used to create thick or dramatic lines. Another
 * common use is to combine this filter with vtkStreamTracer to generate
 * streamtubes.
 *
 * @warning
 * The number of tube sides must be greater than 3. If you wish to use fewer
 * sides (i.e., a ribbon), use vtkRibbonFilter.
 *
 * @warning
 * The input line must not have duplicate points, or normals at points that
 * are parallel to the incoming/outgoing line segments. (Duplicate points
 * can be removed with vtkCleanPolyData.) If a line does not meet this
 * criteria, then that line is not tubed.
 *
 * @sa
 * vtkRibbonFilter vtkStreamTracer vtkTubeBender
 *
 * @par Thanks:
 * Michael Finch for absolute scalar radius
 */

#ifndef vtkTubeFilter_h
#define vtkTubeFilter_h

#include "vtkFiltersCoreModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

#define VTK_VARY_RADIUS_OFF 0
#define VTK_VARY_RADIUS_BY_SCALAR 1
#define VTK_VARY_RADIUS_BY_VECTOR 2
#define VTK_VARY_RADIUS_BY_ABSOLUTE_SCALAR 3
#define VTK_VARY_RADIUS_BY_VECTOR_NORM 4

#define VTK_TCOORDS_OFF 0
#define VTK_TCOORDS_FROM_NORMALIZED_LENGTH 1
#define VTK_TCOORDS_FROM_LENGTH 2
#define VTK_TCOORDS_FROM_SCALARS 3

VTK_ABI_NAMESPACE_BEGIN
class vtkCellArray;
class vtkCellData;
class vtkDataArray;
class vtkFloatArray;
class vtkPointData;
class vtkPoints;

class VTKFILTERSCORE_EXPORT vtkTubeFilter : public vtkPolyDataAlgorithm
{
public:
  vtkTypeMacro(vtkTubeFilter, vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Construct object with radius 0.5, radius variation turned off, the
   * number of sides set to 3, and radius factor of 10.
   */
  static vtkTubeFilter* New();

  ///@{
  /**
   * Set the minimum tube radius (minimum because the tube radius may vary).
   */
  vtkSetClampMacro(Radius, double, 0.0, VTK_DOUBLE_MAX);
  vtkGetMacro(Radius, double);
  ///@}

  ///@{
  /**
   * Turn on/off the variation of tube radius with scalar value.
   */
  vtkSetClampMacro(VaryRadius, int, VTK_VARY_RADIUS_OFF, VTK_VARY_RADIUS_BY_VECTOR_NORM);
  vtkGetMacro(VaryRadius, int);
  void SetVaryRadiusToVaryRadiusOff() { this->SetVaryRadius(VTK_VARY_RADIUS_OFF); }
  void SetVaryRadiusToVaryRadiusByScalar() { this->SetVaryRadius(VTK_VARY_RADIUS_BY_SCALAR); }
  void SetVaryRadiusToVaryRadiusByVector() { this->SetVaryRadius(VTK_VARY_RADIUS_BY_VECTOR); }
  void SetVaryRadiusToVaryRadiusByVectorNorm()
  {
    this->SetVaryRadius(VTK_VARY_RADIUS_BY_VECTOR_NORM);
  }
  void SetVaryRadiusToVaryRadiusByAbsoluteScalar()
  {
    this->SetVaryRadius(VTK_VARY_RADIUS_BY_ABSOLUTE_SCALAR);
  }
  const char* GetVaryRadiusAsString();
  ///@}

  ///@{
  /**
   * Set the number of sides for the tube. At a minimum, number of sides is 3.
   */
  vtkSetClampMacro(NumberOfSides, int, 3, VTK_INT_MAX);
  vtkGetMacro(NumberOfSides, int);
  ///@}

  ///@{
  /**
   * Set the maximum tube radius in terms of a multiple of the minimum radius.
   */
  vtkSetMacro(RadiusFactor, double);
  vtkGetMacro(RadiusFactor, double);
  ///@}

  ///@{
  /**
   * Set the default normal to use if no normals are supplied, and the
   * DefaultNormalOn is set.
   */
  vtkSetVector3Macro(DefaultNormal, double);
  vtkGetVectorMacro(DefaultNormal, double, 3);
  ///@}

  ///@{
  /**
   * Set a boolean to control whether to use default normals.
   * DefaultNormalOn is set.
   */
  vtkSetMacro(UseDefaultNormal, vtkTypeBool);
  vtkGetMacro(UseDefaultNormal, vtkTypeBool);
  vtkBooleanMacro(UseDefaultNormal, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Set a boolean to control whether tube sides should share vertices.
   * This creates independent strips, with constant normals so the
   * tube is always faceted in appearance.
   */
  vtkSetMacro(SidesShareVertices, vtkTypeBool);
  vtkGetMacro(SidesShareVertices, vtkTypeBool);
  vtkBooleanMacro(SidesShareVertices, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Turn on/off whether to cap the ends with polygons. Initial value is off.
   */
  vtkSetMacro(Capping, vtkTypeBool);
  vtkGetMacro(Capping, vtkTypeBool);
  vtkBooleanMacro(Capping, vtkTypeBool);
  ///@}

  ///@{
  /**
   * Control the striping of the tubes. If OnRatio is greater than 1,
   * then every nth tube side is turned on, beginning with the Offset
   * side.
   */
  vtkSetClampMacro(OnRatio, int, 1, VTK_INT_MAX);
  vtkGetMacro(OnRatio, int);
  ///@}

  ///@{
  /**
   * Control the striping of the tubes. The offset sets the
   * first tube side that is visible. Offset is generally used with
   * OnRatio to create nifty striping effects.
   */
  vtkSetClampMacro(Offset, int, 0, VTK_INT_MAX);
  vtkGetMacro(Offset, int);
  ///@}

  ///@{
  /**
   * Control whether and how texture coordinates are produced. This is
   * useful for striping the tube with length textures, etc. If you
   * use scalars to create the texture, the scalars are assumed to be
   * monotonically increasing (or decreasing).
   */
  vtkSetClampMacro(GenerateTCoords, int, VTK_TCOORDS_OFF, VTK_TCOORDS_FROM_SCALARS);
  vtkGetMacro(GenerateTCoords, int);
  void SetGenerateTCoordsToOff() { this->SetGenerateTCoords(VTK_TCOORDS_OFF); }
  void SetGenerateTCoordsToNormalizedLength()
  {
    this->SetGenerateTCoords(VTK_TCOORDS_FROM_NORMALIZED_LENGTH);
  }
  void SetGenerateTCoordsToUseLength() { this->SetGenerateTCoords(VTK_TCOORDS_FROM_LENGTH); }
  void SetGenerateTCoordsToUseScalars() { this->SetGenerateTCoords(VTK_TCOORDS_FROM_SCALARS); }
  const char* GetGenerateTCoordsAsString();
  ///@}

  ///@{
  /**
   * Control the conversion of units during the texture coordinates
   * calculation. The TextureLength indicates what length (whether
   * calculated from scalars or length) is mapped to the [0,1)
   * texture space.
   */
  vtkSetClampMacro(TextureLength, double, 0.000001, VTK_INT_MAX);
  vtkGetMacro(TextureLength, double);
  ///@}

  ///@{
  /**
   * Set/get the desired precision for the output types. See the documentation
   * for the vtkAlgorithm::DesiredOutputPrecision enum for an explanation of
   * the available precision settings.
   */
  vtkSetMacro(OutputPointsPrecision, int);
  vtkGetMacro(OutputPointsPrecision, int);
  ///@}

protected:
  vtkTubeFilter();
  ~vtkTubeFilter() override = default;

  // Usual data generation method
  int RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector*) override;

  double Radius;       // minimum radius of tube
  int VaryRadius;      // controls radius variation
  int NumberOfSides;   // number of sides to create tube
  double RadiusFactor; // maximum allowable radius
  double DefaultNormal[3];
  vtkTypeBool UseDefaultNormal;
  vtkTypeBool SidesShareVertices;
  vtkTypeBool Capping; // control whether tubes are capped
  int OnRatio;         // control the generation of the sides of the tube
  int Offset;          // control the generation of the sides
  int GenerateTCoords; // control texture coordinate generation
  int OutputPointsPrecision;
  double TextureLength; // this length is mapped to [0,1) texture space

  // Helper methods
  int GeneratePoints(vtkIdType offset, vtkIdType npts, const vtkIdType* pts, vtkPoints* inPts,
    vtkPoints* newPts, vtkPointData* pd, vtkPointData* outPD, vtkFloatArray* newNormals,
    vtkDataArray* inScalars, double range[2], vtkDataArray* inVectors, double maxSpeed,
    vtkDataArray* inNormals);
  void GenerateStrips(vtkIdType offset, vtkIdType npts, const vtkIdType* pts, vtkIdType inCellId,
    vtkCellData* cd, vtkCellData* outCD, vtkCellArray* newStrips);
  void GenerateTextureCoords(vtkIdType offset, vtkIdType npts, const vtkIdType* pts,
    vtkPoints* inPts, vtkDataArray* inScalars, vtkFloatArray* newTCoords);
  vtkIdType ComputeOffset(vtkIdType offset, vtkIdType npts);

  // Helper data members
  double Theta;

private:
  vtkTubeFilter(const vtkTubeFilter&) = delete;
  void operator=(const vtkTubeFilter&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif
