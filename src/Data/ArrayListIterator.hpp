#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

// Generic List iterator, not concurrent safe
// The LinkedListIterator<T> is more advanced than this.

template<class T>
class ArrayList;
#include "ArrayList.hpp"

template<class T>
class ArrayListIterator{
private:
    ArrayList<T> *listx;
    int itv; // starts negative?
public:
    ArrayListIterator(ArrayListIterator<T> *_list){
        this->listx = _list;
        itv=-1;
    }
    
    T next(){
        itv++;
        return listx->get(itv);
    }
    
    bool hasNext(){
        if(itv < listx->size()-1)
            return true;
    }
    
    void reset(){
        itv=-1;
    }
    
    bool last(){
        return (itv == listx->size()-1);
    }
    
    bool first(){
        return (itv <= 0);
    }
};

#endif
