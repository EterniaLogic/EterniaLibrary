#include "SpecificSerializer.h"


// Switch/case is going to be used a LOT here.
PointerType::PointerType(){}
PointerType::PointerType(void* ptr, SSEType type){
    this->ptr = ptr;
    this->type = type;
}

// Use on the class creation
void  SpecificSerializer::addSerial(void* ptr, SSEType type){
    addresses.add(new PointerType(ptr, type));
}

void  SpecificSerializer::addSerialClass(void* ptr, SSEType type, int classSize){
    PointerType* t = new PointerType(ptr, type);
    t->classSize = classSize;
    addresses.add(t);
}

int GetSizeOfType(PointerType* pt){
    switch(pt->type) {
        case SSE_Int:
                return sizeof(int);
            break;
        case SSE_CharString:
                return sizeof(char) * ((CharString*)pt->ptr)->getSize();
            break;
        case SSE_CharArray:
                // include 1 int for reconstructor to make this item dynamically
                return sizeof(int) + sizeof((char*)pt->ptr) / sizeof((char) *((char*)pt->ptr));
            break;
        case SSE_double:
                return sizeof(double);
            break;
        case SSE_float:
                return sizeof(float);
            break;
        case SSE_Long:
                return sizeof(long);
            break;
        case SSE_SUBClass:
                return pt->classSize;
            break;
        case SSE_LinkedList:
                LinkedList<char>* t = (LinkedList<char>*)pt->ptr;
                // include 1 int for reconstructor to make this item dynamically
                return sizeof(int) + t->typeSize() * t->size();
            break;
    }
}



// XOR. do a checksum, useful for detecting if the class needs to be updated from a server
CharString* SpecificSerializer::checksum(){
    /*unsigned int sum = 0;

    addresses.freeze();
    PointerType* current;
    int* iptr;
    int len,tolen,j;
    for(int i=0;i<addresses.frozenlen;i++){
        current = addresses.frozen[i];
        len = GetSizeOfType(current);
        tolen = len/sizeof(int);

        iptr = (int*)current->ptr;
        for(j=0; j<tolen; j++){
            sum ^= iptr[j];
        }
    }*/

    return new CharString(md5(serialize()->get()).c_str());
}

// compares the checksum with the current class
bool SpecificSerializer::isDataDifferent(CharString* other_checksum){
    return (checksum()->Compare(other_checksum));
}


// converts this class into a byte stream, enforce the use of size.
// If you do not use ->getSize(), \0 will stop the output.
CharString*  SpecificSerializer::serialize(){
    char* data = (char*)calloc(getClassSize(), sizeof(char));
    CharString* tstring = new CharString();
    tstring->setPtr(data, getClassSize());

    int byteloc = 0; // byte location on data during copy-over
    int j = 0;
    char* vi;
    PointerType* pt;

    addresses.freeze();
    for(int i=0; i<addresses.frozenlen; i++){
        pt = addresses.frozen[i];

        // Test for subclass, LinkedList, ect.
        if(pt->type == SSE_SUBClass){ // Serialize a subclass

            // write the dynamic size of the type
            int* idata = (int*)data;
            idata[byteloc] = GetSizeOfType(pt);
            byteloc += sizeof(int);

            vi = ((SpecificSerializer*)pt->ptr)->serialize()->get();
            for(j=0; j<pt->classSize; j++){
                data[byteloc++] = vi[j];
            }

        }else if(pt->type == SSE_LinkedList){ // Serialize a linkedlist
            LinkedList<char>* list = (LinkedList<char>*)pt->ptr;
            list->freeze(); // freeze the list
            vi = (char*)list->frozen;

            // write the dynamic size of the LinkedList
            int* idata = (int*)data;
            idata[byteloc] = GetSizeOfType(pt);
            byteloc += sizeof(int);

            for(j=0; j<GetSizeOfType(pt); j++){
                data[byteloc++] = vi[j];
            }

        }else if(pt->type == SSE_CharString){
            // Serialize a CharString
            vi = ((CharString*)pt->ptr)->get();

            // write the dynamic size of the charstring
            int* idata = (int*)data;
            idata[byteloc] = GetSizeOfType(pt);
            byteloc += sizeof(int);

            // Loopthrough
            for(j=0; j<GetSizeOfType(pt); j++){
                data[byteloc++] = vi[j];
            }

        }else { // Loop through normal type
            vi = (char*)addresses.frozen[i]->ptr;
            for(j=0; j<GetSizeOfType(pt); j++){
                data[byteloc++] = vi[j];
            }
        }
    }

    return tstring;
}

// converts a byte array into this class
void  SpecificSerializer::deserialize(CharString* datax){
    PointerType* pt;
    int byteloc = 0; // byte location on data during copy-over
    int j = 0;
    char* vi;
    char* data = datax->get();

    addresses.freeze();
    for(int i=0; i<addresses.frozenlen; i++){
        pt = addresses.frozen[i];

        // Test for subclass, LinkedList, ect.
        if(pt->type == SSE_SUBClass){ // Serialize a subclass

            // Retrieve the SUBClass string size
            const int len = (const int)data[byteloc];
            vi = new char[len];
            byteloc += sizeof(int);

            for(j=0; j<len; j++){
                 vi[j] = data[byteloc++];
            }

            CharString* rawdata = new CharString();
            rawdata->setPtr(vi, len);
            ((SpecificSerializer*)pt->ptr)->deserialize(rawdata); // continue down the line

        }else if(pt->type == SSE_LinkedList){ // Serialize a linkedlist
            LinkedList<char>* list = (LinkedList<char>*)pt->ptr;

            // Retrieve the dynamic size of the LinkedList
            const int len = (const int)data[byteloc];
            vi = new char[len];
            byteloc += sizeof(int);

            for(j=0; j<len; j++){
                 vi[j] = data[byteloc++];
            }

            list->unfreeze(vi,len); // reload the list

        }else if(pt->type == SSE_CharString){
            // Serialize a CharString
            CharString* str = ((CharString*)pt->ptr);

            // Retrieve the dynamic size of the LinkedList
            const int len = (const int)data[byteloc];
            vi = new char[len];
            byteloc += sizeof(int);

            for(j=0; j<len; j++){
                 vi[j] = data[byteloc++];
            }

            str->setPtr(vi, len); // final set

        }else { // Loop through normal type
            vi = (char*)addresses.frozen[i]->ptr;
            for(j=0; j<GetSizeOfType(pt); j++){
                vi[j] = data[byteloc++];
            }
        }
    }
}

// get the size of all of the combined addresses with data types
int SpecificSerializer::getClassSize(){
    unsigned int sum = 0;

    addresses.freeze();
    for(int i=0;i<addresses.frozenlen;i++){
        sum += GetSizeOfType(addresses.frozen[i]);
    }

    return sum;
}
