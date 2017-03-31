//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Avatar_health_h_
#define Avatar_health_h_

#include "../../Data/LinkedList.hpp"
#include "../../Data/Protect/PType.hpp"
#include "Disease.h"
#include "Mood.h"
#include "../../Serialization/SpecificSerializer.h"

enum BODYPART {BP_HEAD, BP_TORSO, BP_ABDOMEN, BP_LEFTFOOT, BP_RIGHTFOOT, BP_LEFTKNEE, BP_RIGHTKNEE, BP_LEFTHAND, BP_RIGHTHAND, BP_LEFTWRIST, BP_RIGHTWRIST, BP_LEFTARM, BP_RIGHTARM};


class BodyPartHP : public SpecificSerializer {
    public:
        BodyPartHP();

        void tickRegen(PType<double> regen);
        
        PType<double> value, max;
        PType<int> armor; // determines armor value.
};


class AvatarHealth : public SpecificSerializer {
    private:
        PType<double> regen; // server-side local

    public:
        AvatarHealth(); // set defaults

        void tick(double tps); // tick Regen, power, diseases and moods.


        PType<double> regeneration; // Natural healing of body parts (per second)

        // Energy
        BodyPartHP portable_reactor; // reactor powers detection / shields
        BodyPartHP shield;

        // VITAL
        BodyPartHP head, torso, abdomen;

        // Effects movement
        BodyPartHP leftfoot, rightfoot, leftknee, rightknee;

        // Effects accuracy and precision (you don't want to medicate somebody while you have a broken hand)
        BodyPartHP lefthand, leftwrist, leftarm, righthand, rightwrist, rightarm;

        // Hunger, thirst (Robots/Plants dont have this)
        BodyPartHP hunger; // Hunger is realistic. Ticks down based on eating times.
        BodyPartHP thirst; // Thirst is also realistic. May be modified by NanoRobots.

        // Overall health
        BodyPartHP blood; // Blood in the body, if humanoid
        LinkedList<Disease> diseases; // list of ailments, toxins, drugs, ect.
        LinkedList<Mood> moods; // Humans are complicated
};



#endif
