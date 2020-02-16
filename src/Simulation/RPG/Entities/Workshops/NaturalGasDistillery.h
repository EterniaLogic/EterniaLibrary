#ifndef NGASDISTILLERY_H_
#define NGASDISTILLERY_H_


#include "Workshop.h"
class NaturalGasDistillery : public Workshop{
public:
    NaturalGasDistillery(){
        classname="NaturalGasDistillery";

        // Skipping a lot of processing steps (Acid Gas removal, Dehydration, mercury removail, nitrogen rejection, NGL recovery, frationation, sweeteners)
        recipes.add(WorkshopRecipe("1L Natural Gas","700ml Methane, 100ml Ethane, 100ml Propane, 100ml Butanes, 0.2ml Oxygen, 2ml Hydrogen Sulfide, pentanes", 2400)); // Generic Distillery function
    }
};

#endif
