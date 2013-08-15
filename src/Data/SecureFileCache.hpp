//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SECFILECACHE_H_
#define SECFILECACHE_H_

#include "HashMap.hpp"
#include "../MiscLib/CharString.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// file cache stores information partially on the disk and partially on the RAM.
// The most-used items will be stored on the RAM.
// This is useful for impressively BIG data sets, but not really that fast.

// A useful example for use of this, is the tile data of an item at X,Y.
// Note: This is only useful if the player is very far from the tile... if the player is close, then it must be pre-loaded.

// The secure form of the fileCache can store millions of data points, while preventing hacks to the system. This fileCache is most secure when it is stored in multiple online locations to prevent manipulation.

// Algorithm: AES-256

template<class T>
class SecureFileCache
{
    HashMap<T>* entries; // RAM entries.
    long max_ram_size, max_map_values;
    long current_ram_size;
    char* store_file;
    bool autoManage;
    fstream dFile;
    long iterator;
    
    public:
        // file used to store data and maxSize for the file.
        SecureFileCache(char* storeFile, long maxRAMSize, bool manual){
            long kilo = 1024;
            long mega = kilo*kilo;
            long giga = mega*kilo;
            long tera = giga*kilo;
            
            // init variables
            max_ram_size = maxRAMSize; // max ram size (in bytes)
            max_map_values = 800000;
            entries = new HashMap<T>(max_map_values);
            iterator=0;
            store_file = storeFile;
            autoManage = !manual;
            current_ram_size = 0;
            
            // initialize the file.
            dFile.open(storeFile, ios::out | ios::in | ios::trunc);
            
            // size variables
            const long fsize = max_ram_size*sizeof(T); // this will be a massive number.
            
            /*long rsize = 0;
            char* c;
            if(fsize >= tera){
                rsize = fsize/tera;
                c = "TB";
            }else if(fsize >= giga){
                rsize = fsize/giga;
                c = "GB";
            }else if(fsize >= mega){
                rsize = fsize/mega;
                c = "MB";
            }else if(fsize >= kilo){
                rsize = fsize/kilo;
                c = "KB";
            }
            cout << "size: " << sizeof(T) << "\ntimes: " << max_ram_size << "\ntotal: " << rsize << c << endl;*/
        };

        // return!
        T* get(long id){
            //cout << "arr" << endl;
            CharString* charID = CharString::ConvertFromLong(id);
            T* data = entries->get(charID);
            //cout << "arr1" << endl;
            
            if(data != 0x0){
                // return if our hashmap has an entry.
                return data;
            }else{
                //cout << "Get Item @ " << (id * sizeof(T)) << " (index" << id << ")" << endl;
                //dFile.open(store_file, ios::in);
                // high-speed seeking
                dFile.seekg((id * sizeof(T)), ios::beg);
                dFile.seekp((id * sizeof(T)), ios::beg);
                
                // convert data to type.
                char* tdata = (char*)malloc(sizeof(T));
                dFile.read(tdata,sizeof(T));
                //dFile.close();
                
                return (T*)tdata;
            }
        };

        // returns ID
        long add(T* data){
            long id = iterator++;
            
            // add item to RAM (if ok to do so)
            if(current_ram_size < max_ram_size){
                entries->add(new HTEntry<T>(CharString::ConvertFromLong(id), data, max_map_values));
                current_ram_size += sizeof(T);
            }
            
            // add item to disk
            long ID = (id * sizeof(T));
            dFile.seekp(ID, ios::beg);
            char* tdata = (char*)data;
            dFile.write(tdata,sizeof(T));
            
            //T* data1 = entries->get(CharString::ConvertFromLong(id));
            return id;
        }; // set an entry
        
        void remove(CharString* key){} // remove an entry
        
        // manual management of data
        // force these items into the RAM.
        void preload(long ID){
            /*T* item = get(ID);
            CharString* charID = CharString::ConvertFromLong(ID);
            entries->add(new HTEntry<T>(charID, item, max_map_size));*/
        } 
        
        // remove these items from the RAM. (place them back into the file cache)
        void unload(long ID){
            
        } 
};
#endif
