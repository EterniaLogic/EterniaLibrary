#ifndef LOADFILE_H_
#define LOADFILE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include "../Data/CharString.h"

using namespace std;


void fileOpen(ifstream &infile, char* filename); // open a file for writing
CharString fileGetLine(ifstream &file); // read a single line from the file
void fileWrite(ifstream &file, CharString* data); // write a block of text to the file
void fileClose(ifstream &file); // close the file stream
CharString fileReadAll(CharString file); // read all contents of a file
#endif /*LOADFILE_H_*/
