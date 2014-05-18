//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "SplitResult.h"


//SplitResult is used when calling the ::split function on a CharString.

// init with max sizeof
SplitResult::SplitResult(int sizeOf){
	// clean out listStr
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
		    char* c = new char[1];
		    strcpy(c," ");
			listStr[i][j] = c;
		}
	}
	const int ls = sizeOf;
	listOfSizes = new int[ls]; // lists the lengths of each str. (This saves time in later parsing)
}

// returns the total size of the split result.
int SplitResult::getSize(){
	return CURR;
}

// get a splitresult
char* SplitResult::get(int i){
	char* temp = new char[listOfSizes[i]];
	for(int j=0;j<listOfSizes[i];j++) temp[j] = *listStr[i][j];
	return temp;
}

// get Length of a particular splitResult
const int SplitResult::getLen(int i){
	return listOfSizes[i];
}

// add a splitresult to the list.
void SplitResult::add(char* str, int strLen){
    // quick string copy
	for(int i1=0;i1<strLen;i1++) listStr[CURR][i1] = &str[i1];
	listOfSizes[CURR] = strLen;
	
	CURR++;
}

