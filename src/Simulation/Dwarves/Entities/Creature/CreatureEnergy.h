#ifndef CREATUREENERGY_H_
#define CREATUREENERGY_H_

#include "../../../../Data/includes.h"

#include "CreatureHealth.h"

enum FOODT {FOODT_NONE, FOODT_OMNIVORE, FOODT_HERBIVORE, FOODT_CARNIVORE, FOODT_BLOOD, FOODT_SOUL};

class CreatureEnergy{
public:
    CreatureHealth* health;
    
    bool canstarvetodeath;
    bool usefood, usewater; // calculate hunger via calories
    bool createswaste;
    
    double calories; // ENERGY
    double calories_max; // energy converted into calories (81,500 calories for a human, 60,000 for a Dwarf)
    double calories_use; // current caloric usage per hour
    double calories_use_rest; // energy consumed hourly while sitting/sleeping (0.42 calories for every pound)
    double calories_use_excercise; // energy consumed hourly while exercising (2x weight)
    double calories_use_vigorous; // energy consumed hourly while vigorously moving (4x weight)
    double calories_stomach; // calories of food not digested yet
    double calories_fat; // energy stored as fat (Humans when >2000 calories)
    double calories_conversion_gain; // percentage gained from food eaten
    
    double water_use; // percentage of water used per second
    double water_per; // water percentage (12-15 cups 3 days = 100% .... 0% = death over 3 days)
    
    
    double calories_conversion_sun; // photosynthesis rate for converting glucose into sugar
    
    FOODT foodtype;
    
    CreatureEnergy();
    
    // use calories / water
    void starve(double seconds); // starvation detection
    void thirst(double seconds);
    
    // actions
    void eat(double calories); // put food into stomach, some time (~6 hours) to digest
};

#else
class CreatureEnergy;
#endif
