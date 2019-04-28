#ifndef DYNATYPE_H__
#define DYNATYPE_H__

#include <stdlib.h>
#include "CharString.h"

// Dynamic type, mostly used when scripting or using pseudo-language operations
// Includes the ability to have a single type variable

// Transform operation to re-size data when doing math operations
// e.g: when (int)10 + (float)10.5f => 20.5f
//  value becomes a float.
#define TRANSFORMOP(typex, typet) \
    /*if(_type != typet){*/\
        typex tmp = *(typex*)data; \
        data = malloc(sizeof(typex));\
        *((typex*)data) = tmp; \
    //}

// define basic operation!
#define OPERATION(typex, typet, op, opx) DynamicType operator opx(typex v){ \
    if(isNumber()){ \
        TRANSFORMOP(typex,typet) \
        DynamicType d; \
        d = (typex)(tmp op v); \
        return d; \
    } \
    return *this; \
}

#define OPERATION_EQ(typex, typet, op, opx) DynamicType operator opx(typex v){ \
    if(isNumber()){ \
        TRANSFORMOP(typex,typet) \
        *((typex*)data) = tmp op v; \
    } \
    return *this; \
}

#define GETOP(typex, t) typex get##t(){ \
    return *((typex*)data);\
}

#define OPERATION_DT(t,t1,opx,t3) DynamicType operator opx(DynamicType v){ \
    DynamicType ret; \
    ret = 0.0; \
    if(this->isNumber()){           \
        ret += getDouble();         \
    }                               \
                                    \
    if(v.isNumber()){               \
        ret += v.getDouble();       \
    }                               \
                                    \
    return ret;                     \
}

#define TOPS(OPmacro, type, typet) \
OPmacro(type,typet,+,+) \
OPmacro(type,typet,-,-) \
OPmacro(type,typet,*,*) \
OPmacro(type,typet,/,/) \
//OPmacro(type,typet,%,%) \
//OPmacro(type,typet,<,<) \
//OPmacro(type,typet,>,>)

#define TOPS_EQ_BIN(type, typet) \
OPERATION_EQ(type,typet,|=,|=) \
OPERATION_EQ(type,typet,^=,^=) \
OPERATION_EQ(type,typet,&=,&=) \

#define TOPS_EQ(type, typet)\
OPERATION_EQ(type,typet,+=,+=) \
OPERATION_EQ(type,typet,-=,-=) \
OPERATION_EQ(type,typet,*=,*=) \
OPERATION_EQ(type,typet,/=,/=) \
//OPERATION_EQ(type,typet,==,==) \
OPERATION_EQ(type,typet,>=,>=) \
OPERATION_EQ(type,typet,<=,<=)

#define CONSTRUCTORTYPE(typex, typet) \
    DynamicType(typex val){\
        data = malloc(sizeof(typex));\
        *((typex*)data) = val;\
        _type = typet;\
        tsize=0;\
    }

#define EQOPER(typex, inferred, setnamex) \
DynamicType operator=(typex v){ \
    return set##setnamex(v); \
} \
DynamicType set##setnamex(typex v){\
    if(data == 0x0) free(data); \
    data = malloc(sizeof(v)); \
    *((typex*)data) = v; \
    tsize = sizeof(v); \
    _type = inferred; \
    return *this;\
}


// Dynamic types are types that accept strings, classes, integers, longs, ect.
// ex:
//  DynamicType a = "test!";
//  a = 10L;
//  a += 100.0f; // converts to float
//  a = CharString("blah!");
//  a = new RandomClassThingy();
//  ((RandomClassThingy*)a.get())->doThingy();

// inferred internal type
enum DTType {DT_NONE, DT_CHAR, DT_UCHAR, DT_SHORT, DT_USHORT, DT_INT, DT_UINT, DT_LONG, DT_ULONG,  DT_FLOAT, DT_DOUBLE, 
    DT_STRING, DT_CLASS, DT_LIST};

class DynamicType{
private:
    void* data;
    int tsize; // type size
    DTType _type;
    CharString classname; // used for error reporting when using a special class type
public:
    DynamicType();
    CONSTRUCTORTYPE(unsigned char, DT_UCHAR);
    CONSTRUCTORTYPE(char, DT_CHAR);
    CONSTRUCTORTYPE(unsigned int, DT_UINT);
    CONSTRUCTORTYPE(int, DT_INT);
    CONSTRUCTORTYPE(unsigned long, DT_ULONG);
    CONSTRUCTORTYPE(long, DT_LONG);
    CONSTRUCTORTYPE(float, DT_FLOAT);
    CONSTRUCTORTYPE(double, DT_DOUBLE);
    CONSTRUCTORTYPE(CharString, DT_STRING);
    
    void setZero(); // set value as (double)0
    
    void* get(); // get raw value (must be casted)
    int getSize(); // get type size
    DTType getType(); // get inferred type
    bool isNumber(); // is a numerical type? (short, integer, long, char or float, double)
    bool isString(); // is a DT_CHAR or a DT_STRING
    bool isClass(); // is a DT_CLASS?
    
    // accept pointers to objects, such as classes
    DynamicType operator =(void*);
    
    // Get operations getInt, getChar, etc.
    GETOP(unsigned char, UChar)
    GETOP(char, Char)
    GETOP(unsigned int, UInt)
    GETOP(int, Int) // int getInt()
    GETOP(unsigned long, ULong)
    GETOP(float, Float)
    GETOP(double, Double)
    GETOP(CharString, String)
    //GETOP(LinkedList, List) // getList()
    
    
    // operator=, setChar
    EQOPER(unsigned char, DT_UCHAR, UChar);
    EQOPER(char, DT_CHAR, Char);
    EQOPER(unsigned int, DT_UINT, UInt);
    EQOPER(int, DT_INT, Int);
    EQOPER(unsigned long, DT_ULONG, ULong);
    EQOPER(long, DT_LONG, Long);
    EQOPER(float, DT_FLOAT, Float);
    EQOPER(double, DT_DOUBLE, Double);
    EQOPER(CharString, DT_STRING, String);
    
    
    
    TOPS(OPERATION_DT, DynamicType, 0)
    // define all math operations for numerical types
    // don't use these if you are using strings or arbitrary classes.
    TOPS(OPERATION, unsigned char, DT_UCHAR);
    TOPS(OPERATION, char, DT_CHAR);
    TOPS(OPERATION, unsigned short, DT_USHORT);
    TOPS(OPERATION, short, DT_SHORT);
    TOPS(OPERATION, unsigned int, DT_UINT);
    TOPS(OPERATION, int, DT_INT);
    TOPS(OPERATION, unsigned long, DT_ULONG);
    TOPS(OPERATION, long, DT_LONG);
    TOPS(OPERATION, float, DT_FLOAT);
    TOPS(OPERATION, double, DT_DOUBLE);
    
    // Xor, AND, OR,   |= ^= &=
    TOPS_EQ_BIN(unsigned char, DT_UCHAR);
    TOPS_EQ_BIN(char, DT_CHAR);
    TOPS_EQ_BIN(unsigned short, DT_USHORT);
    TOPS_EQ_BIN(short, DT_SHORT);
    TOPS_EQ_BIN(unsigned int, DT_UINT);
    TOPS_EQ_BIN(int, DT_INT);
    TOPS_EQ_BIN(unsigned long, DT_ULONG);
    TOPS_EQ_BIN(long, DT_LONG);
    
    // +=
    TOPS_EQ(unsigned char, DT_UCHAR);
    TOPS_EQ(char, DT_CHAR);
    TOPS_EQ(unsigned short, DT_USHORT);
    TOPS_EQ(short, DT_SHORT);
    TOPS_EQ(unsigned int, DT_UINT);
    TOPS_EQ(int, DT_INT);
    TOPS_EQ(unsigned long, DT_ULONG);
    TOPS_EQ(long, DT_LONG);
    TOPS_EQ(float, DT_FLOAT);
    TOPS_EQ(double, DT_DOUBLE);
};

#endif
