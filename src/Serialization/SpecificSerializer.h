#ifndef SPECIFIC_SERIALIZER_H_
#define SPECIFIC_SERIALIZER_H_

#include <stdlib.h>
#include <malloc.h>
#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"
#include "../Algorithm/Cryptography/md5.h"

// A SpecificSerializer will take in a specificly assigned
// The difference between 64/32 must be taken into account.

enum SSEType {SSE_Int, SSE_CharString, SSE_CharArray, SSE_double, SSE_float, SSE_Long, SSE_SUBClass, SSE_LinkedList};

class PointerType{
public:
    PointerType();
    PointerType(void* ptr, SSEType);

    void* ptr;
    SSEType type;
    int classSize;
};

class SpecificSerializer {
private:
        LinkedList<PointerType> addresses;
public:
        CharString* serialize(); // converts this class into a byte stream, enforce the use of size.
        void deserialize(CharString* data); // converts a byte array into this class

        void addSerial(void* ptr, SSEType); // Use on the class creation
        void addSerialClass(void* ptr, SSEType type, int classSize);

        CharString* checksum(); // XOR. do a checksum, useful for detecting if the class needs to be updated from a server
        bool isDataDifferent(CharString* other_checksum); // compares the checksum with the current class

        int getClassSize(); // get the size of all of the combined addresses with data types
};

#endif
