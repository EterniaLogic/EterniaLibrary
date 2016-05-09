#ifndef ConcurrentLinkedList_H_
#define ConcurrentLinkedList_H_

// TODO: this

// The ConcurrentLinkedList performs ~like~ a LinkedList, but it takes into account the fact that it
//      may be changed from several threads at the same time.


// Include the LinkedNode with a template

#include "LinkedList.hpp"

//template<T>
class ConcurrentLinkedList{

//private:

public:
    ConcurrentLinkedList(){};
    //void add(T* item); // concurrently add an item to the list
};


#endif
