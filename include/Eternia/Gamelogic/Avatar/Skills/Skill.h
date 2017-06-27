#ifndef Skill_H_
#define Skill_H_

#include "../../../Data/CharString.h"
#include "../../../Serialization/SpecificSerializer.h"

// Skills are active elements for any game.
// In this case, skills can be magic, endurance, ect.

// This is the base for all Skill types.

// Base classes for skills
enum SKCLASS {SK_UNKNOWN, SK_MAGIC, SK_SWORD, SK_RANGED, SK_MELEE, SK_MACHINE, SK_VEHICLE, SK_NANO};

class Skill : public SpecificSerializer {
private:
    CharString name;
    SKCLASS classType;
    double cost;
    double castTime;
public:
    // cost is dependent on the classtype.
    void skillInit(CharString name, SKCLASS classType, double cost, double castTime); // Initialize this skill
    
    // start the cast
    void cast();
    
    // some skills may have damage over time. (Prevents people from getting killed on a long cast super-skill, especially if they are a kilometer away from max radius)
    void onTick();
    
    // end the cast causing effects and final damage.
    void done();
};

#endif
