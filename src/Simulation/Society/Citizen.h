//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Citizen_h
#define Citizen_h

#include "../../Data/includes.h"
#include "../Location.h"
#include "../Business/AssetHolder.h"
#include "Race.h"

#ifndef Government_h
#include "Government/Government.h"
#else
class Government;
#endif

// Provide Social details. Used for chat systems, governments, friendships, guilds, ect.
class Citizen : public AssetHolder{
    double IncomeTotal; // Used for income taxes! :D
    double assetsTotal; // Personal net worth
    Race *race;
    
    
    LinkedList<Citizen> children;
    LinkedList<Citizen> spouse; // can have multiple spouses
    Government* gov;
    
    Location loc;
    
public:
    Citizen();
    virtual ~Citizen();
};

#endif
