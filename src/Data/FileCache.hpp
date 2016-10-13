//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef FILECACHE_H_
#define FILECACHE_H_

// #include "HashMap.hpp"
#include "LinkedList.hpp"
#include "../Data/CharString.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <unordered_map>
#include <string>

using namespace std;

// I do not like templates. >.< they are always so messy, but they are useful only for things like these.

// file cache stores information partially on the disk and partially on the RAM.
// The most-used items will be stored on the RAM.
// This is useful for impressively BIG data sets, but not really that fast.

// A useful example for use of this, is the tile data of an item at X,Y.
// Note: This is only useful if the player is very far from the tile... if the player is close, then it must be pre-loaded.

// TODO: Follow a class's subclass data to allow complex data saving

template<class T>
class FileCache {
        unordered_map<long, T> entries; // RAM entries.
        LinkedList<long> *loadedIDs;
        long max_ram_size;
        long current_ram_size;
        char* store_file;
        bool autoManage;
        fstream dFile;
        long iterator;

    public:
        // file used to store data and maxSize for the file.
        FileCache(char* storeFile, long maxRAMSize, bool manual) {
            long kilo = 1024;
            long mega = kilo*kilo;
            long giga = mega*kilo;
            long tera = giga*kilo;

            // init variables
            max_ram_size = maxRAMSize; // max ram size (in bytes)
            iterator=0;
            store_file = storeFile;
            autoManage = !manual;
            current_ram_size = 0;

            // make sure it's deleted first.
            remove(storeFile);

            //entries = new HashMap<T>(40000);
            loadedIDs = new LinkedList<long>();

            // initialize the file.
            dFile.open(storeFile, ios::out | ios::in | ios::trunc);
        };

        ~FileCache() {

        };

        // return!
        T* get(long id) {
            //CharString* tt = CharString::ConvertFromLong(id);
            T preloaded = entries[id];

            //cout << "preloaded" << preloaded << endl;

            // return data if it is pre-loaded
            if(loadedIDs->get(id) != 0) {
                return &preloaded;
            } else {
                dFile.seekg((id * sizeof(T)), ios::beg);
                dFile.seekp((id * sizeof(T)), ios::beg);

                // convert data to type.
                char* tdata = (char*)malloc(sizeof(T));
                dFile.read(tdata,sizeof(T));

                // return value
                return (T*)tdata;
            }
        };

        // returns ID
        long add(T* data) {
            long id = iterator++;

            // add item to disk
            long ID = (id * sizeof(T));
            dFile.seekp(ID, ios::beg);
            char* tdata = (char*)data;
            dFile.write(tdata,sizeof(T));

            //T* data1 = entries->get(CharString::ConvertFromLong(id));
            return id;
        }; // set an entry

        //void remove(CharString* key){} // remove an entry

        // manual management of data
        // force these items into the RAM.
        void preload(long ID) {
            //CharString* tt = CharString::ConvertFromLong(ID);

            if(entries->get(ID) == 0x0) return; // determine if it has been added before

            loadedIDs->add(&ID);
            entries->addL(ID, get(ID));
        }

        // remove these items from the RAM. (place them back into the file cache)
        void unload(long ID) {
            //CharString* tt = CharString::ConvertFromLong(ID);
            T* data = entries->getL(ID);
            if(data == 0x0) return; // determine that it does not exists

            loadedIDs->remove(ID); // remove from the ID list
            //entries->removeL(ID); // remove data from the HashMap
            // entries[ID]


            add(data);
        }

        void clean() {
            remove(store_file);
        }
};
#endif
