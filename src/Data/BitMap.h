//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef BITMAP_H_
#define BITMAP_H_

#include "../Parsing/LoadFile.h"

// picture storage system
class BitMap
{
public:
    BitMap(int width, int height);
    void loadFromFile(CharString* fileLocation); // load this bitmap from a file.
};

#endif
