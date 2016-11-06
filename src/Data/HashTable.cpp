#include "HashTable.h"

using namespace std;

// ONLY used for initializer
HTEntry::HTEntry() {}

// Used when entering new data, setID() is the hashing function.
HTEntry::HTEntry(CharString key, CharString data) {
    k=key;
    d=data;
    setID();
}


// HASHING function that sets the id.
void HTEntry::setID() {

    //char* table = "sadg-9u4yjhropajhaslmanm"; // quick hash
    // does a hashtable implementation.
    //cout << "GAH!" << endl;
    unsigned int len = k.getSize();
    char* cc = k.get();
    unsigned long end = 0;

    if(len < 3) { // 0 collisions
        for(unsigned int i=0; i<len; i++) {
            end = cc[i] + end<<6 + end << 12 - end;
            //end -= end<<2;
        }
        while(end > 199999999) {
            end /= 10*len;
        }
    } else if(len == 3) { // 0 collisions
        for(unsigned int i=0; i<len; i++) {
            //end = ((end << 5) + end) + (cc[i]);//-31);// * (i+1) * len;
            end = cc[i] + end<<3 + end<<4 - end;
        }
        while(end > 199999999) {
            end /= 10;
        }
    } else if(len == 5) { // len = 5, ? collisions. (tested 8700 -> 61 collisions)
        for(unsigned int i=0; i<len; i++) {
            //end = ((end << 5) + end) + (cc[i]);//-31);// * (i+1) * len;
            //end = cc[i]<<len + (end<<4)/3 - end;
            end += (cc[i]-31)<<(10*(i+1));
        }

        //end = end%len+end;
        while(end > 199999999) {
            end /= 100000;
        }
    } else { // 338 collisions out of 9025 tested. (Pretty good, but not perfect.)
        //end = 1;
        for(int i=0; i<len; i++) {
            end = (cc[i]*len*(i+1)*end)*2 + ~cc[i]<<4 + (end%(len*5)) + (cc[i])%len + end<<7;
            end = end ^ (32416190071*cc[i]); // XOR with very large prime #
            end = end | (15487249*cc[i]); // OR with pretty large prime #
            end = end | (88888*cc[i]);
            end = end | (32416190071*cc[i]);
        }

        //cout << end << endl;

        // smaller number in while loop improves accuracy...
        // it's impossible to be accurate because this algorithm is constricted to a
        //      max size of 199999999...
        while(end > 199999999) {
            end /= 10;
        }
    }

    id = end;
}

// returns id pointer
int HTEntry::getID() {
    return id;
}

// returns stored key pointer
CharString HTEntry::getKey() {
    return k;
}

// returns data pointer
CharString HTEntry::getData() {
    return d;
}

void HTEntry::set(HTEntry* entry) {
    // sets the data values.
    id = entry->getID();
    k = entry->getKey();
    d = entry->getData();
}

void HTEntry::add(HTEntry* entry) {
    // add to the end.
    HTEntry* current = this;
    while(current->next != 0x0) current = current->next;
    current->next = entry;
}

CharString HTEntry::get(CharString key) {
    // add to the end.
    //cout << d << endl;
    HTEntry* current = this;
    while(current != 0x0) {
        if(current->getKey().Compare(key)) {
            //cout << current->getData() << endl;
            return current->getData();
        }
        current = current->next;
    }

    return CharString();
}

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
HashTable::HashTable(int max) {
    // set max entries
    entries = new HTEntry[(const int)max];
}

void HashTable::add(HTEntry* entry) {
    // add at [id]
    if(entries[entry->getID()].getID() != 0) {
        // add to end of list.
        //cout << "add" << endl;
        entries[entry->getID()].add(entry);
        collides++;
    } else {
        entries[entry->getID()].set(entry);
        //cout << "D: " << entries[entry->getID()].getData() << endl;
        //cout << "K: " << entry->getID() << endl;
    }

}

CharString HashTable::get(CharString key) {
    // add at [id]
    //cout << "ht::get - 1" << endl;
    HTEntry* S = new HTEntry(key, CharString());
    //cout << "ht::get - 2" << endl;
    //cout << "keyat: " << S->getID() << endl;
    if(entries[S->getID()].getID() != 0) {
        //cout << "ht::get - 3" << endl;
        if(entries[S->getID()].getKey().Compare(key)) {
            //cout << "ht::get - 4" << endl;
            return entries[S->getID()].getData();
        } else {
            //cout << "ht::get - 5" << endl;
            return entries[S->getID()].get(key);
        }
    }
}
