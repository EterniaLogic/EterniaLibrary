//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "QuickSort.h"

// partition a segment.
int partition(IntegerList *a, int low, int high) {
    int left = low, right=high;
    // value for pivot is x
    int x = a->get(left);

    // fast swap
    while ( right > left ) {
        // fast incrementing.
        while(  x < a->get(right) ) right--;
        while(  x >= a->get(left) ) left++;

        // fast swapping when right > left.
        if ( right > left ) {
            // swap low with high
            int tmp = a->get(left);
            a->set(left,a->get(right));
            a->set(right,tmp);
        }
    }

    // finish this segment.
    a->set(low,a->get(right));
    a->set(right,x);


    //cout << "partion-4" << endl;

    return right;
}

// fast sort!
void QuickSort(IntegerList* list, int left, int right) {
    if(left >= right) return;

    // partition and select the right as the pivot
    int pivot = partition(list, left, right);
    QuickSort(list, left, pivot-1);
    QuickSort(list, pivot+1, right);
}
