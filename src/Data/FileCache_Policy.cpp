#include "FileCache_Policy.h"

template<class T>
FCPolicy<T>::FCPolicy(){
    
}

template<class T>
void FCPolicy<T>::add(ulong addr, T* val) {}

template<class T>
T* FCPolicy<T>::get(ulong addr) {return 0x0;}
    
// RAM / File management
template<class T>
void FCPolicy<T>::load(ulong addr){} // Load from file (keep loaded?)

template<class T>
void FCPolicy<T>::unload(ulong addr){} // Unload to file

template<class T>
void FCPolicy<T>::unload(ulong addr1, ulong addr2){} // unload range to file
    
// flush changed data to file
template<class T>
void FCPolicy<T>::flush(){
    // loop through loaded data and flush changed data to file.
}




template<class T>
FCRange<T>::FCRange(ulong a, ulong b){
    this->a=a;
    this->b=b;
}

template<class T>
FCRange<T>::~FCRange(){ data.clear(); }
    
template<class T>
bool FCRange<T>::inRange(ulong v){
    return ((a <= v) && (v <= b)) ||
            ((b <= v) && (v <= a));
}
    
template<class T>
void FCRange<T>::flush(){
    // loop through loaded data and flush changed data to file.
}



template<class T>
FCRanges<T>::FCRanges(){ }
    
template<class T>
void FCRanges<T>::addRange(FCRange<T> range){}
template<class T>
void FCRanges<T>::remRange(FCRange<T> range){}





// Usage over time policy FIFO
template<class T>
T* FCUsage<T>::get(ulong id){
    T preloaded = entries[id];
    
    if(loadedIDs.get(id) != 0) {
        return &preloaded;
    }else{
        return 0x0;
    }
}

template<class T>
void FCUsage<T>::flush(){
    // loop through loaded data and flush changed data to file.
}
