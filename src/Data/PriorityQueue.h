#ifndef PRIORITYQUEUE_H_1
#define PRIORITYQUEUE_H_1

// PriorityItem is part of the priority queue. It acts as the binary tree node.
class PriorityItem {
    public:
        PriorityItem();
        PriorityItem *left, *right, *parent; // node selections.
        virtual ~PriorityItem();

        unsigned long priority;
        void* data;

};

class PriorityQueue {
        PriorityItem *head;
        int size;
    public:
        PriorityQueue();
        virtual ~PriorityQueue();


        void* removeMin(); // removes the minimum item
        void remove(PriorityItem* item); // remove a specific item
        void clearAll(); // clear all items

        PriorityItem* top(); // returns the head item.

        void dataswap(PriorityItem *a, PriorityItem *b); // swap data between two priority items.

        void downheap(PriorityItem* current);
        void upheap(PriorityItem* current); // sort through list to make sure that it is sorted (Bottom up)

        PriorityItem* insert(unsigned long priority, void* data); // insert item into list.


        // depth is useful for searching each branch for height levels.
        int depth(PriorityItem* c, int initial); // find max depth of item c from c's location.
        bool fullAtDepth(PriorityItem* c); // determines if the branch has even left and right bottoms.

        // finds positions based on leaf locations.
        PriorityItem* findinsertionposition(PriorityItem* current); // finds the correct insertion position.
        PriorityItem* findlastinsertionposition(PriorityItem* current); // finds the LAST available tree leaf.

        bool replaceKey(PriorityItem* current, void* at, unsigned long key); // replaces a priority via data key.

        int getSize(); // returns the total size
        bool empty(); // returns whether the size is zero, or the head is empty.
};

#endif
