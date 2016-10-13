//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "LoadFile.h"

using namespace std;

bool checkFileExistence(const char* filename) {
    ifstream f(filename);
    return f.is_open();
}

// open a file
void fileOpen(ifstream &infile, char* filename) {
    //cout << "fileopen = " << filename << endl;
    if(checkFileExistence(filename)) {
        //cout << "@" << endl;
        infile.open(filename);
    }
}

// get a line from the file.
CharString* fileGetLine(ifstream &file) {
    string sLine = "";
    if (!file.eof()) {
        std::getline(file, sLine);
        const int linelen = sLine.size();
        //cout << sLine << endl;
        char *line = new char[linelen];
        for (int a=0; a<linelen; a++) {
            line[a]=sLine[a];
        }
        //cout << line << endl;
        return new CharString(line, linelen);
    } else {
        return 0x0;
    }
}

// write a block to a file.
void fileWrite(ifstream &file, CharString* data) {

}

// closeFile
void fileClose(ifstream &file) {
    file.close();
}


// size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
