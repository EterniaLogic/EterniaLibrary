#ifndef ITEM_H_ 
#define ITEM_H_

#include "../../../Data/includes.h"
#include "../../../Math/Math.h"
#include "Asset.h"

// An item is a Tangible asset that can be inventoried.
class Item : public Asset{
public:
    double weight; // weight in kilograms
    vertex dimensions; // dimensions in meters
    CharString serial_id; // id string (found on barcode or object)
    
    
    // count, value, type inherited from Asset
    
    
    void setWeightPounds(double pounds);
    double getWeightPounds();
    void setWeightTons(double tons);
    double getWeightTons();
    
    vertex getDimensionsCentimeters();
    vertex getDimensionsMillimeters();
    vertex getDimensionsFeet();
    vertex getDimensionsInches();
    
    Item(){
        type = AT_ITEM;
    }
};

#endif
