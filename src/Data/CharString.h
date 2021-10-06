#ifndef CHARSTRING_H_
#define CHARSTRING_H_

#include <iostream>
#include <malloc.h>

template<class T>
class LinkedList;
#include "LinkedList.hpp"
#include "../Math/Functions/Basic.h"

#include <string.h>

#if defined(_WIN64) || defined(_WIN32)
#define WINDOWSXX
#endif

#ifndef WINDOWSXX
#include <strings.h>
#endif

#define Compare compare
#define _CS(CHARS) CharString(CHARS) // fast-hand declare

enum SortType {SBefore, SSame, SAfter};

// Maintains char* strings along with their size.
class CharString {
    public:
        CharString();
        template<std::size_t N>
        CharString(const char (&stringg)[N]);
        CharString(char* stringg, int length); // initialize & populate
        CharString(char* stringg); // initialize & populate
        CharString(const char* stringg, const int length);
        CharString(const char* stringg);
        CharString(std::string &stringg);
        CharString(const std::string &stringg);
        virtual ~CharString();

        CharString operator =(char* string);
        bool operator ==(CharString other); // operator for 'compare'

        bool isValidCharString(); // checks if empty
        bool isValidNumber(); // checks for "0-9, -, ."
        bool isValidScientific(); // checks for a valid scientific number (or infinity / NaN)

        char* shiftLeft(const int len); // move entire list left N times, removing characters
        LinkedList<CharString> split(char splitter,char stopper);
        LinkedList<CharString> split(CharString splitter);
        void replace(char* toFind,char* replaceWith);

        bool equals(CharString b); // same as compare
        bool compare(CharString b); // compare exactly with another CharString
        bool compare(CharString b,bool useCase); // compare exactly or without case with another CharString
        template<std::size_t N>
        bool compare(const char(&val)[N]);
        bool compare(char* b, int c); // compare exactly with another char
        bool compare(const char* b, int c); // compare exactly with another char
        bool compareNoCase(char* b, int c); // compare with a char* of length c if it contains the same letters with same case.
        bool contains(char* c); // does this string contain the single character 'c'?
        bool contains(const char* c); // does this string contain the single character 'c'?
        CharString clone(); // creates a clone!
        void concata_(const char* str, const int lenx);
        
        template<std::size_t N>
        void concata(const char(val)[N]);
        void concata(char* str, int len);
        template<std::size_t N>
		void concatb(const char(&val)[N]);
        void concatb(char* str, int len);
        void concata(CharString str); //Combine CharStrings after the current charString.
        void concatb(CharString str);  //Combine CharStrings before the current charString.
        CharString substr(int index, int len); // grab a string of size LEN beginning at index.
        SortType SortCompare(CharString str); // determines if this is "less" then another string. Used for automated sorting.



        char* get(); // returns pointer to char variable
        int getInt(); // automatically converts char variable into an integer
        long getLong(); // automatically converts char variable into an integer
        float getFloat(); // automatically converts char variable into an float
        float getScientific(float val);
        std::string getString();

        int getSize(); // returns the size of the CharString
        void setSize(int size); // sets the size of the CharString

        template<std::size_t N>
		void set_(const char(&val)[N]);
        void set_(const char* stringg, const int length);

        template<std::size_t N>
        void set(const char(&val)[N]);
        void set(char* stringg, int length); // sets both the size and pointer for charString
        void set(char* stringg); // sets pointer for CharString, auto-finds length.
        void set(CharString stringg);

        template<std::size_t N>
        void setPtr(const char(&val)[N]);
        void setPtr(char* data, int length); // sets a raw pointer, no changes or copying

        bool isEmpty();
        bool startsWith(CharString starter);
        bool endsWith(CharString ender);
        
        void removeChar(int index); // remove character at index.
        void fixZeroing(char replacement); // removes \0 NULL characters within the size

        

        friend ostream & operator << (ostream &out, const CharString &c);
		friend istream & operator >> (istream &in,  CharString &c);

        template<std::size_t N>
        CharString operator +=(const char(&val)[N]); // handle const char [n] (const char [2])
        CharString operator +=(const char*);
        CharString operator +=(CharString);
        CharString operator +(CharString);
        CharString operator +(const char*);
        template<std::size_t N>
        CharString operator +(const char(&val)[N]);
        CharString operator +=(long);
        CharString operator +=(int val);
        CharString operator +=(double);

        CharString operator =(CharString);

        template<std::size_t N>
        bool operator ==(const char(&val)[N]); // direct compare

        // static functions
        static CharString ConvertFromInt(int l);
        static CharString ConvertFromLong(long l);
        static CharString ConvertFromDouble(double d); // digits represent precision below the 0th place.
        
        // easy identify input base types and convert them to a string
        // NOTE: string and character types add quotes! numbers do not get quotes
        static CharString getQuotedString(int i);
        static CharString getQuotedString(long l);
        static CharString getQuotedString(double d);
        static CharString getQuotedString(float f);
        static CharString getQuotedString(CharString c);
        static CharString getQuotedString(std::string c);

    private:
        char* stringx;
        int len;
};

#else // for cyclic includes
class CharString;
#endif /*CHARSTRING_H_*/

// external constants
extern CharString CS_TAB;
extern CharString CS_NL;
