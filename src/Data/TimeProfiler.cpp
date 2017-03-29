#include "TimeProfiler.h"

TimeProfiler::TimeProfiler(){}

TimeProfiler::~TimeProfiler(){}

// begin a profiling session
void TimeProfiler::beginProfile(){
    startTime = clock();
}

// end the profiler, do tallies
void TimeProfiler::endProfile(){
    
}

void TimeProfiler::profileItem(CharString name){
    items.freeze();
    bool hasItem = false;
    for(int i=0;i<items.frozenlen;i++){
        if(items.frozen[i]->Compare(name)){
            hasItem = true;
            break;
        }
    }
    
    if(!hasItem){
        CharString *chartmp = new CharString();
        chartmp->set(name);
        items.add(chartmp);
        
        CyclicList<long> *list = new CyclicList<long>(60);
        list->add(clock()-startTime);
        
        profilemap.add(name, list);
    }else{
        profilemap.get(name)->add(clock()-startTime);
    }
    //beginProfile();
}

// prints out all profiles onto console.
void TimeProfiler::printProfiles(){
    items.freeze();
    cout << "---Printing Timed Profiles:" << endl;
    for(int i=0;i<items.frozenlen;i++){
        CharString name = *(items.frozen[i]);
        CyclicList<long> *averager = profilemap.get(name);
        cout << name.get() << " averaged at: " << averager->getAverage() << " microseconds." << endl;
    }
    cout << "---------------------------" << endl;
}
