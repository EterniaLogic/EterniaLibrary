#include "QuickSort.h"

// partition a segment.
int partition(LinkedList<int> a, int low, int high) {
    int left = low, right=high;
    // value for pivot is x
    int x = a[left];

    // fast swap
    while ( right > left ) {
        // fast incrementing.
        while(  x < a[right] ) right--;
        while(  x >= a[left] ) left++;

        // fast swapping when right > left.
        if ( right > left ) {
            // swap low with high
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
        }
    }

    // finish this segment.
    a[low] = a[right];
    a[right] = x;

    return right;
}

// fast sort!
void QuickSort(LinkedList<int> list, int left, int right) {
    if(left >= right) return;

    // partition and select the right as the pivot
    int pivot = partition(list, left, right);
    QuickSort(list, left, pivot-1);
    QuickSort(list, pivot+1, right);
}
