#!/usr/bin/env python
from vtkmodules.vtkCommonTransforms import vtkCylindricalTransform
from vtkmodules.vtkFiltersGeneral import vtkTransformPolyDataFilter
from vtkmodules.vtkFiltersSources import vtkPlaneSource
from vtkmodules.vtkIOImage import vtkPNMReader
from vtkmodules.vtkRenderingCore import (
    vtkActor,
    vtkDataSetMapper,
    vtkRenderWindow,
    vtkRenderWindowInteractor,
    vtkRenderer,
    vtkTexture,
)
import vtkmodules.vtkInteractionStyle
import vtkmodules.vtkRenderingFreeType
import vtkmodules.vtkRenderingOpenGL2
from vtkmodules.util.misc import vtkGetDataRoot
VTK_DATA_ROOT = vtkGetDataRoot()

# Create the RenderWindow, Renderer and both Actors
#
ren1 = vtkRenderer()
renWin = vtkRenderWindow()
renWin.AddRenderer(ren1)
iren = vtkRenderWindowInteractor()
iren.SetRenderWindow(renWin)
# avoid the singularity at the Z axis using 0.0001 radian offset
plane = vtkPlaneSource()
plane.SetOrigin(1.0,0.0,-1.0)
plane.SetPoint1(1.0,6.28318530719,-1.0)
plane.SetPoint2(1.0,0.0,1.0)
plane.SetXResolution(19)
plane.SetYResolution(9)
transform = vtkCylindricalTransform()
tpoly = vtkTransformPolyDataFilter()
tpoly.SetInputConnection(plane.GetOutputPort())
tpoly.SetTransform(transform)
tpoly2 = vtkTransformPolyDataFilter()
tpoly2.SetInputConnection(tpoly.GetOutputPort())
tpoly2.SetTransform(transform.GetInverse())
# also cover the inverse transformation by going back and forth
tpoly3 = vtkTransformPolyDataFilter()
tpoly3.SetInputConnection(tpoly2.GetOutputPort())
tpoly3.SetTransform(transform)
mapper = vtkDataSetMapper()
mapper.SetInputConnection(tpoly3.GetOutputPort())
earth = vtkPNMReader()
earth.SetFileName(VTK_DATA_ROOT + "/Data/earth.ppm")
texture = vtkTexture()
texture.SetInputConnection(earth.GetOutputPort())
texture.InterpolateOn()
world = vtkActor()
world.SetMapper(mapper)
world.SetTexture(texture)
# Add the actors to the renderer, set the background and size
#
ren1.AddActor(world)
ren1.SetBackground(0.1,0.2,0.4)
renWin.SetSize(300,300)
ren1.GetActiveCamera().SetPosition(8,-10,6)
ren1.GetActiveCamera().SetFocalPoint(0,0,0)
ren1.GetActiveCamera().SetViewAngle(15)
ren1.GetActiveCamera().SetViewUp(0.0,0.0,1.0)
# render the image
#
cam1 = ren1.GetActiveCamera()
cam1.Zoom(1.4)
ren1.ResetCameraClippingRange()
iren.Initialize()
# prevent the tk window from showing up then start the event loop
# --- end of script --
