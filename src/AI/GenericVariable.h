#ifndef GENERIC_VARIABLE_H_
#define GENERIC_VARIABLE_H_

#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"
#include "../Math/struct/vertex.h"
#include "GenericAI.h"
#include <malloc.h>


// A generic variable pretty much allows any specified type to be used here.

// The type cannot be changed. This system will consider it a constant after it is initialized.
//  this avoids errors and any confusion for the future.

// just detects if the ptr is at a normal location
// re-casts the pointer back to it's original type and frees it.
#define DISPOSE_OLD_PTR(val) \
        if(val != 0x0){                         \
            if(type==GVT_Number){                       \
                double* v1 = (double*)value; \
                free(v1);                   \
            }else if(type==GVT_Boolean){        \
                bool* v2 = (bool*)value;     \
                free(v2);                    \
            }                                   \
        }


// This is required for types that [[DO NOT]] return a pointer type on get method.
#define SETTER_NoPTR(typex, methodname, IsType) \
bool SetType(typex* val) {                          \
    if(IsType()){                                   \
        DISPOSE_OLD_PTR(value)                      \
        typex* valex = (typex*)malloc(sizeof(typex));  \
        valex = val;                               \
        value=val;                                  \
    }                                               \
                                                    \
    return IsType();                                \
}

// This is required for types that return a pointer on the get method.
#define SETTER_PTR(typex, methodname, IsType) \
bool methodname(typex* val) {    \
    if(IsType()){               \
        value=val;              \
    }                           \
                                \
    return IsType();            \
}

#define GETTER_NoPTR(typex, methodname) \
typex methodname() { \
    return *((typex*)value); \
}

#define GETTER_PTR(typex, methodname) \
typex* methodname() { \
    return ((typex*)value); \
}



// Memory cost:
//  32-bit processor = 8 bytes
//  64-bit processor = 12 bytes
enum GVType {GVT_Boolean=0, // only type used by FSM

GVT_Number=1,

// Very specific types for the Advanced Thinker and NoNoder
GVT_AI=2, GVT_Vertex=3, GVT_String=4, GVT_Numeric=5,
GVT_Image=6, GVT_Sound=7
};

class GenericVariable{
private:
    GVType type; // 32 bits = 4 bytes
    void* value; // 32/64 bits = 4/8 bytes
public:
    GenericVariable(GVType type,
                    void* value){
        this->type = type;  
        this->value = value;             
    }
    
    GenericVariable(){ // directed false
        this->type = GVT_Boolean;
        this->value = calloc(sizeof(bool),1); // set to false
    }
    
    // dispose of values that are ONLY initialized here.
    ~GenericVariable(){
        DISPOSE_OLD_PTR(value)
    }
    
    GVType getType() { return type; }

    void operator=(GenericVariable* v){
        *(this) = *v;
    }
    
    // These helper functions provide the following for each type:
    // isNumber()
    // double getNumber()
    // bool setNumber(double num)    // <-- returns false if the wrong function is used for the type


    // type verifications
    bool isNumber(){ return (type == GVT_Number); }
    bool isBool(){ return (type == GVT_Boolean); }
    bool isString(){ return (type == GVT_String); }
    bool isAI(){ return (type == GVT_AI); } // really only used with AdvancedThinker AI.
    bool isVertex(){ return (type == GVT_Vertex); }
    
    // Getters
    // "double getNumber()", ect.
    GETTER_NoPTR(double, getNumber); // double getNumber();
    GETTER_NoPTR(bool, getBool);
    GETTER_PTR(CharString, getString); // CharString* getStr();
    GETTER_PTR(GenericAI, getAI);
    GETTER_PTR(vertex, getVertex);
    
    // Setters (Returns false if wrong data type)
    SETTER_NoPTR(double, setNumber, isNumber) // bool setNumber(void* val);
    SETTER_NoPTR(bool, setBool, isBool)
    SETTER_PTR(CharString, setString, isString) // bool setString(void* val);
    SETTER_PTR(GenericAI, setAI, isAI)
    SETTER_PTR(vertex, setVertex, isVertex)
};


// sort of constant values
extern GenericVariable falseGV, trueGV;


#endif
