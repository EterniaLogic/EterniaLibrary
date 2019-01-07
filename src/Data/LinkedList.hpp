#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <malloc.h>
#include <stdlib.h>
#include <vector>
#include <iterator>

#include <stdio.h>
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

#include "LinkedListIterator.hpp" // Iteration, FOR_LIST

using namespace std;

//#define dbgLog(strx) cout << "[LinkedList] " << strx << endl;
#define dbgLog(strx) cout << "";

#define SIZEOFA(x) (sizeof(x) / sizeof(x[0]))

// Gar! I don't like writing templates because of this!

template<class T>
class LinkedNode {
public:
    //LinkedNode<T> * prev;
    LinkedNode<T> * next;
    T data;
    //int id;
    LinkedNode() {
        //prev =
        next = 0x0;
    }
    ~LinkedNode() {
        //prev = next = 0x0;
        //data = 0x0;
    }
};

template<class T>
class LinkedList {
    //Written January 25th, 2013
    
    int _size;
    bool changed; // used with freezing to help keep better performance
public:
    LinkedNode<T>* baseNode;
    LinkedNode<T>* currentNode;
    T *frozen;
    int frozenlen;


    // Initialize!
    LinkedList() {
        dbgLog("init");
        baseNode = 0x0;
        currentNode = 0x0;
        _size = 0;
        changed=true;
        frozen=0x0;
        frozenlen=0;
    }

    // Clean up!
    ~LinkedList() {
        dbgLog("finalize");
        
        /*void *array[10];
        size_t size;

          // get void*'s for all entries on the stack
        size = backtrace(array, 10);

          // print out all the frames to stderr
        fprintf(stderr, "Error: signal %d:\n", 1);
        backtrace_symbols_fd(array, size, STDERR_FILENO);*/
        
        
        clear();
        /*if(frozen != 0x0){
            for(int i = 0;i<frozenlen;i++)
                frozen[i] = 0x0;
            delete [] frozen;
            frozen = 0x0;
        }
        frozenlen=0;*/
    }
    
    
    
    

    // add item
    T add(T cc) {
        //adds a Void* Object. This can be declared when using the list.
        //cout << "add item " << cc << endl;
        dbgLog("add item");
        LinkedNode<T>* item = new LinkedNode<T>();
        item->data = cc;
        if(baseNode == 0x0 || currentNode == 0x0) {
            baseNode = item;
            currentNode = item;
        } else {
            currentNode->next = item;
            currentNode = item;
        }
        _size++;
        changed=true;
        
        return cc;
    }
    
    T addFirst(T cc){
        //adds a Void* Object. This can be declared when using the list.
        
        LinkedNode<T>* item = new LinkedNode<T>();

        dbgLog("add item first '" << (int)cc[0] << "' @ (" << item << ")");

        item->data = cc;
        
        if(baseNode == 0x0 || currentNode == 0x0) {
            this->baseNode = item;
            this->currentNode = item;
        } else {
            item->next = this->baseNode;
            this->baseNode = item;
        }
        _size++;
        changed=true;
        
        dbgLog("base = " << baseNode << " cur = " << currentNode);
        dbgLog("value item " << (int)item->data[0] << " " << *(baseNode->data));
        
        return cc;
    }


    // return item
    T get(int index) {
        freeze();
        //if(index > _size-1) return 0x0;
        return frozen[index];
    }

    // insert at the specified location
    void insert(T data, int location){
        dbgLog("insert");
        if(location >= _size || baseNode == 0x0){
            add(data);
            return;
        }
        
        

        LinkedNode<T>* current = baseNode;
        LinkedNode<T>* cnt = 0x0;
        int i=0;
        LinkedNode<T>* item = new LinkedNode<T>();
        item->data = data;

        while(current != 0x0){
            if(i == location){
                if(location == 0){
                    cnt = baseNode;
                    baseNode = item;
                    item->next = cnt;
                }else{
                    cnt->next = item;
                    item->next = current;
                }
                _size++;
                break;
            }

            cnt = current;
            current = current->next;
            i++;
        }

        changed=true;
    }

    // return the size
    int size() {
        return _size;
    }
    
    int getSize() {
        return _size;
    }
    
    int length() {
        return _size;
    }



    LinkedNode<T>* top() {
        return baseNode;
    }

    T remove(long index) {
        T r;
        dbgLog("remove");
        
        if(index< _size) {
            // erase element at i

            LinkedNode<T>* current = baseNode;
            LinkedNode<T>* prev = 0x0;
            for(long i=0; i<=index; i++) {
                if(current != 0x0) {
                    if (i == index) {
                        if(prev != 0x0) prev->next = current->next;
                        else baseNode = current->next;
                        
                        current->next = 0x0;
                        //current->prev = 0x0;
                        r = current->data;
                        current->data = 0x0;
                        _size--;

                        //delete current;
                        break;
                    }
                } else {
                    break;
                }
                prev = current;
                current = current->next;
            }
        }
        changed=true;
        return r;
    }
    
    T remove(T v) {
        T r = 0x0;
        dbgLog("remove");

        // erase element with data of v

        LinkedNode<T>* current = baseNode;
        LinkedNode<T>* prev = 0x0;
        for(long i=0; i<_size; i++) {
            if(current != 0x0) {
                if (v == current->data) {

                    if(prev != 0x0) prev->next = current->next;
                    else baseNode = current->next;
                    current->next = 0x0;
                    
                    r = current->data;
                    current->data = 0x0;
                    _size--;

                    changed = true;
                    break;
                }
            } else {
                break;
            }
            prev = current;
            current = current->next;
        }
        return r;
    }

    // Clears up the list
    void clear() {
        dbgLog("list clear");
        //while(remove(0L) != 0x0);
        LinkedNode<T>* current = baseNode;
        LinkedNode<T>* cnt;
        while(current != 0x0){
            cnt = current->next;
            current->next = 0x0;
            current = cnt;
        }

        baseNode = 0x0;
        currentNode = 0x0;
        _size = 0;
        changed=true;
        frozen=0x0;
        frozenlen=0;
    }

    // slice this list up into parts, output new one
    LinkedList<T> slice(int start, int count, int skip){
        LinkedList<T> newList;
        dbgLog("slice");
        
        freeze();
        for(int i=0; i<count && i<frozenlen; i++){
            newList.add(frozen[start+i*skip]);
        }

        return newList;
    }
    
    int indexOf(T val){
        int i = -1;
        dbgLog("index");
        LinkedNode<T> *current = baseNode;
        while(current != 0x0){
            if(current->data == val) return i+1;
            else i++;
            current = current->next;
        }
        
        return -1;
    }

    // retrieve item?
    T operator [](int i) const {
        freeze(); // @suppress("Invalid arguments")
        return frozen[i];
    }

    T& operator [](int i){
        freeze();
        return frozen[i];
    }

    // Returns the type-size of the data
    int typeSize() {
        return sizeof(T);
    }

    // convert from linkedList to a static list.
    void freeze() {
        LinkedNode<T>* current;
        const int len = _size;
        int i;

        if(changed || _size != frozenlen) {
            dbgLog("freeze-1 " << _size);
            if(frozen != 0x0){
                for(i = 0;i<frozenlen;i++)
                    frozen[i] = T();
                delete [] frozen;
                frozen = 0x0;
            }

            if(_size == 0) {
                changed=false;
                return;
            }

            // copy values in!
            if(baseNode != 0x0) {

                this->frozenlen = _size;
                this->frozen = new T[len];

                current = baseNode;
                for(i=0; i<len; i++) {
                    if(current != 0x0) {
                        dbgLog("FREEZE: item " << current->data << " @ " << current);
                        frozen[i] = current->data;
                        current = current->next;
                    } else {
                        break;
                    }
                }
                //cout << endl; cout.flush();
            }
            changed=false;
        }else if(_size <= 0){
            this->frozenlen = _size;
        }
    }
    
    
    LinkedList<T> operator =(T vallist){
        int size_ = SIZEOFA(vallist);
        clear();
        for(int i=0;i<size_;i++){
            add(vallist[i]);
        }
        
        return this;
    }
    
    void operator =(std::initializer_list<T> vallist){
        std::vector<T> v;
        v.insert(v.end(), vallist.begin(), vallist.end());
        for(int i=0;i<vallist.size();i++){
            add(v[i]);
        }
    }
    

    void refreeze(){
        changed=true;
        frozenlen=0;
        freeze();
    }


    // unfreeze will determine if there are any new addresses added
    // First, clears the list, then goes through a brand new list
    void unfreeze(void* list, int bytes) {
        clear();
        _size = bytes/sizeof(T);
        T* thislist = (T*)list;

        for(int i=0; i<_size; i++) {
            add(thislist[i]);
        }

        changed=true;
    }
    
    
    LinkedListIterator<T> getIterator(){
        return LinkedListIterator<T>(*this);
    }
    
};

#else
template<class T>
class LinkedList;
#endif
