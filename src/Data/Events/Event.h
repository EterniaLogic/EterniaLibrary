#ifndef EVENT_H_
#define EVENT_H_

#include "../CharString.h"
#include "../HashMap.hpp"


// An event sent to mods or systems.
//  can be used to prevent a mod from accessing something or w/e.

class Event{
private:
    CharString name;
    bool cancelled;
    HashMap<CharString> properties; // property map
public:
    Event(CharString eventname);
    
    bool isCancelled(); // determine if an event has been cancelled.
    void setCancelled(bool value);
    
    
    // specific options for the event
    template <class T>
    void setProperty(CharString name, T data);
    
    template <class T>
    T getProperty(CharString name);
    
    // return a list of property names
    LinkedList<CharString> getPropertyNames();
};

#endif
