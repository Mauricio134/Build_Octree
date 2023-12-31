// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

// Charts includes
#include "vtkChartXY.h"
#include "vtkColorTransferControlPointsItem.h"
#include "vtkColorTransferFunction.h"
#include "vtkContextInteractorStyle.h"
#include "vtkContextScene.h"
#include "vtkControlPointsItem.h"

// Common includes"
#include "vtkIdTypeArray.h"
#include "vtkInteractorEventRecorder.h"
#include "vtkNew.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"

// STD includes
#include <iostream>
#include <map>

//------------------------------------------------------------------------------
class vtkTFCallback : public vtkCommand
{
public:
  static vtkTFCallback* New() { return new vtkTFCallback; }

  vtkTFCallback() = default;

  void Execute(vtkObject* caller, unsigned long event, void* vtkNotUsed(callData)) override
  {
    vtkColorTransferFunction* self = reinterpret_cast<vtkColorTransferFunction*>(caller);
    if (!self)
    {
      return;
    }
    if (this->EventSpy.count(event) == 0)
    {
      this->EventSpy[event] = 0;
    }
    ++this->EventSpy[event];
    std::cout << "InvokedEvent: " << event << this->EventSpy[event] << std::endl;
  }
  std::map<unsigned long, int> EventSpy;
};

//------------------------------------------------------------------------------
int TestControlPointsItemEvents(int, char*[])
{
  vtkNew<vtkColorTransferFunction> transferFunction;
  transferFunction->AddHSVSegment(50., 0., 1., 1., 85., 0.3333, 1., 1.);
  transferFunction->AddHSVSegment(85., 0.3333, 1., 1., 170., 0.6666, 1., 1.);
  transferFunction->AddHSVSegment(170., 0.6666, 1., 1., 200., 0., 1., 1.);

  vtkNew<vtkTFCallback> cbk;
  transferFunction->AddObserver(vtkCommand::StartEvent, cbk);
  transferFunction->AddObserver(vtkCommand::ModifiedEvent, cbk);
  transferFunction->AddObserver(vtkCommand::EndEvent, cbk);
  transferFunction->AddObserver(vtkCommand::StartInteractionEvent, cbk);
  transferFunction->AddObserver(vtkCommand::InteractionEvent, cbk);
  transferFunction->AddObserver(vtkCommand::EndInteractionEvent, cbk);

  vtkNew<vtkColorTransferControlPointsItem> controlPoints;
  controlPoints->SetColorTransferFunction(transferFunction);

  vtkNew<vtkChartXY> chart;
  chart->AddPlot(controlPoints);

  vtkNew<vtkContextScene> scene;
  scene->AddItem(controlPoints);

  vtkNew<vtkContextInteractorStyle> interactorStyle;
  interactorStyle->SetScene(scene);

  vtkNew<vtkRenderWindowInteractor> iren;
  iren->SetInteractorStyle(interactorStyle);

  vtkNew<vtkInteractorEventRecorder> recorder;
  recorder->SetInteractor(iren);
  recorder->ReadFromInputStringOn();

  // Add a point at (60, 0.5) and move it to (62, 0.5)
  const char addAndDragEvents[] = "# StreamVersion 1\n"
                                  "LeftButtonPressEvent 60 1 0 0 0 0 0\n"
                                  "MouseMoveEvent 62 1 0 0 0 0 0\n"
                                  "LeftButtonReleaseEvent 62 1 0 0 0 0 0\n";
  recorder->SetInputString(addAndDragEvents);
  recorder->Play();

  // 1 ModifiedEvent for adding a point
  // 1 ModifiedEvent for moving the point
  if (cbk->EventSpy[vtkCommand::ModifiedEvent] != 2 ||
    cbk->EventSpy[vtkCommand::StartInteractionEvent] != 1 ||
    cbk->EventSpy[vtkCommand::InteractionEvent] != 1 ||
    cbk->EventSpy[vtkCommand::EndInteractionEvent] != 1 ||
    cbk->EventSpy[vtkCommand::StartEvent] != 2 || cbk->EventSpy[vtkCommand::EndEvent] != 2)
  {
    std::cerr << "Wrong number of fired events : " << cbk->EventSpy[vtkCommand::ModifiedEvent]
              << " " << cbk->EventSpy[vtkCommand::StartInteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::InteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::EndInteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::StartEvent] << " " << cbk->EventSpy[vtkCommand::EndEvent]
              << std::endl;
    return EXIT_FAILURE;
  }
  cbk->EventSpy.clear();
  // Move all the points to the right.
  controlPoints->MovePoints(vtkVector2f(5, 0.));
  // One ModifiedEvent for each moved point

  if (cbk->EventSpy[vtkCommand::ModifiedEvent] > controlPoints->GetNumberOfPoints() ||
    cbk->EventSpy[vtkCommand::StartInteractionEvent] != 0 ||
    cbk->EventSpy[vtkCommand::InteractionEvent] != 0 ||
    cbk->EventSpy[vtkCommand::EndInteractionEvent] != 0 ||
    cbk->EventSpy[vtkCommand::StartEvent] != 1 || cbk->EventSpy[vtkCommand::EndEvent] != 1)
  {
    std::cerr << "Wrong number of fired events : " << cbk->EventSpy[vtkCommand::ModifiedEvent]
              << " " << cbk->EventSpy[vtkCommand::StartInteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::InteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::EndInteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::StartEvent] << " " << cbk->EventSpy[vtkCommand::EndEvent]
              << std::endl;
    return EXIT_FAILURE;
  }

  cbk->EventSpy.clear();

  const char dblClickEvents[] =
    "# StreamVersion 1\n"
    "MouseMoveEvent 56 1 0 0 0 0 0\n"       // shouldn't move the point
    "LeftButtonPressEvent 55 1 0 0 0 0 0\n" // select the first point
    "LeftButtonReleaseEvent 55 1 0 0 0 0 0\n"
    "LeftButtonPressEvent 55 1 0 0 0 1 0\n"   // dbl click
    "LeftButtonReleaseEvent 55 1 0 0 0 0 0\n" // must be followed by release
    ;

  recorder->SetInputString(dblClickEvents);
  recorder->Play();

  if (cbk->EventSpy[vtkCommand::ModifiedEvent] != 0 ||
    cbk->EventSpy[vtkCommand::StartInteractionEvent] != 0 ||
    cbk->EventSpy[vtkCommand::InteractionEvent] != 0 ||
    cbk->EventSpy[vtkCommand::EndInteractionEvent] != 0 ||
    cbk->EventSpy[vtkCommand::StartEvent] != 0 || cbk->EventSpy[vtkCommand::EndEvent] != 0)
  {
    std::cerr << "Wrong number of fired events : " << cbk->EventSpy[vtkCommand::ModifiedEvent]
              << " " << cbk->EventSpy[vtkCommand::StartInteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::InteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::EndInteractionEvent] << " "
              << cbk->EventSpy[vtkCommand::StartEvent] << " " << cbk->EventSpy[vtkCommand::EndEvent]
              << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
