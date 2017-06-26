//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef QUEUE_H_
#define QUEUE_H_

#include "../Data/CharString.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>

class QueueNode {
    public:
        QueueNode();
        void *data;
        QueueNode *Prev, *Next;
};

class Queue {
    private:
        QueueNode *Head,*Tail;
    public:
        Queue();
        virtual ~Queue();

        int Size;
        void push(void* data);
        void* pop();
        void* front();
        int size();
        bool empty();
};

#endif /*QUEUE_H_*/