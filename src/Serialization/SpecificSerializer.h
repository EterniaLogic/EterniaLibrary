#ifndef SPECIFIC_SERIALIZER_H_
#define SPECIFIC_SERIALIZER_H_

#include <stdlib.h>
#include <malloc.h>
#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"
#include "../Algorithm/Cryptography/md5.h"


#include "../Data/Protect/PType.hpp"
template<class T>
class PType;

using namespace std;

#define DBGSSE

#ifdef DBGSSE
    #define _DBGSSE(m) cout << m << endl; cout.flush()
#else
    #define _DBGSSE(m) //
#endif

// A SpecificSerializer will take in a specificly assigned
// The difference between 64/32 must be taken into account.

enum SSEType {SSE_Int, SSE_CharString, SSE_CharArray, SSE_double, SSE_float, SSE_Long,
            SSE_SUBClass, SSE_LinkedList, SSE_SSerializer, SSE_PType=99};

class PointerType {
    public:
        PointerType();
        PointerType(void* ptr, SSEType);

        void* ptr;
        SSEType type;
        int classSize;
};

class SpecificSerializer {
    private:
        LinkedList<PointerType> addresses; // local addresses for this class
    public:
        SpecificSerializer();
        virtual ~SpecificSerializer();

        // Add
        void addSerial(void* ptr, SSEType); // Use on the class creation
        void addSerialClass(void* ptr, SSEType type, int classSize);

        // ID-specific serialization
        CharString serializeId(int id);
        void deserializeId(int id, CharString data);
        uint32_t checksumId(int id);
        bool checksumCompareId(int id, uint32_t otherid);

        // Full serialization
        CharString serialize(); // converts this class into a byte stream, enforce the use of size.
        void deserialize(CharString data); // converts a byte array into this class
        uint32_t checksum(); // XOR. do a checksum, useful for detecting if the class needs to be updated from a server
        bool checksumCompare(uint32_t other_checksum); // compares the checksum with the current class
        int getClassSize(); // get the size of all of the combined addresses with data types
};

#endif
