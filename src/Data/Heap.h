#ifndef HEAP_H_
#define HEAP_H_

// numerical Heap
class Heap {
        int *HeapList, size;
    public:
        Heap(int maxSize);
        virtual ~Heap();

        int removeMin();

        void sortDown(); // implement downheap and sort the list.
        void sortUp(); // implement upheap and sort the list.
        void downheap(int from, int to);
        void upheap(int from, int to); // sort through list to make sure that it is sorted (Bottom up)

        void insert(int item); // insert item into list.
        int findinsertionposition(); // finds the correct insertion position.
};

#endif /*HEAP_H_*/
