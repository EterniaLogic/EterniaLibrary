#ifndef APICore_H_
#define APICore_H_

#include "../Data/Events/Event.h"
#include "../Data/Events/EventHandle.h"
#include "../Data/Events/EventHandler.h"
#include "../Data/LinkedList.hpp"

// The API Registry allows for specific event handlers to be called, models added,
//  scripts monitored, custom event handling.

class APIEventRegistry{
    HashMap<EventHandler> handlers; // list of known handlers
public:
    APIRegistry();
    
    // Used by game developer
    bool callEvent(CharString name, Event* event); // call an event, used by dev. Returns false if cancelled.
    bool addEventHandler(CharString name); // add a new event handler, return ID
    
    // Used by modders
    EventHandler* getHandler(CharString name); // get an event handler
    LinkedList<EventHandler> getHandlers(); // get list of all handlers
    
    void registerHandle(CharString name, EventHandle handle); // register a handle with a specific handler
};

#endif
