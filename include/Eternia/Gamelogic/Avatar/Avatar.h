//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Avatar_h_
#define Avatar_h_

enum AvatarTYPE {AT_Player, AT_AI, AT_Static, AT_Mob, AT_Boss};
enum DAMAGERESULT {DR_MISS, DR_HIT, DR_KILL};
enum StudyTYPE {ST_Book, ST_Circuit, ST_Blacksmith, ST_Gunnery, ST_Ballistic, ST_Laser, ST_Engines, ST_Buildings, ST_ShipCore};


// Ah, the art of abstraction.
#include "AvatarHealth.h"
#include "AvatarGear.h"
#include "AvatarAppearance.h"
#include "SkillSet.h"
#include "../Location.h"
#include "../../Math/struct/vertex.h"
#include "../../Data/Protect/PType.hpp"
#include "../Crafting/CraftingStats.h"
#include "../../Serialization/SpecificSerializer.h"


// The Avatar is a Player/Monster/NPC, who will level skills and attributes.
// Monsters can also level up depending on their faction.
// i.e: Lions will kill deer and get stronger.

// When a player logs out, an AI takes over. This is mostly for base defense and health/hunger/thirst.

// Third person is based on a floating drone around character. If drone is shot down, TP is disabled.

class Avatar : public SpecificSerializer {
    public:
        Avatar(); // define all parameters

        void doAnimation(); // do a defined action. (Dance, hit, die, ect.)

        // Manage attributes
        void addDisease(Disease* d); // diseases act like debuffs, but for long-periods
        //void addSkill(Skill* s);

        // Physical character effects
        DAMAGERESULT damage(BODYPART part, double k); // damage this character with k damage (note: defenses are taken into account)
        DAMAGERESULT damageOther(Avatar* a, BODYPART part, double k); // damage another character with k damage (note: defenses are taken into account)

        void tick(double t); // game tick, evaluate avatar health, equips, skills, ect.

        void loadStats(CharString statsString); // load stats directly from a string.
        CharString getStats(); // retrive stats to a string.

        double calcAvatarExp(Avatar* av); // calculate exp based on Avatar's stats.
        void killAvatar(Avatar* av); // Player/NPC/Monster kills another. EXP is calculated then distributed.

        void Die(); // this avatar dies (Test for clones if Player or NPC)

        // Study an item, increases intelligence and insight.
        // Parts studied are put into crafting skills.
        void study(StudyTYPE st, double value);

    //private:
        // Base attributes
        CharString name;
        AvatarTYPE type;
        AvatarGear gear; // equiped gear
        CraftingStats crafting; // crafting stats
        AvatarHealth health; // Advanced Health class that includes physiology, diseases, ect.
        AvatarAppearance appearance;
        SkillSet skills;

        Location loc; // current location



        PType<bool> hasDrone, hasShield;
};

#endif
