// do not use ifndef/define due to cyclic referencing
#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "../../Data/LinkedList.hpp"

void QuickSort(LinkedList<int> &listx, int left, int right);

// Template for linkedlists with classes (Sort via an external function)



// partition a segment.
template<typename T>
int _partitiontmp(LinkedList<T> *a, int (*valuefunc)(T item), int low, int high) {
    int left = low, right=high;
    // value for pivot is x
    int x = (*valuefunc)((*a)[left]);

    // fast swap
    while ( right > left ) {
        // fast incrementing.
        while(  x < (*valuefunc)((*a)[right]) ) right--;
        while(  x >= (*valuefunc)((*a)[left]) ) left++;

        // fast swapping when right > left.
        if ( right > left ) {
            // swap low with high
            T tmp = (*a)[left];
            (*a)[left] = (*a)[right];
            (*a)[right] = tmp;
        }
    }

    // finish this segment.
    (*a)[low] = (*a)[right];
    (*a)[right] = (*a)[left];

    return right;
}

//void QuickSort<APIMod*>(List<APIMod*>*, int (*)(APIMod*), int, int)
template<class T>
void QuickSortT(LinkedList<T> *listx, int (*valuefunc)(T item), int left, int right){
    if(left >= right) return;
    
    int pivot = _partitiontmp(listx, valuefunc, left, right);
    QuickSortT<T>(listx, valuefunc, left, pivot-1);
    QuickSortT<T>(listx, valuefunc, pivot+1, right);
}


/* Example usage of advanced template quicksort

int getModDep(APIMod* mod){
    return mod->countDependencies;
}

mlist.sort(&getModDep);

// from LinkedList.hpp
void sort(int (*valuefunc)(T item)){
    // sorting valuefunction is passed here
    QuickSort<T>(this, valuefunc, 0, size()-1);
}

*/

#endif
