#ifndef SKILL_H_
#define SKILL_H_
#include "../../../../Data/includes.h"
#include "../../../Object.h"


enum SKILLTYPE {SKT_CLOSE, SKT_RANGED, SKT_MISC};

class Skill : public Object{
public:
    SKILLTYPE type;
    CharString name;
    double level;
    double maxlevel;
    
    double staminacost;
    
    Skill(SKILLTYPE _type, CharString _name, double _level, double _maxlevel, double _staminacost){
        type = _type;
        name = _name;
        level = _level;
        maxlevel = _maxlevel;
        staminacost = _staminacost;
    }
};

#endif
