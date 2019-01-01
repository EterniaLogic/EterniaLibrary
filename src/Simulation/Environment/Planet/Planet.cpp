//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Planet.h"

Planet::Planet(long long seed, long long seed2) {
   terrain = Terrain(seed,seed2);
   atmosphere = Atmosphere(seed,seed2);
}

Planet::~Planet() {
}
