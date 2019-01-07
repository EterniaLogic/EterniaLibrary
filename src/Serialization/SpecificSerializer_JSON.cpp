#include "SpecificSerializer.h"

// converts class specificserializer to a JSON string
CharString SpecificSerializer::toJSON(){
    CharString jsonx = "{";
    
    // int/double types do not have quotes, but that doesn't matter too much.
    // sub-classes become brackets {}
    
    
    // loop through each address
    LinkedListIterator<PointerType> it = addresses.getIterator();
    while(it.hasNext()){
        PointerType tp = it.next();
    }
    
    /*FOR_LIST(PointerType, value, addresses){
        
    }*/
    
    
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
