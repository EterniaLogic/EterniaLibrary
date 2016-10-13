//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "SimpleParser.h"

// simple parser parses line-by-line based on a separator.
// ex:
//  Configuration file:
//      language=english
//      data=/etc/dataloc
//  Translation file:
//      hello;hola;Bonjour
//      one;uno;un

// parse input and split it by separator.
// output: LinkedListT of (CharString *)
LinkedList<CharString>* SimpleParseLine(CharString* input, char separator) {
    LinkedList<CharString>* list = new LinkedList<CharString>();

    // do the splitting!!!
    SplitResult* s = input->split(separator, '`');

    for(int i=0; i<s->getSize(); i++) {
        //cout << s->get(i) << endl;
        list->add(new CharString(s->get(i), s->getLen(i)));
    }

    if(list->size() == 0) list = 0x0;
    return list;
}

// take data in line-by-line and parse it
// output: LinkedListT of LinkedListT of (CharString *)
LinkedList<LinkedList<CharString> >* SimpleParseFile(CharString* filename, char separator) {
    LinkedList<LinkedList<CharString> >* list = new LinkedList<LinkedList<CharString> >();
    //cout << "parse-01" << endl;

    ifstream file;
    //cout << "parse-02 " << filename << endl;
    //cout << "parse-02 " << filename->getSize() << endl;
    //cout << "parse-02 " << filename->get() << endl;
    fileOpen(file, filename->get());
    //cout << "parse-1" << endl;
    CharString* read;
    while((read = fileGetLine(file)) != 0x0) {
        if(!read->startsWith(new CharString("#")) && !read->startsWith(new CharString("//")) && !read->startsWith(new CharString("["))) {
            LinkedList<CharString>* list2 = SimpleParseLine(read, separator);
            if(list2 != 0x0) {
                list->add(list2);
            }
        }
    }
    //cout << "parse-3" << endl;

    fileClose(file);

    return list;
}
