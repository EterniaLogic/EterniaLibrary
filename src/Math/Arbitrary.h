#ifndef ARBITRARY_H_
#define ARBITRARY_H_

#include <inttypes.h>
#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"

// Arbitrary number specification (AKA: Bignum)
// numbers that are so big that 64-bits are not enough to store them, so they must be distributed between multiple bytes of data.
// Arbitrarily large numbers also tend to be accurate at the cost of CPU time, compared to floats, which are fast at the cost of precision.
// an example of bignum usage is RSA key generation for above 64-bits.

// Displaimer:
//  - numbers below OS-bit are incredibly disadvantageous and will not be ANYWHERE as good as using normal types.



// Addition using standard binary carry of a linked list of values
// 



// https://en.wikipedia.org/wiki/Karatsuba_algorithm

class Arbitrary{
public:
    int bits; // estimated # of bits used
    LinkedList<uint64_t> data; // LSB in head. data for arbitrary operations, higher-bit CPUs have an advantage here.
    
    Arbitrary();
    virtual ~Arbitrary();
    
    Arbitrary operator +(Arbitrary value);
    Arbitrary operator =(Arbitrary value);
    
    // calculates # of bits used
    int bitcalc();
    
    CharString toString();
    static Arbitrary fromString(CharString v);
};


#endif
