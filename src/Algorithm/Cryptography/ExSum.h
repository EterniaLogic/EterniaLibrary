#ifndef ExHash_h_
#define ExHash_h_

#include "../../Data/CharString.h"
#include <random>

// failed numerity tests << ExHash 2 is second attempt


// algorithm block solely for HashMaps
//unsigned long exSumMap(CharString *str, unsigned long maxVal, int steps);

template<class T>
T exSumMap(CharString *str, T maxVal, int steps);

#endif
