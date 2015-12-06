#include "EventHandler.h"

//#define DEBUG_EH

#ifdef DEBUG_EH
#define debugLogEH(ehs) cout << ehs << endl; cout.flush();
#else
#define debugLogEH(ehs)
#endif


#include <iostream> // testing purposes only
using namespace std;

EventHandler::EventHandler(){
        handles = new PriorityQueue();
}

EventHandler::~EventHandler(){

}

EventHandle* EventHandler::createEvent(void (*func)(), unsigned long priority){
        EventHandle *handle = new EventHandle(func);
        addEvent(handle, priority);

        return handle;
}

EventHandle* EventHandler::createEvent(void (*func)(void*), unsigned long priority){
        EventHandle *handle = new EventHandle(func);
        addEvent(handle, priority);

        return handle;
}

EventHandle* EventHandler::createEvent(void (*func)(void*,void*), unsigned long priority){
        EventHandle *handle = new EventHandle(func);
        addEvent(handle, priority);

        return handle;
}

// queue is only set for the top item
void doEvents(PriorityItem* item, PriorityQueue* queue){
        // handle left first, then handle right
        if(item == 0x0) return;
        debugLogEH("dE1");

        // execute event
        if(item->data != 0x0){
                EventHandle* handle = (EventHandle*)item->data;
                debugLogEH("dE2---xx");
                if(!handle->handle()){
                        debugLogEH("dE3---" << queue->getSize());
                        queue->remove(item);
                        debugLogEH("dE4");
                }
                debugLogEH("dE5---xx");
        }
        debugLogEH("dE6");

        // go through the branches
        if(item->left != 0x0){
                doEvents(item->left, queue);
        }
        if(item->right != 0x0){
                doEvents(item->right, queue);
        }
}

// handles automatic events
void EventHandler::handleEvents(){
        // loop through all items, priority first
        //      if an item has been handled it will be removed.
        debugLogEH("hE0");
        doEvents(handles->top(),handles);
        debugLogEH("hE1");
        handles->downheap(handles->top());
        debugLogEH("hE2");
}

// add Event, the priority is set by lowest value
void EventHandler::addEvent(EventHandle *event, int priority){
        handles->insert(priority, event);
}

// remove a specific object (expensive)
void EventHandler::removeEvent(EventHandle *event){
        // search through the handles to find it.
}

// clear all objects
void EventHandler::clearEvents(){
        // loop through all items
        debugLogEH("cE1");
        handles->clearAll();
}

// returns if the event queue is empty
bool EventHandler::isEmpty(){
        return handles->empty();
}
