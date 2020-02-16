#ifndef WORLD_H_
#define WORLD_H_

#include "../Entities/Creature/Immortal/God.h"

class World : public Object{
public:
    LinkedList<God> gods; // Major gods of the world.
    
    World(){
        classname="World";
    }
};

#endif
