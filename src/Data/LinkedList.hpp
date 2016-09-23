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
    int id;
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
	bool changed; // used with freezing to help keep better performance
public:
        T **frozen;
        int frozenlen;


        // Initialize!
        LinkedList(){
            baseNode = new LinkedNode<T>();
            currentNode = baseNode;
            _size = 0;
            changed=true;
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
            changed=true;
        }

        // return item
        T* get(int index){
            freeze();
            return frozen[index];
        }

        // return the size
        int size(){
            return _size;
        }

        LinkedNode<T>* top(){
            return baseNode;
        }

        T* remove(long index){
            T* r = 0x0;
            if(index< _size){
                // erase element at i
                LinkedNode<T>* current = baseNode;
                for(long i=0;i<index;i++){
                    if(current != 0x0){
                        if (i == index){
                            if(current->next != 0x0) current->next->prev = 0x0;
                            if(current->prev != 0x0) current->prev->next = 0x0;
                            r = current->data;
                            break;
                        }
                    }else{
                        break;
                    }
                }
            }
            changed=true;
            return r;
        }

        // Clears up the list
        void clear(){
            while(remove(0L) != 0x0);
            changed=true;
        }

        // Returns the type-size of the data
        int typeSize(){
            return sizeof(T);
        }

		// convert from linkedList to a static list.
        void freeze(){
            if(_size > 0 && changed){
                //cout << "freeze-1 " << _size << endl;
                const int len = _size;
                frozen = new T*[len];
                frozenlen = len;
                //cout << "freeze-2" << endl;

                // copy values in!
                if(baseNode != 0x0){
                    LinkedNode<T> * current = baseNode->next;
                    for(int i=0;i<_size;i++){
                        if(current != 0x0){
                            frozen[i] = current->data;
                            current = current->next;
                        } else{
                            frozenlen = i;
                            break;
                        }
                    }
                }
                changed=false;
            }else{
                frozenlen = 0;
                frozen = 0x0;
            }
        }


        // unfreeze will determine if there are any new addresses added
        // First, clears the list, then goes through a brand new list
        void unfreeze(void* list, int bytes){
            clear();
            _size = bytes/sizeof(T);
            T* thislist = (T*)list;

            for(int i=0;i<_size;i++){
                add(&thislist[i]);
            }

            changed=true;
        }
};

#endif
