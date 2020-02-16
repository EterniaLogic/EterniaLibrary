#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_


template<class T>
class ArrayListIterator;
#include "ArrayListIterator.hpp"

template<class T>
class ArrayList{
    T* listx;
    long len;
public:
    ArrayList(long length){ // set base length, malloc(length)
        this->listx = malloc(length*sizeof(T));
        this->len = length;
    }
    
    ArrayList(){ // assume zero
        this->listx = 0x0;
        this->len = 0;
    }
    
    
    // append to end of list (Expensive!)
    T add(T val){
        len++;
        T* tmplist = malloc(len*sizeof(T));
        for(long i=0;i<len-1;i++){
            tmplist[i] = listx[i];
        }
        
        tmplist[len-1] = val;
        listx = tmplist;
        
        return val;
    }
    
    // append to front end of list (Expensive!)
    T addFirst(T val){ // add at the first of the list
        len++;
        T* tmplist = (T*)malloc(len*sizeof(T));
        tmplist[0] = val;
        for(long i=1;i<len;i++){
            tmplist[i] = listx[i-1];
        }
        
        listx = tmplist;
        
        return val;
    }
    
    // insert to into list (Expensive!)
    void insert(T val, long loc){
        len++;
        T* tmplist = (T*)malloc(len*sizeof(T));
        
        for(long i=0;i<loc;i++){
            tmplist[i] = listx[i];
        }
        
        tmplist[loc] = val;
        
        for(long i=loc+1;i<len;i++){
            tmplist[i] = listx[i];
        }
        
        listx = tmplist;
    }
    
    T get(long index){
        return listx[index];
    }
    
    T get(long index) const{
            return listx[index];
        }

    // remove one of val from list (Expensive!)
    T remove(T val){
        for(long i=0;i<len;i++){
            if(val == listx[i]){
                remove(i);
                return val;
            }
        }
        
        return val;
    }
    
    // remove from list (Expensive!)
    T remove(long loc){
        if(len > 0) len--;
        T* tmplist = (T*)malloc(len*sizeof(T));
        
        for(long i=0;i<loc;i++){
            tmplist[i] = listx[i];
        }
        
        for(long i=loc+1;i<len;i++){
            tmplist[i-1] = listx[i]; // skip
        }
        
        T val = get(loc);
        listx = tmplist;
        
        return val;
    }
    
    T operator [](long index) const{
        return ((T)this->get(index));
    }
    
    T& operator [](long index){
        return &listx[index];
    }
    
    // cross-list operation
    void operator =(ArrayList<T> listx){
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
    
    ArrayListIterator<T> getIterator(){ // generic iterator
        return ArrayListIterator<T>(this);
    }
    
    void clear(){
        if(listx != 0x0){
            len=0;
            T* l = listx;
            listx = 0x0;
        }
    }
    
    int size(){
        return len;
    }
};

#endif
