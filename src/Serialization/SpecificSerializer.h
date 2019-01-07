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

//#define DBGSSE

#ifdef DBGSSE
    #define _DBGSSE(m) cout << m << endl; cout.flush()
#else
    #define _DBGSSE(m) //
#endif

// A SpecificSerializer will take in a specificly assigned
// The difference between 64/32 must be taken into account.


// Example:
/*
class testClass : public SpecificSerializer{
public:
    testClass(){
        addSerial(&lista, SSE_LinkedList);
        addSerial(&valuea, SSE_Int);
        addSerial(&valueb, SSE_double);
        addSerial(&class2, SSE_SUBClass);
        addSerial(&tsc, SSE_SSerializer);
        addSerial(&characterlevel, SSE_PType);
    }
    
    LinkedList<int> lista;
    int valuea;
    double valueb;
    testClass2 class2;
    testSerClassA tsc; // Class that is a SpecificSerializer
    PType<int> characterlevel = 0; // Protector type that prevents memory hacking via CheatEngine or scanmem
}

*/







enum SSEType {SSE_Int, SSE_CharString, SSE_CharArray, SSE_double, SSE_float, SSE_Long,
            SSE_SUBClass, SSE_LinkedList, SSE_SSerializer, SSE_bool, SSE_LinkedListClass, SSE_PType=99};

class PointerType {
    public:
        PointerType();
        PointerType(void* ptr, CharString name, SSEType);

        void* ptr; // direct pointer to variable/class
        CharString name; // name of the parameter
        SSEType type;
        int classSize; // only used with classes
};

class SpecificSerializer {
private:
    LinkedList<PointerType> addresses; // local addresses for this class
public:
    SpecificSerializer();
    virtual ~SpecificSerializer();
    
    // for classes that are polymorphed and have multiple constructors
    void setupSerialization(){}
    

    // Add (&param, "paramname", SSE_Int);
    void addSerial(void* ptr, CharString name, SSEType); // Use on the class creation
    void addSerialClass(void* ptr, CharString name, SSEType type, int classSize);
    void clearSerial();

    // ID-specific serialization (Serialize a specific variable, not the entire class)
    CharString serializeId(int id);
    void deserializeId(int id, CharString data);
    uint32_t checksumId(int id);
    bool checksumCompareId(int id, uint32_t otherid);

    // Full serialization (for the entire class and sub-serialized classes)
    CharString serialize(); // converts this class into a byte stream, enforce the use of size.
    void deserialize(CharString data); // converts a byte array into this class
    uint32_t checksum(); // XOR. do a parity checksum, useful for detecting if the class needs to be updated from a server
    bool checksumCompare(uint32_t other_checksum); // compares the checksum with the current class
    int getClassSize(); // get the size of all of the combined addresses with data types
    
    
    // API specifications
    
    // to API type
    CharString toJSON(); // converts class specificserializer to a JSON string
    
    template<class T> // T is of the class type of subtype SpecificSerializer
    static T fromJSON(CharString json); // converts a JSON string to a SS class
};

#endif
