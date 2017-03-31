#ifndef CPLVAR_H_
#define CPLVAR_H_

enum CPLVarType {CPLInt, CPLString, CPLFloat}; // Variable types are automatically detected.


class CPLVariable {
        char* data; // direct data to be converted, length for conversion is based off of type
        CPLVarType type;
    public:
        CPLVariable(CharString var); // initialize variable, auto-detect type
        void set(CharString var); // set this variable, auto-detect type

        float getF(); // get float
        int getI();   // get int
        long getL();  // get long
        char* getS(); // get string
        CPLVarType getType(); // get data type
};

#endif
