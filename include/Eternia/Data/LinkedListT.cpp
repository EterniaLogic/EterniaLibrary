//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "LinkedListT.h"

LinkedNodeT::LinkedNodeT(){
    // do nothing.
}

LinkedNodeT::~LinkedNodeT(){
}

LinkedListT::LinkedListT()
{
	baseNode = new LinkedNodeT();
	currentNode = baseNode;
}

// remove all nodes
LinkedListT::~LinkedListT()
{
  LinkedNodeT* current = baseNode;
  while(current != 0x0){
    LinkedNodeT* cc = current;
    current = current->next;
    delete cc;
  }
}

void LinkedListT::add(void *cc){
	//adds a Void* Object. This can be declared when using the list.
	LinkedNodeT* item = new LinkedNodeT();
	item->data = cc;
	if(currentNode == 0x0){
	    baseNode = currentNode = item;
	}else{
    	currentNode->next = item;
    	currentNode = item;
	}
	_size++;
}

void* LinkedListT::get(int index){
	LinkedNodeT * current = baseNode;
	for(int i=0;i<index+1;i++){
		current = current->next;
	}
	return current->data;
}

int LinkedListT::size(){
    return _size;
}

// convert from linkedList to a static list.
void LinkedListT::freeze(){
    const int len = _size;
    frozen = new void*[len];
    frozenlen = len;
    
    // copy values in!
    LinkedNodeT * current = baseNode; 
	int i=0;
	while(current != 0x0){
	    frozen[i] = current->data;
	    current = current->next; 
		i++;
	}
}
