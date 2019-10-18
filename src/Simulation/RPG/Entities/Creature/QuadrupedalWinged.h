#ifndef QUADRUPEDALWINGED_H_
#define QUADRUPEDALWINGED_H_

#include "IntelligentCreature.h"

class QuadrupedalWinged : public IntelligentCreature{
    QuadrupedalWinged(){
        classname="[QuadrupedalWinged]";
        // important bits (HP, HPMAX, blood liters/min,   deathonbreak?)
        health.limbs.add(new Limb(BL_HEAD, 100, 100, 4, true)); // can cause death on loss
        health.limbs.add(new Limb(BL_TEETH, 100, 100, 0));
        health.limbs.add(new Limb(BL_NECK, 100, 100, 5, true));
        health.limbs.add(new Limb(BL_TORSO, 100, 100, 5, true));
        health.limbs.add(new Limb(BL_ABDOMEN, 100, 100, 5, true));
        health.limbs.add(new Limb(BL_CROTCH, 100, 100, 0.2)); // the 'asset' (M/F have this, determines if they can procreate)
        health.limbs.add(new Limb(BL_LWING, 100, 100, 0.1));
        health.limbs.add(new Limb(BL_RWING, 100, 100, 0.1));
        health.limbs.add(new Limb(BL_TAIL, 100, 100, 0.1)); // tail
        
        health.limbs.add(new Limb(BL_LFORELIMB, 100, 100, 1));
        health.limbs.add(new Limb(BL_RFORELIMB, 100, 100, 1));
        health.limbs.add(new Limb(BL_LFORECLAWS, 100, 100, 0));
        health.limbs.add(new Limb(BL_RFORECLAWS, 100, 100, 0));
        
        health.limbs.add(new Limb(BL_LLEG, 100, 100, 4));
        health.limbs.add(new Limb(BL_RLEG, 100, 100, 4));
        health.limbs.add(new Limb(BL_LAFTCLAWS, 100, 100, 0));
        health.limbs.add(new Limb(BL_RAFTCLAWS, 100, 100, 0));
        
        tamable = true;
        
        energy.foodtype = FOODT_CARNIVORE; // a lot of wing quadrupeds are carnivores
    }
    
    void think(double seconds){} // make the creature think, kind of needed for surviving.
};

#endif
