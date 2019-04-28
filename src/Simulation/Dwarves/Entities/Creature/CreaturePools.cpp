#include "CreaturePools.h"

CreaturePools::CreaturePools(){
    MP=MPMax=100;
    SP=SPMax=2000;
    
    MPregen = 1;
    SPregen = 1;
}

// regeneration
void CreaturePools::tick(double seconds){
    MP = MP*MPregen*(seconds/60);
    SP = SP*SPregen*(seconds/60);
}
