//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "test.h"

void testParsers(){
    // tests parsing system.
    // testParsers.txt
    char* a = new char[15];
    strcpy(a,"./testParsers.txt");
    
    CharString* location = new CharString(a,15);
    LinkedListT* list = SimpleParseFile(location,'=');
    
    for(int i=0;i<list->size();i++){
        LinkedListT* list2 = (LinkedListT*)list->get(i);
        for(int j=0;j<list2->size();j++){
            CharString* item = (CharString*)list2->get(j);
            cout << item->get() << endl;
        }    
        cout << "---" << endl;
    }
}
