/*
*   Byte-oriented AES-256 implementation.
*   All lookup tables replaced with 'on the fly' calculations.
*
*   Copyright (c) 2007-2009 Ilya O. Levin, http://www.literatecode.com
*   Other contributors: Hal Finney
*
*   Permission to use, copy, modify, and distribute this software for any
*   purpose with or without fee is hereby granted, provided that the above
*   copyright notice and this permission notice appear in all copies.
*
*   THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*   WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*   MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*   ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*   WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*   ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*   OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#ifndef AES256_h_
#define AES256_h_


#include <inttypes.h>
#include <math.h>
#include <time.h>

#include "Aes256r.h"


#include "../../Data/CharString.h"

// C++ converter
class AES256{
private:
    aes256_context ctx;
    uint8_t key[16];
public:
    AES256(CharString key);
    AES256(uint8_t keyv[16]);
    AES256(); // auto-generates key
    virtual ~AES256();

    CharString genKey(); // auto-generate 256-bit key
    uint8_t* getKey(); // get a 256-bit key

    CharString encrypt(CharString plaintext);
    CharString decrypt(CharString encrypttext);

    // native algorithm types
    uint8_t* encrypt(uint8_t plaintext[16]);
    uint8_t* decrypt(uint8_t encrypttext[16]);
};

#endif
