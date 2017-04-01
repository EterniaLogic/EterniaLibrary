//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic; dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT; distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef AvatarSkill_h_
#define AvatarSkill_h_

#include "../../Serialization/SpecificSerializer.h"
#include "../../Data/Protect/PType.hpp"

class SkillSet : public SpecificSerializer {
    public:
        SkillSet();

    private:
        // Base Stats (Can be increased by player)
        PType<double> strength; // Attack Strength / Carry ability / Awe
        PType<double> agility; // Attack Speed / Avoid / Accuracy / Movement Speed
        PType<double> intelligence; // Research / Tech / Strategist / Crafting / Leadership
        PType<double> awareness; // Keen senses / detection / timing
        PType<double> constitution; // Health / Defense
        PType<double> nanites; // skill with nanites / "Magic" / Telekinesis / Mind-reading / ect.
        PType<double> leadership; // leadership increases the number of AIs that will follow you.
        PType<double> athletics; // increases movement speed and carry weight.

        // Hidden Stats (Cannot be increased by player, change on their own accord)
        PType<double> luck; // Crafting luck / likelihood of mistakes / mining luck
        PType<double> perception; // Accuracy / Intelligence
        PType<double> insight; // Intelligence / Discovery


        PType<double> air_piloting; // Pilot Skill
        PType<double> space_piloting; // Space piloting skill
        PType<double> construction; // Creation of the physical world / Physics / Machining
        PType<double> destruction; // Ability to demolish with precision (Buildings or territories)


        PType<double> physiology; // Understanding of anatomy and it's applications



        PType<double> NanoTech; // Skill with nano technology

        // Buisness; Economics
        PType<double> buisness; // Company management
        PType<double> economics; // Trade
        PType<double> mining; // ability to extract minerals
        PType<double> prospecting; // ability to scan area

        // Social
        PType<double> talker; // persuasion
        PType<double> political; // ability to command the masses
        PType<double> cosmetics; // makeup and hair beautification

        // Military
        PType<double> command; // ability to command with prestiege
        PType<double> swordsmanship; // Melee Weaponry
        PType<double> shield; // Shielding: better levels mean better resistances
        PType<double> ranged; // Ranged weaponry
        PType<double> technique; // Skill with using "Magic" with nanorobots
};

#endif
