// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause
#include "vtkWidgetEventTranslator.h"
#include "vtkAbstractWidget.h"
#include "vtkCallbackCommand.h"
#include "vtkCommand.h"
#include "vtkEvent.h"
#include "vtkEventData.h"
#include "vtkObjectFactory.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkSmartPointer.h"
#include "vtkWidgetEvent.h"
#include <list>
#include <map>

VTK_ABI_NAMESPACE_BEGIN
vtkStandardNewMacro(vtkWidgetEventTranslator);

// This is what is place in the list
struct EventItem
{
  vtkSmartPointer<vtkEvent> VTKEvent;
  unsigned long WidgetEvent;
  vtkEventData* EventData = nullptr;
  bool HasData = false;

  EventItem(vtkEvent* e, unsigned long we)
  {
    this->VTKEvent = e;
    this->WidgetEvent = we;
    this->HasData = false;
  }
  EventItem(vtkEventData* edata, unsigned long we)
  {
    this->EventData = edata;
    this->EventData->Register(nullptr);
    this->WidgetEvent = we;
    this->HasData = true;
  }
  ~EventItem()
  {
    if (this->HasData && this->EventData)
    {
      this->EventData->UnRegister(nullptr);
      this->EventData = nullptr;
    }
  }

  EventItem(const EventItem& v)
  {
    this->VTKEvent = v.VTKEvent;
    this->WidgetEvent = v.WidgetEvent;
    this->HasData = v.HasData;
    this->EventData = v.EventData;
    if (this->HasData && this->EventData)
    {
      this->EventData->Register(nullptr);
    }
  }

private:
  EventItem() = delete;
};

// A list of events
struct EventList : public std::list<EventItem>
{
  unsigned long find(unsigned long VTKEvent)
  {
    std::list<EventItem>::iterator liter = this->begin();
    for (; liter != this->end(); ++liter)
    {
      if (VTKEvent == liter->VTKEvent->GetEventId())
      {
        return liter->WidgetEvent;
      }
    }
    return vtkWidgetEvent::NoEvent;
  }

  unsigned long find(vtkEvent* VTKEvent)
  {
    std::list<EventItem>::iterator liter = this->begin();
    for (; liter != this->end(); ++liter)
    {
      if (*VTKEvent == liter->VTKEvent)
      {
        return liter->WidgetEvent;
      }
    }
    return vtkWidgetEvent::NoEvent;
  }

  unsigned long find(vtkEventData* edata)
  {
    std::list<EventItem>::iterator liter = this->begin();
    for (; liter != this->end(); ++liter)
    {
      if (liter->HasData && *edata == *liter->EventData)
      {
        return liter->WidgetEvent;
      }
    }
    return vtkWidgetEvent::NoEvent;
  }

  // Remove a mapping
  int Remove(vtkEvent* VTKEvent)
  {
    std::list<EventItem>::iterator liter = this->begin();
    for (; liter != this->end(); ++liter)
    {
      if (*VTKEvent == liter->VTKEvent)
      {
        this->erase(liter);
        return 1;
      }
    }
    return 0;
  }
  int Remove(vtkEventData* edata)
  {
    std::list<EventItem>::iterator liter = this->begin();
    for (; liter != this->end(); ++liter)
    {
      if (liter->HasData && *edata == *liter->EventData)
      {
        this->erase(liter);
        return 1;
      }
    }
    return 0;
  }
};

// A STL map used to translate VTK events into lists of events. The reason
// that we have this list is because of the modifiers on the event. The
// VTK event id maps to the list, and then comparisons are done to
// determine which event matches.
class vtkEventMap : public std::map<unsigned long, EventList>
{
};
typedef std::map<unsigned long, EventList>::iterator EventMapIterator;

//------------------------------------------------------------------------------
vtkWidgetEventTranslator::vtkWidgetEventTranslator()
{
  this->EventMap = new vtkEventMap;
  this->Event = vtkEvent::New();
}

//------------------------------------------------------------------------------
vtkWidgetEventTranslator::~vtkWidgetEventTranslator()
{
  delete this->EventMap;
  this->Event->Delete();
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::SetTranslation(unsigned long VTKEvent, unsigned long widgetEvent)
{
  vtkSmartPointer<vtkEvent> e = vtkSmartPointer<vtkEvent>::New();
  e->SetEventId(VTKEvent); // default modifiers
  if (widgetEvent != vtkWidgetEvent::NoEvent)
  {
    (*this->EventMap)[VTKEvent].push_back(EventItem(e, widgetEvent));
  }
  else
  {
    this->RemoveTranslation(e);
  }
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::SetTranslation(const char* VTKEvent, const char* widgetEvent)
{
  this->SetTranslation(
    vtkCommand::GetEventIdFromString(VTKEvent), vtkWidgetEvent::GetEventIdFromString(widgetEvent));
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::SetTranslation(unsigned long VTKEvent, int modifier, char keyCode,
  int repeatCount, const char* keySym, unsigned long widgetEvent)
{
  vtkSmartPointer<vtkEvent> e = vtkSmartPointer<vtkEvent>::New();
  e->SetEventId(VTKEvent);
  e->SetModifier(modifier);
  e->SetKeyCode(keyCode);
  e->SetRepeatCount(repeatCount);
  e->SetKeySym(keySym);
  if (widgetEvent != vtkWidgetEvent::NoEvent)
  {
    (*this->EventMap)[VTKEvent].push_back(EventItem(e, widgetEvent));
  }
  else
  {
    this->RemoveTranslation(e);
  }
}

void vtkWidgetEventTranslator::SetTranslation(
  unsigned long VTKEvent, vtkEventData* edata, unsigned long widgetEvent)
{
  if (widgetEvent != vtkWidgetEvent::NoEvent)
  {
    (*this->EventMap)[VTKEvent].push_back(EventItem(edata, widgetEvent));
  }
  else
  {
    this->RemoveTranslation(edata);
  }
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::SetTranslation(vtkEvent* VTKEvent, unsigned long widgetEvent)
{
  if (widgetEvent != vtkWidgetEvent::NoEvent)
  {
    (*this->EventMap)[VTKEvent->GetEventId()].push_back(EventItem(VTKEvent, widgetEvent));
  }
  else
  {
    this->RemoveTranslation(VTKEvent);
  }
}

//------------------------------------------------------------------------------
unsigned long vtkWidgetEventTranslator::GetTranslation(unsigned long VTKEvent)
{
  EventMapIterator iter = this->EventMap->find(VTKEvent);
  if (iter != this->EventMap->end())
  {
    EventList& elist = (*iter).second;
    return elist.find(VTKEvent);
  }
  else
  {
    return vtkWidgetEvent::NoEvent;
  }
}

//------------------------------------------------------------------------------
const char* vtkWidgetEventTranslator::GetTranslation(const char* VTKEvent)
{
  return vtkWidgetEvent::GetStringFromEventId(
    this->GetTranslation(vtkCommand::GetEventIdFromString(VTKEvent)));
}

//------------------------------------------------------------------------------
unsigned long vtkWidgetEventTranslator::GetTranslation(
  unsigned long VTKEvent, int modifier, char keyCode, int repeatCount, const char* keySym)
{
  EventMapIterator iter = this->EventMap->find(VTKEvent);
  if (iter != this->EventMap->end())
  {
    this->Event->SetEventId(VTKEvent);
    this->Event->SetModifier(modifier);
    this->Event->SetKeyCode(keyCode);
    this->Event->SetRepeatCount(repeatCount);
    this->Event->SetKeySym(keySym);
    EventList& elist = (*iter).second;
    return elist.find(this->Event);
  }
  return vtkWidgetEvent::NoEvent;
}

//------------------------------------------------------------------------------
unsigned long vtkWidgetEventTranslator::GetTranslation(unsigned long, vtkEventData* edata)
{
  EventMapIterator iter = this->EventMap->find(edata->GetType());
  if (iter != this->EventMap->end())
  {
    EventList& elist = (*iter).second;
    return elist.find(edata);
  }
  return vtkWidgetEvent::NoEvent;
}

//------------------------------------------------------------------------------
unsigned long vtkWidgetEventTranslator::GetTranslation(vtkEvent* VTKEvent)
{
  EventMapIterator iter = this->EventMap->find(VTKEvent->GetEventId());
  if (iter != this->EventMap->end())
  {
    EventList& elist = (*iter).second;
    return elist.find(VTKEvent);
  }
  else
  {
    return vtkWidgetEvent::NoEvent;
  }
}

//------------------------------------------------------------------------------
int vtkWidgetEventTranslator::RemoveTranslation(
  unsigned long VTKEvent, int modifier, char keyCode, int repeatCount, const char* keySym)
{
  vtkSmartPointer<vtkEvent> e = vtkSmartPointer<vtkEvent>::New();
  e->SetEventId(VTKEvent);
  e->SetModifier(modifier);
  e->SetKeyCode(keyCode);
  e->SetRepeatCount(repeatCount);
  e->SetKeySym(keySym);
  return this->RemoveTranslation(e);
}

//------------------------------------------------------------------------------
int vtkWidgetEventTranslator::RemoveTranslation(vtkEvent* e)
{
  EventMapIterator iter = this->EventMap->find(e->GetEventId());
  int numTranslationsRemoved = 0;
  if (iter != this->EventMap->end())
  {
    while (iter->second.Remove(e))
    {
      ++numTranslationsRemoved;
      iter = this->EventMap->find(e->GetEventId());
      if (iter == this->EventMap->end())
      {
        break;
      }
    }
  }

  return numTranslationsRemoved;
}

//------------------------------------------------------------------------------
int vtkWidgetEventTranslator::RemoveTranslation(vtkEventData* edata)
{
  EventMapIterator iter = this->EventMap->find(edata->GetType());
  int numTranslationsRemoved = 0;
  if (iter != this->EventMap->end())
  {
    while (iter->second.Remove(edata))
    {
      ++numTranslationsRemoved;
      iter = this->EventMap->find(edata->GetType());
      if (iter == this->EventMap->end())
      {
        break;
      }
    }
  }

  return numTranslationsRemoved;
}

//------------------------------------------------------------------------------
int vtkWidgetEventTranslator::RemoveTranslation(unsigned long VTKEvent)
{
  vtkSmartPointer<vtkEvent> e = vtkSmartPointer<vtkEvent>::New();
  e->SetEventId(VTKEvent);
  return this->RemoveTranslation(e);
}

//------------------------------------------------------------------------------
int vtkWidgetEventTranslator::RemoveTranslation(const char* VTKEvent)
{
  vtkSmartPointer<vtkEvent> e = vtkSmartPointer<vtkEvent>::New();
  e->SetEventId(vtkCommand::GetEventIdFromString(VTKEvent));
  return this->RemoveTranslation(e);
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::ClearEvents()
{
  EventMapIterator iter = this->EventMap->begin();
  for (; iter != this->EventMap->end(); ++iter)
  {
    EventList& elist = (*iter).second;
    elist.clear();
  }
  this->EventMap->clear();
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::AddEventsToInteractor(
  vtkRenderWindowInteractor* i, vtkCallbackCommand* command, float priority)
{
  EventMapIterator iter = this->EventMap->begin();
  for (; iter != this->EventMap->end(); ++iter)
  {
    i->AddObserver((*iter).first, command, priority);
  }
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::AddEventsToParent(
  vtkAbstractWidget* w, vtkCallbackCommand* command, float priority)
{
  EventMapIterator iter = this->EventMap->begin();
  for (; iter != this->EventMap->end(); ++iter)
  {
    w->AddObserver((*iter).first, command, priority);
  }
}

//------------------------------------------------------------------------------
void vtkWidgetEventTranslator::PrintSelf(ostream& os, vtkIndent indent)
{
  // Superclass typedef defined in vtkTypeMacro() found in vtkSetGet.h
  this->Superclass::PrintSelf(os, indent);

  // List all the events and their translations
  os << indent << "Event Table:\n";
  EventMapIterator iter = this->EventMap->begin();
  for (; iter != this->EventMap->end(); ++iter)
  {
    EventList& elist = (*iter).second;
    std::list<EventItem>::iterator liter = elist.begin();
    for (; liter != elist.end(); ++liter)
    {
      os << "VTKEvent(" << vtkCommand::GetStringFromEventId(liter->VTKEvent->GetEventId()) << ","
         << liter->VTKEvent->GetModifier() << "," << liter->VTKEvent->GetKeyCode() << ","
         << liter->VTKEvent->GetRepeatCount() << ",";
      os << (liter->VTKEvent->GetKeySym() ? liter->VTKEvent->GetKeySym() : "(any)");
      os << ") maps to " << vtkWidgetEvent::GetStringFromEventId(liter->WidgetEvent) << "\n";
    }
  }
}
VTK_ABI_NAMESPACE_END
