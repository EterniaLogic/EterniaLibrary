//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Government_h
#define Government_h

//#include "../../../include.h"
#include "../../../Data/includes.h"

#ifndef Citizen_h
#include "../Citizen.h"
#else
class Citizen;
#endif

enum GOV_SLAVERY {GOV_SLAV_ALIENS, GOV_SLAV_ANY, GOV_SLAV_CRIME, GOV_SLAV_BANNED, GOV_SLAV_INHERITED};
enum GOV_FAMILY {GOV_FAM_INHERITED, GOV_FAM_UNITS, GOV_FAM_CLANS, GOV_FAM_FREE};
enum GOV_SPECIAL_RIGHTS {GOV_SRIGHTS_INHERITED, GOV_SRIGHTS_ARISTOCRACY};
enum GOV_RELIGION {GOV_RELIGION_STATE, GOV_RELIGION_MIXED, GOV_RELIGION_SECULARISM};

enum GOV_TYPE {GT_ANARCHY, GT_DEMOCRACY, GT_MONARCHY, GT_THEOCRACY};

class Government {
    //Tax taxes;
    LinkedList<Citizen> citizens; // list of citizens living in this government (Effectively online)
    LinkedList<Government> branches; // list of government power sectors (branches of government)
    
    // Social Policies
    GOV_SLAVERY slavery;
    GOV_FAMILY family;
    GOV_SPECIAL_RIGHTS specrights;
    GOV_RELIGION religion;
    
    // Tax Policies
    
    
public:
    Government();
    virtual ~Government();
};

#endif
