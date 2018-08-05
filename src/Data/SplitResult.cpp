

#include "SplitResult.h"


//SplitResult is used when calling the ::split function on a CharString.

// init with max sizeof
SplitResult::SplitResult() {
    // clean out listStr

}

SplitResult::~SplitResult() {}

// returns the total size of the split result.
int SplitResult::getSize() {
    return listStr.size();
}

// get a splitresult
char* SplitResult::get(int i) {
    if(listStr.get(i) == 0x0) return "";
    return listStr.get(i)->get();
}

CharString SplitResult::getCS(int i) {
    if(listStr.get(i) == 0x0) return CharString();
    return *listStr.get(i);
}

// get Length of a particular splitResult
const int SplitResult::getLen(int i) {
    return listStr.get(i)->getSize();
}

// add a splitresult to the list.
void SplitResult::add(char* str, int strLen) {
    // quick string copy
    listStr.add(CharString(str, strLen));
}

void SplitResult::clear() {
    // clear out the list
    listStr.clear();
}

