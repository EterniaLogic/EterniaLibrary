#ifndef FCP_H_
#define FCP_H_

#include "LinkedList.hpp"
#include "../Data/CharString.h"
#include "CRCData.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <unordered_map>
#include <string>


#define KB 1000
#define MB 1000000
#define GB 1000000000
#define TB 1000000000000
#define ulong unsigned long



template<class T>
class FCPolicy{
public:
    FCPolicy();
    
    void add(ulong addr, T* val);
    T* get(ulong addr);
    
    // RAM / File management
    void load(ulong addr); // Load from file (keep loaded?)
    void unload(ulong addr); // Unload to file
    void unload(ulong addr1, ulong addr2); // unload range to file
    
    void flush(); // flush changed data to file
};



template<class T>
class FCRange{
public:
    ulong a, b;
    LinkedList<CRCData<T>> data; // list with change-detection data
    
    FCRange(ulong a, ulong b);
    
    ~FCRange();
    
    bool inRange(ulong v);
    
    void flush();
};



template<class T>
class FCRanges : public FCPolicy<T>{
public:
    LinkedList<FCRange<T>> ranges;
    
    FCRanges();
    
    void addRange(FCRange<T> range);
    void remRange(FCRange<T> range);
};



// Usage over time policy FIFO
template<class T>
class FCUsage : public FCPolicy<T>{
    unordered_map<ulong, CRCData<T>> entries; // RAM entries.
    LinkedList<ulong> loadedIDs;
    
    
    T* get(ulong id);
    void flush();
};

#endif
