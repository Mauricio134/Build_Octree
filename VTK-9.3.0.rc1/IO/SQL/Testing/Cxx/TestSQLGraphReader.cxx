// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov

#include "vtkActor.h"
#include "vtkGraphMapper.h"
#include "vtkMath.h"
#include "vtkRegressionTestImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include "vtkSQLGraphReader.h"
#include "vtkSQLQuery.h"
#include "vtkSQLiteDatabase.h"
#include "vtkSmartPointer.h"

#include <sstream>

#define VTK_CREATE(type, name) vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

int TestSQLGraphReader(int argc, char* argv[])
{
  vtkIdType vertices = 10;

  // Create a SQLite in-memory database
  VTK_CREATE(vtkSQLiteDatabase, database);
  database->SetDatabaseFileName(":memory:");

  bool ok = database->Open("");
  if (!ok)
  {
    cerr << "Could not open database!" << endl;
    cerr << database->GetLastErrorText() << endl;
    return 1;
  }

  // Build a graph
  vtkSmartPointer<vtkSQLQuery> q;
  q.TakeReference(database->GetQueryInstance());
  std::ostringstream oss;

  q->SetQuery("DROP TABLE IF EXISTS vertices");
  q->Execute();

  q->SetQuery("CREATE TABLE vertices (id INTEGER, x FLOAT, y FLOAT)");
  q->Execute();
  for (int i = 0; i < vertices; i++)
  {
    oss.str("");
    oss << "INSERT INTO vertices VALUES(" << i << ", "
        << 0.5 * cos(i * 2.0 * vtkMath::Pi() / vertices) << ", "
        << 0.5 * sin(i * 2.0 * vtkMath::Pi() / vertices) << ")" << endl;
    q->SetQuery(oss.str().c_str());
    q->Execute();
  }

  q->SetQuery("DROP TABLE IF EXISTS edges");
  q->Execute();

  q->SetQuery("CREATE TABLE edges (id INTEGER, source INTEGER, target INTEGER)");
  q->Execute();
  for (int i = 0; i < vertices; i++)
  {
    oss.str("");
    oss << "INSERT INTO edges VALUES(" << 2 * i + 0 << ", " << i << ", " << (i + 1) % vertices
        << ")" << endl;
    q->SetQuery(oss.str().c_str());
    q->Execute();
    oss.str("");
    oss << "INSERT INTO edges VALUES(" << 2 * i + 1 << ", " << (i + 3) % vertices << ", " << i
        << ")" << endl;
    q->SetQuery(oss.str().c_str());
    q->Execute();
  }

  // Set up graph reader
  VTK_CREATE(vtkSQLGraphReader, reader);
  vtkSmartPointer<vtkSQLQuery> edgeQuery;
  edgeQuery.TakeReference(database->GetQueryInstance());
  edgeQuery->SetQuery("select * from edges");
  reader->SetEdgeQuery(edgeQuery);

  vtkSmartPointer<vtkSQLQuery> vertexQuery;
  vertexQuery.TakeReference(database->GetQueryInstance());
  vertexQuery->SetQuery("select * from vertices");
  reader->SetVertexQuery(vertexQuery);

  reader->SetSourceField("source");
  reader->SetTargetField("target");
  reader->SetVertexIdField("id");
  reader->SetXField("x");
  reader->SetYField("y");

  // Display the graph
  VTK_CREATE(vtkGraphMapper, mapper);
  mapper->SetInputConnection(reader->GetOutputPort());
  mapper->SetEdgeColorArrayName("id");
  mapper->ColorEdgesOn();
  mapper->SetVertexColorArrayName("id");
  mapper->ColorVerticesOn();
  VTK_CREATE(vtkActor, actor);
  actor->SetMapper(mapper);
  VTK_CREATE(vtkRenderer, ren);
  ren->AddActor(actor);
  VTK_CREATE(vtkRenderWindowInteractor, iren);
  VTK_CREATE(vtkRenderWindow, win);
  win->AddRenderer(ren);
  win->SetInteractor(iren);

  int retVal = vtkRegressionTestImage(win);
  if (retVal == vtkRegressionTester::DO_INTERACTOR)
  {
    iren->Initialize();
    iren->Start();

    retVal = vtkRegressionTester::PASSED;
  }

  return !retVal;
}
