#ifndef DYNATYPE_H__
#define DYNATYPE_H__

#include <stdlib.h>

// Transform operation to re-size data when doing math operations
// e.g: when (int)10 + (float)10.5f => 20.5f
//  value becomes a float.
#define TRANSFORMOP(typex, typet) \
    if(type != typet){\
        typex tmp = *(typex*)data; \
        data = malloc(sizeof(typex));\
        *data = tmp; \
    }

// define basic operation!
#define OPERATION(typex, typet, op, opx) DynamicType operator opx(typex v){ \
    if(type == DT_INT || type==DT_UINT || type==DT_CHAR || type==DT_UCHAR || type == DT_SHORT || type==DT_USHORT || type==DT_LONG || type==DT_ULONG || type==DT_FLOAT || type==DT_DOUBLE){ \
        TRANSFORMOP(typex,typet) \
        (typex)*data = *((typex*)data) op v; \
    } \
    return *this; \
}

#define TOPS(type, typet) \
OPERATION(type,typet,+,+) \
OPERATION(type,typet,-,-) \
OPERATION(type,typet,*,*) \
OPERATION(type,typet,/,/) \
OPERATION(type,typet,%,%) \
OPERATION(type,typet,+=,+=) \
OPERATION(type,typet,-=,-=) \
OPERATION(type,typet,*=,*=) \
OPERATION(type,typet,/=,/=) \
OPERATION(type,typet,|=,|=) \
OPERATION(type,typet,^=,^=) \
OPERATION(type,typet,==,==) \
OPERATION(type,typet,>=,>=) \
OPERATION(type,typet,<=,<=) \
OPERATION(type,typet,<,<) \
OPERATION(type,typet,>,>)


#define EQOPER(typex, inferred) \
EQOPER(typex v){ \
    if(data == 0x0) free(data); \
    data = malloc(sizeof(v)); \
    *data = v; \
    tsize = sizeof(v); \
    type = typex; \
}


// Dynamic types are types that accept strings, classes, integers, longs, ect.
// ex:
//  DynamicType a = "test!";
//  a = 10L;
//  a += 100.0f; // converts to float
//  a = new CharString("blah!");
//  a = new RandomClassThingy();
//  a.doThingy();

// inferred internal type
enum DTType {DT_NONE, DT_INT, DT_UINT, DT_LONG, DT_ULONG, DT_SHORT, DT_USHORT, DT_CHAR, CT_UCHAR, DT_FLOAT, DT_DOUBLE, DT_STRING, DT_CLASS};

class DynamicType{
private:
    void* data;
    int tsize; // type size
    DTType _type;
public:
    DynamicType();
    
    void* get(); // get raw value (must be casted)
    int getSize(); // get type size
    DTType getType(); // get inferred type
    
    // accept pointers to objects, such as classes
    DynamicType operator =(void*);
    
    
    // operator=
/*    EQOPER(unsigned char, DT_UCHAR);
    EQOPER(char, DT_CHAR);
    EQOPER(unsigned int, DT_UINT);
    EQOPER(int, DT_INT);
    EQOPER(unsigned long, DT_ULONG);
    EQOPER(long, DT_LONG);
    EQOPER(float, DT_FLOAT);
    EQOPER(double, DT_DOUBLE);
    EQOPER(string, DT_STRING);
    
    // define all math operations for numerical types
    // don't use these if you are using strings or arbitrary classes.
    TOPS(unsigned char, DT_UCHAR);
    TOPS(char, DT_CHAR);
    TOPS(unsigned short, DT_USHORT);
    TOPS(short, DT_SHORT);
    TOPS(unsigned int, DT_UINT);
    TOPS(int, DT_INT);
    TOPS(unsigned long, DT_ULONG);
    TOPS(long, DT_LONG);
    TOPS(float, DT_FLOAT);
    TOPS(double, DT_DOUBLE);*/
};

#endif
