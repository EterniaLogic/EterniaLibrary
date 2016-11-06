//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SPLITRESULT_H_
#define SPLITRESULT_H_

#include <cstring>
#include "LinkedList.hpp"

#ifndef CHARSTRING_H_
#include "CharString.h"
#else
class CharString;
#endif

//Split result is used to take in data from a char* string split.
class SplitResult {
    public:
        SplitResult();
        virtual ~SplitResult();

        // returns the size of the list
        int getSize();

        // returns the selected index for the char*
        char* get(int i);
        CharString getCS(int i);

        const int getLen(int i);

        void add(char* str, int strLen);
        void clear(); // used when a ridiculous number of splitresults will be required
        
        
        // initializes splitlist by size sizeof
        //void initList(int sizeOf);

    private:
        LinkedList<CharString> listStr;
};

#endif /*SPLITRESULT_H_*/
