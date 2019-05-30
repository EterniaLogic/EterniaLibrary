#ifndef DWRACES_H_
#define DWRACES_H_

#include "../Society/include.h"
#include "Dwarves.h"


// hard-coded races

Race* initdwarf(){
    Race *dwarf = new Race();
    dwarf->name = "Dwarf";
    dwarf->description = "A short and burly intelligent species which prefers the ground to land.";

    Caste dw_male;
    dw_male.type = RaceCaste::male;
    dw_male.castename = "Dwarf Male";
    dw_male.intelligence = 120;
    dw_male.psyche = 0.002;
    dw_male.emotion = 45;
    dw_male.xenophilia = 0;
    dw_male.temperature = 291.483; // ~65 fahreneheit, 18.3 celcius
    dw_male.sleep = 0.25; // percent of day asleep
    dw_male.breathing = Chemistry::CompositeGas::o2;
    dw_male.lifespan = {65, 100, 200};
    dw_male.weight_adult = {45, 77, 100}; // kg
    dw_male.size_adult = {0.5, 1.1, 1.47};
    dw_male.weight_baby = {2.5,3,5}; // kg
    dw_male.size_baby = {0.3,0.5,0.7}; // meters    
    dw_male.age_fertile = 10;
    dw_male.age_maxfertile = -1; // does not lose fertility over time
    dw_male.age_puberty=8; 
    dw_male.puberty_years=4;
    
    
    Caste dw_female;
    dw_female.type = RaceCaste::female;
    dw_female.castename = "Dwarf Female";
    dw_female.intelligence = 140;
    dw_female.psyche = 0.0015;
    dw_female.emotion = 60;
    dw_female.xenophilia = 0.2;
    dw_female.temperature = 300;
    dw_female.sleep = 0.25; // percent of day asleep
    dw_female.breathing = Chemistry::CompositeGas::o2;
    dw_female.lifespan = {70, 120, 250};
    dw_female.weight_adult = {40, 70, 95}; // kg
    dw_female.size_adult = {0.5, 1.1, 1.45};
    dw_female.weight_baby = {2.5,3,5}; // kg
    dw_female.size_baby = {0.3,0.45,0.65}; // meters
    dw_female.age_fertile = 13;
    dw_female.age_maxfertile = 80;
    dw_female.age_puberty=7; 
    dw_female.puberty_years=5;

    dwarf->castes.add(dw_male);
    dwarf->castes.add(dw_female);
    return dwarf;
}

Race* inithuman(){
    Race *human = new Race();
    human->name = "Human";
    human->description = "The default race throughout the lands.";

    Caste male;
    male.type = RaceCaste::male;
    male.castename = "Human Male";
    male.intelligence = 100;
    male.psyche = 0.001;
    male.emotion = 50;
    male.xenophilia = 0;
    male.temperature = 291.483; // ~65 fahreneheit, 18.3 celcius
    male.sleep = 0.25; // percent of day asleep
    male.breathing = Chemistry::CompositeGas::o2;
    male.lifespan = {65, 100, 120};
    male.weight_adult = {50, 81, 200}; // kg
    male.size_adult = {1.45, 1.77, 2};
    male.weight_baby = {2.5,3,5}; // kg
    male.size_baby = {0.3,0.5,0.7}; // meters    
    male.age_fertile = 12;
    male.age_maxfertile = -1; // does not lose fertility over time
    male.age_puberty=12; 
    male.puberty_years=4;
    
    
    Caste female;
    female.type = RaceCaste::female;
    female.castename = "Human Female";
    female.intelligence = 120;
    female.psyche = 0.0008; // percentage of population that is kinda bonkers
    female.emotion = 65;
    female.xenophilia = 0.2;
    female.temperature = 300;
    female.sleep = 0.25; // percent of day asleep
    female.breathing = Chemistry::CompositeGas::o2;
    female.lifespan = {40, 60, 120};
    female.weight_adult = {50, 66, 200}; // kg
    female.size_adult = {1.4, 1.61, 1.8};
    female.weight_baby = {2.5,3,5}; // kg
    female.size_baby = {0.3,0.45,0.65}; // meters
    female.age_fertile = 13;
    female.age_maxfertile = 41;
    female.age_puberty=10; 
    female.puberty_years=5;

    human->castes.add(male);
    human->castes.add(female);
    return human;
}

Race* initelemental(){
    Race *elemental = new Race();
    elemental->name = "Elemental";
    elemental->description = "One of the more overpowered races. The Elemental is immortal except when their mana is depleted or their soul is extinguished.";
    
    Caste fire;
    fire.type = RaceCaste::asexual;
    fire.castename = "Fire Elemental";
    fire.intelligence = 200; // pretty much OP, since probably lived forever
    fire.psyche = 0; // percentage of population that is kinda bonkers
    fire.emotion = 80; // fires are pretty emotional, particular quick to anger
    fire.xenophilia = 0.1; // don't like other races
    fire.temperature = 3000; // freaking hot to the touch, prefers lava
    fire.sleep = 0; // percent of day asleep
    fire.lifespan = {10.e60, 10.e60, 10.e60};
    
    fire.weight_adult = {0, 0, 0}; // kg (Fire elementals are weightless
    fire.size_adult = {1.4, 1.61, 1.8}; // sizes based off of 2x humans
    fire.weight_baby = {0,0,0}; // kg
    fire.size_baby = {0,0,0}; // meters
    fire.age_fertile = -1;
    fire.age_maxfertile = -1;
    fire.age_puberty=-1; 
    fire.puberty_years=-1;
    
    Caste wind;
    wind = fire; // copy values
    wind.castename = "Wind Elemental";
    wind.emotion=10; // not particularly emotional
    wind.temperature = 298.15; // room temperature
    
    Caste earth;
    earth = wind; // copy values
    earth.castename = "Earth Elemental";
    earth.temperature = 250; // stone cold
    earth.weight_adult = {50, 81, 200}; // kg (About average for humans???)
    
    Caste water;
    water = wind; // copy values
    water.castename = "Water Elemental";
    water.temperature = 290; // Dry ice temperatures, prefers incredibly cold climates
    water.weight_adult = {50, 81, 200}; // kg (About average for humans???)
    
    Caste ice;
    ice = wind; // copy values
    ice.castename = "Ice Elemental";
    ice.temperature = -109.3; // Dry ice temperatures, prefers incredibly cold climates
    ice.weight_adult = {50, 81, 200}; // kg (About average for humans???)
    
    elemental->castes.add(fire);
    elemental->castes.add(wind);
    elemental->castes.add(earth);
    elemental->castes.add(water);
    elemental->castes.add(ice);
    return elemental;
}

void Dwarves::initraces(){
    races.add(initdwarf());
    races.add(inithuman());
    races.add(initelemental());
}

#endif
