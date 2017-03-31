//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

//include all of the gamelogic subsystems

// npc artificial intelligence
#include "AI/AI.h"
#include "AI/AIAttack.h"
#include "AI/AICommand.h"
#include "AI/AIDecide.h"
#include "AI/AIMovement.h"
#include "AI/AIUse.h"

// Player / NPC stats and skills
#include "Avatar/Avatar.h" // General Avatar
#include "Avatar/AvatarHealth.h" // Health and condition
#include "Avatar/Disease.h" // Diseases

// Inventories, Bags, ect.
#include "Inventory/BaseInventory.h"
#include "Inventory/DynamicAttribute.h"
#include "Inventory/DynamicEquip.h"
#include "Inventory/ItemBase.h"
