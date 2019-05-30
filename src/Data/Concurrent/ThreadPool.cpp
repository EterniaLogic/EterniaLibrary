#include "ThreadPool.h"

// Dynamic growth
ThreadPool::ThreadPool(){
    _init(1, true);
    dynthreadlimit = 10; // if there are over 10 extra threads, remove them.
}

// Fixed threadpool with no dynamic thread starting
ThreadPool::ThreadPool(int numthreads){
    _init(numthreads, false);
}

// semi-dynamic with a fixed start
ThreadPool::ThreadPool(int numthreads, bool startextra){
    _init(numthreads, startextra);
}

// main initializer from constructors
void ThreadPool::_init(int numthreads, bool startextra){
    for(int i=0;i<numthreads;i++){
        threads.add(new PoolThread(this));
    }

    this->startextra = startextra;
    this->threadlimit = -1;
    this->dynthreadlimit = -1; // for dynamic threading (> 10 threads means that 10 threads will be unused extra, but over that, there will be none)

    // start thread pool manager thread
    this->poolmanager = std::thread(&ThreadPool::_threadpoolmanager, this);
}

// stops all threads?
ThreadPool::~ThreadPool(){
    stopThreads();
}




// in function `EventHandler::_doEvents(PriorityItem*, bool)': undefined reference to
//std::future<std::result_of<void (EventHandler::*(EventHandler*, PriorityItem*&, bool&))(PriorityItem*, bool)>::type> ThreadPool::enqueue<void (EventHandler::*)(PriorityItem*, bool), EventHandler*, PriorityItem*&, bool&>(void (EventHandler::*&&)(PriorityItem*, bool), EventHandler*&&, PriorityItem*&, bool&)
//std::future<std::result_of<void (EventHandler::*(EventHandler*, PriorityItem*&, bool&))(PriorityItem*, bool)>::type> ThreadPool::enqueue<void (EventHandler::*)(PriorityItem*, bool), EventHandler*, PriorityItem*&, bool&>(void (EventHandler::*&&)(PriorityItem*, bool), EventHandler*&&, PriorityItem*&, bool&)


void ThreadPool::stopThreads(){ // removes # of threads that are not in use
    LinkedListIterator<PoolThread*> iter = threads.getIterator();
    while(iter.hasNext()){
        PoolThread *pt = iter.next();
        if(!pt->inuse){
            pt->stop(); // make sure nothing is running?
            threads.remove(pt);
        }
    }
}


int ThreadPool::removeThreads(int number){ // removes # of threads that are not in use
    int removed = 0;
    for(int i=0;i<number;i++){
        // loop N times, unless reached the end of the other list.
        // LinkedListIterator is supposedly good with MT operations since it runns with internal pointers.
        LinkedListIterator<PoolThread*> iter = threads.getIterator();
        while(iter.hasNext()){
            PoolThread *pt = iter.next();
            if(!pt->inuse){
                pt->stop(); // make sure nothing is running?
                threads.remove(pt);
                removed++;
            }
        }
    }
    return removed; // possibly didn't get the required number but there are too many threads in use(?)
}

void ThreadPool::setThreadLimit(int numthreads){
    this->threadlimit = numthreads;
}

void ThreadPool::setMaxRuntime(double seconds){
    this->maxruntime = seconds;
}

bool ThreadPool::hasFreeThread(){
    // loop through threads
    LinkedListIterator<PoolThread*> iter = threads.getIterator();
    while(iter.hasNext()){
        PoolThread *pt = iter.next();
        if(! pt->inuse){
            return true;
        }
    }

    return false;
}

int ThreadPool::countFreeThreads(){
    int freet = 0;

    // loop through threads
    LinkedListIterator<PoolThread*> iter = threads.getIterator();
    while(iter.hasNext()){
        PoolThread *pt = iter.next();
        if(! pt->inuse){
            freet++;
        }
    }

    return freet;
}

void ThreadPool::setThreadNum(int numthreads, bool startextrathreads){
    this->startextra = startextrathreads;

    int tr = threads.size() - numthreads;
    for(int i=0;i<tr;i++){
        threads.add(new PoolThread(this));
    }

}

void ThreadPool::_threadpoolmanager(){
    long ticks_per_sec, time, last;

    ticks_per_sec = 5.0; // fairly fast, about 0.5% cpu?

    int iw=0; // used for limitthreads, max runtime so that not too much CPU is used for thread management

    while(true){
        last = clock();
        iw = (iw >= 5) ? 0 : iw+1; // sub-counter for manager


        if(iw == 0){ // run every second
            _threadpoolmanager_manageThreads();
        }


        _threadpoolmanager_manageThreadQueue();


        time = (1000000.0/ticks_per_sec) - (((clock()-last)*1000000.0)/CLOCKS_PER_SEC);
        if(time > 0) std::this_thread::sleep_for(std::chrono::microseconds(time));
    }
}


void ThreadPool::_threadpoolmanager_manageThreads(){
    if(threadlimit > -1){
        // remove extra if above limitthreads, does not kill threads but will try to remove them when they are not in use.
        int numbert = threads.size();
        int overt = numbert - threadlimit;

        if(overt > 0){
            removeThreads(overt);
        }
    }

    // dynamic threading
    if(dynthreadlimit > -1){
        // count inactive threads and remove extras
        int freet = countFreeThreads();
        int freelimit = freet-dynthreadlimit;
        if(freelimit > 0){
            // remove extras
            removeThreads(freelimit);
        }
    }

    // Manage maximum runtime
    LinkedListIterator<PoolThread*> iter = threads.getIterator();
    while(iter.hasNext()){
        PoolThread *pt = iter.next();

        if(! pt->inuse) continue; // skip this one.

        // determine max runtime (PoolThread runtime has a higher priority than global runtime in ThreadPool)
        // if threadpool runtime is >-11, then focus on that. Otherwise, if ThreadPool runtime >-1, then focus on that
        double _maxruntime = (pt->maxruntime > -1) ? pt->maxruntime :
                                                    ((maxruntime > -1) ? maxruntime :
                                                        -1);
        if(_maxruntime > -1){
            double timenowsec = clock()/CLOCKS_PER_SEC;
            double timediff = timenowsec - pt->starttime;
            if(timediff > _maxruntime){
                pt->stop(); // kill thread!
            }
        }
    }
}

void ThreadPool::_threadpoolmanager_manageThreadQueue(){
    // start enqueued jobs
    while(!tasks.empty() && (hasFreeThread() || startextra)){
        // only pop a job from the queue if there is a free thread...
        bool found = false;
        LinkedListIterator<PoolThread*> iter = threads.getIterator();
        while(iter.hasNext()){
            PoolThread *pt = iter.next();
            if(! pt->inuse){
                // pop a job and use it.
                pt->run(tasks.front());
                tasks.pop();
                found=true;
            }
        }

        // can start extra?
        if(!found && startextra){
            PoolThread* pt = new PoolThread(this);
            threads.add(pt);
            pt->run(tasks.front());
            tasks.pop();
        }
    }
}
