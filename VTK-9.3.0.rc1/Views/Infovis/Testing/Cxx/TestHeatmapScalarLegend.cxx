// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#include "vtkHeatmapItem.h"
#include "vtkIntArray.h"
#include "vtkNew.h"
#include "vtkStringArray.h"
#include "vtkTable.h"

#include "vtkContextMouseEvent.h"
#include "vtkContextScene.h"
#include "vtkContextTransform.h"
#include "vtkContextView.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"

#include "vtkRegressionTestImage.h"

//------------------------------------------------------------------------------
int TestHeatmapScalarLegend(int argc, char* argv[])
{
  vtkNew<vtkTable> table;
  vtkNew<vtkStringArray> tableNames;
  vtkNew<vtkIntArray> column;

  tableNames->SetNumberOfTuples(3);
  tableNames->SetValue(0, "3");
  tableNames->SetValue(1, "2");
  tableNames->SetValue(2, "1");
  tableNames->SetName("names");

  column->SetNumberOfTuples(3);
  column->SetName("values");
  column->SetValue(0, 3);
  column->SetValue(1, 2);
  column->SetValue(2, 1);

  table->AddColumn(tableNames);
  table->AddColumn(column);

  vtkNew<vtkHeatmapItem> heatmap;
  heatmap->SetTable(table);

  vtkNew<vtkContextTransform> trans;
  trans->SetInteractive(true);
  trans->AddItem(heatmap);
  trans->Translate(125, 125);

  vtkNew<vtkContextView> contextView;
  contextView->GetScene()->AddItem(trans);

  contextView->GetRenderWindow()->SetMultiSamples(0);
  contextView->GetRenderWindow()->Render();

  // double click to display the color legend
  vtkContextMouseEvent mouseEvent;
  mouseEvent.SetInteractor(contextView->GetInteractor());
  vtkVector2f pos;
  mouseEvent.SetButton(vtkContextMouseEvent::LEFT_BUTTON);
  pos.Set(16, 38);
  mouseEvent.SetPos(pos);
  heatmap->MouseDoubleClickEvent(mouseEvent);
  contextView->GetRenderWindow()->Render();

  int retVal = vtkRegressionTestImage(contextView->GetRenderWindow());
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    contextView->GetRenderWindow()->Render();
    contextView->GetInteractor()->Start();
    retVal = vtkRegressionTester::PASSED;
  }
  return !retVal;
}
