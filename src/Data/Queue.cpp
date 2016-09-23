//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Queue.h"

using namespace std;

////////////////////////
//////// Queue! ////////
////////////////////////

QueueNode::QueueNode(){
    data = 0x0;
    Prev = 0x0;
    Next = 0x0;
}

Queue::Queue()
{
    Head=0x0;
    Tail=0x0;
    Size=0;
}

// clean up!
Queue::~Queue()
{
    void* cc = pop();
    while(cc != 0x0){
      delete cc;
      void* cc = pop();
    }
}

/* Desc: Add to the back of the queue
 */
void Queue::push(void* data){
      // increment address system
      QueueNode* item = new QueueNode();
      item->data = data;
      if(Tail == 0x0){ // is head null?
            Head = item; // tadah! :D
            Tail = item;
      }else{
            // insert item at end.
            item->Prev = Tail;
            Tail->Next = item;
            Tail = item;
      }
      Size++;
}

/* Desc: Return the front of the queue without removing it.
 * Output: Addr* of Front of queue.
 */
void* Queue::front(){
	// return head. :D
	if(Head != 0x0){
		return Head->data;
	}else{
		throw 1;
	}
};

/* Desc: Return the Front of the queue and remove it from list.
 * Output: Addr* from Front of queue.
 */
void* Queue::pop(){
	// modify tail.
	cout << "Queue Head: " << Head << endl; cout.flush();
	if(Head != 0x0){
		QueueNode* item = Head;
		Tail = (Head->Next == 0x0) ? 0x0 : Tail; // set head to null if this is the end of list.
		Head = Head->Next;
		
		if(Head != 0x0) Head->Prev = 0x0;
		Size--;
		
		// error checking
		if(item == 0x0) return 0x0;
		 
		return item->data;
	}else{
	    return 0x0;
	}
};


/* Desc: returns the size of list.
 * Output: the current size of the queue
 */
int Queue::size(){
	return Size;
}

/* Desc: returns whether the list is empty or not based on size.
 * Output: true if list is empty.
 */
bool Queue::empty(){
	return (Size==0 || Head == 0x0);
}
