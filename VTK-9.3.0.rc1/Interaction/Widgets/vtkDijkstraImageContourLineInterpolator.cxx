// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkDijkstraImageContourLineInterpolator.h"

#include "vtkCellArray.h"
#include "vtkContourRepresentation.h"
#include "vtkDijkstraImageGeodesicPath.h"
#include "vtkImageActor.h"
#include "vtkImageActorPointPlacer.h"
#include "vtkImageData.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"
#include "vtkPointData.h"
#include "vtkPoints.h"
#include "vtkPolyData.h"

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkDijkstraImageContourLineInterpolator);

//------------------------------------------------------------------------------
vtkDijkstraImageContourLineInterpolator ::vtkDijkstraImageContourLineInterpolator()
{
  this->DijkstraImageGeodesicPath = vtkDijkstraImageGeodesicPath::New();
  this->CostImage = nullptr;
}

//------------------------------------------------------------------------------
vtkDijkstraImageContourLineInterpolator ::~vtkDijkstraImageContourLineInterpolator()
{
  this->DijkstraImageGeodesicPath->Delete();
  this->CostImage = nullptr;
}

//------------------------------------------------------------------------------
void vtkDijkstraImageContourLineInterpolator::SetCostImage(vtkImageData* arg)
{
  if (this->CostImage == arg)
  {
    return;
  }

  this->CostImage = arg;
  if (this->CostImage)
  {
    this->DijkstraImageGeodesicPath->SetInputData(this->CostImage);
  }
}

//------------------------------------------------------------------------------
int vtkDijkstraImageContourLineInterpolator::InterpolateLine(
  vtkRenderer* vtkNotUsed(ren), vtkContourRepresentation* rep, int idx1, int idx2)
{
  // if the user didn't set the image, try to get it from the actor
  if (!this->CostImage)
  {

    vtkImageActorPointPlacer* placer =
      vtkImageActorPointPlacer::SafeDownCast(rep->GetPointPlacer());

    if (!placer)
    {
      return 1;
    }

    vtkImageActor* actor = placer->GetImageActor();
    if (!actor || !(this->CostImage = actor->GetInput()))
    {
      return 1;
    }
    this->DijkstraImageGeodesicPath->SetInputData(this->CostImage);
  }

  double p1[3], p2[3];
  rep->GetNthNodeWorldPosition(idx1, p1);
  rep->GetNthNodeWorldPosition(idx2, p2);

  vtkIdType beginVertId = this->CostImage->FindPoint(p1);
  vtkIdType endVertId = this->CostImage->FindPoint(p2);

  // Could not find the starting and ending cells. We can't interpolate.
  if (beginVertId == -1 || endVertId == -1)
  {
    return 0;
  }

  int nnodes = rep->GetNumberOfNodes();

  if (this->DijkstraImageGeodesicPath->GetRepelPathFromVertices() && nnodes > 2)
  {
    vtkPoints* verts = vtkPoints::New();
    double pt[3];
    for (int i = 0; i < nnodes; ++i)
    {
      if (i == idx1)
        continue;

      for (int j = 0; j < rep->GetNumberOfIntermediatePoints(i); ++j)
      {
        rep->GetIntermediatePointWorldPosition(i, j, pt);
        verts->InsertNextPoint(pt);
      }
    }
    this->DijkstraImageGeodesicPath->SetRepelVertices(verts);
    verts->Delete();
  }
  else
  {
    this->DijkstraImageGeodesicPath->SetRepelVertices(nullptr);
  }

  this->DijkstraImageGeodesicPath->SetStartVertex(endVertId);
  this->DijkstraImageGeodesicPath->SetEndVertex(beginVertId);
  this->DijkstraImageGeodesicPath->Update();

  vtkPolyData* pd = this->DijkstraImageGeodesicPath->GetOutput();

  vtkIdType npts = 0;
  const vtkIdType* pts = nullptr;
  pd->GetLines()->InitTraversal();
  pd->GetLines()->GetNextCell(npts, pts);

  for (int i = 0; i < npts; ++i)
  {
    rep->AddIntermediatePointWorldPosition(idx1, pd->GetPoint(pts[i]));
  }

  return 1;
}

//------------------------------------------------------------------------------
void vtkDijkstraImageContourLineInterpolator::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
  os << indent << "DijkstraImageGeodesicPath: " << this->DijkstraImageGeodesicPath << endl;
  os << indent << "CostImage: " << this->GetCostImage() << endl;
}
VTK_ABI_NAMESPACE_END
