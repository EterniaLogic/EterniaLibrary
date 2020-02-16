#ifndef ACTION_H_
#define ACTION_H_

#include "../Data/Object.h"

enum ACTION_TYPE {AT_NONE, AT_SLEEP, AT_BATHROOM, AT_USESKILL, AT_CRAFT, 
    AT_MINE, AT_BUILD, AT_FILL,
    AT_FARM,
    AT_SURVIVE, AT_EAT, AT_FORAGE, AT_HUNT, AT_BREED, // Standard for most creatures
    
    AT_PRAY, AT_REPENT, AT_SACRIFICE, // Religious
    AT_COMMAND, AT_ATTACK, // military
};

class Action : public Object{
public:
    ACTION_TYPE type;
    Object *target; // item, object, or person to act on.
    Object *location; // location for target.
    bool cancel; // prevents the action from being completed
    
    Action(){
        classname=(char*)"Action";
        type = AT_NONE;
        target = location = 0x0;
        cancel=false;
    }
    
    // Returns a string for the action being performed
    CharString getActionString(){
        CharString s;
        
        s.concata(getActionName());
        s.concata(" ");
        
        if(target != 0x0){
            s.concata(target->classname);
            s.concata(" ");
        }
        
        if(location != 0x0){
            s.concata("at ");
            s.concata(location->classname);
        }
        
        return s;
    }
    
    CharString getActionName(){
        switch(type){
            case AT_NONE: return "Nothing";
            case AT_SLEEP: return "Sleeping";
            case AT_BATHROOM: return "Going to the washroom";
            case AT_USESKILL: return "Using Skill";
            case AT_CRAFT: return "Crafting";
            
            case AT_MINE: return "Mining";
            case AT_BUILD: return "Building";
            case AT_FILL: return "Filling";
            
            case AT_FARM: return "Farming"; // "Farming Wheat at Farm"
            
            case AT_SURVIVE: return "Surviving"; // essentially running away/eating?
            case AT_EAT: return "Eating";
            case AT_FORAGE: return "Foraging";
            case AT_HUNT: return "Hunting";
            case AT_BREED: return "Breed";
            
            case AT_PRAY: return "Praying";
            case AT_REPENT: return "Repenting";
            case AT_SACRIFICE: return "Sacrificing";
            
            case AT_COMMAND: return "Commanding";
            case AT_ATTACK: return "Attacking";
            
        }
        return "Nothing";
    }

};

#endif
