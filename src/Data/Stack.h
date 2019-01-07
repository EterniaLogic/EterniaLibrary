#ifndef STACK_H_
#define STACK_H_

#include <iostream>

// Value node used for the Stack
class ValueNode {
public:
	int data;
	ValueNode* Next; // Node linker
};


// Primary Stack system
class Stack {
	ValueNode* Head;
public:
	Stack();
	virtual ~Stack();
	int pop(); // pull from front of list, removed it
	int poll(); // pull from front of list, do not remove
	void push(int value); // push to front of list

	int size;
};

#endif /*STACK_H_*/
