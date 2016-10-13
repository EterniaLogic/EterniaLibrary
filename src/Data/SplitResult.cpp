//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "SplitResult.h"


//SplitResult is used when calling the ::split function on a CharString.

// init with max sizeof
SplitResult::SplitResult() {
    // clean out listStr

}

SplitResult::~SplitResult() {
    /*delete listOfSizes;

    for(int i=0;i<20;i++){
        delete listStr[i];
    }*/
}

// returns the total size of the split result.
int SplitResult::getSize() {
    return listStr.size();
}

// get a splitresult
char* SplitResult::get(int i) {
    return listStr.get(i)->get();
}

CharString* SplitResult::getCS(int i) {
    return listStr.get(i);
}

// get Length of a particular splitResult
const int SplitResult::getLen(int i) {
    return listStr.get(i)->getSize();
}

// add a splitresult to the list.
void SplitResult::add(char* str, int strLen) {
    // quick string copy
    CharString* a = new CharString();
    a->setPtr(str, strLen);
    listStr.add(a);
}

