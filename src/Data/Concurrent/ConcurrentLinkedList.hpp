#ifndef ConcurrentLinkedList_H_
#define ConcurrentLinkedList_H_

#include "../LinkedList.hpp"
#include "Locker.hpp"
// The ConcurrentLinkedList performs ~like~ a LinkedList, but it takes into account the fact that it
//      may be changed from several threads at the same time.


template<class T>
class LockedNode{
public:
	Locker<LockedNode<T>*> next;
	Locker<T> data;
	LockedNode(){}
	Locker<LockedNode<T>*> getLocker(){
		Locker<LockedNode<T>*> lockx;
		lockx._val = this;
		return lockx;
	}
};

template<class T>
class ConcurrentLinkedList{
private:
    int _size;
    //Locker<LinkedNode<T>> head, currentNode;
    LockedNode<T> *head, *currentNode; // use a list for each node instead of just a node
    
public:
    ConcurrentLinkedList(){head=0x0;currentNode=0x0;}
    
    void add(T cc){
        // 
    	LockedNode<T>* item = new LockedNode<T>();
        item->data = cc;
        if(head == 0x0 || currentNode == 0x0) {
            head = item;
            currentNode = item;
        } else {
            currentNode->next = item->getLocker();
            currentNode = item;
        }
        _size++;
    }
    
    
    T get(int i){
        //    
    }
    
    
    int size(){
        //    
    }
    
    
    void remove(T){
        //
    }
    
    
    void clear(){
        //
    }



};


#endif
