#ifndef APIEVENTREG_H_
#define APIEVENTREG_H_

#include "../Data/LinkedList.hpp"
#include "../Data/Events/Event.h"
#include "../Data/Events/EventHandle.h"
#include "../Data/Events/EventHandler.h"


// The API Registry allows for specific event handlers to be called, models added,
//  scripts monitored, custom event handling.

class APIEventRegistry{
    HashMap<EventHandler*> handlers; // list of known handlers
    LinkedList<EventHandler*> handlerList;
public:
    APIEventRegistry();
    virtual ~APIEventRegistry();

    // Used by game developer
    // if(callEvent("DigHole", new Event("dighole"))){
    //      doDig(args...);
    // }
    bool callEvent(CharString name, Event* event); // call an event, used by dev. Returns false if cancelled.
    bool addEventHandler(CharString name, EventHandler* handler); // add a new event handler, return ID

    // Used by modders
    EventHandler* getHandler(CharString name); // get an event handler
    LinkedList<EventHandler*> getHandlers(); // get list of all handlers

    bool registerHandle(CharString name, EventHandle *handle, int priority); // register a handle with a specific handler (returns false if handler doesn't exist.
};

#endif
