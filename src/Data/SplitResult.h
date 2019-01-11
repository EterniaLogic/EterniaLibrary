#ifndef SPLITRESULT_H_
#define SPLITRESULT_H_

#include <string.h>

template<class T>
class LinkedList;
class CharString;

#include "CharString.h"
#include "LinkedList.hpp"

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


#else // for cyclic includes
class SplitResult;
#endif /*SPLITRESULT_H_*/
