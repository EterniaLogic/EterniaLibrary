#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include "../PriorityQueue.h"
#include "EventHandle.h"
#include "../Concurrent/ThreadPool.h"

#include <iostream> // testing purposes only

// The Event Handler is an API that allows use and execution of set events
//      These events can include window draws, physics, mouse clicks, ect.

// Tests: Do not add over 10,000 events, huge performance loss when adding due to priority queue (10 seconds)

// Multi-threading possibly added later

// Theoretical times:
//      get Highest priority item: O(1)
//      Add item: O(N^2)
//      Remove item: O(N^2)
//      loop through all items: O(N)

class EventHandler {
    private:
        PriorityQueue *handles; // events to handle
        bool threads; // if threading, prevents handleEvents() from running on single CPU
        std::thread managerthread;

        void _managethread(double ticks_per_sec, bool subthreads); // manages events and handlers
        //void _doEvents(PriorityItem* item, bool subthreaded);
    public:
        ThreadPool pool;

        EventHandler();
        ~EventHandler();

        // enable threading to multi-thread the handler ticks
        //  TPS is ticks-per-second
        //  subthreads are run for every event to make a system that can run up to 1000 threads without too much CPU usage. (can be disabled individually in EventHandle)
        void startThreading(double TPS, int threads, bool subthreads);
        void stopThreading(); // kills threads

        // O(N)
        void handleEvents(); // handles automatic events (Runs automatically if startThreading(...) is on)
        void handleEvents(bool subthreaded); // sub-threaded events?

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

void _doEvents(EventHandler* handler, PriorityQueue* handles, PriorityItem* item, bool threaded);

#endif
