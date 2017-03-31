#ifndef BASICSERIALIZER_H_
#define BASICSERIALIZER_H_

#include <stdlib.h>
#include <malloc.h>

// A BasicSerializer will take an entire class and convert it to a string

// When declaring a class, you must add ": public BasicSerializer" otherwise, you can just use
//      static methods to convert over.


// All sub-classes must have the declaration for BasicSerializer

namespace BasicSerialize {
    // usage: BasicSerialize::serializeClass((void*)object, sizeof(object));
    char* serializeClass(void* object, int size); // use a pointer for the class

    void* deserializeClass(char* data, int size);

    long classChecksum(void* object, int size);
}


// use this for inheritance. Allows for easier conversion
class BasicSerializer {
    private:
        int classSize;
        void* classLoc;

    public:
        void initSerializer(void* thisobject, int class_size); // initialize the serializer in bytes
        char* serialize(); // converts this class into a byte stream
        void deserialize(char* data); // converts a byte array into this class

        long classChecksum(); // do a checksum, useful for detecting if the class needs to be updated
        bool isDataDifferent(long removeChecksum); // compares the checksum with the current class
};


#endif
