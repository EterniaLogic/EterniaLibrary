#ifndef STACK_H_
#define STACK_H_

#include <iostream>

// Value node used for the Stack
template<class T>
class ValueNode {
public:
	T data;
	ValueNode<T>* Next; // Node linker
};


// Primary Stack system
template<class T>
class Stack {
	ValueNode<T>* Head;
public:
    int size;
    Stack() {
        Head = 0x0;
        size = 0;
    }
    
    ~Stack() {
        // deflate the stack
        while(Head != 0x0) pop();
    }

    // withdraw from the top
    T pop() {
        if(Head != 0x0) {
            ValueNode<T>* node = Head;
            if(Head->Next != 0x0) { // next is not null
                Head = Head->Next; // re-assign Head
            }
            size--;
            T data = node->data;
            delete node;
            return data;
        } else {
            return T();
        }
    }

    // pull from top, but do not withdrawl the top one.
    T poll() {
        if(Head != 0x0) {
            return Head->data;
        } else {
            return T();
        }
    }

    // push to the top
    void push(T input) {
        ValueNode<T>* node = new ValueNode<T>();
        node->data=input;
        //cout << "Push " << input << endl;
        if(Head == 0x0) {
            Head = node;
        } else {
            node->Next = Head;
            Head = node;
        }
        size++;
    }
    
    void clear(){
        Head = 0x0;
        size=0;
    }

	
};

#endif /*STACK_H_*/
