//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef LINKEDLISTT_H_
#define LINKEDLISTT_H_

class LinkedNodeT{
	public:
		LinkedNodeT * prev;
		LinkedNodeT * next;
		void * data;
		LinkedNodeT();
};

class LinkedListT{
	//Written January 25th, 2013
	LinkedNodeT * baseNode;
	LinkedNodeT * currentNode;
	int _size;
	public:
		LinkedListT();
		virtual ~LinkedListT();
		void add(void *cc);
		void* get(int index);
		int size();
		
		void freeze();
		
		void **frozen;
		int frozenlen;
};

#endif /*LINKEDLISTT_H_*/
