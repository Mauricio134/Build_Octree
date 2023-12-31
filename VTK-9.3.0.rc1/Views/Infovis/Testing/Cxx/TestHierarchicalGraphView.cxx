// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov

#include "vtkCosmicTreeLayoutStrategy.h"
#include "vtkDataRepresentation.h"
#include "vtkHierarchicalGraphView.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderedHierarchyRepresentation.h"
#include "vtkRenderer.h"
#include "vtkSelection.h"
#include "vtkSplineGraphEdges.h"
#include "vtkTestUtilities.h"
#include "vtkViewTheme.h"
#include "vtkXMLTreeReader.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

using std::string;

int TestHierarchicalGraphView(int argc, char* argv[])
{
  VTK_CREATE(vtkTesting, testHelper);
  testHelper->AddArguments(argc, const_cast<const char**>(argv));
  string dataRoot = testHelper->GetDataRoot();
  string treeFileName = dataRoot + "/Data/Infovis/XML/vtklibrary.xml";
  string graphFileName = dataRoot + "/Data/Infovis/XML/vtkclasses.xml";

  // We need to put the graph and tree edges in different domains.
  VTK_CREATE(vtkXMLTreeReader, reader1);
  reader1->SetFileName(treeFileName.c_str());
  reader1->SetEdgePedigreeIdArrayName("tree edge");
  reader1->GenerateVertexPedigreeIdsOff();
  reader1->SetVertexPedigreeIdArrayName("id");

  VTK_CREATE(vtkXMLTreeReader, reader2);
  reader2->SetFileName(graphFileName.c_str());
  reader2->SetEdgePedigreeIdArrayName("graph edge");
  reader2->GenerateVertexPedigreeIdsOff();
  reader2->SetVertexPedigreeIdArrayName("id");

  reader1->Update();
  reader2->Update();

  VTK_CREATE(vtkHierarchicalGraphView, view);
  view->DisplayHoverTextOff();
  view->GetRenderWindow()->SetMultiSamples(0);
  view->SetHierarchyFromInputConnection(reader1->GetOutputPort());
  view->SetGraphFromInputConnection(reader2->GetOutputPort());
  view->SetVertexColorArrayName("VertexDegree");
  view->SetColorVertices(true);
  view->SetVertexLabelArrayName("id");
  view->SetVertexLabelVisibility(true);
  view->SetScalingArrayName("TreeRadius");

  view->Update(); // Needed for now
  view->SetGraphEdgeColorArrayName("graph edge");
  view->SetColorGraphEdgesByArray(true);
  vtkRenderedHierarchyRepresentation::SafeDownCast(view->GetRepresentation())
    ->SetGraphSplineType(vtkSplineGraphEdges::CUSTOM, 0);

  VTK_CREATE(vtkCosmicTreeLayoutStrategy, ct);
  ct->SetNodeSizeArrayName("VertexDegree");
  ct->SetSizeLeafNodesOnly(true);
  view->SetLayoutStrategy(ct);

  // Apply a theme to the views
  vtkViewTheme* const theme = vtkViewTheme::CreateMellowTheme();
  theme->SetLineWidth(1);
  view->ApplyViewTheme(theme);
  theme->Delete();

  view->ResetCamera();

  int retVal = vtkRegressionTestImage(view->GetRenderWindow());
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    view->GetInteractor()->Initialize();
    view->GetInteractor()->Start();

    retVal = vtkRegressionTester::PASSED;
  }

  return !retVal;
}
