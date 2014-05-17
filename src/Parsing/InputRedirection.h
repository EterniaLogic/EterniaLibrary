//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef INPUTREDIRECTION_H_
#define INPUTREDIRECTION_H_

#include <iostream>
#include "LoadFile.h"
#include "../MiscLib/CharString.h"

using namespace std;

class InputRedirection
{
    bool process(); // process line by line
    bool stop;
    
public:
    InputRedirection();
    // OVERRIDE with your input
    // virtual void handleInputLine(CharString* input);
    virtual void handleInputLine(CharString* input);

    // InputRedirector redirects line of data to handleInputLine
    // common usage: InputRedirector(&cin);  Will do a while loop until program is forcibly stopped.
    void redirect(); 
};


#endif /*INPUTREDIRECTION_H_*/
