#ifndef testDB_h
#define testDB_h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <istream>
#include <fstream>
#include <math.h>

#include "../LinkedList.hpp"
#include "../PriorityQueue.h"
#include "../CharString.h"

#include "AbstractDBDate.hpp"

using namespace std;

// all definitions in bytes (8 bits)
#define DB_CHAR_SIZE    1
#define DB_INT_SIZE     4
#define DB_LONG_SIZE    8

#define DB_STRING_SIZE  4 // blob file pointer
#define DB_DATE_SIZE    8 // 64-bit stores year, month, day, hour, minute, second

#define DB_REAL_SIZE    2
#define DB_FLOAT_SIZE   4
#define DB_DOUBLE_SIZE  8
#define DB_QUAD_SIZE    16 // 128-bit Mantissa precision 64



// number of bits corresponding to type
// DB_STRING data type is a pointer to a string file
enum ADBF_TYPE { DB_CHAR, DB_INT, DB_LONG,
                 DB_STRING, DB_DATE,
                 DB_REAL, DB_FLOAT, DB_DOUBLE, DB_QUAD
               };
enum ADBT_SECURITY {ADBT_NONE, ADBT_AES256};

enum ADB_STOREBASE {                                  // MapSize: Normal = 32, Extended = b*32. Wide = b*1000*32 (b = base number)
    // log-based keys
    ADB_BASE_2, ADB_BASE_2_EXTENDED, ADB_BASE_2_WIDE, // 32, 64,  2048  << DYNAMIC PERFORMANCE AND DATAINDEX SIZES with dynamic ram and disk usage
    ADB_BASE_3, ADB_BASE_3_EXTENDED, ADB_BASE_3_WIDE, // 32, 96,  3078
    ADB_BASE_5, ADB_BASE_5_EXTENDED, ADB_BASE_5_WIDE, // 32, 160, 5120
    ADB_BASE_7, ADB_BASE_7_EXTENDED, ADB_BASE_7_WIDE, // 32, 224, 7168
    // Direct keys
    ADB_BASE_MAXV_1000, ADB_BASE_MAXV_10000,          // 1000,     10000
    ADB_BASE_MAXV_100000, ADB_BASE_MAXV_1000000,      // 100000,   1000000  << HIGH PERFORMANCE DATAINDEX SIZES, predefined disk and ram usage
    ADB_BASE_MAXV_10000000, ADB_BASE_MAXV_100000000,  // 10000000, 100000000 // WARNING: will use a LOT of ram just to hold the main map
    ADB_BASE_DYNAMIC
}; // Dynamic base allows for the base to change over the number of values in the file.
// Using a larger base will achieve a larger maximum index value.
//      Larger index values are useful if you need to
//      store extremely large amounts of data with low priority
//      to access speed and large use of memory.
// Extended subdivides the base n times, where n is the base
//      may provide better performance,
//      but uses slightly more memory and filesize
// Wide subdivies the base by n*32 times,
//      which will use a substantial amount of
//      filesize and memory based on base number

std::ifstream::pos_type filesize(fstream &in);


class AbstractDBField {
        ADBF_TYPE fieldtype;
        bool iskey;
        void init(ADBF_TYPE type, bool isKey);
    public:
        AbstractDBField(ADBF_TYPE type, bool isKey);
        AbstractDBField(ADBF_TYPE type);
        AbstractDBField(){}
        ~AbstractDBField();

        int getSize();
        bool getIsKey();
        ADBF_TYPE getType();
};


// Abstract DB row that is read from file
// may be temporarily stored based on frequency of use
class AbstractDBRow {
        LinkedList<AbstractDBField> fieldList;
        CharString value;
    public:
        AbstractDBRow();
        LinkedList<AbstractDBField> getFieldValues();
        void addField(AbstractDBField field);
        void clearRow();
        
        int getIntValue();
        CharString getStringValue();
        AbstractDBDate getDateValue();

        int mapindex;
};



class AbstractDBCacheMap {
        ADBT_SECURITY security;
        ADB_STOREBASE base;
        LinkedList<char> mapArray;
        LinkedList<AbstractDBRow> rowList;
    public:
        AbstractDBCacheMap(ADB_STOREBASE Base, ADBT_SECURITY Security);
        AbstractDBCacheMap();
        ~AbstractDBCacheMap();

        void clearCache();
        int getKey(double index);
        AbstractDBRow getRow(double index);

        LinkedList<AbstractDBRow> getAllRows();
};

class AbstractDBTable {
        LinkedList<AbstractDBField> fields;
        CharString fileloc;
        ADBT_SECURITY security;
        ADB_STOREBASE base;
        AbstractDBCacheMap cache;
        fstream file, filetmp;
        
        AbstractDBDate created, modified; // create/modified date timestamp
        
        int headersize;
        int seekfirst; // seek to go to get to first row
        int seeksize; // size total of each row
        void initFile(CharString file);
        void readHeader();
    public:
        // input file and Row security
        // Base value should be larger if a larger index range
        // Larger bases also slow down performance
        // Base 2 goes from 0 to 4,294,967,296 (DEFAULT)
        // Base 3 goes from 0 to 1,853,020,188,851,841
        // Base 5 goes from 0 to 23,283,064,365,386,962,890,625
        AbstractDBTable(){}
        AbstractDBTable(CharString file, ADB_STOREBASE Base, ADBT_SECURITY Security);
        AbstractDBTable(CharString file); // no security, Default Base 2
        ~AbstractDBTable();

        LinkedList<AbstractDBField> getFields(); // returns header that was read from file on init
        LinkedList<AbstractDBRow> getAllRows(); // SLOW: reads all data from DB file

        void addField(AbstractDBField field); // add a field (insert data into file and change all rows)
        void deleteField(AbstractDBField field); // remove a field
        void insertRow(int index, AbstractDBRow row);
        void removeIndex(int index); // remove row from index

        void flushTable(); // writes all data in cache to file
        void reinitTable(); // close resources for reinit
};


class AbstractDB {
private:
    LinkedList<AbstractDBTable> tables;
public:
    AbstractDB(CharString folder, ADB_STOREBASE Base, ADBT_SECURITY Security);
    AbstractDB(){}
    
    
};

#endif
