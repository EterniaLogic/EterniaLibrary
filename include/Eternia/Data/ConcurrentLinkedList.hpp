#ifndef ConcurrentLinkedList_H_
#define ConcurrentLinkedList_H_

#include "LinkedList.hpp"
// The ConcurrentLinkedList performs ~like~ a LinkedList, but it takes into account the fact that it
//      may be changed from several threads at the same time.

template<class T>
class ConcurrentLinkedList{
private:
    bool inuse;
    int _size;
    LinkedNode<T> *head, *currentNode;
    
public:
    ConcurrentLinkedList(){
        _size=0;
        inuse=false;
        head = 0x0;
    }
    
    void add(T*){
        // 
        LinkedNode<T>* item = new LinkedNode<T>();
        item->data = cc;
        if(head == 0x0 || currentNode == 0x0) {
            head = item;
            currentNode = item;
        } else {
            currentNode->next = item;
            currentNode = item;
        }
        _size++;
    }
    
    
    T* get(int i){
        //    
    }
    
    
    int size(){
        //    
    }
    
    
    void remove(T*){
        //
    }
    
    
    void clear(){
        //
    }
};


#endif
