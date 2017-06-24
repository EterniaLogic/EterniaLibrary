//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef Wire_h_
#define Wire_h_

#include "ComponentRating.h"

// Wires are used to connect components together.
// This is used like a Graph

class Node {
    public:
        Node();
        virtual ~Node();
        
        LinkedList<Component> components;
};

#endif
