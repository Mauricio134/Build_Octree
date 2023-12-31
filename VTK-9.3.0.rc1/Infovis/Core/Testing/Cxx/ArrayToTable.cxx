// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2008 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov

#include <vtkAbstractArray.h>
#include <vtkArrayData.h>
#include <vtkArrayToTable.h>
#include <vtkDenseArray.h>
#include <vtkSmartPointer.h>
#include <vtkSparseArray.h>
#include <vtkTable.h>

#include <iostream>
#include <stdexcept>

#define test_expression(expression)                                                                \
  do                                                                                               \
  {                                                                                                \
    if (!(expression))                                                                             \
      throw std::runtime_error("Expression failed: " #expression);                                 \
  } while (false)

int ArrayToTable(int vtkNotUsed(argc), char* vtkNotUsed(argv)[])
{
  try
  {
    vtkSmartPointer<vtkDenseArray<vtkStdString>> a =
      vtkSmartPointer<vtkDenseArray<vtkStdString>>::New();
    a->Resize(2);
    a->SetValue(0, "Howdy");
    a->SetValue(1, "World!");

    vtkSmartPointer<vtkArrayData> b = vtkSmartPointer<vtkArrayData>::New();
    b->AddArray(a);

    vtkSmartPointer<vtkArrayToTable> c = vtkSmartPointer<vtkArrayToTable>::New();
    c->SetInputData(0, b);
    c->Update();

    test_expression(c->GetOutput()->GetNumberOfColumns() == 1);
    test_expression(c->GetOutput()->GetNumberOfRows() == 2);
    test_expression(vtkStdString(c->GetOutput()->GetColumn(0)->GetName()).empty());
    test_expression(c->GetOutput()->GetValue(0, 0).ToString() == "Howdy");
    test_expression(c->GetOutput()->GetValue(1, 0).ToString() == "World!");

    vtkSmartPointer<vtkSparseArray<double>> d = vtkSmartPointer<vtkSparseArray<double>>::New();
    d->Resize(2, 2);
    d->SetValue(0, 0, 1.0);
    d->SetValue(1, 1, 2.0);

    vtkSmartPointer<vtkArrayData> e = vtkSmartPointer<vtkArrayData>::New();
    e->AddArray(d);

    vtkSmartPointer<vtkArrayToTable> f = vtkSmartPointer<vtkArrayToTable>::New();
    f->SetInputData(0, e);
    f->Update();

    test_expression(f->GetOutput()->GetNumberOfColumns() == 2);
    test_expression(f->GetOutput()->GetNumberOfRows() == 2);
    test_expression(vtkStdString(f->GetOutput()->GetColumn(0)->GetName()) == "0");
    test_expression(vtkStdString(f->GetOutput()->GetColumn(1)->GetName()) == "1");
    test_expression(f->GetOutput()->GetValue(0, 0).ToDouble() == 1.0);
    test_expression(f->GetOutput()->GetValue(0, 1).ToDouble() == 0.0);
    test_expression(f->GetOutput()->GetValue(1, 0).ToDouble() == 0.0);
    test_expression(f->GetOutput()->GetValue(1, 1).ToDouble() == 2.0);

    return 0;
  }
  catch (std::exception& e)
  {
    cerr << e.what() << endl;
    return 1;
  }
}
