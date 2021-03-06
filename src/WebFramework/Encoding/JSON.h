#ifndef JSON_H_
#define JSON_H_

#include "../../Data/includes.h"
#include <vector>
// src/Serialization/SpecificSerializer.h has JSON to/from methods for classes, it is recommended.

// JSON is a language that helps make text human readable between the server and client.

struct TFIELD{
    CharString name;
    DynamicType value; // can be integer, float, string, ect.
};

struct TSTRUCT{
    std::vector<TFIELD> fields;
};

class JSON {
    private:
        CharString data;
    public:
        JSON(CharString data);

        void loadFile(CharString loc); // load JSON from file
        void saveFile(CharString loc); // save JSON (overwrite) to file
        
        
        // SpecificSerializer
        
        
        
        // Convert string to map and back.
        static CharString encodeM(HashMap<DynamicType> _map);
        static HashMap<DynamicType> decodeM(CharString _data);
        
        // Static methods to convert to struct
        static CharString encode(TSTRUCT _d);
        static TSTRUCT encode(CharString _data);
};


#endif
