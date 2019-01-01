#ifndef DWRACES_H_
#define DWRACES_H_

#include "../Society/include.h"


// hard-coded races
Race *dwarf = new Race();

void initraces(){
    dwarf->name = "Dwarf";
    dwarf->description = "A short and burly intelligent species which prefers the ground to land.";

    RaceCaste::Caste *dw_male = new RaceCaste::Caste();
    dw_male->type = RaceCaste::male;
    dw_male->castname = "Dwarf Male";
    dw_male->intelligence = 120;
    dw_male->psyche = 0.002;
    dw_male->emotion = 45;
    dw_male->xenophilia = 0;
    dw_male->temperature = 291.483; // ~65 fahreneheit, 18.3 celcius
    dw_male->sleep = 0.25; // percent of day asleep
    dw_male->breathing = CompositeGas::o2;
    dw_male->lifespan = {65, 100, 200};
    dw_male->weight_adult = {50, 77, 100}; // kg
    dw_male->size_adult = {0.5, 1.1, 1.47};
    dw_male->weight_baby = {2.5,3,5}; // kg
    dw_male->size_baby = {0.3,0.5,0.7}; // meters    
    dw_male->age_fertile = 10;
    dw_male->age_maxfertile = -1; // does not lose fertility over time
    dw_male->age_puberty=8; 
    dw_male->puberty_years=4;
    
    dw_male->limbs.add({RaceLimb::Arm, 2, 3});
    
    
    RaceCaste::Caste *dw_female = new RaceCaste::Caste();
    dw_female->type = RaceCaste::female;
    dw_female->castname = "Dwarf Female";
    dw_female->intelligence = 140;
    dw_female->psyche = 0.0015;
    dw_female->emotion = 60;
    dw_female->xenophilia = 0.2;
    dw_female->temperature = 300;
    dw_female->sleep = 0.25; // percent of day asleep
    dw_female->breathing = CompositeGas::o2;
    dw_female->lifespan = {70, 120, 250};
    dw_female->weight_adult = {45, 70, 95}; // kg
    dw_female->size_adult = {0.5, 1.1, 1.45};
    dw_female->weight_baby = {2.5,3,5}; // kg
    dw_female->size_baby = {0.3,0.45,0.65}; // meters
    dw_female->age_fertile = 13;
    dw_female->age_maxfertile = 80;
    dw_female->age_puberty=7; 
    dw_female->puberty_years=5;



    dwarf->caste.add(dw_male);
    dwarf->caste.add(dw_female);
}

const Race[1] = {dwarves};

#endif
