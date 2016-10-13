#include "FileSystem.h"
using namespace std;

/////////// FileStructure Node functions.


// Remove this node from existance. Patch siblings together.
void FileStructureNode::del() {
    //cout << "Removing dir: " << this->name->get() << endl;

    if(this->Parent != 0x0) {
        if(this->Parent->Child == this) {
            // pass parent's childhood to sibling.
            this->Parent->Child = this->Sibling;
        }
    }

    // if there are both siblings and prevsiblings.
    if(this->Sibling != 0x0 && this->PrevSibling != 0x0) {
        this->Sibling->PrevSibling = this->PrevSibling;
        this->PrevSibling->Sibling = this->Sibling;
    } else if(this->Sibling != 0x0) { // only a sibling exists.
        this->Sibling->PrevSibling = 0x0;
    } else if(this->PrevSibling != 0x0) { // only a Previous sibling exists.
        this->PrevSibling->Sibling = 0x0;
    }
}

// add an object (File or Directory) to the node structure.
void FileStructureNode::addObject(FileStructureNode* object) {
    if(this->Child == 0x0) {
        // completely new!
        this->Child = object;
    } else {

        FileStructureNode* current = this->Child, *prev;
        bool isBefore = false;

        // pre-sort to make sure that the Child is at the very left of the values.
        // fixes any errors where the Prev Nodes are behind the header.
        if(this->Child != 0x0) {
            if(this->Child->PrevSibling != 0x0) {
                FileStructureNode* c = this->Child;
                while(c->PrevSibling != 0x0) c = c->PrevSibling;
                current = c;
                this->Child = c;
            }
        }


        // Auto-sort name.
        // determine whether this is "Before" or after the current placement.

        // quick compare items
        SortType st = object->name->SortCompare(current->name);
        if(st == SAfter) {
            // this is After the current placement.

            // determine if it is before the next one.
            while(current->Sibling != 0x0) {
                // quick compare items
                SortType st = object->name->SortCompare(current->Sibling->name);
                if(st == SBefore) {
                    //this is before the sibling of the after item. It works.
                    break;
                } else if (st==SAfter) {
                    // This failed, it cannot be after the after Sibling. retry.
                }
                current = current->Sibling;
            }

        } else if (st == SSame) {
            // ... it exists! ... :/
        } else if (st == SBefore) {
            // This is before the current

            isBefore=true;

            // loop through the previous siblings
            while(current->PrevSibling != 0x0) {
                // quick compare items
                SortType st = object->name->SortCompare(current->PrevSibling->name);
                if(st == SAfter) {
                    // This is after the previous sibling.
                    isBefore=false;
                    current = current->PrevSibling;
                    break;
                } else if (st==SBefore) {
                    // This is before the previous sibling.
                    break;
                }
                current = current->PrevSibling;
            }
        }


        if(isBefore) {
            // set Parent's Child
            if(current->Parent->Child == current) {
                current->Parent->Child = object;
            }

            // set familial relationships
            object->PrevSibling = current->PrevSibling;
            if(object->PrevSibling != 0x0) object->PrevSibling->Sibling = object;
            current->PrevSibling = object;
            object->Sibling = current;
        } else {
            // set familial relationships
            object->Sibling = current->Sibling;
            if(object->Sibling != 0x0) object->Sibling->PrevSibling = object;
            current->Sibling = object;
            object->PrevSibling = current;
        }
    }
}


FileSystem::FileSystem() {
    // initialize the "/" directory.
    this->Root = new FileStructureNode();
    this->Root->name = new CharString(""); // stagnant name
    this->Root->type = Directory;
    this->Current = this->Root;
}

FileSystem::~FileSystem() {}

/* Desc: Find the location of a node
*  Input: node
*  Output: String location of node
 */
CharString* FileSystem::getStringFromNode(FileStructureNode* location) {
    // place a string before the current string.
    CharString* cstring = new CharString();

    FileStructureNode* current = location;

    // loop through and append "/" to all the names
    while(current != 0x0 && current != Root) {
        cstring->concatb(current->name);
        cstring->concatb("/",1);

        current = current->Parent;
    }
    //cstring->concatb("/",1);
    return cstring;
}


/* Desc: Finds a BASE node based on a string. If location does not exist, stop at the current point.
*  Input: String location
*  Output: node from location
*/
FileStructureNode* FileSystem::getBaseNodeFromString(CharString* location) {
    // get the Node from the location... trying to get as accurate as possible.
    //cout << "nodeFromString" << endl;
    if(location->contains("/")) {
        SplitResult* sresult = location->split('/','`');
        FileStructureNode* current = this->Root;
        //cout << "/" << endl;
        for(int i=1; i<sresult->getSize(); i++) {
            // search this node if it is a directory.
            CharString* item = new CharString(sresult->get(i));

            // is directory?
            if(current->type == Directory && current->Child != 0x0) {
                FileStructureNode* tmp = current->Child;
                // quickie loop through this dirs siblings
                while(tmp != 0x0) {
                    // compare the tmp node with the item we are seeking.
                    if(tmp->name->Compare(item)) {
                        current = tmp;
                        break;
                    }
                    tmp = tmp->Sibling;
                }
            }
        }

        return current;
    } else {
        // appending item to the current working dir.
        FileStructureNode* current = this->Current;
        if(current->type == Directory && current->Child != 0x0) {
            FileStructureNode* tmp = current->Child;
            bool exists = false;

            // loop through and find the item based on name.
            while(tmp != 0x0) {
                if(tmp->name->Compare(location)) {
                    current = tmp;
                    exists=true;
                    break;
                }
                tmp = tmp->Sibling;
            }

            if(!exists) {
                //return 0x0;
            }
        } else {
            //return 0x0;
        }

        return current;
    }
}

// Finds a node based on a string. If location does not exist, stop at the current point.
// Input: String location
// Output: Node from location
FileStructureNode* FileSystem::getNodeFromString(CharString* location) {
    // get the Node from the location... trying to get as accurate as possible.
    //cout << "nodeFromString" << endl;
    if(location->contains("/")) {
        SplitResult* sresult = location->split('/','`');
        FileStructureNode* current = this->Root;

        // loop through the result set
        for(int i=1; i<sresult->getSize(); i++) {
            // search this node if it is a directory.
            CharString* item = new CharString(sresult->get(i));

            // if it is a directory, go!
            if(current->type == Directory && current->Child != 0x0) {
                FileStructureNode* tmp = current->Child;
                bool exists = false;
                while(tmp != 0x0) {
                    // compare items
                    if(tmp->name->Compare(item)) {
                        current = tmp;
                        exists=true;
                        break;
                    }
                    tmp = tmp->Sibling;
                }
                if(!exists) {
                    return 0x0;
                }
            } else {
                // check to see whether this child is the abominal item we are seeking.
                return 0x0;
            }
        }
        //cout << "Found: '" << current->name->get() << "'" << endl;
        return current;
    } else {
        // appending item to the current working dir.
        FileStructureNode* current = this->Current;
        // is directory?
        if(current->type == Directory && current->Child != 0x0) {
            FileStructureNode* tmp = current->Child;
            bool exists = false;

            // loop through and determine if it exists in the sibling set.
            while(tmp != 0x0) {
                if(tmp->name->Compare(location)) {
                    current = tmp;
                    exists=true;
                    break;
                }
                tmp = tmp->Sibling;
            }

            // if it does not exist, throw null
            if(!exists) {
                return 0x0;
            }
        } else {
            return 0x0;
        }

        return current;
    }
}

/* Returns the name of the end point.
*  Input: String location
*  Output: Very ending of string after last "/"
 */
CharString* FileSystem::getNameFromString(CharString* location) {
    // gets the name of the last "/dir/dir2/name", even if it ends with "/".
    if(location->get()[location->getSize()-1] == '/') {
        // remove trailing "/".
        location->get()[location->getSize()-1] = '\0';
        location->setSize(location->getSize()-1);
    }

    CharString* result = 0x0;
    // split all by "/".
    if(location->contains("/")) {
        // get the very last result of the split.
        SplitResult* sresult = location->split('/','`');
        result = new CharString(sresult->get(sresult->getSize()-1));
    } else {
        result = location;
    }

    return result;
}

/* Removes all from a file structure if "*" is used adjascent with a "rm" or "rmdir" command.
 * Target: Current Directory
 */
void FileSystem::removeAll(DType t, FileStructureNode* location) {
    // purge this directory of children of type t.
    if(Current->Child != 0x0) {
        FileStructureNode* cc = Current->Child;
        // loop through siblings
        while(cc != 0x0) {
            if(cc->type == t) {
                // delete!
                cc->del();
            }
            cc = cc->Sibling;
        }
    }
}

// Adds a directory to the current directory based on location.
void FileSystem::addDirectory(CharString* location) {
    // get base node of location path.
    FileStructureNode* node = getBaseNodeFromString(location);
    // get name from last "/"
    CharString* name = getNameFromString(location);

    // init a new node
    FileStructureNode* nodenew = new FileStructureNode();
    nodenew->Parent = node;
    nodenew->name = name;
    nodenew->type = Directory;

    // add node to the filesystem
    node->addObject(nodenew);
}

/* Adds a file to the current directory based on location.
 */
void FileSystem::addFile(CharString* location) {
    // get base path
    FileStructureNode* node = getBaseNodeFromString(location);
    // get name from last "/"
    CharString* name = getNameFromString(location);

    // make sure that the node is viable. (base path is current dir)
    if(node == 0x0 && !location->contains("/")) node = Current;

    // init a new node
    FileStructureNode* nodenew = new FileStructureNode();
    nodenew->Parent = node;
    nodenew->name = name;
    nodenew->type = File;

    // add node to the filesystem
    node->addObject(nodenew);
}

// Desc: Removes a file from the current directory based on location.
// Input: String location
void FileSystem::removeFile(CharString* location) {
    FileStructureNode* node = getNodeFromString(location);
    if(node != 0x0) { // is node available?
        if(node->type == File) { // is node a file?
            // directly delete file.
            node->del();
        } else { // else throw DNE error
            CharString* cs = new CharString("rm: ");
            cs->concata(location);
            cs->concata(": file does not exist",21);
            this->ErrorString = cs->get();
            throw 6;
        }
    } else { // else throw DNE error
        // throw error!
        CharString* cs = new CharString("rm: ");
        cs->concata(location);
        cs->concata(": file does not exist",21);
        this->ErrorString = cs->get();
        throw 5;
    }
}

// Removes a directory from the current directory based on location.
// Input: String location
void FileSystem::removeDir(CharString* location) {
    FileStructureNode* node = getNodeFromString(location);
    if(node != 0x0 && node != Root) {
        // type-dir
        if(node->type == Directory) {
            // determine if CD is inside this dir.
            bool isCD = false;
            if(node->Child != 0x0) {
                FileStructureNode* cc = node->Child;
                while(cc != 0x0 && !isCD) {
                    // search through all of the relatives.
                    if(cc == Current) {
                        isCD = true;
                        break;
                    } else if(cc->Sibling != 0x0) {
                        FileStructureNode* ccd = cc->Sibling;
                        while(ccd != 0x0) {
                            if(ccd == Current) {
                                isCD=true;
                                break;
                            }
                            ccd = ccd->Sibling;
                        }
                    }
                    cc = cc->Child;
                }
            } else if(node == Current) {
                isCD = true;
            }


            if(!isCD) {
                node->del();
            } else {
                // this is restricted by call directory
                CharString* cs = new CharString("rmdir: ");
                cs->concata(location);
                cs->concata(": directory cannot be deleted",29);
                this->ErrorString = cs->get();
                throw 15;
            }

        } else {
            // cannot find!
            CharString* cs = new CharString("rmdir: ");
            cs->concata(location);
            cs->concata(": directory does not exist",26);
            this->ErrorString = cs->get();
            throw 8;
        }
    } else {
        // throw error!
        CharString* cs = new CharString("rmdir: ");
        cs->concata(location);
        cs->concata(": directory does not exist",26);
        this->ErrorString = cs->get();
        throw 7;
    }
}

// Lists all files and dirs in this directory.
void FileSystem::listDirs() {
    cout << "." << endl;
    cout << ".." << endl;


    if(Current == 0x0) Current = Root;
    if(Current->Child != 0x0) {
        FileStructureNode* cc = Current->Child;
        // loop through all of the siblings
        while(cc != 0x0) {
            cout << this->getStringFromNode(cc)->get() << endl;
            cc = cc->Sibling;
        }
    } else {
        // empty?
    }
}

// NON-USED
/*// Lists all files and dirs in a specific directory.
void FileStructure::listDirs(CharString* location){

}*/


// Set the Current variable to the current directory.
void FileSystem::callDirectory(CharString* location) {
    if(location->Compare("..",2)) {
        if(Current->Parent != 0x0) {
            Current = Current->Parent;
        }
    } else {
        FileStructureNode* node = getNodeFromString(location);
        if(node != 0x0) {
            if(node->type == Directory) {
                Current = node;
            } else {
                // throw error!
                CharString* cs = new CharString("cd: ");
                cs->concata(location);
                cs->concata(": not a directory",17);
                this->ErrorString = cs->get();
                throw 10;
            }
        } else {
            // throw error!
            CharString* cs = new CharString("cd: ");
            cs->concata(location);
            cs->concata(": directory does not exist",26);
            this->ErrorString = cs->get();
            throw 9;
        }
    }
}

// Print out the current location.
void FileSystem::printWorkingDirectory() {
    if(Current == Root) {
        //cout << "/" << endl;
    } else {
        //cout << this->getStringFromNode(Current)->get() << endl;
    }
}
