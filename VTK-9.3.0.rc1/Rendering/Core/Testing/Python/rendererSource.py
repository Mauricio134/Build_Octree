#!/usr/bin/env python
from vtkmodules.vtkCommonColor import vtkNamedColors
from vtkmodules.vtkCommonExecutionModel import vtkCastToConcrete
from vtkmodules.vtkFiltersCore import (
    vtkContourFilter,
    vtkPolyDataNormals,
    vtkProbeFilter,
    vtkStructuredGridOutlineFilter,
)
from vtkmodules.vtkFiltersSources import vtkPlaneSource
from vtkmodules.vtkIOParallel import vtkMultiBlockPLOT3DReader
from vtkmodules.vtkRenderingCore import (
    vtkActor,
    vtkPolyDataMapper,
    vtkRenderWindow,
    vtkRenderWindowInteractor,
    vtkRenderer,
    vtkRendererSource,
    vtkTexture,
)
import vtkmodules.vtkInteractionStyle
import vtkmodules.vtkRenderingFreeType
import vtkmodules.vtkRenderingOpenGL2
from vtkmodules.util.misc import vtkGetDataRoot
VTK_DATA_ROOT = vtkGetDataRoot()

def GetRGBColor(colorName):
    '''
        Return the red, green and blue components for a
        color as doubles.
    '''
    rgb = [0.0, 0.0, 0.0]  # black
    vtkNamedColors().GetColorRGB(colorName, rgb)
    return rgb

# Create the RenderWindow, Renderer and both Actors
#
ren1 = vtkRenderer()
ren2 = vtkRenderer()
renWin = vtkRenderWindow()
renWin.AddRenderer(ren1)
renWin.AddRenderer(ren2)
iren = vtkRenderWindowInteractor()
iren.SetRenderWindow(renWin)

# create pipeline for ren1
#
pl3d2 = vtkMultiBlockPLOT3DReader()
pl3d2.SetXYZFileName(VTK_DATA_ROOT + "/Data/combxyz.bin")
pl3d2.SetQFileName(VTK_DATA_ROOT + "/Data/combq.bin")
pl3d2.SetScalarFunctionNumber(153)
pl3d2.Update()

output2 = pl3d2.GetOutput().GetBlock(0)

pl3d = vtkMultiBlockPLOT3DReader()
pl3d.SetXYZFileName(VTK_DATA_ROOT + "/Data/combxyz.bin")
pl3d.SetQFileName(VTK_DATA_ROOT + "/Data/combq.bin")
pl3d.SetScalarFunctionNumber(120)
pl3d.SetVectorFunctionNumber(202)
pl3d.Update()

output = pl3d.GetOutput().GetBlock(0)

iso = vtkContourFilter()
iso.SetInputData(output)
iso.SetValue(0, -100000)

probe2 = vtkProbeFilter()
probe2.SetInputConnection(iso.GetOutputPort())
probe2.SetSourceData(output2)

cast2 = vtkCastToConcrete()
cast2.SetInputConnection(probe2.GetOutputPort())

normals = vtkPolyDataNormals()
normals.SetInputConnection(cast2.GetOutputPort())
normals.SetFeatureAngle(45)

isoMapper = vtkPolyDataMapper()
isoMapper.SetInputConnection(normals.GetOutputPort())
isoMapper.ScalarVisibilityOn()
isoMapper.SetScalarRange(output2.GetPointData().GetScalars().GetRange())

isoActor = vtkActor()
isoActor.SetMapper(isoMapper)
isoActor.GetProperty().SetColor(GetRGBColor('bisque'))

outline = vtkStructuredGridOutlineFilter()
outline.SetInputData(output)

outlineMapper = vtkPolyDataMapper()
outlineMapper.SetInputConnection(outline.GetOutputPort())

outlineActor = vtkActor()
outlineActor.SetMapper(outlineMapper)

# Add the actors to the renderer, set the background and size
#
ren1.AddActor(outlineActor)
ren1.AddActor(isoActor)
ren1.SetBackground(1, 1, 1)
ren1.SetViewport(0, 0, .5, 1)

renWin.SetSize(512, 256)

ren1.SetBackground(0.1, 0.2, 0.4)
ren1.ResetCamera()

cam1 = ren1.GetActiveCamera()
cam1.SetClippingRange(3.95297, 50)
cam1.SetFocalPoint(9.71821, 0.458166, 29.3999)
cam1.SetPosition(2.7439, -37.3196, 38.7167)
cam1.SetViewUp(-0.16123, 0.264271, 0.950876)

aPlane = vtkPlaneSource()

aPlaneMapper = vtkPolyDataMapper()
aPlaneMapper.SetInputConnection(aPlane.GetOutputPort())

screen = vtkActor()
screen.SetMapper(aPlaneMapper)

ren2.AddActor(screen)
ren2.SetViewport(.5, 0, 1, 1)
ren2.GetActiveCamera().Azimuth(30)
ren2.GetActiveCamera().Elevation(30)
ren2.SetBackground(.8, .4, .3)
ren1.ResetCameraClippingRange()
ren2.ResetCamera()
ren2.ResetCameraClippingRange()

renWin.Render()

ren1Image = vtkRendererSource()
ren1Image.SetInput(ren1)
ren1Image.DepthValuesOn()

aTexture = vtkTexture()
aTexture.SetInputConnection(ren1Image.GetOutputPort())

screen.SetTexture(aTexture)

# renWin.Render()
# render the image
#
renWin.Render()

#iren.Start()
