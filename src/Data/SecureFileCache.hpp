#ifndef SECFCACHE_H_
#define SECFCACHE_H_

// TODO: NOT IMPLEMENTED

// idea:
//  AES256, other algorithms used for blocks
//  In-between scrambles for low-security high-speed scrambles

#include "CharString.h"
#include "../Algorithm/Cryptography/Aes256.h"
#include "../Math/Random.hpp"

// Implicit cryptography and scrambler
// CSEC_AES256 - use Aes256 for the primary cypher.
// EXSEC_SCRIB - Scribble up the bits throughout the file and blocks during read/writes based on a given seed.
// EXSEC_PASSWD - Simble Scramble data based on password as seed+random
enum CRYPT_SECURITY {CSEC_none, CSEC_AES256};
enum EX_SEC {EXSEC_none=0, EXSEC_SCRIB=1, EXSEC_PASSWD=2};

template <class T>
class SourceFileCache {
private:
    CRYPT_SECURITY crypttype;
    CRYPT_SECURITY floc;
    int esecbit; // EX_SEC bits.
    long blocksize;
    CharString passwd;
public:
    // SourceFileCache(CSEC_AES256, EXSEC_SCRIB|EXSEC_PASSWD, "testfile.dat", 1024);
    SourceFileCache(CRYPT_SECURITY crypttype, EX_SEC esecbit, CharString floc, long blocksize){
        this->crypttype = crypttype;
        this->esecbit = esecbit;
        this->floc = floc;
        this->blocksize = blocksize;
    }
};

#endif
