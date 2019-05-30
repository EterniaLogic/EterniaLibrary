#ifndef LISTABSTRACT_H
#define LISTABSTRACT_H

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <iterator>

#include <stdio.h>

#include "ListIterator.h"
//#define SIZEOFA(x) (sizeof(x) / sizeof(x[0]))

#ifdef _WIN64 || _WIN32
#else
   #define LINUXX
	#include <execinfo.h>
	#include <signal.h>
	#include <unistd.h>
#endif

// ABSTRACT
//  - LinkedList
//  - ArrayList


template<class T>
class List{
public:
    List(){}
    
    virtual T add(T val) {}
    virtual T addFirst(T val) {} // add at the first of the list
    virtual void insert(T val, long loc) {}
    virtual T get(long index) {}
    virtual T remove(T val) {}
    virtual T remove(long val) {}
    
    virtual ListIterator<T> getIterator(){ // generic iterator
        return ListIterator<T>(this);
    }
    
    virtual T operator [](long index) const {}
    virtual T& operator [](long index) {}
    
    // cross-list operation
    void operator =(List<T> listx){
        clear();
        for(int i=0;i<listx.size();i++)
            add(listx[i]);
    }
    
    
    // cross-list operation
    void operator =(std::initializer_list<T> vallist){ //List a = {a, b};
        clear();
        std::vector<T> v;
        v.insert(v.end(), vallist.begin(), vallist.end());
        for(int i=0;i<vallist.size();i++)
            add(v[i]);
    }
    
    virtual void clear(){}
    virtual int size(){return 0;}
}; 

#else
template<class T>
class List;
#endif
