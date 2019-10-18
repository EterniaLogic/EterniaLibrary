#include "CreatureStats.h"

CreatureStats::CreatureStats(){
    level = 1;
    attributepoints = 0;
    str=agi=vit=spi=will=luck=charisma = 10;
    canlevel = true;
    
    addSerial(&level, "level", SSE_Int);
    addSerial(&canlevel, "canlevel", SSE_bool);
    addSerial(&str, "str", SSE_double);
    addSerial(&agi, "agi", SSE_double);
    addSerial(&vit, "vit", SSE_double);
    addSerial(&spi, "spi", SSE_double);
    addSerial(&will, "will", SSE_double);
    addSerial(&luck, "luck", SSE_double);
    addSerial(&charisma, "charisma", SSE_double);
    addSerial(&attributepoints, "attributepoints", SSE_double);
}
