#include "CEntity.h"

CEntity::CEntity(){

}

// called before any action, also calls action and postaction
bool CEntity::onaction(Action act){
    
    // send to mods or w/e
    // ???
    
    return !act.cancel;
}
