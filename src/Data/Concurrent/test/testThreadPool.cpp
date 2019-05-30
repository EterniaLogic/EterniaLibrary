#include "testConcurrent.h"

class ClassT{
public:
    ClassT(){}

    void testfunc(bool *running, CharString text){
        while(*running){
            cout << "SPAM: " << text << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }


};

void domsg(bool *running){
    cout << "domsg test 1" << endl;
}

void inittest(){
    ThreadPool tp; // dynamic threadpool (adds extra threads when there are no free threads)
    ClassT t;
    bool v = false;
    tp.enqueue(domsg, &v); //new ThreadJob("j1", (void*)(&domsg)));
    //tp.enqueue(new ThreadJob<ClassT, ClassT>("j1", &domsg));
    //tp.enqueue(new ThreadJob<ClassT::testfunc, ClassT, CharString>("j2", &ClassT::testfunc, &t, "testfunc thread 2"));
    //tp.enqueue(new ThreadJob("j3",&ClassT::testfunc, &t, "testfunc thread 3"));
    //tp.enqueue(new ThreadJob("j4",&ClassT::testfunc, &t, "testfunc thread 4"));


    std::this_thread::sleep_for(std::chrono::seconds(5));
    tp.stopThreads();
}


void testThreadPool(){
    inittest();
}
