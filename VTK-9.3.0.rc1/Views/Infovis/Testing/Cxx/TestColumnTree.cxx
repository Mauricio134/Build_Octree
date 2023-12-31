// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkDataSetAttributes.h"
#include "vtkDoubleArray.h"
#include "vtkMutableDirectedGraph.h"
#include "vtkNew.h"
#include "vtkStringArray.h"
#include "vtkTable.h"
#include "vtkTree.h"
#include "vtkTreeHeatmapItem.h"

#include "vtkContextInteractorStyle.h"
#include "vtkContextMouseEvent.h"
#include "vtkContextScene.h"
#include "vtkContextTransform.h"
#include "vtkContextView.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"

#include "vtkRegressionTestImage.h"

//------------------------------------------------------------------------------
int TestColumnTree(int argc, char* argv[])
{
  // Construct a tree
  vtkNew<vtkMutableDirectedGraph> graph;
  vtkIdType root = graph->AddVertex();
  vtkIdType internalOne = graph->AddChild(root);
  vtkIdType internalTwo = graph->AddChild(internalOne);
  vtkIdType a = graph->AddChild(internalTwo);
  vtkIdType b = graph->AddChild(internalTwo);
  vtkIdType c = graph->AddChild(internalOne);

  vtkNew<vtkDoubleArray> weights;
  weights->SetNumberOfTuples(5);
  weights->SetValue(graph->GetEdgeId(root, internalOne), 1.0f);
  weights->SetValue(graph->GetEdgeId(internalOne, internalTwo), 2.0f);
  weights->SetValue(graph->GetEdgeId(internalTwo, a), 1.0f);
  weights->SetValue(graph->GetEdgeId(internalTwo, b), 1.0f);
  weights->SetValue(graph->GetEdgeId(internalOne, c), 3.0f);

  weights->SetName("weight");
  graph->GetEdgeData()->AddArray(weights);

  vtkNew<vtkStringArray> names;
  names->SetNumberOfTuples(6);
  names->SetValue(a, "a");
  names->SetValue(b, "b");
  names->SetValue(c, "c");

  names->SetName("node name");
  graph->GetVertexData()->AddArray(names);

  vtkNew<vtkDoubleArray> nodeWeights;
  nodeWeights->SetNumberOfTuples(6);
  nodeWeights->SetValue(root, 0.0f);
  nodeWeights->SetValue(internalOne, 1.0f);
  nodeWeights->SetValue(internalTwo, 3.0f);
  nodeWeights->SetValue(a, 4.0f);
  nodeWeights->SetValue(b, 4.0f);
  nodeWeights->SetValue(c, 4.0f);
  nodeWeights->SetName("node weight");
  graph->GetVertexData()->AddArray(nodeWeights);

  vtkNew<vtkTree> tree;
  tree->ShallowCopy(graph);

  vtkNew<vtkTree> tree2;
  tree2->DeepCopy(tree);

  // Construct a table
  vtkNew<vtkTable> table;
  vtkNew<vtkStringArray> tableNames;
  vtkNew<vtkDoubleArray> m1;
  vtkNew<vtkDoubleArray> m2;
  vtkNew<vtkDoubleArray> m3;

  tableNames->SetNumberOfTuples(3);
  tableNames->SetValue(0, "c");
  tableNames->SetValue(1, "b");
  tableNames->SetValue(2, "a");
  tableNames->SetName("name");

  m1->SetNumberOfTuples(3);
  m2->SetNumberOfTuples(3);
  m3->SetNumberOfTuples(3);

  m1->SetName("a");
  m2->SetName("b");
  m3->SetName("c");

  m1->SetValue(0, 1.0f);
  m1->SetValue(1, 3.0f);
  m1->SetValue(2, 1.0f);

  m2->SetValue(0, 2.0f);
  m2->SetValue(1, 2.0f);
  m2->SetValue(2, 2.0f);

  m3->SetValue(0, 3.0f);
  m3->SetValue(1, 1.0f);
  m3->SetValue(2, 3.0f);

  table->AddColumn(tableNames);
  table->AddColumn(m1);
  table->AddColumn(m2);
  table->AddColumn(m3);

  vtkNew<vtkTreeHeatmapItem> treeItem;
  treeItem->SetTree(tree);
  treeItem->SetColumnTree(tree2);
  treeItem->SetTable(table);

  vtkNew<vtkContextTransform> trans;
  trans->SetInteractive(true);
  trans->AddItem(treeItem);

  // center the item within the render window
  trans->Translate(80, 25);
  trans->Scale(1.5, 1.5);

  vtkSmartPointer<vtkContextView> view = vtkSmartPointer<vtkContextView>::New();
  view->GetRenderWindow()->SetSize(400, 200);
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
  view->GetScene()->AddItem(trans);

  // Finally render the scene and compare the image to a reference image
  view->GetRenderWindow()->SetMultiSamples(0);
  view->GetRenderWindow()->Render();

  // collapse a column subtree
  vtkContextMouseEvent mouseEvent;
  mouseEvent.SetInteractor(view->GetInteractor());
  vtkVector2f pos;
  mouseEvent.SetButton(vtkContextMouseEvent::LEFT_BUTTON);
  pos.Set(62, 81);
  mouseEvent.SetPos(pos);
  treeItem->MouseDoubleClickEvent(mouseEvent);
  view->GetRenderWindow()->Render();

  int retVal = vtkRegressionTestImage(view->GetRenderWindow());
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    view->GetRenderWindow()->Render();
    view->GetInteractor()->Start();
    retVal = vtkRegressionTester::PASSED;
  }
  return !retVal;
}
