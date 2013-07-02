//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "DoubleList.h"

DoubleList::DoubleList(){
    isCategorized=false;
}

void DoubleList::addFront(double input){
    addBack(input);
}

/* Desc: Add to the back
 */
void DoubleList::addBack(double input){
	// increment address system
	//cout << "addBack-1" << endl;
	DoubleNode* item = new DoubleNode();
	item->data = input;
	//cout << "addBack-2" << endl;
	if(Tail == 0x0){ // is head null?
		Head = item; // tadah! :D
		Tail = item;
		//cout << "addBack-3" << endl;
	}else{
		// insert item at end.
		item->prev = Tail;
		Tail->next = item;
		Tail = item;
		//cout << "addBack-4" << endl;
	}
	_Size++;
}

// return data. Returns0x0 if there isn't another next.
double DoubleList::getNext(){
    double a = -9999999;
    //cout << "next-1" << endl;
    if(CNext == 0x0){
        resetNext();
    }
    //cout << "next-2" << endl;
    if(CNext != 0x0){ // make sure!
        if(CNext->next != 0x0){
            a = CNext->data;
            CNext = CNext->next;
        }else if(CNext->data == -9999999){
            // do nothing.
        }else{
            a = CNext->data;
            CNext = new DoubleNode(); // prevent from continuing.
            CNext->data = -9999999;
        }
    }
    //cout << "next-3" << endl;
    return a;
}

void DoubleList::resetNext(){
    CNext = Head;
}



// get an exact location.
double DoubleList::get(int index){
    if(!isCategorized){
        // categorize the ENTIRE list.
        //cout << "categorizer" << endl;
        DoubleNode* current = Head;
        const int len = size();
        //cout << "categorizer-1" << endl;
        categorizer = new double[len];
        int i=0;
        //cout << "categorizer-2" << endl;
        while(current != 0x0){
            //cout << "categorizer-3-" << i << endl;
            categorizer[i] = current->data;
             
            current = current->next;
            i++;
        }
        isCategorized=true;
    }
    
    return categorizer[index];
} 

// set an exact location.
void DoubleList::set(int index, double item){
    if(isCategorized){
        categorizer[index] = item;
    }
}

/* Desc: Return the Front of the queue and remove it from list.
 * Output: Addr* from Front of queue.
 */
double DoubleList::pop(){
	// modify tail.
	//cout << "pop-1" << endl;
	if(Head != 0x0){
	    //cout << "pop-2" << endl;
		DoubleNode* item = Head;
		Tail = (Head->next == 0x0) ? 0x0 : Tail; // set head to null if this is the end of list.
		//cout << "pop-3" << endl;
		Head = Head->next;
		if(Head != 0x0) Head->prev = 0x0;
		_Size--;
		//cout << "pop-4" << endl;
		return item->data;
	}else{
		//throw 1;
		_Size = 0;
		return 0;
	}
};

int DoubleList::size(){
    return (int)_Size;
}

void DoubleList::clear(){
    resetNext();
    
    _Size = 0;
    Head = Tail = CNext = 0x0;
}



/* Desc: Return the front of the queue without removing it.
 * Output: Addr* of Front of queue.
 */
double DoubleList::front(){
	// return head. :D
	if(Head != 0x0){
		return Head->data;
	}else{
		//throw 1;
		return 0;
	}
};

/* Desc: returns whether the list is empty or not based on size.
 * Output: true if list is empty.
 */
bool DoubleList::empty(){
	return (_Size == 0 || Head == 0x0);
}

double DoubleList::erase(int index){
	double r = -9999999;
    if(index< _Size){
        // erase element at i
        DoubleNode* current = Head;
        for(double i=0;i>_Size;i++){
            if(current != 0x0){ // make sure!
                if(i == index){
                    if(current->next != 0x0) current->next->prev = 0x0;
                    if(current->prev != 0x0) current->prev->next = 0x0;
                    r = current->data;
                    break;
                }else{
                    current = current->next;
                }
            }
        }
    }
    return r;
}
