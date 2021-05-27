#ifndef FORTH_H_
#define FORTH_H_

#include "../../Data/includes.h"

// Forth is an early programming language that implements the stack.
//  51 years old language.


// Built-in words:
//  https://www.complang.tuwien.ac.at/forth/gforth/Docs-html/Word-Index.html

// 1 2 3 4 5 +   // put 1 2 3 4 5 into the stack


// Several words are 


class Forth{
private:
    HashMap<CharString> ForthWords;
    
    void initWords();
public:
    Forth();
    virtual ~Forth();
    
    Stack<double> memory;
    
    // Send a command to the Forth interpreter
    // output will goto a console for prints
    CharString command(CharString s);
    
    // Clear the stack, effectively resetting the memory
    void clearStack();
};

#endif
