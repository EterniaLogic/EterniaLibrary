//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Government_h
#define Government_h

#include "../../Economics/Tax/Tax.h"
#include "../../Data/LinkedList.hpp"

#include "../Citizen.h"
#include "GovernmentBranch.h"


class Government
{
    Tax taxes;
    LinkedList<Citizen> citizens; // list of citizens living in this government (Effectively online)
    LinkedList<GovernmentBranch> branches; // list of government power sectors (branches of government)
public:
    Government();
};

#endif
