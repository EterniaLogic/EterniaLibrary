#ifndef JSON_H_
#define JSON_H_

#include "../../Data/CharString.h"
#include "../../Data/HashMap.h"
#include "../../Data/DynamicType.h"
// JSON is a language that helps make text human readable between the server and client.

struct TFIELD{
    string name;
    DynamicType value; // can be integer, float, string, ect.
}

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

        // Convert string to map and back.
        CharString static encodeM(HashMap<DynamicType> map);
        HashMap<DynamicType> static decodeM(CharString data);
        
        // Static methods to convert to struct
        CharString static encode(TSTRUCT d);
        TSTRUCT static encode(CharString data);
};


#endif
