//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Heap.h"

// swaps position x with position y
void swap(int &x, int &y){
    int tmp = x;
    x = y;
    y = tmp;
}

void HeapSort(int* list, int len){
     // loop through to make sure this the heap is in order.
     // use downheap to structure.
     
     
     Heap* h = new Heap(len);
     //cout << list[len-1] << endl;
     for(int i = 0; i<len;i++){
        h->insert(list[i]);
     }
     
     h->sortDown();
     
     for(int i = 0; i<len;i++){
        list[i] = h->removeMin();
     }
    
    // currently in increasing order, we need descending order.
    // loop through list and make sure that the list is inverted to assume descending order.
    for(int i = 0; i<len/2;i++){
        swap(list[i],list[len-i-1]);
    }
}


// initialize the heap and fill in the data slots.
Heap::Heap(int maxSize){ 
    HeapList = new int[maxSize]; 
    size = maxSize;
    for(int i=0;i<maxSize;i++){
        HeapList[i] = -999999; // standalone identifier of non-inserted item.
    }
}

// remove the root node. (Shift every item left, Right-most item is -999999)
int Heap::removeMin(){
    int a = HeapList[0];
    // shift all values left.
    for(int i=0;i<size-1;i++){
        HeapList[i] = HeapList[i+1];
    }
    // reset right-most value.
    HeapList[size-1] = -999999;
    
    if(a == -999999) return 0;
    else return a;
}

// sort down the list.
void Heap::sortDown(){
    // re-order list.
    for(int start = (size-1)/2 ; start >= 0; start--){
        downheap(start,size-1);
    }
    
    for (int end = size-1; end >= 1; end--){
        swap(HeapList[end], HeapList[0]);
        
        // make sure heap is in order.
        downheap(0,end-1);
    }
}

// sort through list (top down)
void Heap::downheap(int from, int to){
    int root = from;
    
    // loop down the tree list.
    while((root*2+1) <= to){
        int child = root*2+1; // left-most child
        int swapwith = root; // swap point to use
        
        // root is smaller then location of child?
        if(HeapList[swapwith] < HeapList[child]){
            swapwith = child;
        }
        
        // does the child on the right side exist!?!?
        if(child+1 <= to && HeapList[swapwith] < HeapList[child+1]){
            swapwith = child+1;
        }
        
        // do we need to swap?!?!
        if(swapwith != root){
            swap(HeapList[root], HeapList[swapwith]);
            root = swapwith; // repeat to siffle down children.
        }else{
            return; // else, exit the function.
        }
        
        /*for(int i=from;i<=to;i++) {
	        cout << a[i];
	        if(i < to){
	            cout << " ";
	        }
        }
        cout << endl;*/
        
    }
}

// sort up the list.
void Heap::sortUp(){
    // re-order list.
    for(int end = 1 ; end < size; end++){
        upheap(0,size);
    }
    
    for (int end = size-1; end >= 1; end--){
        swap(HeapList[end], HeapList[0]);
        
        // make sure heap is in order.
        upheap(0,end-1);
    }
}

// sort through list to make sure that it is sorted (Bottom up)
void Heap::upheap(int from, int to){
    int child = to;
    // make sure that the child is greater than the beginning, sort from right to left.
    while(child > from){
        int parent = (child-1)/2;
        
        // if parent is less than child, then swap. 
        // Set Child to Parent.
        if(HeapList[parent] < HeapList[child]){
            swap(HeapList[parent], HeapList[child]);
            child = parent;
        }else{
            return;
        }
    }
} 

// insert at boolean position.
void Heap::insert(int item){
    HeapList[findinsertionposition()] = item;
}

int Heap::findinsertionposition(){
    for(int i=0;i<size;i++){
        if(HeapList[i] == -999999){
            return i;
        }
    }
    return size-1;
}
