#ifndef LISTABSTRACT_H
#define LISTABSTRACT_H

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <iterator>

#include <stdio.h>

#include <signal.h>
#include <unistd.h>

#ifdef _WIN64
   #define WINDOWSXX
#elif _WIN32
   #define WINDOWSXX
#else
   #define LINUXX
   #include <execinfo.h>
#endif

// ABSTRACT
// users: LinkedList

template<class T>
class List{
public:
    List(){}
    
    T add(T val);
    T addFirst(T val); // add at the first of the list
    void insert(T val, long loc);
    T get(long index);
    T remove(T val);
    T remove(long val);
    
    T operator [](int index) const;
    T& operator [](int index);
    void operator =(std::initializer_list<T> vallist); //List a = {a, b};
    List<T> operator =(T list);
    
    int size();
}; 

#else
template<class T>
class List;
#endif
