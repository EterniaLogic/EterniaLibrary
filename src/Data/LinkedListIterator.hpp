#ifndef LLITERATOR_H_
#define LLITERATOR_H_

template<class T>
class LinkedList;

template<class T>
class LinkedNode;

#include "LinkedList.hpp"

template<class T>
class LinkedListIterator{
public:
    LinkedNode<T> *curnode;
    LinkedList<T> *list;
    LinkedListIterator(LinkedList<T> *list){
        this->list = list;
        curnode = list->baseNode;
    }
    
    T next(){
        T outdata = curnode->data;
        curnode = curnode->next;
        return outdata;
    }
    
    bool hasNext(){
        return (curnode != 0x0);
    }
    
    void reset(){
        curnode = list->baseNode;
    }
    
    bool last(){
        return (curnode == list->currentNode);
    }
    
    bool first(){
        return (curnode == list->baseNode);
    }
};

// ALIASES
#define LLIterator LinkedListIterator
#define LListIterator LinkedListIterator


#endif
