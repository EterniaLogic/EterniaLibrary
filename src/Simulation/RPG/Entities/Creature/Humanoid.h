#ifndef HUMANOID_H_
#define HUMANOID_H_

#include "IntelligentCreature.h"

class Humanoid : public IntelligentCreature{
public:
    Humanoid(){
        classname="[Humanoid]";
        // important bits (HP, HPMAX, blood liters/min)
        health.limbs.add(new Limb(BL_HEAD, 100, 100, 4, true)); // can cause death on loss
        health.limbs.add(new Limb(BL_TEETH, 100, 100, 0));
        health.limbs.add(new Limb(BL_NECK, 100, 100, 5, true));
        health.limbs.add(new Limb(BL_TORSO, 100, 100, 5, true));
        health.limbs.add(new Limb(BL_ABDOMEN, 100, 100, 5, true));
        health.limbs.add(new Limb(BL_CROTCH, 100, 100, 0.2)); // the 'asset' (M/F have this, determines if they can procreate)
        
        health.limbs.add(new Limb(BL_LARM, 100, 100, 1));
        health.limbs.add(new Limb(BL_RARM, 100, 100, 1));
        health.limbs.add(new Limb(BL_LHAND, 100, 100, 0.2));
        health.limbs.add(new Limb(BL_RHAND, 100, 100, 0.2));
        
        health.limbs.add(new Limb(BL_LLEG, 100, 100, 4));
        health.limbs.add(new Limb(BL_RLEG, 100, 100, 4));
        health.limbs.add(new Limb(BL_LFOOT, 100, 100, 0.2));
        health.limbs.add(new Limb(BL_RFOOT, 100, 100, 0.2));
    }
    
    void think(double seconds){} // make the creature think, kind of needed for creating things
};

#endif
