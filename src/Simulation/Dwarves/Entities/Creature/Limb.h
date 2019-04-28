#ifndef LIMB_H_
#define LIMB_H_

//enum LIMB_LOCATION {LL_HEAD, LL_TORSO, LL_LARM, LL_RARM, LL_LLEG, LL_RLEG, LL_STOMACH,
//    LL_LFORELIMB, LL_RFORELIMB, LL_TAIL, LL_LWING, LL_RWING, LL_NECK};

#include "Injury.h"
#include "../Items/Item.h"

class Limb : public Item{
public:
    BODY_LOCATION location;
    double HP, HPMax, bloodrate;
    bool causedeath;
    
    Limb(){
        location=BL_NONE;
        HP=HPMax=100;
        causedeath=false;
    }
    
    Limb(BODY_LOCATION loc, double hp, double hpmax, double _bloodrate, bool _causedeath){
        location = loc;
        HP = hp;
        HPMax = hpmax;
        causedeath = _causedeath;
    }
    
    // limb that can be removed and not cause death
    Limb(BODY_LOCATION loc, double hp, double hpmax, double _bloodrate){
        location = loc;
        HP = hp;
        HPMax = hpmax;
        causedeath = false;
        bloodrate = _bloodrate;
    }
};

#endif
