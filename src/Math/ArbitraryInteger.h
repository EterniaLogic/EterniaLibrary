#ifndef ARB_INT_H_
#define ARB_INT_H_

#include <inttypes.h>
#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"


// static arbitrary integer number

// About 100-10k times slower operations than the standard 32 or 64-bit number, but it can become very large.

// Big Endian
//  MSByte .... LSByte    LSByte = [MSB...LSB]


#define TYPET uint32_t
#define __TYPETBits sizeof(TYPET)*8
#define __TYPETBytes sizeof(TYPET)
#define __MAXSIZET 0xFFFFFFFFUL // (1<<(__TYPETBits+1))-1
#define __TYPETMASK 0xFFFFFFFFUL

// Multi-substitution
#define OP1(OP, TP) ArbitraryInteger& operator OP(TP value);

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
OP1(/=, TP);

#define OPALLI(TP) \
OP1(+, TP); \
OP1(-, TP); \
OP1(*, TP); \
OP1(/, TP); \
OP1(=, TP); \
OP1(+=, TP); \
OP1(-=, TP); \
OP1(*=, TP); \
OP1(/=, TP); \
OP1(^, TP); /*  bitwise operations only available with ArbInt */ \
OP1(&, TP); \
OP1(|, TP); \
OP1(^=, TP); \
OP1(&=, TP); \
OP1(|=, TP);



#define ARBInt Math::ArbitraryInteger // Fast Alias
#define AInt Math::ArbitraryInteger // Fast Alias

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
        
        
        ArbitraryInteger operator ++(int); // O(20 N) to O(3741 N) for each operation (where C int value++ is O(N))
        
        CharString toString();
        
        int getBits(); // bits used total (discounting leading 0s)
        int toInt(); // returns the int value of the data (SLOW algorithm)
        long toLong(); // returns the long value of the data (SLOW algorithm)
        CharString getBinary(); // returns "00100....0"
        CharString getHex(); // returns "....00000000" -> "....FFFFFFFF"
        CharString getScientific(); // returns "1e30291" scientific mode used with REALLY long numbers
        CharString getNumberly(); // returns "1 Millinillion" (1e3003) outputs standardized names for really big numbers and some non-standardized ones for even larger
        void setNumberly(CharString numbername); // set("1 Vigintillion"); // >to set 1e63
        
        void resize(int bytes); // resize to include # of bytes
        
        OPALLI(char);
        OPALLI(long);
        OPALLI(long long); // supposedly 64-bit, but 32-bit in 32-bit systems
        OPALLI(int);
        OPALLI(unsigned int);
        OPALLI(ArbitraryInteger); // math with self type
        
        // converts doubles into integers
        OPALL(float); // strips the decimal
        OPALL(double); // strips the decimal, a number that is like 3.0e300 will have 301 digits.
        
        
        template<class T>
        void set(T value);
        
        virtual ~ArbitraryInteger();
    };
}

#endif
