#include "BasicSerializer.h"

namespace BasicSerialize{
        // usage: BasicSerialize::serializeClass((void*)object, sizeof(object));
        // use a pointer for the class
        char* serializeClass(void* object, int size){
                char* newData = (char*)malloc(size+1);
                newData[size] = 0x0; // null so that info can be output to console
                
                // copy data over
                for(int i=0;i<size;i++){
                        newData[i] = (char)(((char*)object)[i]);
                }
                
                return newData;
        }
        
        void* deserializeClass(char* data, int size){
        
        }
        
        long classChecksum(void* object, int size){
        
        }
}


// initialize the serializer in bytes
void BasicSerializer::initSerializer(void* thisobject, int class_size){
        classSize = class_size;
        classLoc = thisobject;
}

// converts this class into a byte list
char* BasicSerializer::serialize(){
        return BasicSerialize::serializeClass(classLoc, classSize);
}

// converts a byte array into this class
void BasicSerializer::deserialize(char* data){

}

// do a checksum, useful for detecting if the class needs to be updated
long BasicSerializer::classChecksum(){

}

// compares the checksum with the current class
bool BasicSerializer::isDataDifferent(long removeChecksum){

}
