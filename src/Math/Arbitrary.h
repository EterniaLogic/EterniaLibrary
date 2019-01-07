#ifndef ARBITRARY_H_
#define ARBITRARY_H_

#include <inttypes.h>
#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"


#include "ArbitraryInteger.h"


// Arbitrary number specification (AKA: Bignum)
// numbers that are so big that 64-bits are not enough to store them, so they must be distributed between multiple bytes of data.
// Arbitrarily large numbers also tend to be accurate at the cost of CPU time, compared to floats, which are fast at the cost of precision.
// an example of bignum usage is RSA key generation for above 64-bits.

// Displaimer:
//  - numbers below OS-bit are incredibly disadvantageous and will not be ANYWHERE as good as using normal types.
//      However, this will allow for systems that have small-bits, like 8-bits to have many usable bits.
//      This will substitute memory for large numbers



// Multi-substitution
#define OP1(OP, TP) Arbitrary operator OP(TP value);

#define OPC(_TP) Arbitrary(_TP val);

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


// FastMultiplication Algorithm:    https://en.wikipedia.org/wiki/Karatsuba_algorithm

#define ARB Math::Arbitrary // Fast Alias
#define Number Math::Arbitrary // Fast Alias

namespace Math {
    class Arbitrary{
    public:
        bool negative; // assume positive
        LinkedList<uint8_t> mantissa; // treat like a segment of memory instead of a list
        LinkedList<uint8_t> exponent;
        
        Arbitrary();
        virtual ~Arbitrary();
        void clear();
        
        // All operations for +-*/=
        OPALL(char);
        OPALL(long);
        OPALL(long long); // supposedly 64-bit, but 32-bit in 32-bit systems
        OPALL(int);
        OPALL(float);
        OPALL(double);
        
        Arbitrary operator +(Arbitrary value);
        Arbitrary operator =(Arbitrary value);
        Arbitrary operator +=(Arbitrary value);
        
        // calculates # of bits used
        int bitcalc();
        
        ArbitraryInteger getInt(); // strips the decimal point
        
        CharString toString();
        static Arbitrary fromString(CharString v);
    };
}

#endif
