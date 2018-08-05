

#include "InsertionSort.h"

// about the same as selection sort, with some variances.
void InsertionSort(int *list, int len) {
    for(int i=0; i<len; i++) {
        int thisValue = list[i];
        int minimumPosition = i;
        // loop through to find the minimum location.
        for(int k=0; k<i; k++) {
            // if k is less than this.
            if(list[k] > list[i]) {
                minimumPosition = k;
                break;
            }
        }

        // shift all from position to the right!
        for(int k = i; k>minimumPosition; k--) {
            list[k] = list[k-1];
        }

        // set the smalles position to the value
        list[ minimumPosition] = thisValue;
    }
}
