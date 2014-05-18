#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include "../MiscLib/CharString.h"

// basic filesystem data structure
// set file/dir types
enum DType{Directory,File};

// node to store siblings, parents, children and data.
class FileStructureNode
{
public:
        CharString* name;
        DType type;

        bool nameEquals(CharString* AName); // quick compare of names

        void addObject(FileStructureNode* object); // add object to this
        bool delObject(FileStructureNode* object); // delete object from this

        void del(); // delete THIS from listings.

        // Node's familial relationships
        FileStructureNode *Child,*Parent;
        FileStructureNode *Sibling,*PrevSibling;
};


// Complete filesystem that manages internal data.
class FileSystem
{
        FileStructureNode *Root, *Current;
public:
        FileSystem();
        virtual ~FileSystem();

        FileStructureNode* getNodeFromString(CharString* location); // find a directory or file at location.
        FileStructureNode* getBaseNodeFromString(CharString* location); // find a BASE directory or file at location.
        CharString* getNameFromString(CharString* location); // returns the name of the object in the breadcrum list.
        CharString* getStringFromNode(FileStructureNode* location); // converts current location into a directory location

        void removeAll(DType t, FileStructureNode* location); // use of '*' mask to remove all of type

        void addDirectory(CharString* location); // add directory to system
        void addFile(CharString* location); // add file (touch) to system
        void removeFile(CharString* location); // remove file (rm)
        void removeDir(CharString* location); // remove directory (rmdir)

        void listDirs(); // list directories (ls)
        void listDirs(CharString* location); // list directories (ls /loc)
        void callDirectory(CharString* location); // call directory (cd /)

        void printWorkingDirectory(); // print current directory location (pwd)

        // used to store error strings when they are thrown.
        char* ErrorString;
};

#endif