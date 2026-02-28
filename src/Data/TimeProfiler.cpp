#include "TimeProfiler.h"

TimeProfiler::TimeProfiler(){
    averagelistsize = 60;
}

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
        if(items.frozen[i].compare(name)){
            hasItem = true;
            break;
        }
    }
    
    if(!hasItem){
        CharString chartmp = name;
        items.add(chartmp);
        
        CyclicList<double> *list = new CyclicList<double>(averagelistsize);
        list->add((double)clock()-startTime);
        
        profilemap.add(name, list);
    }else{
        profilemap.get(name)->add((double)clock()-startTime);
    }
    //beginProfile();
}

// prints out all profiles onto console.
void TimeProfiler::printProfiles(){
    items.freeze();
    cout << "---Printing Timed Profiles:" << endl;
    for(int i=0;i<items.frozenlen;i++){
        CharString name = items.frozen[i];
        CyclicList<double> *averager = profilemap.get(name);
        cout << name << " averaged at: " << averager->getAverage() << " microseconds." << endl;
    }
    cout << "---------------------------" << endl;
}

double TimeProfiler::getProfileAvg(CharString profile){
    CyclicList<double> *averager = profilemap.get(profile);
    return averager->getAverage();
}
