//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;

// Gar! I don't like writing templates because of this!

template<class T>
class LinkedNode
{
public:
    LinkedNode<T> * prev;
    LinkedNode<T> * next;
    T* data;
    LinkedNode(){
      prev = next = 0x0;
      data = 0x0;
    }
    ~LinkedNode(){
      prev = next = 0x0;
      data = 0x0;
    }
};

template<class T>
class LinkedList
{
	//Written January 25th, 2013
	LinkedNode<T> * baseNode;
	LinkedNode<T> * currentNode;
	int _size;
public:

        // Initialize!
        LinkedList(){
            baseNode = new LinkedNode<T>();
            currentNode = baseNode;
            _size = 0;
        }

        // Clean up!
        ~LinkedList(){
            LinkedNode<T>* current = baseNode;
            while(current != 0x0){
              LinkedNode<T>* cc = current;
              current = current->next;
              delete cc;
            }
        }

        // add item
        void add(T* cc){
            //adds a Void* Object. This can be declared when using the list.
            LinkedNode<T>* item = new LinkedNode<T>();
            item->data = cc;
            if(currentNode == 0x0){
                baseNode = currentNode = item;
            }else{
            currentNode->next = item;
            currentNode = item;
            }
            _size++;
        }

        // return item
        T* get(int index){
            LinkedNode<T> * current = baseNode;
            for(int i=0;i<index+1;i++){
                    current = current->next;
            }
            return current->data;
        }

        // return the size
        int size(){
            return _size;
        }

        LinkedNode<T>* top(){
            return baseNode;
        }

		// convert from linkedList to a static list.
        void freeze(){
            if(_size > 0){
                //cout << "freeze-1 " << _size << endl;
                const int len = _size;
                frozen = new T*[len];
                frozenlen = len;
                //cout << "freeze-2" << endl;

                // copy values in!
                LinkedNode<T> * current = baseNode->next;
                for(int i=0;i<_size;i++){
                    frozen[i] = current->data;
                    current = current->next;
                }
            }else{
                frozenlen = 0;
                frozen = 0x0;
            }
        }

        T **frozen;
        int frozenlen;
};

#endif
