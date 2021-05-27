#include "ExSum.h"

#include <limits.h>
// EterniaLogic's attempt at a primitive hashing algorithm
// Mostly used for HashMaps.

// Partly the idea here is that it is not a standardized algorithm.
// Compared to md5, which has an exact number of steps that makes rainbow tables easy.

// 64-bit machines will have a different output than a 32-bit machine.

// Random hashing algorithm.
// Probably not optimized.

// initialization magic prime numbers
#define exa1 32416190071
#define exa2 15487249UL
#define exa3 6997UL
#define exa4 32416190071
// 512-bit value
#define exa64_1 0x0e4b8427716fc2b4
#define exa64_2 0x0aee7563982cceb4
#define exa64_3 0x0b2e4507b4448ed3
#define exa64_4 0x0dbf099e536a4633
//#define exa256_2 0x6e4b8427716fc2b4daee7563982cceb4fb2e4507b4448ed36dbf099e536a4633


// Constant shuffle bits
const int shufflelocs[64] = {32, 41, 42, 12, 14, 45, 48, 37, 13, 63, 5, 44, 20, 58, 18, 22, 2, 8, 33, 6, 60, 51, 16, 49, 57, 50, 46, 21, 43, 19, 61, 38, 11, 10, 24, 3, 52, 47, 28, 9, 27, 35, 26, 25, 54, 62, 36, 4, 40, 0, 1, 56, 7, 34, 30, 15, 17, 31, 53, 39, 29, 23, 59, 55};

template<class T>
int countBits(T maxVal) {
    // get the number of bits required for the maxVal
    int ret = 0;

    while(maxVal > 0) {
        maxVal = maxVal>>1;
        ret++;
    }

    return ret;
}

// reverse the # of bits
template<class T>
T reverseBits(T val) {
    T newv = 0;

    for(int i=0; i<(int)sizeof(T)*8; i++) {
        newv |= 2<<(sizeof(T)*8-1-i) & val;
    }

    return newv;
}

// generates a number where all bits up to the specified bits are 1
template<class T>
T genBitmask(int bits) {
    T newv = 1;

    for(int i=0; i<bits-1; i++) {
        newv |= 2<<i;
    }

    return newv;
}


// Add prive large numbers to help add entropy for the shuffle stage
template<class T>
T exHashPrime(char* str, int len, T maxVal) {
    // Bitwise AND/or prime numbers
    T sum = 0;
    int bits = countBits<T>(maxVal); // the # of bits is used here to help prevent collisions, full hash just uses 64 bits
    sum = 0;

    T bitmask = genBitmask<T>(bits); // generates a bitmask (i.e: 0xFFFF for 32-bit)

    //sum = (T)exa2;
    
    
    // pre-sum
    for(int i=0; i<len; i++) sum += str[i];
    
    srand(sum);

    // lots and lots of xor here.
    for(int i=0; i<len; i++) {
        unsigned char valx = str[i];
        
        
        //srand(rand());
        //sum += (sum^(valx^len))<<(i+1);
        //sum = reverseBits<T>(sum);
        //sum += (sum ^ len) & bitmask;

       // sum += 2<<(str[i]-1);

        // preleminary prime number xors
        /*sum ^= ((exa1&bitmask)^valx);
        sum ^= ((exa2&bitmask)^valx);
        sum ^= ((exa3&bitmask)^valx);
        sum ^= ((exa4&bitmask)^valx);*/
        
        sum ^= /*bitmask & */((T)rand() ^ valx);

        sum ^= (exa64_2&bitmask);


    }
    
//    sum ^= (T)exa2;

    /*for(int i=0;i<len;i++){
        unsigned char valx = str[i];

        // Follow the # of bits that are allowed to be occupied
        sum = sum^(valx&maxVal);
    }*/

    //sum = reverseBits(sum); // reverse bits to keep lower values non-colliding

    //cout << sum << endl;

    return sum;
}

// fully shuffle the bits based on # of bits
template<class T>
T exHashShuffleBits(T sum) {
    T newsum = 0;
    for(int i=0; i<sizeof(T); i++) {
        // sum AND 2^(v[i]-1)
        newsum |= (sum & (2<<(shufflelocs[i]-1)));
    }

    return newsum;
}


/*template<class T>
T randMinMaxValue(T maxVal, unsigned long maxrand){
    long double v = ((long double) rand() / (long double)maxrand);
    long double out = v*(long double)maxVal;
    return (T)(out);
}*/

template<class T>
T downsizeValue(T inval, T maxVal, unsigned long possiblemax){
    long double out = ((long double) inval) / (long double)possiblemax;
    out *= (long double)maxVal;
    //long long out = v*;
    return (T)(out);
}

// trim final result attempting to preserve some of the bits
template<class T>
T exHashTrim(T sum, T maxVal) {
    //sum = reverseBits<T>(sum);
    //T rval = randMinMaxValue(maxVal);

    //while(sum > maxVal) sum /= 3;
    //int bits = countBits<T>(maxVal); // the # of bits is used here to help prevent collisions, full hash just uses 64 bits
    //T bitmask = genBitmask<T>(bits);
    //sum ^= rval;
    //sum &= bitmask;
    //while(sum > maxVal) sum = (T)((double)sum/1.5);
    
    
    // Downsize randomize
    if(sum > maxVal){
        int bits = countBits<T>(maxVal);
        unsigned long possiblemax = pow(2,bits);
        
        T nsum = downsizeValue(sum, maxVal, possiblemax);
        
        //cout << sum << " " << bits << " " << possiblemax << "  = " << nsum << endl;
        sum = nsum;
    }

    return sum; // only pick certain bits?
}





// str to mix into a hash
// maxVal for HashMaps of N size
// steps help maximize entropy at the cost of CPU time
// Approximate cost: O(steps * maxval)
// Note: since unsigned longs are used here along with divs, this is not useful for Microcontrollers.
template<class T>
T exSumMap(CharString *str, T maxVal, int steps) {
    long seedval = maxVal+steps+str->getSize();
    char* strc = str->get();
    srand(seedval);
    //std::mt19937_64 gen(seedval); //Standard mersenne_twister_engine seeded with rd()
    //std::uniform_real_distribution<> distrib(0.0, ULONG_MAX);
    
    
    // redo, just use special characters with srand RNG (kinda bad implementation tbh)
    unsigned int ch,cx;
    for(int i=0; i<str->getSize(); i++){
        ch = (unsigned char)(strc[i]);
        
        //gen.discard(ch*(i+1));
        for(cx=0; cx<=(ch*((i+1))); cx++){ // every character runs rand() a set number of times;
            //sum ^= randMinMaxValue(maxVal);
            //gen.discard(ch);
            rand();
            //sum ^= (T)distrib(gen); // run rand number of times
        }
        //sum += ch;
        
    }

    // compress and truncate

    //sum = exHashTrim(sum, maxVal);
    
    //if(sum > maxVal) sum = 0; // just place oversizes at [0]
    return ((T)rand()) % maxVal;
}
