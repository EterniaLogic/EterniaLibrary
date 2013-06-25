//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SPLITRESULT_H_
#define SPLITRESULT_H_

#include <cstring>

//Split result is used to take in data from a char* string split.
class SplitResult{
	public:
		SplitResult(int sizeOf);
		
		// returns the size of the list
		int getSize();
		
		// returns the selected index for the char*
		char* get(int i);
		
		const int getLen(int i);
		
		void add(char* str, int strLen);
		
		// initializes splitlist by size sizeof
		//void initList(int sizeOf);
		
	private:
		int* listOfSizes;
		char* listStr[100][100];
		int CURR; // current position in list.
};

#endif /*SPLITRESULT_H_*/
