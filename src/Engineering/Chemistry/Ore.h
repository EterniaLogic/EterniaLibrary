#ifndef ORE_H_
#define ORE_H_

#import "elementals.h"

// Ore is something that players/NPCs can mine
//  Ore comes in different types, but here will be all of the "standard" earth
//  types defined.

// Using the chemistry library, ores can be specified by the elements along with chemicals.



class Ore {
        CharString *name, *formula, *elements; // ore name
        vertex* color; // color of this ore
        Composite* formula; // formula used for this ore

        double oreSize; // amount of ore in deposit, measrured in kilograms.

    public:
        Ore(char* name, char* formula, char* elements);

        Ore* Clone(); // clone this ore for use with implementations

        vertex* getColor(); // get the color for this ore based on the formula given
        Composite* getComposite(); // get the full composite of materials
};


// IMA approved mineral types: (Pretty much most games use these, but some are made up)


#endif
