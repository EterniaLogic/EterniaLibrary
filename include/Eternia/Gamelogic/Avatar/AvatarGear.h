//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef AvatarGear_h_
#define AvatarGear_h_

#include "../Inventory/BaseInventory.h"
#include "../Inventory/DynamicEquip.h"

enum GEAR_Placement {GEARP_Helmet, GEARP_ChestPlate, GEARP_Arm, GEARP_Back, GEARP_Wrist, GEARP_Hand, GEARP_Abdomen, GEARP_Leg, GEARP_Shin, GEARP_Foot, GEARP_FINGER};
enum GEAR_SIDE {GEARSIDE_LEFT, GEARSIDE_RIGHT};

// Helper to define the mounting positions on the character
class MountedEquip
{
public:
  MountedEquip();
  
private:
  DynamicEquip* gear;
  GEAR_Placement location;
  GEAR_SIDE side;
  int PlacementNumber; // Used for rings and earings, each hand can have 5 rings
}

// Main Gear class
class AvatarGear
{
private:
  LinkedList<BaseInventory>* bags;
  LinkedList<MountedEquip>* mountedGear;
};

#endif