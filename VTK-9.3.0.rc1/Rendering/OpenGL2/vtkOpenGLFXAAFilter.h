// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

/**
 * @class   vtkOpenGLFXAAFilter
 * @brief   Perform FXAA antialiasing on the current
 * framebuffer.
 *
 *
 * Call Execute() to run a FXAA antialiasing pass on the current OpenGL
 * framebuffer. See method documentation for tunable parameters.
 *
 * Based on the following implementation and description:
 *
 * Whitepaper:
 * http://developer.download.nvidia.com/assets/gamedev/files/sdk/11/FXAA_WhitePaper.pdf
 *
 * Sample implementation:
 * https://github.com/NVIDIAGameWorks/GraphicsSamples/blob/master/samples/es3-kepler/FXAA/FXAA3_11.h
 *
 * TODO there are currently some "banding" artifacts on some edges, particularly
 * single pixel lines. These seem to be caused by using a linear RGB input,
 * rather than a gamma-correct sRGB input. Future work should combine this pass
 * with a gamma correction pass to correct this. Bonus points for precomputing
 * luminosity into the sRGB's alpha channel to save cycles in the FXAA shader!
 */

#ifndef vtkOpenGLFXAAFilter_h
#define vtkOpenGLFXAAFilter_h

#include "vtkFXAAOptions.h" // For DebugOptions enum
#include "vtkObject.h"
#include "vtkRenderingOpenGL2Module.h" // For export macro

#include <string> // For std::string

VTK_ABI_NAMESPACE_BEGIN
class vtkFXAAOptions;
class vtkOpenGLRenderer;
class vtkOpenGLRenderTimer;
class vtkShaderProgram;
class vtkTextureObject;
class vtkOpenGLQuadHelper;

class VTKRENDERINGOPENGL2_EXPORT vtkOpenGLFXAAFilter : public vtkObject
{
public:
  static vtkOpenGLFXAAFilter* New();
  vtkTypeMacro(vtkOpenGLFXAAFilter, vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Perform FXAA on the current render buffer in @a ren.
   */
  void Execute(vtkOpenGLRenderer* ren);

  /**
   * Release all OpenGL state.
   */
  void ReleaseGraphicsResources();

  /**
   * Copy the configuration values from @a opts into this filter. Note that
   * this copies the configuration values from opts -- it does not save the
   * @a opts pointer.
   */
  void UpdateConfiguration(vtkFXAAOptions* opts);

  ///@{
  /**
   * Parameter for tuning the FXAA implementation. See vtkFXAAOptions for
   * details and suggested values.
   */
  vtkSetClampMacro(RelativeContrastThreshold, float, 0.f, 1.f);
  vtkGetMacro(RelativeContrastThreshold, float);
  vtkSetClampMacro(HardContrastThreshold, float, 0.f, 1.f);
  vtkGetMacro(HardContrastThreshold, float);
  vtkSetClampMacro(SubpixelBlendLimit, float, 0.f, 1.f);
  vtkGetMacro(SubpixelBlendLimit, float);
  vtkSetClampMacro(SubpixelContrastThreshold, float, 0.f, 1.f);
  vtkGetMacro(SubpixelContrastThreshold, float);
  virtual void SetUseHighQualityEndpoints(bool val);
  vtkGetMacro(UseHighQualityEndpoints, bool);
  vtkBooleanMacro(UseHighQualityEndpoints, bool);
  vtkSetClampMacro(EndpointSearchIterations, int, 0, VTK_INT_MAX);
  vtkGetMacro(EndpointSearchIterations, int);
  virtual void SetDebugOptionValue(vtkFXAAOptions::DebugOption opt);
  vtkGetMacro(DebugOptionValue, vtkFXAAOptions::DebugOption);
  ///@}

protected:
  vtkOpenGLFXAAFilter();
  ~vtkOpenGLFXAAFilter() override;

  void Prepare();
  void FreeGLObjects();
  void CreateGLObjects();
  void LoadInput();
  void ApplyFilter();
  void SubstituteFragmentShader(std::string& fragShader);
  void Finalize();

  void StartTimeQuery(vtkOpenGLRenderTimer* timer);
  void EndTimeQuery(vtkOpenGLRenderTimer* timer);
  void PrintBenchmark();

  // Cache GL state that we modify
  bool BlendState;
  bool DepthTestState;

  int Viewport[4]; // x, y, width, height

  // Used to measure execution time:
  vtkOpenGLRenderTimer* PreparationTimer;
  vtkOpenGLRenderTimer* FXAATimer;

  // Parameters:
  float RelativeContrastThreshold;
  float HardContrastThreshold;
  float SubpixelBlendLimit;
  float SubpixelContrastThreshold;
  int EndpointSearchIterations;

  bool UseHighQualityEndpoints;
  vtkFXAAOptions::DebugOption DebugOptionValue;

  // Set to true when the shader definitions change so we know when to rebuild.
  bool NeedToRebuildShader;

  vtkOpenGLRenderer* Renderer;
  vtkTextureObject* Input;

  vtkOpenGLQuadHelper* QHelper;

private:
  vtkOpenGLFXAAFilter(const vtkOpenGLFXAAFilter&) = delete;
  void operator=(const vtkOpenGLFXAAFilter&) = delete;
};

VTK_ABI_NAMESPACE_END
#endif // vtkOpenGLFXAAFilter_h
