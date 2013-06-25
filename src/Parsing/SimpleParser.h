//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SIMPLEPARSER_H_
#define SIMPLEPARSER_H_

#include <iostream>
#include "LoadFile.h"
#include "../Data/LinkedListT.h"
#include "../MiscLib/CharString.h"

using namespace std;

// output: LinkedListT of (CharString *)
LinkedListT* SimpleParseLine(CharString* input, char separator); // parse input and split it by separator.

// output: LinkedListT of LinkedListT of (CharString *)
LinkedListT* SimpleParseFile(CharString* input, char separator); // take data in line-by-line and parse it

#endif /*SIMPLEPARSER_H_*/
