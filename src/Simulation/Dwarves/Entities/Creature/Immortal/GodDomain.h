#ifndef GODDOMAIN_H_
#define GODDOMAIN_H_

#include "../../../../Object.h"

// A god's soul attunement must match domain type if elemental-based.
//      god1.soul.attunement = SA_LIGHT;   // God with the "Light" Domain

// A God's domain is both their established "Home Base" and their attunement.
//  Domains hold the souls of believers when they die.


// Elemental and Race Gods are common, Concepts are rarer and Devil-Gods are despised.
// Devil-Gods are Gods that control the concept of Devils, like gluttony, etc and are usually killed as soon as they gain their domain.
enum GODDOMAINTYPE {GDT_ELEMENTAL, GDT_RACE, GDT_CONCEPT, GDT_DEVIL};



class GodDomain : public Object{
public:
    CharString name; // "Human", "Light", "War", "Gluttony", etc.   (God of Humanity)
    GODDOMAINTYPE type; // most domains are racial or elemental. Conceptual domains are for pantheons that are way too big.
    
    LinkedList<Soul> souls; // stored souls
    LinkedList<Creature> angels; // God's personal army created by the God after training and vouching.
    
    GodDomain(){
        classname="GodDomain";
    }
};

#endif
