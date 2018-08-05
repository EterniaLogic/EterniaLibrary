#ifndef DBList_H_
#define DBList_H_
#include "DBRow.h"

// Database list, requires an implementation to be usable

template<class T>
class DBList{
public:
    DBList();
    
    bool beginFor(); // begin a transaction for loop through all items in DB
    DBRow<T>* next(); // next in result (returns 0x0 or NULL if end or error)
    
};

#endif
