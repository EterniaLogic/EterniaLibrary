#include "Config.h"


Config::Config() {
    //items = new HashMap<CharString>();
}

void Config::Load(CharString* filename) {
    ifstream file;
    fileOpen(file, filename->get());
    CharString read;

    cout << "Loading Config... ";
    cout.flush();
    while((read = fileGetLine(file)).getSize() > -1) {
        // cout << "item... "; cout.flush();
        //cout << "b " << endl; cout.flush();
        if(read.getSize() < 1) continue;
        if(!read.startsWith(CharString("#\0",1)) && !read.startsWith(CharString("//\0",2)) && !read.startsWith(CharString("[",1))) {
            // do the splitting!!!
            LinkedList<CharString> s = read.split('=', '`');
            //s.freeze();
            //cout << s.get(0)->get() << " = " << s.get(1)->get() << " @MEM(" << s.get(1) << ") " << s.frozenlen << endl; cout.flush();
            
            if(s.get(1).getSize() > 0) {
                items[s.get(0).get()] = s.get(1);
            }
        }
        // cout << "c " << endl; cout.flush();
    }
    cout << "Loaded" << endl;
    cout.flush();

    fileClose(file);
}
