#include "ThreadPool.h"

PoolThread::PoolThread(ThreadPool* pool){
    connectedPool = pool;
    inuse = false;
    maxruntime = -1;
    currentjob = 0x0; // no job on startup
    starttime = 0; // uses clock()/CLOCKS_PER_SEC;
}

// standard maxruntime is -1
PoolThread::PoolThread(ThreadPool* pool, double maxruntime_seconds){
    connectedPool = pool;
    inuse = false;
    maxruntime = maxruntime_seconds;
    currentjob = 0x0; // no job on startup
    starttime = 0; // uses clock()/CLOCKS_PER_SEC;
}



// MID-RUNNERS
void PoolThread::_run(void (*func)(bool *), bool* running){
    currentjob = 0x0; // no job
    inuse = true;
    starttime = ((double)clock())/(double)CLOCKS_PER_SEC;
    func(running); // send running so that the function can stop any while loops
    inuse = false;
}

// in-between to check if thread is done or not
void PoolThread::_runjob(ThreadJobBase *job){
    inuse = true;
    starttime = ((double)clock())/(double)CLOCKS_PER_SEC;
    job->_run();
    currentjob = 0x0; // done with job
    inuse = false;
}


bool PoolThread::run(std::function<void()> task){
    if(inuse) return false;
    currentjob = 0x0;
    task();
    return true;
}

// Very basic thread run
bool PoolThread::run(void (*func)(bool *), bool* running){
    // just run the thread!
    if(inuse) return false;
    currentjob = 0x0;
    threadx = std::thread(&PoolThread::_run, this, func, running);
    
    return true;
}

// run a function with a specific class
bool PoolThread::run(ThreadJobBase *job){
    if(inuse) return false;
    currentjob = job;
    threadx = std::thread(&PoolThread::_runjob, this, job);
    
    return true;
}


// force-stop this thread
void PoolThread::stop(){
    if(currentjob != 0x0) currentjob->running=false; // do not set done, since it was not completed?
    inuse = false;
    threadx.join(); // Join might be a problem here since the developer might have an infinite loop?
    starttime = 0;
    currentjob = 0x0; // remove connections here...
}
