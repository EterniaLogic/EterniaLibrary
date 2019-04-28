#ifndef CREATURE_HEALTH_H_
#define CREATURE_HEALTH_H_

#include "../../../../Data/includes.h"
#include "Limb.h"
#include "Injury.h"
#include "CreatureEnergy.h"


enum HPTYPE {HP_NONE, HP_HP, HP_FOOD, HP_MANA, HP_QI, HP_BELIEF, HP_SOUL};

class CreatureHealth{
private:
    
    
    bool check_limbs_alive(); // check if limbs are dead or not.
    
    // all values here are assumed for humans, define differently in inherrited classes
    // e.g: devourers can hold tons of fast-burning calories and convert it into super-fast healing
    
    void bleed(double seconds);
    
    // heart/death
    bool checkHeart(); // check for food/thirst
    double getBleedRate(); // get bleed rate from injuries
public:
    // uselimbs
    CreatureEnergy *energy;
    bool uselimbs, useblood; // calculate HP via limbs or just the HP stat
    bool regrowlimbs;
    bool immortal; // requires soul to be destroyed
    bool heartbeating; // alive for 4 minutes after heart stops
    bool selfhealing;
    double heartstoptime = 0; // Not used, HP is determine by HEAD limb which is damaged for 4 minutes after heart stops
    double blood; // liters of blood
    double bloodmax; // max liters of blood
    double bloodmin; // minimum blood for heart to beat
    double HP, HPMax; // Health (Other pools in CreaturePools)
    HPTYPE hptype; // usually HP_HP
    
    LinkedList<Injury*> injuries;
    LinkedList<Limb*> limbs, missinglimbs;

    void selfheal(CreatureEnergy &energy, double seconds); // self-healing
    
    CreatureHealth();
    
    
    
    
    // act on this
    void amputate(BODY_LOCATION limbloc); // amputation will remove a limb, but also open bleeders (Amptutating neck/head will remove other limbs)
    void hurt(BODY_LOCATION limbloc, double damage);
    void injure(Injury injury);
    void stopHeart(); // caused when starvation or thirst bottoms out or not enough blood
    
    // stats
    Limb* getLimb(BODY_LOCATION loc);
    bool isAlive();
    
    void tick(double seconds);
};

#else
class CreatureHealth;
#endif
