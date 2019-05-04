
#ifndef Wire_h_
#define Wire_h_

#include "Components/ComponentRating.h"

// Wires are used to connect components together.
// This is used like a Graph

class VNode {
    public:
        VNode();
        virtual ~VNode();
        
        LinkedList<Component> components;
};

#endif
