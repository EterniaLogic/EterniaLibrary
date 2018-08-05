#ifndef BITMAP_H_
#define BITMAP_H_

#include "../Parsing/LoadFile.h"

class bmbit {
    public:
        bmbit();
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
};

// picture storage system
class BitMap {
    public:
        BitMap(const int wid, const int hei);
        virtual ~BitMap();
        void loadFromFile(CharString* fileLocation); // load this bitmap from a file.

        bmbit** map; // 2-dim array
        int width;
        int height;
};

#endif
