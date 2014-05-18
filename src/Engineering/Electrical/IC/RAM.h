//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef ICRAM_h_
#define ICRAM_h_

#include "IC.h"

// Direct RAM access. Simulates RAM memory structure using managed C++

class RAM: private IC
{
public:
  RAM(long size); // defines maximum size of this RAM.
  virtual ~RAM();
  
  void setPower(PowerValue* value); // Sets the input power value
};

#endif  