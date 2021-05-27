#ifndef ExHash2_h_
#define ExHash2_h_

#include "../../Data/CharString.h"
#include "../../Data/LinkedList.hpp"
#include <random>
#include <iomanip>
#include <sstream>
#include <limits.h>   // for CHAR_BIT
//#include <bits/stdc++.h>

#define uint64 unsigned long long

namespace ExHash{
    // 64-bit to 1024-bit precalculated prime compression seeds
    const uint64 hconst[16] = {0x6cc10938f549e3b6, //64-bit
    0xeba2021d87ed0997, //128
    0xa5f0356e5f3e8782, 0x332bbbd90278755f, // 256
    0xb9fa3eefca183b0, 0x643f43fb630e392d, 0xfd4dc6ca13f285db, 0x40e34298620e5219, // 512
    0xbafd965bef2c6ca1, 0x59f6db96a6e75f71, 0x8a064150de72bee2, 0xed3b8a477ee8c0c, 
    0x5f8bc1b4d53889b5, 0x85f1f61e0199930a, 0xcf4f78305663e080, 0x35ecb852ccfbf7de // 1024
    }; 
}


// algorithm for generating a hash
// str: input string
// salt: pre-hash salt (like a password)
// length: number of bits for the output, multiple of 64 (up to 1024)
CharString exHash64(CharString str, CharString salt, int blockbits);

// various bit sizes
CharString exHash256(CharString str, CharString salt);
CharString exHash512(CharString str, CharString salt);
CharString exHash1024(CharString str, CharString salt);

// used for pre-calculated constants
void exHash2ComputeConstants();

#endif
