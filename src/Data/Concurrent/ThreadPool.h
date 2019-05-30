#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include <thread>
#include "../Queue.h"
#include "../CharString.h"
#include "../LinkedList.hpp"
#include "ThreadJob.h"
#include <time.h>
#include <chrono>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

// ThreadPools enables for a dynamic data processing environment for computers with multiple CPUs or exclusive sets of code that needs to be run.

// ThreadPool Modes:
//  ThreadJob (Future-like command)
//  EventHandler (uses the ThreadPool to enqueue jobs with certain priorities)

class ThreadPool;

class PoolThread{
private:
    void _run(void (*func)(bool *running), bool* running);
    void _runjob(ThreadJobBase *job); // in-between to check if thread is done or not
public:
    CharString name; // thread name currently being used
    std::thread threadx;
    ThreadPool* connectedPool;
    bool inuse; // thread is running?
    double starttime,maxruntime; // maximum time allowed to run in seconds. (-1 means forever!)
    ThreadJobBase *currentjob; // if using a job while inuse?

    PoolThread(ThreadPool* pool);
    PoolThread(ThreadPool* pool, double maxruntime_seconds);

    bool run(std::function<void()> task);

    bool run(void (*func)(bool *running), bool* running); // run a non-class global function, running is false when nicely asked to stop any while loops.
    bool run(ThreadJobBase *job); // class-specific function with public/private data "run(new ThreadJob("messagefunc", &classa::messagefunc, &pool->running, classa));"
    void stop(); // stops running thread nicely (sets running to false)
};

class ThreadPool{
private:
    LinkedList<PoolThread*> threads;
    //Queue queue; // queue of ThreadJob
    std::queue<std::function<void()>> tasks; // queue

    bool startextra; // starts extra threads when there are no slots or Just Queue up

    int threadlimit, dynthreadlimit; // population cap for threads, managed in poolmanager (-1 for no limit)
    double maxruntime; // global max runtime, threads obey this.
    std::mutex queue_mutex;
    std::condition_variable condition;

    // manages jobs in enqueue
    std::thread poolmanager; // thread that manages all the other thread jobs
    void _threadpoolmanager();
    void _threadpoolmanager_manageThreads(); // limits/stops threads based on options
    void _threadpoolmanager_manageThreadQueue(); // pulls from queue when there is a thread open

    void _init(int numthreads, bool startextra);

public:
    ThreadPool(); // Dynamic number of threads, adds more if no free threads
    ThreadPool(int numthreads); // Fixed number of threads
    ThreadPool(int numthreads, bool startextrathreads); // auto-starts a thread for running slow threads
    virtual ~ThreadPool(); // stops all threads?

    // Running when available [new ThreadJob("jobname", &classa::func, classa)]
    //template<class Function, class... Args>
    //auto enqueue(Function&& f, Args&&... args) -> std::future<typename std::result_of<Function(Args...)>::type>; // function with args

    template<class Function, class... Args>
    void runForceNow(Function&& f, Args&&... args); // run a command right away (skips queue and even creates a new thread if there is not one available)

    // need extra threads?
    void addThreads(int thr); // adds an aditional threads to the pool
    int removeThreads(int number); // removes # of threads that are not in use (returns # actually removed from list)
    void stopThreadAction(CharString jobname);
    void stopThreads(); // Stops all threads forcibly



    bool hasFreeThread(); // is there a thread that is not in use right now?
    int countFreeThreads();

    // -1 by default, doesn't limit.
    void setThreadLimit(int numthreads); // limits threads if above -1. (does not kill them, just removes them when over the limit and finished)
    void setMaxRuntime(double seconds); // (-1 default) sets maximum runtime for all threads, prevents threads that are running forever and ever.
    void setThreadNum(int numthreads, bool startextrathreads);








    // adds queued function
    // enqueue from https://github.com/progschj/ThreadPool/blob/master/ThreadPool.h
    template<class Function, class... Args>
    auto enqueue(Function&& f, Args&&... args)
        -> std::future<typename std::result_of<Function(Args...)>::type>
    {
        //ThreadJobBase *job
        //queue.push(job);

        using return_type = typename std::result_of<Function(Args...)>::type;

        auto task = std::make_shared< std::packaged_task<return_type()> >(
                std::bind(std::forward<Function>(f), std::forward<Args>(args)...)
            );

        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            // don't allow enqueueing after stopping the pool
            tasks.emplace([task](){ (*task)(); });
        }
        condition.notify_one();

        return res;
    }

};

#endif
