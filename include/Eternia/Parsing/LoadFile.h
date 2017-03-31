//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef LOADFILE_H_
#define LOADFILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include "../Data/CharString.h"

using namespace std;


void fileOpen(ifstream &infile, char* filename); // open a file for writing
CharString fileGetLine(ifstream &file); // read a single line from the file
void fileWrite(ifstream &file, CharString* data); // write a block of text to the file
void fileClose(ifstream &file); // close the file stream

#endif /*LOADFILE_H_*/
