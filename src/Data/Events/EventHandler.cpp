#include "EventHandler.h"

//#define DEBUG_EH

#ifdef DEBUG_EH
#define debugLogEH(ehs) cout << ehs << endl; cout.flush();
#else
#define debugLogEH(ehs)
#endif


#include <iostream> // testing purposes only
using namespace std;

EventHandler::EventHandler() {
    handles = new PriorityQueue();
    threads=false;
}

EventHandler::~EventHandler() {
    if(threads){
        stopThreading();
    }
}


void EventHandler::_managethread(double ticks_per_sec, bool subthreads){
    long time, last;
    
    // handle events
    while(threads){
        last = clock();
        
        // run handler
        handleEvents(subthreads); // subthreaded?
        
        time = (1000000.0/ticks_per_sec) - (((clock()-last)*1000000.0)/CLOCKS_PER_SEC);
        if(time > 0) std::this_thread::sleep_for(std::chrono::microseconds(time));
    }
}

// Start threading!
void EventHandler::startThreading(double TPS, int threads, bool subthreads){
    threads = true;
    this->pool.setThreadNum(threads,false);
    
    // Manager thread
    managerthread = std::thread(&EventHandler::_managethread, this, TPS, subthreads);
}

void EventHandler::stopThreading(){
    managerthread.join();
    pool.stopThreads();
    threads = false;
}

EventHandle* EventHandler::createEvent(void (*func)(), unsigned long priority) {
    EventHandle *handle = new EventHandle(func);
    addEvent(handle, priority);

    return handle;
}

EventHandle* EventHandler::createEvent(void (*func)(void*), unsigned long priority) {
    EventHandle *handle = new EventHandle(func);
    addEvent(handle, priority);

    return handle;
}

EventHandle* EventHandler::createEvent(void (*func)(void*,void*), unsigned long priority) {
    EventHandle *handle = new EventHandle(func);
    addEvent(handle, priority);

    return handle;
}

// handles automatic events
void EventHandler::handleEvents(bool subthreaded) {
    // loop through all items, priority first
    //      if an item has been handled it will be removed.
    
    _doEvents(this, handles, handles->top(), subthreaded);
    handles->downheap(handles->top());
}

// handles automatic events
void EventHandler::handleEvents() {
    // loop through all items, priority first
    //      if an item has been handled it will be removed.
    
    debugLogEH("hE0");
    _doEvents(this, handles, handles->top(), false);
    debugLogEH("hE1");
    handles->downheap(handles->top());
    debugLogEH("hE2");
}

// add Event, the priority is set by lowest value
void EventHandler::addEvent(EventHandle *event, int priority) {
    handles->insert(priority, event);
}

// remove a specific object (expensive)
void EventHandler::removeEvent(EventHandle *event) {
    // search through the handles to find it.
    //handles->remove(event);
}

// clear all objects
void EventHandler::clearEvents() {
    // loop through all items
    debugLogEH("cE1");
    handles->clearAll();
}

// returns if the event queue is empty
bool EventHandler::isEmpty() {
    return handles->empty();
}



// queue is only set for the top item
void _doEvents(EventHandler* handler, PriorityQueue* handles, PriorityItem* item, bool threaded) {
    // handle left first, then handle right
    if(item == 0x0) return;
    debugLogEH("dE1");

    // execute event
    if(item->data != 0x0) {
        EventHandle* handle = (EventHandle*)item->data;
        debugLogEH("dE2---xx");
        if(!handle->handle()) {
            debugLogEH("dE3---" << handles->getSize());
            handles->remove(item);
            debugLogEH("dE4");
        }
        debugLogEH("dE5---xx");
    }
    debugLogEH("dE6");

    // go through the branches
    if(item->left != 0x0) {
        if(threaded){ 
            handler->pool.enqueue(_doEvents, handler, handles, item->left, threaded);
            /*void (*f1)(EventHandler* handler, PriorityQueue* handles, PriorityItem* item, bool threaded);
            f1 = &_doEvents;
            handler->pool.enqueue([f1, handler, handles, item, threaded]{
                return (*_doEvents)(handler, handles, item->left, threaded);
            }); //&_doEvents, handler, handles, item->left, threaded);*/
        }else{
            (*_doEvents)(handler, handles, item->left, threaded);
        }
    }
    if(item->right != 0x0) {
        if(threaded){
            handler->pool.enqueue(_doEvents, handler, handles, item->right, threaded);
        }else{
            _doEvents(handler, handles, item->right, threaded);
        }
    }
}
