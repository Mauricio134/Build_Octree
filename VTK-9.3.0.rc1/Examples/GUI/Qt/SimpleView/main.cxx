// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-FileCopyrightText: Copyright 2007 Sandia Corporation
// SPDX-License-Identifier: LicenseRef-BSD-3-Clause-Sandia-USGov
// QT includes
#include <QtGui/QSurfaceFormat>
#include <QtWidgets/QApplication>

#include "QVTKRenderWidget.h"
#include "SimpleView.h"

extern int qInitResources_icons();

int main(int argc, char** argv)
{
  // needed to ensure appropriate OpenGL context is created for VTK rendering.
  QSurfaceFormat::setDefaultFormat(QVTKRenderWidget::defaultFormat());

  // QT Stuff
  QApplication app(argc, argv);

  QApplication::setStyle("fusion");

  qInitResources_icons();

  SimpleView mySimpleView;
  mySimpleView.show();

  return app.exec();
}
