#include "CreatureHealth.h"

CreatureHealth::CreatureHealth(){
    uselimbs=true; // Calculate damage based on limbs
    useblood=true; // can bleed out
    heartbeating = true;
    selfhealing = true; // heal over time
    
    hptype = HP_HP; // Standard HP model
    
    HP = HPMax = 1000; // raw HP not used if using limbs
    blood = bloodmax = 5; // 5 liters on average
}


void CreatureHealth::bleed(double seconds){
    blood *= getBleedRate() * (seconds/60);
    
    checkHeart();
    
    // if heart is stopped, damage head!
    if(!heartbeating){
        Limb* head = getLimb(BL_HEAD);
        if(head != 0x0){
            double dmg = head->HPMax * (seconds/(4*60));
            head->HP -= dmg; // brain cells slowly dying.
        }
    }
}


void CreatureHealth::selfheal(CreatureEnergy &energy, double seconds){
    // Convert some hunger into HP by Percentage
    
    if(!selfhealing) return;
    
    double healpercent = 5 *seconds; // scale based on seconds
    double fooduse = 20 *seconds;
    
    double healrate = HPMax*(healpercent/100.0); // healing by percentage
    
    if(HP+healrate < HPMax){ // standard values
        if(energy.calories > fooduse){ // really low efficiency food!
            HP += healrate;
            energy.calories -= fooduse;
        }
    }
}





bool CreatureHealth::checkHeart(){
    bool canstart=true; // can start, or not beating
    
    // if heart is beating, but shouldn't be.
    if(energy->water_per <= 0.05 || blood < 3 || 
        energy->calories <= 10){
        canstart = false;
        stopHeart();
    }
    
    return canstart;
}

void CreatureHealth::stopHeart(){
    heartbeating=false;
}


bool CreatureHealth::check_limbs_alive(){
    limbs.freeze();
    for(int i=0;i<limbs.frozenlen;i++){
        Limb* limb = limbs.frozen[i];
        if(limb->HP <= 0 && limb->causedeath){
            return false;
        }
    }
    return true;
}

Limb* CreatureHealth::getLimb(BODY_LOCATION loc){
    limbs.freeze();
    for(int i=0;i<limbs.frozenlen;i++){
        Limb* limb = limbs.frozen[i];
        return limb;
    }
    
    return 0x0;
}

// amputation will remove a limb, but also open bleeders (assuming creature can bleed)
// if a tourniquet is not used, very likely to bleed out due to extreme bleeding rates
// a tourniquet restricts flow down by 95% assuming that you didn't cut off a head or something.
// if amputating a head/neck, it is still technically alive for 4 minutes
void CreatureHealth::amputate(BODY_LOCATION limbloc){
    double _bleedrate=0;
    
    Limb* l = getLimb(limbloc);
    if(limbloc == BL_TORSO){
        // remove all limbs below with torso (essentially just leaving neck and head)
    }else if(limbloc == BL_ABDOMEN){
        // remove all limbs below with abdomen (keeps torso+head+wings+arms)
    }else if(limbloc == BL_NECK){
        // remove all limbs below with neck (keeps head)
    }else if(limbloc == BL_HEAD){
        // remove all but head, since you kinda need a head to live.
    }else if(limbloc == BL_LLEG){
        // remove all below Left Leg
    }

    limbs.freeze();
    for(int i=0;i<limbs.frozenlen;i++){
        if(limbs.frozen[i]->location == limbloc){
            Limb* limb = limbs.frozen[i];
            
            // remove limb & give a bleeder
            limbs.remove(i);
            missinglimbs.add(limb);
            injure(Injury(IT_AMPUTATE, limb->location, IS_CRIPPLING, limb->bloodrate));
        }
    }
}

bool CreatureHealth::isAlive(){
    if(uselimbs && !check_limbs_alive()){ // head, neck, torso, abdomen's HP is less than 0.
        return false;
    }
    
    return true;
}

// get bleed rate from injuries (Liters/min)
double CreatureHealth::getBleedRate(){
    double rate=0; 
    injuries.freeze();
    for(int i=0;i<limbs.frozenlen;i++){
        rate += limbs.frozen[i]->bloodrate;
    }
    return rate;
}

void CreatureHealth::tick(double seconds){
    if(useblood)     bleed(seconds);
}
