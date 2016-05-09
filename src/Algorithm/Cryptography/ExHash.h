#ifndef ExHash_h_
#define ExHash_h_

#include "../../MiscLib/CharString.h"
#include "../../Data/SpecialTypes.hpp"

// algorithm block solely for HashMaps
unsigned long exSumMap(CharString *str, unsigned long maxVal, int steps);

// algorithm for generating a hash
// str: input string
// salt: pre-hash salt
// length: number of bits for the output (each set of 8 bits is a character on the output)
// --> (e.g.:) If you want a hash with a length of 40, you need 157-160 bits
CharString* exHash(CharString *str, CharString* salt, int bits);

// Simplifier for the above function, produces the extact # of bits per character.
// --> outchar = 40, you will get exactly 160 bits on the output
CharString* exHashChars(CharString *str, CharString* salt, int outchars);

#endif
