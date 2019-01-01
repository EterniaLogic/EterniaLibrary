#ifndef CREATURE_H_
#define CREATURE_H_

#include "../../../Data/includes.h"
#include "Injury.h"
#include "Skill/Spell.h"
#include "Skill/Skill.h"
#include "Action.h"

// General type of creature
enum CREATURETYPE {
    CT_Unknown, 
    CT_Undead, CT_Vampire,
    CT_Tree, CT_Plant,
    CT_Animal, CT_Monster, // Monsters and animals are two different things entirely
    CT_Dwarf,
    CT_Elf, CT_Human
};

enum CREATURECLASS{
    CC_NONE, // trees probably don't have a class.
    CC_WARRIOR,
    CC_MAGE,
    CC_CRAFT
};


class Creature{
public:
    CharString name;
    CREATURETYPE _type;
    CREATURECLASS _class;
    
    LinkedList<Injury> injuries;
    LinkedList<Spell> spells;
    LinkedList<Skill> skills;
    int level; // level
    double str,agi,vit,spi,will,luck,charisma; // 10 = human
    double attributepoints; // spare attribute points
    bool alive; // spirit still connected with the body? (in cases of undead, etc)
    
    // Biological energy
    double weight_kg;
    double water_per; // water percentage (12-15 cups 3 days = 100% .... 0% = death over 3 days)
    double calories; // ENERGY
    double calories_max; // energy converted into calories (81,500 calories for a human, 60,000 for a Dwarf)
    double calories_rest; // energy consumed hourly while sitting/sleeping (0.42 calories for every pound)
    double calories_excercise; // energy consumed hourly while exercising (2x weight)
    double calories_vigorous; // energy consumed hourly while vigorously moving (4x weight)
    
    
    
    Creature();
    
    
    // timing
    void tick(double seconds); // tick this creature
    
    // stats
    int getAttack(); // general attack of class + equipment + stats
};

#endif
