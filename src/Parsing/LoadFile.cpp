

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
CharString fileGetLine(ifstream &file) {
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
        //cout << "xx" << endl; cout.flush();
        return CharString(line, linelen);
    } else {
        //cout << "xx" << endl; cout.flush();
        return CharString("",-1);
    }
}

// write a block to a file.
void fileWrite(ifstream &file, CharString* data) {

}

// closeFile
void fileClose(ifstream &file) {
    file.close();
}

CharString fileReadAll(CharString file){
    std::ifstream ifs(file.get());
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
    return CharString(content);
}


// size_t fread ( void * ptr, size_t size, size_t count, FILE * stream );
