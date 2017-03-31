#ifndef COMPRESSEDJSON_H_
#define COMPRESSEDJSON_H_

// This is a modification of the JSON library where all of the data is compressed.
//  This should help speed up network transmission of data, but will not be (directly) supported by other libraries.

class CompressedJSON {
    private:
        CharString data;
    public:
        CompressedJSON(CharString data);


        // Static methods to help speed up the process
        CharString static encode(CharString data);
        CharString static decode(CharString data);
};


#endif
