#ifndef CPLSCRIPTER_H_
#define CPLSCRIPTER_H_

//#include "../Network/Client.h"
#include "../../Data/includes.h"
#include "../Instruction.h"
#include "../ProgrammingLanguage.h"

// This is the backend javascript-like scripter for the WebFramework.
//  This serves as a scripting language which can be used instead of directly using C++.

// As such, this scripter will perform much slower since it is an interpreter.


// The benefits of using this over C++ is that the majority of the library is included already.
// *.cpl files

// var globalvar;
// globalvar = "testvar";
// globalvar = 1;
// globalvar = 1.0230E100;

// function func1(arguments){
// 	func();
// }

// function main(){
//  func();
// }




class CPLScripter {
        // built-in memory
        HashMap<DynamicType> globalvars; // Global variables. Used everywhere in text, for this specific script.
        LinkedList<Instruction> instructions; // general list of compiled instructions.
        //HashMap<CPLVariable> localvars; // Local variables used in the current scope (clears data at end of scope)

        int line; // current line

    public:
        // raw script data, space allocated in RAM
        CPLScripter(CharString script, int spaceKb);

        //void processScript(Client* client, CharString scriptloc); // recursively process a specific script for a client

        void precompileAll(); // precompiles all of the scripts into *.cpo files.
};


#endif
