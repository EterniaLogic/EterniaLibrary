#ifndef DBROW_H_
#define DBROW_H_

#include "../CharString.h"

template<class T>
class DBRow{
public:
    LinkedList<CharString> fields; // names for headers
    LinkedList<T> rowdata;
};

#endif
