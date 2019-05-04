
#ifndef Circuit_h_
#define Circuit_h_

#include "../../Data/LinkedList.hpp"
#include "Components/Component.h" // << includes PowerValue and SecondTick
#include "VNode.h"

// Defines the basic building location for EE.

class Circuit {
    public:
        Circuit(double emulationRate); // Ratio of Emulated/Real time.
        virtual ~Circuit();

        void tick(SecondTick* tickTime); // operate time for entire circuit, emulate current, voltage, temperature

        void addComponent(Component* component); // add a component to the circuit
        void addNode(VNode* wire); // add a wire to the circuit
    private:
        LinkedList<Component>* componentList;
        LinkedList<VNode>* nodeList;
};

#endif
