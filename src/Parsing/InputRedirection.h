#ifndef INPUTREDIRECTION_H_
#define INPUTREDIRECTION_H_

#include <iostream>
#include "LoadFile.h"
#include "../Data/CharString.h"



class InputRedirection {
        bool process(); // process line by line
        bool stop;

    public:
        InputRedirection();
        virtual ~InputRedirection();
        // OVERRIDE with your input
        // virtual void handleInputLine(CharString* input);
        virtual void handleInputLine(CharString* input);

        // InputRedirector redirects line of data to handleInputLine
        // common usage: InputRedirector(&cin);  Will do a while loop until program is forcibly stopped.
        void redirect();
};


#endif /*INPUTREDIRECTION_H_*/
