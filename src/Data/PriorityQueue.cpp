//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "PriorityQueue.h"

// initialize PriorityItem.
PriorityItem::PriorityItem() {
    priority = 0;
    data = 0x0;
    left = right = parent = 0x0;
}

// Clean up Item!
PriorityItem::~PriorityItem() {
    left = right = parent = 0x0;
}

/////////////
/////////////
/////////////

// initialize PriorityQueue.
PriorityQueue::PriorityQueue() {
    head = 0x0;
    size = 0;
}

// Clean up Queue!
PriorityQueue::~PriorityQueue() {
    // head
    while(removeMin() != 0x0); // empty it!
}


// swap values from a to b.
void PriorityQueue::dataswap(PriorityItem *a, PriorityItem *b) {
    // only swap data.
    if(a==0x0 || b==0x0) return;

    void* tmpdata = a->data;
    int tmppriority = a->priority;


    a->data = b->data;
    a->priority = b->priority;

    b->data = tmpdata;
    b->priority = tmppriority;
}

// remove minimum item.
void* PriorityQueue::removeMin() {
    // place last-inserted at top.
    if(head == 0x0) {
        size=0;
        return 0x0;
    }

    if(size == 1) { // head item.
        void* ret = head->data;
        PriorityItem* last = head;
        head = 0x0;
        size=0;

        //delete last;

        return ret;
    } else if(!empty()) { // not empty and not head.
        PriorityItem* last = findlastinsertionposition(head);

        // get data from the head item and swap it with the last item in the list.
        void* ret = head->data;
        dataswap(head, last);

        // reset the data for the last item's children. (not likely to happen, but might as well)
        if(last->left != 0x0) last->left->parent = 0x0;
        if(last->right != 0x0) last->right->parent = 0x0;

        // reset the parent's child.
        if(last->parent != 0x0) {
            if(last->parent->left == last) last->parent->left = 0x0;
            else if(last->parent->right == last) last->parent->right = 0x0;
        }

        // remove the last item from the list.
        //delete last;


        // re-sort the entire structure.
        this->downheap(head);

        // decrement size, because we removed the item.
        size--;

        return ret;
    } else {
        return 0x0;
    }
}

void _remove(PriorityQueue* queue, PriorityItem* item) {
    // recursive branch to the arms of the tree
    if(item == 0x0) return;

    if(item->left != 0x0) {
        _remove(queue, item->left);
    }
    if(item->right != 0x0) {
        _remove(queue, item->right);
    }

    // remove all items that have the priority of 2<<32-1 (4.2 billion)
    if(item->priority == 2<<31-1) {
        // remove this item
        if(item->parent != 0x0) {
            if(item->parent->left == item) item->parent->left = 0x0;
            if(item->parent->right == item) item->parent->right = 0x0;
            item->parent = 0x0;
            queue->getSize();
        } else {
            // remove the parent
            queue->clearAll();
        }
    }
}

void PriorityQueue::remove(PriorityItem* item) {
    if(item == 0x0) return;

    item->priority = 2<<31-1;
    downheap(top());
    _remove(this,item);
}

void PriorityQueue::clearAll() {
    while(!empty()) {
        removeMin();
    }
}

// returns the head of the queue.
PriorityItem* PriorityQueue::top() {
    return head;
}

// top-down sort
// is not perfect, but gets the job done.
void PriorityQueue::downheap(PriorityItem* current) {
    // repeat another time to enforce proper placement.
    if(current == 0x0) return;

    if(current->left != 0x0) {
        this->downheap(current->left);
    }
    if(current->right != 0x0) {
        this->downheap(current->right);
    }

    if(current->left == 0x0 && current->right == 0x0) {
        this->upheap(current);
    }
}

// sort through list to make sure that it is sorted. (Bottom up)
void PriorityQueue::upheap(PriorityItem* current) {
    // go up this current node's tree section.
    if(current == 0x0) return;

    // check the left side
    if(current->left != 0x0) {
        if(current->left->priority < current->priority) {
            dataswap(current, current->left);
        }
    }

    // check the right side
    if(current->right != 0x0) {
        if(current->right->priority < current->priority) {
            dataswap(current, current->right);
        }
    }

    // make sure that the parent is set and upheap this branch.
    if(current->parent != 0x0) {
        if(current->parent->priority > current->priority) {
            dataswap(current, current->parent);
        }

        upheap(current->parent);
    }
}



///////////////////////////////////////////////
////////////// insertion systems //////////////
///////////////////////////////////////////////

// insert item into list.
PriorityItem* PriorityQueue::insert(unsigned long priority, void* data) {
    // pick location to add at.
    PriorityItem* location = head == 0x0 ? head : findinsertionposition(head);

    // create item to base off of.
    PriorityItem* newItem = new PriorityItem();
    newItem->priority = priority;
    newItem->data = data;

    // is the head null?
    if(head == 0x0) {
        head = newItem;
    } else if(location->left == 0x0) { // if not, is the location's left null?
        location->left = newItem;
        newItem->parent = location;
    } else { // if not, overwrite the right.
        location->right = newItem;
        newItem->parent = location;
    }

    // increment size
    size++;

    // quickly sort bottom up.
    upheap(newItem);
    return newItem;
}


// find max depth of item c from c's location.
int PriorityQueue::depth(PriorityItem* c, int initial) {
    if(c == 0x0) return initial;

    initial++;

    int depthleft = depth(c->left, initial);
    int depthright = depth(c->right, initial);

    // determine depth between the two items. (maximum)
    return ((depthright > depthleft) ? depthright : depthleft);
}

// determines if the item c's branch is full at the bottom.
bool PriorityQueue::fullAtDepth(PriorityItem* c) {
    // quick depth check to determine fullness
    if(c == 0x0) return false;

    int depthleft = depth(c->left, 0);
    int depthright = depth(c->right, 0);
    if(depthleft > depthright) return false; // is the maxdepth of the left greater then the right?

    else if(c->right == 0x0 && c->left != 0x0) return false; // is the right not full?
    else if(c->right != 0x0 && c->left != 0x0) { // are both sides not empty?
        bool left = fullAtDepth(c->left);
        bool right = fullAtDepth(c->right);

        if(!left || !right) return false; // if the left or right is not empty.
    }

    return true;
}

// finds the correct insertion position.
PriorityItem* PriorityQueue::findinsertionposition(PriorityItem* current) {
    if(current == 0x0) return 0x0;

    if(current->left == current) current->left = 0x0;
    if(current->right == current) current->right = 0x0;

    if(current->right != 0x0 && current->left != 0x0) {
        // determine depth of left and right from current location.
        int depthleft = depth(current->left,0);
        int depthright = depth(current->right,0);
        bool fullOnLeft = fullAtDepth(current->left);
        bool fullOnRight = fullAtDepth(current->right);

        // is the left side somewhat empty?
        if(depthleft > depthright && !fullOnLeft) {
            return findinsertionposition(current->left);
            // is the right side somewhat empty?
        } else if(depthleft == depthright && !fullOnRight) {
            return findinsertionposition(current->right);
            // are both sides equal?
        } else if(depthleft == depthright) {
            return findinsertionposition(current->left);
        } // is the left side full, but not the left side?
        else {
            return findinsertionposition(current->right);
        }
    } else {
        // this is a leaf node.
        return current;
    }
}

// finds the LAST available tree leaf.
PriorityItem* PriorityQueue::findlastinsertionposition(PriorityItem* current) {
    if(current == 0x0) return 0x0;

    if(current->left == current) current->left = 0x0;
    if(current->right == current) current->right = 0x0;

    if(current->right != 0x0 && current->left != 0x0) {
        // determine depth of left and right from current location.
        int depthleft = depth(current->left,0);
        int depthright = depth(current->right,0);
        bool fullOnLeft = fullAtDepth(current->left);
        bool fullOnRight = fullAtDepth(current->right);

        // is the left side somewhat empty?
        if(depthleft > depthright && !fullOnLeft) {
            return findlastinsertionposition(current->left);
            // is the right side somewhat empty?
        } else if(depthleft == depthright && !fullOnRight) {
            return findlastinsertionposition(current->right);
            // are both sides equal?
        } else if(depthleft == depthright) {
            return findlastinsertionposition(current->right);
        } // is the left side full, but not the right side?
        else {
            return findlastinsertionposition(current->left);
        }
    } else if(current->left != 0x0) {
        return findlastinsertionposition(current->left);
    } else {
        return current;
    }
}

// replaces the priority at an address.
bool PriorityQueue::replaceKey(PriorityItem* current, void* at, unsigned long key) {
    // recursively replace key.
    if(current == 0x0) return false;

    if(current->data == at) {
        // at goal location:
        current->priority = key;
        // re-sort
        this->downheap(head);
        return true;
    } else {
        // else recursive calls.
        if(current->left != 0x0 && current->left != current) this->replaceKey(current->left, at, key);
        if(current->right != 0x0 && current->right != current) this->replaceKey(current->right, at, key);
    }
    return false;
}

// returns the size.
int PriorityQueue::getSize() {
    return size;
}

// returns whether the size is zero, or the head is empty.
bool PriorityQueue::empty() {
    return (size == 0 || head == 0x0);
}

