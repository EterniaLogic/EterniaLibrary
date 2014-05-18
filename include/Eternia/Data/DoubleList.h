//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef DoubleLIST_H_
#define DoubleLIST_H_

class DoubleNode
{
    public:
        DoubleNode *prev, *next;
        double data;
};

class DoubleList
{
    // contains N-th number of Doubles.
    
    double _Size;
    public:
        DoubleList();
        virtual ~DoubleList();
        void addFront(double a);
        void addBack(double a);
        
        double getNext();
        void resetNext();
        
        double get(int index);
        void set(int index, double item);
        double erase(int index);
        
        double pop(); // erase front
        
        void clear();
        double front();
        
        int size();
        bool empty();
        
        
        DoubleNode *Head;
        DoubleNode *Tail;
        DoubleNode *CNext;
        double* categorizer;
	    
        bool isCategorized;// is the list categorized doubleo a fast fixed list?
};

#endif /*DoubleLIST_H_*/
