#include "SpecificSerializer.h"

// PType subtype copy-over
#ifndef TID_DEF(type)
    #define TID_DEF(type) if(xsize == sizeof(type)){ \
            PType<type> *ptxx = (PType<type>*)ptr; \
            vi = (char*)ptxx->getPtr(); \
    }
#endif

#ifndef TID_SET(type, data)
    #define TID_SET(type, data) if(xsize == sizeof(type)){ \
            type value; \
            rawCpy(data, (char*)&value, xsize, 0, byteloc); \
            PType<type> *ptxx = (PType<type>*)ptr; \
            *ptxx = value; \
    }
#endif

// Switch/case is going to be used a LOT here.
PointerType::PointerType() {}
PointerType::PointerType(void* ptr, CharString namex, SSEType type) {
    this->ptr = ptr;
    this->type = type;
    this->name = namex;
}



SpecificSerializer::SpecificSerializer(){
    //cout << "Add serial" << endl; cout.flush();
}

SpecificSerializer::~SpecificSerializer(){
    //cout << "Remove serial" << endl; cout.flush();
    addresses.clear();
}

// Use on the class creation
void  SpecificSerializer::addSerial(void* ptr, CharString namex, SSEType type) {
    if(type == SSE_SSerializer){
        // loop through ptr's variables
        SpecificSerializer* ser = (SpecificSerializer*)ptr;
        ser->addresses.refreeze();
        for(int i=0;i<ser->addresses.frozenlen;i++){

            this->addresses.add(ser->addresses.frozen[i]);
        }
    }else
        addresses.add(PointerType(ptr, namex, type));

}

void  SpecificSerializer::addSerialClass(void* ptr, CharString namex, SSEType type, int classSize) {
    PointerType t = PointerType(ptr, namex, type);
    t.classSize = classSize;
    addresses.add(t);
}

void SpecificSerializer::clearSerial(){
    addresses.clear();
}

int SpecificSerializer::GetSizeOfType(PointerType pt) {
    _DBGSSE("[Specific Serializer] Get type SIZE");
    switch(pt.type) {
        case SSE_Int:
            return sizeof(int);
            break;
        case SSE_CharString:
            return sizeof(int)+sizeof(char) * ((CharString*)pt.ptr)->getSize();
            break;
        case SSE_CharArray:
            // include 1 int for reconstructor to make this item dynamically
            return sizeof(int) + sizeof((char*)pt.ptr) / sizeof((char) *((char*)pt.ptr));
            break; 
        case SSE_double:
            return sizeof(double);
            break;
        case SSE_bool:
            return sizeof(bool);
            break;
        case SSE_float:
            return sizeof(float);
            break;
        case SSE_Long:
            return sizeof(long);
            break;
        case SSE_PType:
            return ((PType<int>*)pt.ptr)->getByteSize()+sizeof(char);
            break;
        case SSE_SUBClass:
            return pt.classSize;
            break;
        case SSE_SSerializer: // Sub-class serializer

            break;
        case SSE_LinkedList:
            LinkedList<char>* t = (LinkedList<char>*)pt.ptr;
            // include 1 int for reconstructor to make this item dynamically
            return sizeof(int) + t->typeSize() * t->size();
            break;
    }
}

// Copy a into b
void SpecificSerializer::rawCpy(char* a, char* b, int len, int aoff, int boff){
    for(int i=0;i<len;i++)
        b[boff+i] = a[aoff+i];
}



CharString SpecificSerializer::serializeId(int id){
    CharString tstring;
    if(id < 0 || id > addresses.size()-1) return tstring;


    _DBGSSE("   [Specific Serializer] SerializeId Start ["<< id <<"]");
    int byteloc = 0; // byte location on data during copy-over
    int j = 0;
    char* vi;
    addresses.freeze();
    PointerType pt = addresses.frozen[id];
    void* ptr = pt.ptr;

    int xsize = GetSizeOfType(pt);

    char* data; // = (char*)calloc(xsize, sizeof(char));
    //tstring.setPtr(data, GetSizeOfType(pt));


    _DBGSSE("       [Specific Serializer] SerializeId testing");
    // Test for subclass, LinkedList, ect.
    if(pt.type == SSE_SUBClass) { // Serialize a subclass

        // write the dynamic size of the type
        data = (char*)calloc(xsize+sizeof(int), sizeof(char));
        int* idata = (int*)data;
        idata[byteloc] = xsize;
        byteloc += sizeof(int);

        vi = (((SpecificSerializer*)ptr)->serialize()).get();
        rawCpy(vi, data, pt.classSize, 0, byteloc);
        byteloc += pt.classSize;

    } else if(pt.type == SSE_LinkedList) { // Serialize a linkedlist
        LinkedList<char>* list = (LinkedList<char>*)ptr;
        list->freeze(); // freeze the list
        vi = (char*)list->frozen;

        // write the dynamic size of the LinkedList
        data = (char*)calloc(xsize+sizeof(int), sizeof(char));
        int* idata = (int*)data;
        idata[byteloc] = xsize;
        byteloc += sizeof(int);

        rawCpy(vi, data, xsize, 0, byteloc);
        byteloc += xsize;

    } else if(pt.type == SSE_CharString) {
        // Serialize a CharString
        vi = ((CharString*)ptr)->get();

        // write the dynamic size of the charstring
        data = (char*)calloc(xsize+sizeof(int), sizeof(char));
        int* idata = (int*)data;
        idata[byteloc] = xsize;
        byteloc += sizeof(int);

        // Loopthrough
        rawCpy(vi, data, xsize, 0, byteloc);
        byteloc += xsize;

    } else if(pt.type == SSE_SSerializer){
        ////
    } else if(pt.type == SSE_PType){ // Memory-protected type
        xsize = ((int*)ptr)[0];
        //type_info tinfo = ((type_info*)(ptr+sizeof(int))[0];
        char* vi=0;

        

        TID_DEF(char)
            else TID_DEF(short)
            else TID_DEF(int)
            else TID_DEF(long long) // 64-bit on any 32/64 system


        data = (char*)calloc(xsize+sizeof(char), sizeof(char));
        char* idata = (char*)data;
        idata[byteloc] = xsize;
        byteloc += sizeof(char);

        rawCpy(vi, data, xsize, 0, byteloc);
        byteloc += xsize;
    }else { // Loop through normal type
        vi = (char*)ptr;
        data = (char*)calloc(xsize, sizeof(char));
        rawCpy(vi, data, xsize, 0, byteloc);
        byteloc += xsize;
    }
    _DBGSSE("   [Specific Serializer] SerializeId End ["<< id <<"]");

    tstring.setPtr(data,byteloc);
    return tstring;
}

void SpecificSerializer::deserializeId(int id, CharString datax){
    if(id < 0 || id > addresses.size()-1) return;


    int byteloc = 0; // byte location on data during copy-over
    int j = 0;
    char* vi;
    char* data = datax.get();
    int xsize;

    addresses.freeze();
    PointerType pt = addresses.frozen[id];
    void* ptr = pt.ptr;

    // Test for subclass, LinkedList, ect.
    if(pt.type == SSE_SUBClass) { // Serialize a subclass

        // Retrieve the SUBClass string size
        const int len = (const int)data[byteloc];
        vi = new char[len];
        byteloc += sizeof(int);

        for(j=0; j<len; j++) {
            vi[j] = data[byteloc++];
        }

        CharString rawdata;
        rawdata.setPtr(vi, len);
        ((SpecificSerializer*)ptr)->deserialize(rawdata); // continue down the line

    } else if(pt.type == SSE_LinkedList) { // Serialize a linkedlist
        LinkedList<char>* list = (LinkedList<char>*)ptr;

        // Retrieve the dynamic size of the LinkedList
        const int len = (const int)data[byteloc];
        vi = new char[len];
        byteloc += sizeof(int);

        for(j=0; j<len; j++) {
            vi[j] = data[byteloc++];
        }

        list->unfreeze(vi,len); // reload the list

    } else if(pt.type == SSE_CharString) {
        // Serialize a CharString
        CharString* str = ((CharString*)ptr);

        // Retrieve the dynamic size of the LinkedList
        const int len = (const int)data[byteloc];
        vi = new char[len];
        byteloc += sizeof(int);

        for(j=0; j<len; j++) {
            vi[j] = data[byteloc++];
        }

        str->setPtr(vi, len); // final set

    } else if(pt.type == SSE_SSerializer){
        // SSerializers already have their content controlled by this.
    } else if(pt.type == SSE_PType){ // Memory-protected type
        xsize = ((char*)ptr)[0];
        //type_info tinfo = ((type_info*)(ptr+sizeof(int))[0];
        char* vi=0;
        byteloc += sizeof(char);

        TID_SET(char, data) // 1*8 bits = 8
            else TID_SET(short, data) // 2*8 bits = 16
            else TID_SET(int, data) // 4*8 bits = 32
            else TID_SET(long long, data) // 8*8 bits = 64
                
    } else { // Loop through normal type
        vi = (char*)ptr;
        for(j=0; j<GetSizeOfType(pt); j++) {
            vi[j] = data[byteloc++];
        }
    }
}

// Use smaller segments
uint32_t SpecificSerializer::checksumId(int id){
    uint32_t sum;
    CharString c = serializeId(id);

    // sizeof(char) = 1, but this expalins it.
    int divs = (sizeof(uint32_t)/sizeof(char))*2-3;
    int divSeg = 0;


    for(int i=0;i<c.getSize();i++){
        if(divSeg >= divs)
            divSeg = 0;

        sum ^= c.get()[i] << (divSeg*4); // shift 4 bits throughout the sum
        divSeg++;

    }

    return sum;
}

bool SpecificSerializer::checksumCompareId(int id, uint32_t other_checksum){
    return (checksumId(id) != other_checksum);
}


// XOR. do a checksum, useful for detecting if the class needs to be updated from a server
uint32_t SpecificSerializer::checksum() {
    uint32_t sum = 0;
    CharString c = serialize();

    // sizeof(char) = 1, but this expalins it.
    int divs = (sizeof(uint32_t)/sizeof(char))*8-7;
    int divSeg = 0;

    for(int i=0;i<c.getSize();i++){
        if(divSeg >= divs)
            divSeg = 0;
        sum ^= c.get()[i] << (divSeg); // shift 1 throughout the sum
        divSeg++;
    }

    return sum;
}

// compares the checksum with the current class
bool SpecificSerializer::checksumCompare(uint32_t other_checksum) {
    return (checksum() != other_checksum);
}


// converts this class into a byte stream, enforce the use of size.
// If you do not use ->getSize(), \0 will stop the output.
CharString SpecificSerializer::serialize() {
    _DBGSSE("[Specific Serializer] Serialize Start");
    CharString tstring;
    addresses.refreeze();
    for(int i=0;i<addresses.frozenlen;i++){
        CharString t = serializeId(i);
        _DBGSSE("   [Specific Serializer] Serialize:" << t.get());
        tstring.concata(t); // insert id after
    }
    _DBGSSE("[Specific Serializer] Serialize End");

    return tstring;
}

// converts a byte array into this class
void  SpecificSerializer::deserialize(CharString datax) {
    addresses.freeze();
    int locsum = 0, j=0;
    int locsize;
    char* tmp;
    for(int i=0;i<addresses.frozenlen;i++){
        locsize = GetSizeOfType(addresses.frozen[i]);
        tmp = (char*)calloc(locsize+1,sizeof(char));

        // copy text over for char
        for(j=0;j<locsize;j++){
            tmp[j] = datax.get()[j+locsum];
        }

        CharString c(tmp,locsize);

        deserializeId(i, c); // insert id after
        locsum += locsize;
    }
}

// get the size of all of the combined addresses with data types
int SpecificSerializer::getClassSize() {
    unsigned int sum = 0;

    addresses.freeze();
    for(int i=0; i<addresses.frozenlen; i++) {
        sum += GetSizeOfType(addresses.frozen[i]);
    }

    return sum;
}
