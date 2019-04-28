#include "Creature.h"

// Default values provided here are based on an average human male
Creature::Creature(){
    classname="[Creature]";
    alive=true; // would be nice to have
    energy.health = &health;
    health.energy = &energy;
    
    _type=CT_Unknown;
    _class=CC_NONE;
    
    weight_kg = 81; // average human male
    
    
    health.uselimbs = true;
    health.regrowlimbs = false; // most creatures cannot regrow limbs
    health.useblood = false;
    health.immortal = false; // most creatures can be disconnected from their souls.
    energy.usefood=true; // use calories
    energy.usewater=true; // use calories
    energy.canstarvetodeath = true;
    energy.createswaste = true;
    stats.canlevel = false; // Gods cannot gain material power
    stats.canlevel = true;
    pools.MP = pools.MPMax = 100; // soul also has MP alongside Psi.
    pools.SP = pools.SPMax = 100;
}

void Creature::_tick(double seconds){
    if(!alive) return;
    
    // humans do selfheal, but REALLY slowly
    
    
    if(energy.usefood)      energy.starve(seconds); // use food! if possible, starve to death!
    if(energy.usewater)     energy.thirst(seconds);
    
    
    health.selfheal(energy, seconds);
    
    
    if(!health.isAlive()){
        alive=false;
    }
    
    
    age = age*(seconds/(60*60*24*365)); // add to age
    soul._tick(seconds);
    pools.tick(seconds);
    health.tick(seconds);
    tick(seconds);
}

void Creature::_movetick(double seconds){
    // move creature
    
    // ?
    movetick(seconds);
}

void Creature::tick(double seconds){
    // provided by subclass
}

void Creature::movetick(double seconds){
    // provided by subclass
}


