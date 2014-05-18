//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef Wire_h_
#define Wire_h_ 

#include "ComponentRating.h"

// Wires are used to connect components together.
// This is used like a Graph

class Wire
{
public:
  Wire(Component* A, Component* B, double Resistance);
  virtual ~Wire();
  
private:
  Component* comp_a; // First component
  Component* comp_b; // Second component
  double resist; // Resistivity of this wire
  
  
};

#endif