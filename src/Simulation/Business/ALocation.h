#ifndef ALOCATION_H_
#define ALOCATION_H_

#include "../../Data/includes.h"

#include "../Location.h"

// ALocation helps identify the location of an object
class ALocation : public Location{
    
    // Standard address
    CharString address;
    CharString state_province; // state or province
    CharString country;
    
    // non-standard location
    CharString GPS; // GPS coordinates if a specific location on earth
    
    // inventory
    char row, shelf;
};

#endif
