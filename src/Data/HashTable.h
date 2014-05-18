#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include "../MiscLib/CharString.h"



class HTEntry
{
    CharString *k, *d;
    unsigned int id;
    void setID(); // h(k), hashing function.
    
    // nodes private:
    HTEntry* next;
    
    public:
        HTEntry();
        HTEntry(CharString* key, CharString* data);
        
        int getID();
        CharString* getKey();
        CharString* getData();
        void set(HTEntry* entry); // set value directly.
        
        // nodes
        void add(HTEntry* entry); // add to the list.
        CharString* get(CharString* key); // get using EXACT key values.
        
};

class HashTable
{
    HTEntry* entries;
    public:
        HashTable(int max);
        void add(HTEntry* entry);
        CharString* get(CharString* key); // get value
        
        int collides;
};
#endif /*HASHTABLE_H_*/
