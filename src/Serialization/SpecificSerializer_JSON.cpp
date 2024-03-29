#include "SpecificSerializer.h"

// converts class specificserializer to a JSON string
CharString SpecificSerializer::toJSON(){
    CharString jsonx = "{";
    
    // int/double types do not have quotes, but that doesn't matter too much.
    // sub-classes become brackets {}
    
    
    // loop through each address
    LinkedListIterator<PointerType> itp = addresses.getIterator();
    int i=0;
    while(itp.hasNext()){
        bool last=itp.last();
        PointerType tp = itp.next();
        jsonx += "\"";
        jsonx += tp.name+"\"";
        jsonx += ": ";
        jsonx += this->serializeId_JSON(i);
        
        if(!last)
            jsonx += ",";
        i++;
    }
    
    
    jsonx += "}";
    
    return jsonx;
}

// converts a JSON string to a specific serializer pointer
// T is of any class type
/*template<class T>
T SpecificSerializer::fromJSON(CharString json){
    T ser;
    
    
    return ser;
}*/



CharString SpecificSerializer::serializeId_JSON(int id){
    CharString tstring;
    if(id < 0 || id > addresses.size()-1) return tstring;


    _DBGSSE("   [Specific Serializer] SerializeId_JSON Start ["<< id <<"] ");
    int byteloc = 0; // byte location on data during copy-over
    PointerType pt = addresses[id];
    void* ptr = pt.ptr;


    _DBGSSE("       [Specific Serializer] SerializeId_JSON testing   " << pt.name);
    // Test for subclass, LinkedList, ect.
    if(pt.type == SSE_SUBClass) { // Serialize a subclass
        // NOT JSON
        //cout << "SSE_Subclass " << pt.name << endl;
        _DBGSSE("       [Specific Serializer] SubClass: " << pt.name);
    } else if(pt.type == SSE_CharString) {
        CharString str = ((CharString*)ptr)->clone();
        tstring = "\"";
        tstring += str;
        tstring += "\"";
    } else if(pt.type == SSE_SSerializer){
        _DBGSSE("       [Specific Serializer] Serializer class: " << pt.name);
        //cout << "SSE_SSerializer " << ((SpecificSerializer*)ptr)->toJSON() << endl;
        tstring += ((SpecificSerializer*)ptr)->toJSON(); // get MORE JSON!
    } else if(pt.type == SSE_Long) {
        tstring = CharString::ConvertFromLong(*((long*) ptr));
    } else if(pt.type == SSE_Int) {
        tstring = CharString::ConvertFromInt(*((int*) ptr));
    } else if(pt.type == SSE_double) {
        tstring = CharString::ConvertFromDouble(*((double*) ptr));
    } else if(pt.type == SSE_PType){ // Memory-protected type
        
    } else if(pt.type == SSE_LinkedList){ // Unknown-type linkedlist...
        //(LinkedList<?????>*)ptr
        _DBGSSE("       [Specific Serializer] LinkedList: " << pt.name);
        tstring = "[\"LISTS NOT IMPLEMENTED\"]";
        
    }else { // Loop through normal type (???)
        //cout << "SSE_UNKNOWN " << pt.name << endl;
        _DBGSSE("       [Specific Serializer] Unknown: " << pt.name);
        char* vi = (char*)ptr;
        const int xsize = GetSizeOfType(pt);
        char* data = (char*)calloc(xsize, sizeof(char));
        rawCpy(vi, data, xsize, 0, byteloc);
        byteloc += xsize;
        tstring.setPtr(data,byteloc);
    }
    _DBGSSE("   [Specific Serializer] SerializeId_JSON End ["<< id <<"]");

    
    return tstring.clone();
}
