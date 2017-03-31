#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include "../PriorityQueue.h"
#include "EventHandle.h"

#include <iostream> // testing purposes only

// The Event Handler is an API that allows use and execution of set events
//      These events can include window draws, physics, mouse clicks, ect.

// Tests: Do not add over 10,000 events, huge performance loss when adding due to priority queue (10 seconds)

// Theoretical times:
//      get Highest priority item: O(1)
//      Add item: O(N^2)
//      Remove item: O(N^2)
//      loop through all items: O(N)

class EventHandler {
    private:
        PriorityQueue *handles; // events to handle

    public:
        EventHandler();
        ~EventHandler();

        // O(N)
        void handleEvents(); // handles automatic events

        // Create Event O(N^2) due to priority heap
        EventHandle* createEvent(void (*func)(), unsigned long priority);
        EventHandle* createEvent(void (*func)(void*), unsigned long priority);
        EventHandle* createEvent(void (*func)(void*,void*), unsigned long priority);
        void addEvent(EventHandle *event, int priority); // add Event, the priority is set by lowest value
        void removeEvent(EventHandle *event); // remove a specific object (expensive)

        // O(N^2)
        void clearEvents(); // clear all objects

        // O(k)
        bool isEmpty(); // returns if the event queue is empty
};

#endif
