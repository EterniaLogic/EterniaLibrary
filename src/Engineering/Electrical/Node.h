
#ifndef Wire_h_
#define Wire_h_

#include "Components/ComponentRating.h"

// Wires are used to connect components together.
// This is used like a Graph

class Node {
    public:
        Node();
        virtual ~Node();
        
        LinkedList<Component> components;
};

#endif
