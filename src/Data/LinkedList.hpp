//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template<class T>
class LinkedNode
{
	public:
		LinkedNode<T> * prev;
		LinkedNode<T> * next;
		T* data;
		LinkedNode(){
	        // do nothing.
        }
};

template<class T>
class LinkedList
{
	//Written January 25th, 2013
	LinkedNode<T> * baseNode;
	LinkedNode<T> * currentNode;
	int _size;
	public:
		LinkedList(){
	        baseNode = new LinkedNode<T>();
	        currentNode = baseNode;
        }
		
		// add item
		void add(T* cc){
	        //adds a Void* Object. This can be declared when using the list.
	        LinkedNode<T>* item = new LinkedNode<T>();
	        item->data = cc;
	        if(currentNode == 0x0){
	            baseNode = currentNode = item;
	        }else{
            	currentNode->next = item;
            	currentNode = item;
	        }
	        _size++;
        }
        
        // return item
		T* get(int index){
	        LinkedNode<T> * current = baseNode;
	        for(int i=0;i<index+1;i++){
		        current = current->next;
	        }
	        return current->data;
        }
        
        // return the size
		int size(){
            return _size;
        }
		
		// convert from linkedList to a static list.
		void freeze(){
            const int len = _size;
            frozen = new T*[len];
            frozenlen = len;
            
            // copy values in!
            LinkedNode<T> * current = baseNode; 
            int i;
	        while(current != 0x0){
	            frozen[i] = current->data;
	            current = current->next; 
	            i++;
	        }
        }
		
		T **frozen;
		int frozenlen;
};

#endif
