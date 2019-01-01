#ifndef ARB_INT_H_
#define ARB_INT_H_

#include <inttypes.h>
#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"


// static arbitrary integer number

// Big Endian
//  MSByte .... LSByte    LSByte = [MSB...LSB]


#define TYPET uint32_t
#define __TYPETBits sizeof(TYPET)*8
#define __TYPETBytes sizeof(TYPET)
#define __MAXSIZET 0xFFFFFFFFUL // (1<<(__TYPETBits+1))-1
#define __TYPETMASK 0xFFFFFFFFUL

// Multi-substitution
#define OP1(OP, TP) ArbitraryInteger operator OP(TP value);

#define OPC(_TP) ArbitraryInteger(_TP val);

#define OPALL(TP) \
OP1(+, TP); \
OP1(-, TP); \
OP1(*, TP); \
OP1(/, TP); \
OP1(=, TP); \
OP1(+=, TP); \
OP1(-=, TP); \
OP1(*=, TP); \
OP1(/=, TP); \



#define ARBInt Math::ArbitraryInteger // Fast Alias

namespace Math{
    class ArbitraryInteger{
    public:
        bool negative;
        LinkedList<TYPET> *data; // data signifying the number

        ArbitraryInteger();
//        OPC(char);
        OPC(int);
        OPC(unsigned int);
        OPC(long);
        
        
        ArbitraryInteger operator ++(int);
        
        CharString toString();
        
        int getBits(); // bits used total (discounting leading 0s)
        int toInt(); // returns the int value of the data (SLOW algorithm)
        long toLong(); // returns the long value of the data (SLOW algorithm)
        CharString getBinary();
        CharString getHex();
        
        void resize(int bytes); // resize to include # of bytes
        
        OPALL(char);
        OPALL(long);
        OPALL(long long); // supposedly 64-bit, but 32-bit in 32-bit systems
        OPALL(int);
        OPALL(unsigned int);
        OPALL(float); // strips the decimal
        OPALL(double); // strips the decimal, a number that is like 3.0e300 will have 301 digits.
        OPALL(ArbitraryInteger); // math with self type
        
        template<class T>
        void set(T value);
        
        virtual ~ArbitraryInteger();
    };
}

#endif
