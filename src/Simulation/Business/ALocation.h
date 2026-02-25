#ifndef ALOCATION_H_
#define ALOCATION_H_

#include "../../Data/CharString.h"

// ALocation helps identify the location of an object
class ALocation : public Location{
    
    // Standard address
    CharString address, address2, pobox;
    CharString state_province; // state or province
    CharString country;
    
    // non-standard location
    CharString GPS; // GPS coordinates if a specific location on earth
    
    // inventory
    int row, shelf, building;
};

#endif
