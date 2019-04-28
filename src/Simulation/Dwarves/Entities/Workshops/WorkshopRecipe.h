#ifndef WORKSHOPRECIPE_H_
#define WORKSHOPRECIPE_H_

#include "../Item/Item.h"
#include "../../../../Data/includes.h"
class WorkshopRecipe : public Object{
public:
    CharString inputitems;
    CharString product;
    double timeseconds; // seconds to complete the process
    
    // kg, ml, l, m3  measurement types
    // NOCONSUME keyword => do not consume item
    
    
    // Recipes preserve item data when performing actions so "1 Metal Item" -> "1 Metal Hammer" knows that it is made out of copper.
    
    
    WorkshopRecipe(CharString _input, CharString _product){
        classname = "WorkshopRecipe";
        inputitems = _input;
        product = _product;
    }
    
    WorkshopRecipe(CharString _input, CharString _product, double seconds){
        classname = "WorkshopRecipe";
        inputitems = _input;
        product = _product;
        timeseconds=seconds;
    }
};

#endif
