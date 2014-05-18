//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Planet.h"

Planet::Planet()
{
    seed = 0;
}

Planet::~Planet()
{
}

// Returns a list of verticies that enables for super-low poly planet models from far away. 
//      Up close, a high-poly planet is generated.
LinkedList<vertex>* Planet::listOfVerticies(int MIPLevel){
    // include Terrain generator
}
