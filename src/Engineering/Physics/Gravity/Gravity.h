//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "../../../Math/struct/vector.h"

//helps find the Center of Gravity!
// summation M * x / summantion M
// M = mass, x = location of x. change to y if doing multiple axes.

namespace physical
{
    findCenterOfGravity(LinkedListT* list); // list of ../math/vector.h
    gravityBetweenMasses(vector* a, vector* b, double massA, double massB);
}
