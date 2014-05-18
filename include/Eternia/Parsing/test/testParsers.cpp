//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "testParsers.h"

void testSimpleParser(){
  // tests parsing system.
  // testParsers.txt
  char* a = new char[13];
  strcpy(a,"testParsers.txt");
  
  CharString* location = new CharString(a,15);
  LinkedListT* list = SimpleParseFile(location,'=');
  
  for(int i=0;i<list->size();i++){
      LinkedListT* list2 = (LinkedListT*)list->get(i);
      for(int j=0;j<list2->size();j++){
          CharString* item = (CharString*)list2->get(j);
          item->replace(" ","");
          item->replace("\t","");
          cout << "'" << item->get() << "'" << endl;
      }    
      cout << "---" << endl;
  }
}

void testSecureParser(){
  CharString* spkey = new CharString("d0f0h-d0f9d9h021d0f0h-d0f9d9h021");
  CharString* file = new CharString("testSecureParser.txt");
  SecuredParser* sp = new SecuredParser(spkey,file);
  cout << "out:" << endl;
  cout << sp->encodeText(new CharString("test test"))->get() << endl;
  //cout << sp->getText()->get() << endl;
}

void testParsers(){
    testSecureParser();
}
