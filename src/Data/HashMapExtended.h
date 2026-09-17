#ifndef HASH_MAP_EXT_
#define HASH_MAP_EXT_

#include "HashMap.hpp"

// Acts the same as a hash map, but enables for a vastly larger hash map by creating
//  several discrete internal hash maps that do not have a table larger than 30000.
template<class T>
class HashMapExtended : public HashMap<T>{
    LinkedList<HashMap<T>> maps;
public:
    HashMapExtended<T>(); // total size is handled internally, so dont even need a long input
    ~HashMapExtended<T>(); // very important, to prevent memory leaks with huge hashmaps getting created/destroyed.

    void add(CharString key, T data);
    void addL(uint64_t key, T data); // specific key location
    void addLoc(uint64_t key, HMEntry<T>* entry);
    void clear();

};


#endif
