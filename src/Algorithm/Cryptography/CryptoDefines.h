//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------
#ifndef CRYPTO_DEFINES_H_
#define CRYPTO_DEFINES_H_


// Crypto defines are used to prevent programs such as CheatEngine from
// modifying values in the working memory.

// NOTE: Do not use D_ variables for high-speed variables.
//              This class uses aes256, which can be slower than
//              a RAM variable because it has to be transcribed.

//
// C_INT, C_FLOAT, C_LONG, C_BOOL

#include "CryptoDefiner_Class.hpp"


#define D_CHAR(DVAR) CryptoDefiner<char>   DVAR(PCHAR_);
#define D_INT(DVAR) CryptoDefiner<int>     DVAR(PINT_);
#define D_FLOAT(DVAR) CryptoDefiner<float> DVAR(PFLOAT_);
#define D_LONG(DVAR) CryptoDefiner<long>   DVAR(PLONG_);
#define D_BOOL(DVAR) CryptoDefiner<bool>   DVAR(PBOOL_);

void testfunc() {
    D_INT( testVar );
    CryptoDefiner<int> testVar2(PINT_);

    testVar2 = 20;
}

#endif
