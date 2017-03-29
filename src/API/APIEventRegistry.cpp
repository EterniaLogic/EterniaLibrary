#include "APIEventRegistry.h"

APIEventRegistry::APIEventRegistry(){

}

APIEventRegistry::~APIEventRegistry(){

}

// Used by game developer
// call an event, used by dev. Returns false if cancelled.
bool APIEventRegistry::callEvent(CharString name, Event* event){
    if(handlers.get(name) != 0x0)
        handlers.get(name)->handleEvents();
}
// add a new event handler, return ID
bool APIEventRegistry::addEventHandler(CharString name, EventHandler* handler){
    handlers.add(name,handler);
}


// Used by modders
// get an event handler
EventHandler* APIEventRegistry::getHandler(CharString name){
    return handlers.get(name);
}

// get list of all handlers
LinkedList<EventHandler> APIEventRegistry::getHandlers(){

}

// register a handle with a specific handler
// lower priority means that it will get called first.
bool APIEventRegistry::registerHandle(CharString name, EventHandle *handle, int priority){
    EventHandler *handler = handlers.get(name);
    if(handler != 0x0){
        handler->addEvent(handle,priority);
    }else{
        return false;
    }
}
