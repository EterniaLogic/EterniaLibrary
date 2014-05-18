//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#include "Pin.h" 

Pin::Pin(CharString* PinName, PowerValue* value){
  name = PinName;
  val = value;
}

Pin::~Pin(){}