#ifndef CPLSCRIPTER_H_
#define CPLSCRIPTER_H_

#include "../Network/Client.h"


// This is the backend scripter for the WebFramework.
// 	This serves as a scripting language which can be used instead of directly using C++.

// As such, this scripter will perform much slower since it is an interpreter.


// The benefits of using this over C++ is that the majority of the library is included already.

enum CPLVarType {CPLInt, CPLString, CPLFloat}; // Variable types are automatically detected.

// *.cpl files

class CPLVariable;


class CPLScripter{
	// build-in memory
	HashMap<CPLVariable> globalvars; // Global variables. Used everywhere, for any client.
	//HashMap<CPLVariable> localvars; // Local variables used in the current scope
	
public:
	CPLScripter(CharString scriptloc); // denoting the script location
	
	void processScript(Client* client, CharString scriptloc); // recursively process a specific script for a client	
	
	void precompileAll(); // precompiles all of the scripts into *.cpo files.
};


// 
class CPLVariable{
	char* data; // direct data to be converted, length for conversion is based off of type
public:
	CPLVariable(CharString var); // initialize variable, auto-detect type
	void set(CharString var); // set this variable, auto-detect type
	
	float getF(); // get float
	int getI();   // get int
	long getL();  // get long
	char* getS(); // get string
	
	CPLVarType type;
};

#endif