#ifndef MODSHIPPART_H_
#define MODSHIPPART_H_

#include "ShipHangar.h"

// a Modular Ship part

enum MSType {MSP_None, MSP_Hull, MSP_Thruster, MSP_CargoHold, MSP_Medbay,
             MSP_CrewQuarters, MSP_Armor, MSP_Reactor, MSP_ShieldGen, MSP_Hangar
            };

class ModularShipPart : public ItemBase {
    public:
        ModularShipPart();

        // info
        MSType type; // type of ship part
        CharString name; // name of this part
        CharString description; // description of this part (possibly dynamically generated)

        // specific ship parts
        ShipHangar hangar; // used in ship hangar, ships stored internally

        // Attributes
        double armor, weight;
};

#endif
