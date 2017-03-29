//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "SelectionSort.h"

void SelectionSort(int *list, int len) {
    for(int i = 0; i<len; i++) {
        // select the smallest element in list[i..listSize-1];
        int smallestNum = list[i];
        int atloc = i;
        for(int k=i; k<len; k++) {
            if(smallestNum > list[k]) {
                // position and value
                smallestNum = list[k];
                atloc=k;
            }
        }
        // swap the smallest with list[i], if necessary;
        // so... we swap the positions?
        if(atloc != i) {
            list[atloc] = list[i];
            list[i] = smallestNum;
        }
    }
}
