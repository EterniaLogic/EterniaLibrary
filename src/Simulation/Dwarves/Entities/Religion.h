#ifndef RELIGION_H_
#define RELIGION_H_

#include "../../Object.h"
#include "Creature/Creature.h"
#include "Creature/Immortal/God.h"


class Religion : public Object{
public:
    God* god; // Top God of the religion. (religions might have more than one, like a pantheon)
    LinkedList<God> gods; // other gods in the religion.
    
    LinkedList<Creature> Pope; // Pope(s) for the religion.
    LinkedList<Creature> Bishops, Priests, Believers;
    
    GodDomain* domain; // holy domain
    
    Religion(){
        classname = "Religion";
    }
};

#endif
