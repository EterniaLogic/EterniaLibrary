#ifndef SOUL_H_
#define SOUL_H_

enum SOUL_ATTUNEMENT : int {SA_FIRE=0, SA_WATER=1, SA_EARTH=2, SA_WIND=3, SA_ICE=4, SA_LIGHTNING=5, SA_DARK=6, SA_LIGHT=7, SA_CHAOS=8, SA_VOID=9};

// Generic/random soul for most humans, Gods and elementals have specific attunements

// Souls have HP and MP, but most magic cannot tap into MP or Psi.
// Values here are not usually seen or felt, even if HP is nearly zero; a soul falling apart.


#include "../../../../Math/Random.hpp"
#include "../../../Object.h"
#include "../../../Location.h"
class Soul : public Object{
public:
    bool alive; // a fully defeated soul is not alive
    bool eatsouls; // soul can eat the majority of another soul if touching.
    int attunement; //SOUL_ATTUNEMENT   soul's attunement is a requirement for Gods 
    Location location; // location of the soul, only used when a soul is separate from a material/ethereal body.
    
    double mana, manacapacity, manaregen; // in-soul mana capacity
    double psi, psicapacity, psiregen; // in-soul Psi capacity
    
    double HP, HPMax, HPRegen; // Soul HP, incredibly difficult to kill a soul entirely
    
    double age; // soul age in years. (Most souls are from the age of Gods, pretty freaking old... billions of years)
    
    
    Soul(){
        classname="Soul";
        Math::Random r;
        alive=true; // kinda gotta be alive to exist.
        eatsouls=false;
        age = r.nextDouble(0,1.e12); // can be pretty old... (Some may even be from before the BigBang)
        attunement = (int)r.nextInt(0,7); // Chaos and void are 'Special' soul types that are dependent on the dimension born in.
        
        // HP, MP, Psi
        mana = manacapacity = r.nextDouble(2,300); // random bit of mana storage
        manaregen = 0.01; // every soul has a little bit of mana generation every minute
        psi = psicapacity = 0.1; // most souls cannot manipulate anything with Psi
        psiregen = 0.001;
        HP = HPMax = 1000000; // souls are kinda OP, along with the required usage of Ethereal power to kill them. (they do not easily repair)
        HPRegen = 0.00004; // HP/minute is kinda slow. Might take thousands of years to fully regenerate.
        
        // HPRATE = 1000000/(0.00004*60*24*365)   => 48,000 years to heal soul from nearly zero.
    }
    
    // Soul Power affects tasks such as using magic or being smart or holding soul chains may be difficult to bind to the earth.
    //  Soul power is lowered if a soul is low on health. Sanity is also affected by soul power.
    // 0 to 1 ... can be above 1 if HP exceeds normal 1million. (This would occur if one were to 'Eat' other souls creating Godlike souls)
    double getSoulPower(){
        return HP/HPMax;
    }
    
    // handle regeneration over years
    void _tick(double seconds){
        double minutes = seconds/60;
        
        if(HP < HPMax) HP += HP*(HPRegen*minutes);
        if(mana < manacapacity) mana += mana*(manaregen*minutes);
        if(psi < psicapacity) psi += psi*(psiregen*minutes);
    }
};

#endif
