#include "Entity.h"

Entity::Entity(){

}

// called before any action, also calls action and postaction
bool Entity::onaction(Action act){
    
    // send to mods or w/e
    // ???
    
    return !act.cancel;
}
