

#include "SimpleParser.h"
using namespace std;

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
LinkedList<CharString> SimpleParseLine(CharString input, char separator) {
    // do the splitting!!!
    return input.split(separator, '`');
}

// take data in line-by-line and parse it
// output: LinkedListT of LinkedListT of (CharString *)
LinkedList<LinkedList<CharString>> SimpleParseFile(CharString filename, char separator) {
    LinkedList<LinkedList<CharString>> list;
    //cout << "parse-01" << endl;

    ifstream file;
    //cout << "parse-02 " << filename << endl;
    //cout << "parse-02 " << filename->getSize() << endl;
    //cout << "parse-02 " << filename->get() << endl;
    fileOpen(file, filename.get());
    //cout << "parse-1" << endl;
    CharString read;
    while((read = fileGetLine(file)).getSize() > -1) {
        if(!read.startsWith("#") && !read.startsWith("//") && !read.startsWith("[")) {
            LinkedList<CharString> list2 = SimpleParseLine(read, separator);
            if(list2.size() > 0) {
                list.add(list2);
            }
        }
    }
    //cout << "parse-3" << endl;

    fileClose(file);

    return list;
}


// take data in line-by-line and parse it
// output: LinkedListT of LinkedListT of (CharString *)
LinkedList<LinkedList<CharString>> SimpleParseString(CharString data, char separator) {
    LinkedList<LinkedList<CharString>> list;
    LinkedList<CharString> lines = SimpleParseLine(data, '\n');
    lines.freeze();
    for(int i=0;i<lines.frozenlen;i++){
        CharString read = lines.frozen[i];
        if(!read.startsWith("#") && !read.startsWith("//") && !read.startsWith("[")) {
            LinkedList<CharString> list2 = SimpleParseLine(read, separator);
            if(list2.size() > 0) {
                list.add(list2);
            }
        }
    }

    return list;
}
