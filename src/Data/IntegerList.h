#ifndef INTEGERLIST_H_
#define INTEGERLIST_H_

class IntegerNode {
    public:
        IntegerNode *prev, *next;
        int data;
};

class IntegerList {
        // contains N-th number of integers.

        int _Size;
    public:
        IntegerList();
        virtual ~IntegerList();
        void addFront(int a);
        void addBack(int a);

        int getNext();
        void resetNext();

        int get(int i);
        void set(int i, int item);
        int erase(int i);

        int pop(); // erase front

        void clear();
        int front();

        int size();
        bool empty();


        IntegerNode *Head, *Tail, *CNext;
        int* categorizer;

        bool isCategorized;// is the list categorized into a fast fixed list?
};

#endif /*INTEGERLIST_H_*/
