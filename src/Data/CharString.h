//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef CHARSTRING_H_
#define CHARSTRING_H_

#include "CharString.h"
#include "SplitResult.h"
#include <iostream>
#include <malloc.h>
#include "../Math/Functions/Basic.h"

#ifndef SPLITRESULT_H_
    #include "SplitResult.h"
#else
    class SplitResult;
#endif

enum SortType {SBefore, SSame, SAfter};

// Maintains char* strings along with their size.
class CharString {
    public:
        CharString();
        CharString(char* stringg, int length); // initialize & populate
        CharString(char* stringg); // initialize & populate
        CharString(const char* stringg, const int length);
        CharString(const char* stringg);
        CharString(std::string &stringg);
        CharString(const std::string &stringg);
        virtual ~CharString();

        void operator =(char* string);
        bool operator ==(CharString other); // operator for 'compare'

        bool isValidCharString(); // checks if empty
        bool isValidNumber(); // checks for "0-9, -, ."
        bool isValidScientific(); // checks for a valid scientific number (or infinity / NaN)

        char* shiftLeft(const int len);
        LinkedList<CharString>* split(char splitter,char stopper);
        void replace(char* toFind,char* replaceWith);


        bool Compare(CharString b); // compare exactly with another CharString
        bool Compare(CharString b,bool useCase); // compare exactly or without case with another CharString
        bool Compare(char* b, int c); // compare exactly with another char
        bool Compare(const char* b, int c); // compare exactly with another char
        bool CompareNoCase(char* b, int c); // compare with a char* of length c if it contains the same letters with same case.
        bool contains(char* c); // does this string contain the single character 'c'?
        CharString clone(); // creates a clone!
        void concata_(const char* str, const int lenx);
        void concata(char* str, int len);
        void concatb(char* str, int len);
        void concata(CharString str); //Combine CharStrings after the current charString.
        void concatb(CharString str);  //Combine CharStrings before the current charString.
        CharString substr(int index, int len); // grab a string of size LEN beginning at index.
        SortType SortCompare(CharString str); // determines if this is "less" then another string. Used for automated sorting.



        char* get(); // returns pointer to char variable
        int getInt(); // automatically converts char variable into an integer
        float getFloat(); // automatically converts char variable into an float
        float getScientific(float val);

        int getSize(); // returns the size of the CharString
        void setSize(int size); // sets the size of the CharString
        void set_(const char* stringg, const int length);
        void set(char* stringg, int length); // sets both the size and pointer for charString
        void set(char* stringg); // sets pointer for CharString, auto-finds length.
        void set(CharString stringg);

        void setPtr(char* data, int length); // sets a raw pointer, no changes or copying

        bool isEmpty();
        bool startsWith(CharString starter);
        bool endsWith(CharString ender);
        
        void removeChar(int index); // remove character at index.

        static CharString ConvertFromInt(int l);
        static CharString ConvertFromLong(long l);


    private:
        char* stringx;
        int len;
};


#endif /*CHARSTRING_H_*/
