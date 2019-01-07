#ifndef LLITERATOR_H_
#define LLITERATOR_H_

#include "LinkedList.hpp"

// The LinkedList Iterator is useful for quickly executing a thread-safe iteration that does not throw errors.

// Fast iteration expansion definition
// FOR_LIST(tp at : listxx)
#define FOR_LIST(typex, val, listxx){ \
LinkedListIterator<typex> it = listxx.getIterator(); \
while(it.hasNext()){ \
    typex* val = it.next();


template<class T>
class LinkedListIterator{
public:
    T* listt;
    int listlen;
    int i;
    
    LinkedListIterator(){listlen=0; listt=0x0; i=0;}
    LinkedListIterator(LinkedList<T> list){
        list.freeze();
        listt = list.frozen;
        listlen = list.frozenlen;
        list.frozen=0x0; // disconnect list pointer from the list
        list.frozenlen=0;
    }
    
    T next(){
        i++;
        return listt[i-1];
    }
    
    bool hasNext(){
        return i < listlen;
    }
};


#else 
template<class T>
class LinkedListIterator;
#endif
