

#include "Stack.h"

using namespace std;

////////////////////////
//////// Stack! ////////
////////////////////////


// stack is based on LinkedLists to maximize efficiency. (Singly-linked list)

// init
Stack::Stack() {
}

Stack::~Stack() {
    // deflate the stack
    while(Head != 0x0) pop();
}

// withdraw from the top
int Stack::pop() {
    if(Head != 0x0) {
        ValueNode* node = Head;
        if(Head->Next != 0x0) { // next is not null
            Head = Head->Next; // re-assign Head
        }
        size--;
        int data = node->data;
        delete node;
        return data;
    } else {
        return 0x0;
    }
}

// pull from top, but do not withdrawl the top one.
int Stack::poll() {
    if(Head != 0x0) {
        return Head->data;
    } else {
        return 0x0;
    }
}

// push to the top
void Stack::push(int input) {
    ValueNode* node = new ValueNode();
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
