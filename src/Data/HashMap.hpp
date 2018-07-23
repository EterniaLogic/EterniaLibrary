//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef HashMap_H_
#define HashMap_H_

// woo for messy template time! =P

#include <iostream>
#include "../Data/CharString.h"
#include "LinkedList.hpp"
#include "../Algorithm/Cryptography/ExHash_SumMap.hpp"
using namespace std;

template<class T>
class HTEntry {
        // nodes private:
        // h(k), hashing function.
        void setID() {
            // does a HashMap<T> implementation.

            //cout << calcmaxsize(sizeof(uint8_t)) << endl;
            if(size < calcmaxsize(sizeof(uint8_t)))
                this->id = (uint8_t)exSumMap<uint8_t>(&k,(uint8_t)size,3);
            else if(size < calcmaxsize(sizeof(uint16_t)))
                this->id = (uint16_t)exSumMap<uint16_t>(&k,(uint16_t)size,3);
            else if(size < calcmaxsize(sizeof(uint32_t)))
                this->id = (uint32_t)exSumMap<uint32_t>(&k,(uint32_t)size,3);
            else if(size < calcmaxsize(sizeof(uint64_t))) // That is a BIG list.. better have exabytes of memory...
                this->id = (uint64_t)exSumMap<uint64_t>(&k,(uint64_t)size,3);
                
            //cout << "DBG HMID ("<< k.get() <<") " << this->id << " " <<(uint64_t) size << endl;
            //cout.flush();
        }
        
        uint64_t calcmaxsize(int wid){
            return (2<<((8*wid)-1));
        }


    public:
        HTEntry() {
            this->id=0;
            this->k=0x0;
            this->d=0x0;
            this->size=65535;
            this->next=0x0;
        }
        HTEntry(CharString key, T* data,int size) {
            this->id=0;
            this->k=key;
            this->d=data;
            this->next=0x0;
            this->size=size;
            setID();
        }
        HTEntry(uint64_t id_, T* data,int size) {
            this->id=id_;
            this->k=0x0;
            this->d=data;
            this->next=0x0;
            this->size=size;
        }

        uint64_t size;
        HTEntry<T>* next; // for over-load of collisions. (separate chaining)

        CharString k;
        T *d;
        uint64_t id;

        uint64_t getID() {
            return id;    // returns ID (Hashed key)
        }
        CharString getKey() {
            return k;    // returns key
        }
        T* getData() {
            return d;   // returns data
        }
        void set(HTEntry<T>* entry) {
            id = entry->getID();    // set value directly.
            k = entry->getKey();
            d = entry->getData();
        }

        // nodes
        void add(HTEntry<T>* entry) {
            HTEntry<T>* current = this;
            while(current->next != 0x0)
                current = current->next;
            current->next = entry;
            current->next->size = this->size;
        } // add to the list.



        T* get(CharString key) {
            // add to the endx.
            HTEntry<T>* current = this;
            // loop through the list.
            while(current != 0x0) {
                if(current->getKey().Compare(key)) {
                    return current->getData();
                }
                current = current->next;
            }

            return 0x0;
        } // get using EXACT key values.

        T* get(uint64_t key) {
            // add to the endx.
            HTEntry<T>* current = this;
            // loop through the list.
            while(current != 0x0) {
                if(current->getKey().Compare(key)) {
                    return current->getData();
                }
                current = current->next;
            }

            return 0x0;
        } // get using EXACT key values.

        T* remove(CharString* key) {
            // add to the endx.
            HTEntry<T>* current = this, last = 0x0;
            // loop through the list.
            while(current != 0x0) {
                if(current->getKey().Compare(key)) {
                    T* data = current->getData();

                    if(last == 0x0) {
                        this->next = current->next;
                    } else {
                        last->next = current->next;
                    }

                    delete current;
                    return data;
                }

                last = current;
                current = current->next;
            }

            return 0x0;
        } // get using EXACT key values.

        // reset this item
        void reset() {
            next = 0x0;
            k = 0x0;
            id = 0;
            d = 0x0;
        }

};

template<class T>
class HashMap {
        HTEntry<T>* entries;
        LinkedList<CharString> keys;
    public:
        HashMap() {
            // initialize hashmap
            entries=new HTEntry<T>[65535];
            size=65535;
            keys.clear();
            for(int i=0; i<size; i++) {
                entries[i].id=0;
                entries[i].next=0x0;
                entries[i].k=0x0;
                entries[i].d=0x0;
                entries[i].size = size;
            }
        };


        HashMap(int max) {
            // initialize hashmap with pre-defined value
            entries = new HTEntry<T>[(const int)max];
            size=max;
            keys.clear();
            for(int i=0; i<size; i++) {
                entries[i].id=0;
                entries[i].next=0x0;
                entries[i].k=0x0;
                entries[i].d=0x0;
                entries[i].size = size;
            }
        };


        void add(CharString key, T* data) {
            //cout << "add(key,*data)" << endl;
            HTEntry<T>* entry = new HTEntry<T>(key,data,size);
            entry->size = size;

            int idx = entry->getID();

            // prevent repetitive code
            //cout << "addLoc("<< idx <<",*entry)" << endl;
            this->addLoc(idx,entry);
            //cout << "keys add key" << endl;
            keys.add(new CharString(key.get(), key.getSize()));
            //cout << "add(key,*data) END" << endl;
        };

        void addL(uint64_t key, T* data) {
            HTEntry<T>* entry = new HTEntry<T>(key,data,size);
            entry->size = size;
            this->addLoc(key,entry);
        };

        void addLoc(uint64_t key, HTEntry<T>* entry) {
            //cout << "addLoc("<< key <<","<< entry <<")" << endl;
            entry->size = size; // make sure size is correct
            //cout << "entry size = " << entry->size << endl;
            if(entries[key].id > 0) {
                // add to endx of linked list.
                entries[key].add(entry);
                collides++;
            } else {
                // directly set first item at key.
                entries[key].set(entry);
                entries[key].size = this->size;
            }
        }


        T* get(CharString key) {
            // basic key to search with.
            HTEntry<T>* S = new HTEntry<T>(key, 0x0, size);
            // does this key exist?

            if(entries[S->getID()].id > 0) {
                // if so, compare the key in the list.
                // determine if item on this list is within bounds.
                if(entries[S->getID()].getKey().Compare(key)) {
                    return entries[S->getID()].getData();
                } else {
                    // if not, then we need to loop through the linked list for it.
                    return entries[S->getID()].get(key);
                }
            }
            return 0x0;
        }; // get value

        T* getL(uint64_t key) {
            // basic key to search with.

            if(entries[key].id > 0) {
                return entries[key].getData();
            }
            return 0x0;
        }; // get value
        
        LinkedList<T>* getKeys(){
            return &keys;
        }


        // get the direct item
        T* getDirect(uint64_t id) {
            // does this key exist?


            if(entries[id].getID() > 0) {
                // if so, compare the key in the list.
                // determine if item on this list is within bounds.
                return entries[id].getData();
            }
            return 0x0;
        }; // get value


        // remove item based on key.
        T* remove(CharString key) {
            // basic key to search with.
            HTEntry<T>* S = new HTEntry<T>(key, 0x0, size);
            // does this key exist?
            if(entries[S->getID()].getID() > -1) {
                // if so, compare the key in the list.
                // determine if item on this list is within bounds.

                //cout << "a1" << key->get() << endxl;
                if(entries[S->getID()].getKey().Compare(key)) {
                    //cout << "a2" << endxl;
                    T* item = entries[S->getID()].getData();
                    entries[S->getID()].reset();
                    return item;
                } else {
                    // if not, then we need to loop through the linked list for it.
                    //cout << "a3" << key->get() << endxl;
                    T* item = entries[S->getID()].get(key);
                    entries[S->getID()].remove(key);
                    return item;
                }
            }
            return 0x0;
        };

        // remove item based on key.
        T* removeL(uint64_t ID) {
            // basic key to search with.
            // does this key exist?
            if(entries[ID].getID() > -1) {
                // if so, compare the key in the list.
                // determine if item on this list is within bounds.

                T* item = entries[ID].getData();
                entries[ID].reset();
                return item;
            }
            return 0x0;
        };

        int collides,size; // for use with hashmap debugging.
};

#endif /*HashMap_H_*/
