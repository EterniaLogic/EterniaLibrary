//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
#include <malloc.h>
using namespace std;

// Gar! I don't like writing templates because of this!

template<class T>
class LinkedNode {
public:
    //LinkedNode<T> * prev;
    LinkedNode<T> * next;
    T* data;
    int id;
    LinkedNode() {
        //prev =
        next = 0x0;
        data = 0x0;
    }
    ~LinkedNode() {
        //prev = next = 0x0;
        //data = 0x0;
    }
};

template<class T>
class LinkedList {
    //Written January 25th, 2013
    LinkedNode<T>* baseNode;
    LinkedNode<T>* currentNode;
    int _size;
    bool changed; // used with freezing to help keep better performance
public:
    T **frozen;
    int frozenlen;


    // Initialize!
    LinkedList() {
        baseNode = 0x0;
        currentNode = 0x0;
        _size = 0;
        changed=true;
        frozen=0x0;
        frozenlen=0;
    }

    // Clean up!
    ~LinkedList() {
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
    void add(T* cc) {
        //adds a Void* Object. This can be declared when using the list.
        //cout << "add item " << cc << endl;
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
    }

    // Add non-pointer
    void add(T cc) {
        //adds a Void* Object. This can be declared when using the list.
        T* val = (T*)malloc(sizeof(T));
        *val = cc;
        add(val);
    }

    // return item
    T* get(int index) {
        freeze();
        if(index > _size-1) return 0x0;
        return frozen[index];
    }

    // insert at the specified location
    void insert(T* data, int location){
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

    LinkedNode<T>* top() {
        return baseNode;
    }

    T* remove(long index) {
        T* r = 0x0;

        if(index< _size) {
            // erase element at i

            LinkedNode<T>* current = baseNode;
            LinkedNode<T>* prev = 0x0;
            for(long i=0; i<=index; i++) {
                if(current != 0x0) {
                    if (i == index) {
                        /*if(current->next != 0x0){
                            if(current->prev != 0x0) current->next->prev = current->prev->next;
                            else current->next->prev = 0x0;
                        }
                        if(current->prev != 0x0){
                            if(current->next != 0x0) current->prev->next = current->next->prev;
                            else current->prev->next = 0x0;
                        }*/

                        prev->next = current->next;
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

    // Clears up the list
    void clear() {
        //while(remove(0L) != 0x0);
        LinkedNode<T>* current = baseNode;
        LinkedNode<T>* cnt;
        while(current != 0x0){
            current->data = 0x0;
            //current->prev = 0x0;

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

        freeze();
        for(int i=0; i<count && i<frozenlen; i++){
            newList.add(frozen[start+i*skip]);
        }

        return newList;
    }

    // retrieve item?
    T operator [](int i) const {
        freeze();
        return frozen[i];
    }

    T& operator [](int i){
        freeze();
        return *frozen[i];
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
            //cout << "freeze-1 " << _size << endl;
            if(frozen != 0x0){
                for(i = 0;i<frozenlen;i++)
                    frozen[i] = 0x0;
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
                this->frozen = new T*[len];

                current = baseNode;
                //cout << "FREEZE: ";
                for(i=0; i<len; i++) {
                    if(current != 0x0) {
                        //cout << " " << current->data;
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
            add(&thislist[i]);
        }

        changed=true;
    }
};

#endif
