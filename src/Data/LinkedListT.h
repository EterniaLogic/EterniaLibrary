#ifndef LINKEDLISTT_H_
#define LINKEDLISTT_H_

class LinkedNodeT {
    public:
        LinkedNodeT();
        virtual ~LinkedNodeT();
        LinkedNodeT * prev;
        LinkedNodeT * next;
        void * data;
};

class LinkedListT {
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
