//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

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
