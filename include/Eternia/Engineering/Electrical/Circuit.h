//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef Circuit_h_
#define Circuit_h_

#include "../../Data/LinkedList.hpp"
#include "Component.h" // << includes PowerValue and SecondTick
#include "Wire.h"

// Defines the basic building location for EE.

class Circuit {
    public:
        Circuit(double emulationRate); // Ratio of Emulated/Real time.
        virtual ~Circuit();

        void tick(SecondTick* tickTime); // operate time for entire circuit, emulate current, voltage, temperature

        void addComponent(Component* component); // add a component to the circuit
        void addNode(Node* wire); // add a wire to the circuit
    private:
        LinkedList<Component>* componentList;
        LinkedList<Node>* nodeList;
};

#endif
