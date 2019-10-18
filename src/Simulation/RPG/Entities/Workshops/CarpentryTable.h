#ifndef CARPENTRYTABLE_H_
#ifndef CARPENTRYTABLE_H_

#include "Workshop.h"

class CarpentryTable : public Workshop{
public:
    CarpentryTable(){
        classname="CarpentryTable";
        // convert wood into stuffs
        
        recipes.add(new Recipe("8m wood log, NOCONSUME sawblade","8 wood planks 8m")); // used ash can be used as a fertilizer
        recipes.add(new Recipe("wood","wood chips"));
    }
};

#endif
