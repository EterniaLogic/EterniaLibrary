#ifndef BITMAP_H_
#define BITMAP_H_

#include "../Parsing/LoadFile.h"
#include "../Math/Math.h"

class bmbit {
    public:
        bmbit();
        bmbit(unsigned int rgba); // convert from rgba integer
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
        
        unsigned int getRGBA(); // simple 8-bits for each type
};

// simple picture storage system
class BitMap {
    public:
        BitMap(const int wid, const int hei);
        virtual ~BitMap();
        void loadFromFile(CharString* fileLocation); // load this bitmap from a file.

        bmbit** map; // 2-dim array
        int width;
        int height;
        
        // basic processing
        void setBrightness(double v); // brighen all values in map from between 0-100.
        void setContrast(double v); // contrast the image from 0-100.
        
        void setGrayscale(); // Strips colors by averaging them.
};

#endif
