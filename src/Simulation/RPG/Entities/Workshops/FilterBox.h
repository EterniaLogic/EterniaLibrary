#ifndef FILTERBOX_H_
#define FILTERBOX_H_

#include "Workshop.h"

class FilterBox : public Workshop{
public:
    FilterBox(){
        classname="FilterBox";
        // filter specific dusts to produce products
        
        recipes.add(new Recipe("100ml dirty water, 100g charcoal","95ml water, 95g charcoal",60));
        recipes.add(new Recipe("100ml water, 100g ash","95ml lye water, 95g fertilizer", 120)); // used ash can be used as a fertilizer
        
    }
};

#endif
