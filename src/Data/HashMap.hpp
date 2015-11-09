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
#include "../MiscLib/CharString.h"
using namespace std;

template<class T>
class HTEntry
{
    // nodes private:
    HTEntry<T>* next; // for over-load of collisions. (separate chaining)
    

    // h(k), hashing function.
    void setID(){
        // does a HashMap<T> implementation.    
        unsigned int len = k->getSize();
        char* cc = k->get();
        unsigned long end = 0;
        
        if(len < 3){ // 0 collisions
            for(unsigned int i=0;i<len;i++){
                end = cc[i] + (end<<6) + (end << 12) - end;
                //end -= end<<2;
            }
            while(end > size){
                end /= 10;
            }
        }else if(len == 3){ // 0 collisions
            for(unsigned int i=0;i<len;i++){
                // 3-len collision test
                end = cc[i] + (end<<3) + (end<<4) - end;
            }
            while(end > size){
                end /= 10;
            }
        }else if(len == 5){ // len = 5, ? collisions. (tested 8700 -> 61 collisions)
            for(unsigned int i=0;i<len;i++){
                // 5-len collision test
                end += (cc[i]-31)<<(10*(i+1));
            }
            
            //end = end%len+end;
            while(end > size){
                end /= 1000;
            }
        }else{ // 338 collisions out of 9025 tested. (Pretty good, but not perfect.)
            //end = 1;
            unsigned long a1 = 32416190071;
            unsigned long a2 = 15487249;
            unsigned long a3 = 88888;
            unsigned long a4 = 32416190071;
            for(unsigned int i=0;i<len;i++){
                end = (cc[i]*len*(i+1)*end)*2 + ~(cc[i]<<4) + (end%(len*5)) + ((cc[i])%len) + (end<<7);
                end = end ^ (a1*cc[i]); // XOR with very large prime #
                end = end | (a2*cc[i]); // OR with pretty large prime #
                end = end | (a3*cc[i]);
                end = end | (a4*cc[i]);
            }
        
            
            // smaller number in while loop improves accuracy...
            // it's impossible to be accurate because this algorithm is constricted to a 
            //      max size of 199999999...
            while(end > size){
                end /= 10;
            }
        }
        
        id = end;
    } 
    
    
    public:
        HTEntry(){id=0; k=0x0; d=0x0;size=0;}
        HTEntry(CharString* key, T* data, int _size){id=0; k=key; d=data; size=_size; setID();}
        HTEntry(long id_, T* data, int _size){id=id_; k=0x0; d=data; size=_size;}
        
        unsigned long size;
        
        CharString *k;
        T *d;
        unsigned int id;    
        
        int getID(){ return id; } // returns ID (Hashed key)
        CharString* getKey(){ return k; } // returns key
        T* getData(){return d;} // returns data
        void set(HTEntry<T>* entry){id = entry->getID(); k = entry->getKey(); d = entry->getData();} // set value directly.
        
        // nodes
        void add(HTEntry<T>* entry){
            HTEntry<T>* current = this;
            while(current->next != 0x0){
                current = current->next;
                cout << current << endl;
            }
            entry->next = 0x0;
            current->next = entry;
        } // add to the list.
        
        
        
        T* get(CharString* key){
            // add to the end.    
            HTEntry<T>* current = this;
            // loop through the list.
            while(current != 0x0) {
                if(current->getKey()->Compare(key)){    
                    return current->getData();
                }
                current = current->next;
            }
            
            return 0x0;
        } // get using EXACT key values.
        
        T* get(long key){
            // add to the end.    
            HTEntry<T>* current = this;
            // loop through the list.
            while(current != 0x0) {
                if(current->getKey()->Compare(key)){    
                    return current->getData();
                }
                current = current->next;
            }
            
            return 0x0;
        } // get using EXACT key values.
        
        T* remove(CharString* key){
            // add to the end.    
            HTEntry<T>* current = this, last = 0x0;
            // loop through the list.
            while(current != 0x0) {
                if(current->getKey()->Compare(key)){   
                    T* data = current->getData();
                    
                    if(last == 0x0) {
                        this->next = current->next;
                    }else{
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
        void reset(){
            next = 0x0;
            k = 0x0;
            id = 0;
            d = 0x0;
        }
        
};

template<class T>
class HashMap
{
    HTEntry<T>* entries;
    public:
        HashMap(){
            // initialize hashmap
            entries=new HTEntry<T>[40000];
            size=40000;
            for(int i=0;i<size;i++){
                entries[i].size = size;
            }
        };
        
        
        HashMap(int max){
            // initialize hashmap with pre-defined value
            entries = new HTEntry<T>[(const int)max];
            size=max;
            for(int i=0;i<size;i++){
                entries[i].size = size;
            }
        };
        
        
        void add(HTEntry<T>* entry){
            if(entries[entry->getID()].id != 0){
                // add to end of linked list.    
                entries[entry->getID()].add(entry);
                collides++;
            }else{
                // directly set first item at key.
                entries[entry->getID()].set(entry);        
            }
        };
        
        
        T* get(CharString* key){
            // basic key to search with.
            HTEntry<T>* S = new HTEntry<T>(key, 0x0, size);  
            // does this key exist?
            
            if(entries[S->getID()].id != 0){
                // if so, compare the key in the list.
                // determine if item on this list is within bounds.
                if(entries[S->getID()].getKey()->Compare(key)){    
                    return entries[S->getID()].getData();
                }else{    
                    // if not, then we need to loop through the linked list for it.
                    return entries[S->getID()].get(key);
                }
            }
            return 0x0;
        }; // get value
        
        
        // get the direct item
        T* getDirect(long id){
            // does this key exist?
            
            
            if(entries[id].getID() != 0){
                // if so, compare the key in the list.
                // determine if item on this list is within bounds.
                return entries[id].getData();
            }
            return 0x0;
        }; // get value
        
        
        // remove item based on key.
        T* remove(CharString* key){
            // basic key to search with.
            HTEntry<T>* S = new HTEntry<T>(key, 0x0, size);  
            // does this key exist?
            if(entries[S->getID()].getID() != 0){
                // if so, compare the key in the list.
                // determine if item on this list is within bounds.
                
                cout << "a1" << key->get() << endl;
                if(entries[S->getID()].getKey()->Compare(key)){ 
                    cout << "a2" << endl;
                    T* item = entries[S->getID()].getData();                
                    entries[S->getID()].reset();
                    return item;
                }else{    
                    // if not, then we need to loop through the linked list for it.
                    cout << "a3" << key->get() << endl;
                    T* item = entries[S->getID()].get(key);
                    entries[S->getID()].remove(key);
                    return item;
                }
            }
            return 0x0;
        };
        
        int collides,size; // for use with hashmap debugging.
};

#endif /*HashMap_H_*/
