#ifndef INJURY_H_
#define INJURY_H_

#include "../../../../Data/Object.h"
#include "../../../BodyLocation.h"

enum INJURYTYPE {IT_BURN, IT_CUT, IT_STAB, IT_BLUNT, IT_BREAK, IT_AMPUTATE};


enum INJURYSEVERITY {IS_LOW, IS_SEVERE, IS_CRIPPLING};

class Injury : public Object{
public:
    INJURYTYPE type;
    BODY_LOCATION location;
    INJURYSEVERITY severity; // crippling injuries will cause one to fall on the ground and not be able to move
    double bleedrate; // liters/minute (5 = death in a half-minute for humans)
    
    Injury(INJURYTYPE type, BODY_LOCATION location, INJURYSEVERITY severity, double _bleedrate){
        classname="Injury";
        this->type = type;
        this->location = location;
        this->severity = severity;
        this->bleedrate = _bleedrate;
    }
};

#endif
