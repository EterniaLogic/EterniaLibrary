#ifndef EVENT_H_
#define EVENT_H_

#include "../HashMap.hpp"
#include "../CharString.h"
// An event sent to mods or systems.
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
