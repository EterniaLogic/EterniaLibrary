#include "AbstractDB.h"

using namespace std;

std::ifstream::pos_type filesize(fstream &in) {
    in.seekg(0, std::ifstream::end);
    return in.tellg();
}

AbstractDBTable::AbstractDBTable(const char* loc, ADB_STOREBASE Base, ADBT_SECURITY sec) {
    fileloc = (char*)loc;
    security = sec;
    base = Base;
    cache = new AbstractDBCacheMap(base, sec);
    seekfirst = seeksize = 0;
    headersize = 0;
    initFile(loc);
}

AbstractDBTable::AbstractDBTable(const char* loc) {
    fileloc = (char*)loc;
    security = ADBT_NONE;
    base = ADB_BASE_2;
    cache = new AbstractDBCacheMap(base, security);
    seekfirst = seeksize = 0;
    headersize = 0;
    initFile(loc);
}

void AbstractDBTable::initFile(const char* loc) {
    fclose(fopen(loc, "a+"));
    fclose(fopen("/tmp/db.tmp", "a+"));
    fileloc = (char*)loc;
    file.open(loc);
    filetmp.open("/tmp/db.tmp", std::fstream::trunc);
    if (filesize(file) > 0) {
        readHeader();
    } else {
        // Assume that data size is 0
        fields = new AbstractDBLinkedDataset();
        file.put('\0');
        file.put(base);
    }
}

void AbstractDBTable::readHeader() {
    reinitTable();
    headersize = 0;
    char headerbase = '\0';
    // read in header size
    file.seekg(0, ios::beg);
    headersize = file.get();
    cout << "Header has " << headersize << " fields" << endl;

    // pupulate fields container
    fields = new AbstractDBLinkedDataset();
    for (int i = 0; i < headersize; i++) {
        fields->push_front(NULL);
    }

    // read in file base
    headerbase = file.get();
    cout << "Header has base ";
    // MapSize: Normal = 32, Extended = b*32. Wide = b*1000*32 (b = base number)
    switch (headerbase) {
        case ADB_BASE_2:
            cout << "2 (32 values)" << endl;
            break;
        case ADB_BASE_2_EXTENDED:
            cout << "2e (64 values)" << endl;
            break;
        case ADB_BASE_2_WIDE:
            cout << "2w (2048 values)" << endl;
            break;

        case ADB_BASE_3:
            cout << "3 (48 values)" << endl;
            break;
        case ADB_BASE_3_EXTENDED:
            cout << "3e (96 values)" << endl;
            break;
        case ADB_BASE_3_WIDE:
            cout << "3w (3078 values)" << endl;
            break;

        case ADB_BASE_5:
            cout << "5 (80 values)" << endl;
            break;
        case ADB_BASE_5_EXTENDED:
            cout << "5e (160 values)" << endl;
            break;
        case ADB_BASE_5_WIDE:
            cout << "5w (5120 values)" << endl;
            break;

        case ADB_BASE_7:
            cout << "7 (112 values)" << endl;
            break;
        case ADB_BASE_7_EXTENDED:
            cout << "7e (224 values)" << endl;
            break;
        case ADB_BASE_7_WIDE:
            cout << "7w (7168 values)" << endl;
            break;

        case ADB_BASE_MAXV_1000:
            cout << "mxv1000 (1000 values, inefficient)" << endl;
            break;
        case ADB_BASE_MAXV_10000:
            cout << "mxv10000 (10000 values, inefficient)" << endl;
            break;
        case ADB_BASE_MAXV_100000:
            cout << "mxv100000 (100000 values, mid-inefficient)" << endl;
            break;
        case ADB_BASE_MAXV_1000000:
            cout << "mxv1000000 (1000000 values, mid-inefficient)" << endl;
            break;
        case ADB_BASE_MAXV_10000000:
            cout << "mxv10000000 (10000000 values, inefficient)" << endl;
            break;
        case ADB_BASE_MAXV_100000000:
            cout << "mxv100000000 (100000000 values, inefficient)" << endl;
            break;

        case ADB_BASE_DYNAMIC:
            cout << "dynamic (up to 2^32 or 2^64 values, unknown efficiency)" << endl;
            break;
    }

    if (base != headerbase) {
        base = static_cast<ADB_STOREBASE>(headerbase);
        cout << "Changed base because file base is different" << endl;
    }

    // read in field formats
    int header_field = 0;
    AbstractDBField* field;
    bool iskey = false;
    seekfirst = 2;
    for (int i = 0; i < headersize; i++) {
        // get an unsigned char
        header_field = file.get();

        // check if it is a key
        if (header_field > 64) {
            // is key, remove 64
            header_field -= 64;
            iskey = true;
        } else iskey = false;

        field = new AbstractDBField(static_cast<ADBF_TYPE>(header_field), iskey);
        seeksize += field->getSize();
        seekfirst++;

        fields->frozen_set(i, (void*)field);
    }
}

// unload all cached rows
AbstractDBTable::~AbstractDBTable() {
    cache->clearCache();
}

void AbstractDBTable::addField(AbstractDBField* field) {
    AbstractDBLinkedDataset* rowList = cache->getAllRows();
    // increment the header size by 1
    file.seekp(0, std::fstream::beg);
    file.put(++headersize);


    // copy the first 2 bits to a temp file
    file.seekg(0, std::fstream::beg);
    filetmp.seekp(0, std::fstream::beg);
    char c1 = file.get();
    char c2 = file.get();
    filetmp.put(c1);
    filetmp.put(c2);

    // write to the fields list
    char c3 = (field->getType() + field->getIsKey() * 64);
    filetmp.put(c3);

    filetmp.flush();

    // loop through cache rows and add the field
    for (int i = 0; i < rowList->getSize(); i++) {
        AbstractDBRow* row = (AbstractDBRow*)rowList->frozen_get(i);
        row->addField(field);

        for (int i = 0; i < seeksize; i++)
            filetmp.put(file.get());

        // modify database file to add the field loop through the characters
        file.seekp(seeksize, ios::beg);
        for (int i = 0; i < seeksize; i++)
            file.put('\0');
    }

    filetmp.flush();

    // set seek
    int tmpsize = filesize(filetmp);
    for (int i = 0; i < tmpsize; i++)
        filetmp.put(file.get());

    // add field to the list.
    seeksize += field->getSize();
    seekfirst++;
    fields->push_back(field); // push field to end of list
}

void AbstractDBTable::flushTable() {
    // write all data in temporary cache to file

}

void AbstractDBTable::reinitTable() {
    flushTable();
    cache->clearCache();

    if (fields != NULL) {
        fields->~AbstractDBLinkedDataset();
        delete(fields);
    }
}

