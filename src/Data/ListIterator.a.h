#ifndef LIST_ITERATOR_H_
#define LIST_ITERATOR_H_

// Generic List iterator, not concurrent safe
// The LinkedListIterator<T> is more advanced than this.

template<class T>
class List;
#include "List.a.h"

template<class T>
class ListIterator{
private:
    List<T> *listx;
    int itv;
public:
    

    ListIterator(){}
    ListIterator(List<T> *_list){
        this->listx = _list;
        itv=0;
    }
    
    T next(){
        itv++;
        return listx->get(itv-1);
    }
    
    bool hasNext(){
        if(itv <= listx->size()-1)
            return true;
    }
    
    void reset(){
        itv=0;
    }
    
    bool last(){
        return (itv == listx->size()-1);
    }
    
    bool first(){
        return (itv == 0);
    }
};

#endif
