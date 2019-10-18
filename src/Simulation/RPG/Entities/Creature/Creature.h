#ifndef CREATURE_H_
#define CREATURE_H_

#include "../../../../Data/includes.h"
#include "Injury.h"
#include "../Skill/Spell.h"
#include "../Skill/Skill.h"
#include "../../../Action.h"
#include "Limb.h"
#include "CreatureStats.h"
#include "CreaturePools.h"
#include "CreatureEnergy.h"
#include "CreatureHealth.h"
#include "CreatureResistances.h"
#include "../../../CEntity.h"
#include "../../../Society/Race.h"
#include "Soul.h"

// General type of creature
enum CREATURETYPE {
    CT_Unknown, 
    CT_Undead, CT_Vampire, // undead
    CT_Tree, CT_Plant, // non-moving
    CT_Animal, CT_Monster, // Monsters and animals are two different things entirely
    CT_Dwarf,
    CT_Elf, CT_Human, // Mortal Humanoids
    CT_Elemental, CT_God, CT_Devil, // Immortals
    CT_Devourer, // Monsters?
    CT_Beast_Lion, // Basic Beast types
    CT_Lich, CT_Skeleton, CT_Zombie, // Standard undead types
    CT_Hive,
    CT_Mixed, // Half-type of creature. (Eg:  Half-Wolf, Half-Elf)
};

// Social Hierarchy class types
enum CREATURECLASS {
    CCL_NONE, // trees probably don't have a class.
    CCL_WARRIOR,
    CCL_RANGED, // guns/bows
    CCL_MAGE,
    CCL_CRAFT,
    CCL_GATHERER,
    CCL_CHIEF, // Chiefs are all-arounders
};



// Some creatures may not even need to eat food when they are strong enough to eat mana from the air.
//  they may start with usefood=true, but eventually they will just exist as long as they have mana.


class Creature : public CEntity{
protected:
    void _initSerializers();
public:
    CREATURETYPE _type;
    CREATURECLASS _class;
    
    
    Caste *caste; // read-only caste (Male Dwarf? etc, effects personality, age, etc.)
    Soul soul; // Generic/random soul for most humans, Gods and elementals have specific attunements
    
    Object *mother, *father;
    LinkedList<Object*> children;
    
    
    LinkedList<Spell> spells;
    LinkedList<Skill> skills;
    LinkedList<Action> actionqueue; // list of actions currently performing
    
    CreaturePools pools; // Stamina, Mana pools
    CreatureStats stats; // level, str, agi,... , attribute points
    CreatureHealth health; // HP, limbs
    CreatureEnergy energy; // calories/water
    CreatureResistances resistances;
    
    bool alive; // spirit still connected with the body? (in cases of undead, etc)
    double age;
    double weight_kg;
    

    Creature();
    
    
    // timing
    void _tick(double seconds); // tick this creature
    void tick(double seconds); // tick this creature (For inherited use)
    
    void _movetick(double seconds);
    void movetick(double seconds); // for inherited use
    
    
    int getAttack(); // general attack of class + equipment + stats
};

#else
class Creature;
#endif
