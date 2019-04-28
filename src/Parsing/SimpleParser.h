#ifndef SIMPLEPARSER_H_
#define SIMPLEPARSER_H_

#include <iostream>
#include "LoadFile.h"
#include "../Data/LinkedList.hpp"
#include "../Data/CharString.h"

using namespace std;

// output: LinkedListT of (CharString *)
LinkedList<CharString> SimpleParseLine(CharString inputfile, char separator); // parse input and split it by separator.

// output: LinkedListT of LinkedListT of (CharString *)
LinkedList<LinkedList<CharString>> SimpleParseFile(CharString input, char separator); // take data in line-by-line and parse it
LinkedList<LinkedList<CharString>> SimpleParseString(CharString data, char separator); // read RAM data.
#endif /*SIMPLEPARSER_H_*/
