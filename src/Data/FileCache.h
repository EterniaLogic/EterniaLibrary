#ifndef FC_H
#define FC_H

#include "FileCache_Policy.h"
#include "LinkedList.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <thread>
#include <chrono>
#define ulong unsigned long

using namespace std;

template<class T>
class FileCache{
public:
    
    ulong max_ram_size;
    ulong current_ram_size;
    CharString store_file;
    fstream dFile;
    ulong iterator;
    
    FCPolicy<T> policy;
    
    FileCache();
    virtual ~FileCache();
    
    void init(CharString storeFile, ulong maxRAMSize,  FCPolicy<T> policy);
    void flush(); // flush changes (follows policy)
    void clear(); // removes ALL data. (AKA: flushes, then moves file to a backup file and makes a new file)
    
    
    static LinkedList<FileCache<T>> FC_flushList = new LinkedList<FileCache<T>>();
    static void flushThread(long milliseconds); // thread to flush data every set # of milliseconds
};


// Treats the FC as a massive array list.
// Removals and inserts are VERY expensive, since gigabytes in a file may have to be shifted to add/remove a value.
template<class T>
class FileCacheList : public FileCache<T>{
public:
    FileCacheList();
    
    long add(T& item); // add item reference, return index
    T& get(long i);
    
    
};

#endif
