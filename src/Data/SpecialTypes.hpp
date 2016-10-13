#ifndef specialtypes_h_
#define specialtypes_h_

#include <inttypes.h>

// Check windows
#if _WIN32 || _WIN64
#if _WIN64
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// Check GCC
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ENVIRONMENT64
#else
#define ENVIRONMENT32
#endif
#endif

// O(32) for each operation
class UInt512 {
    public:
        uint64_t val[16]; // 512 bits

        // automatically generated
        UInt512() {
            for(int i=0; i<16; i++) {
                val[i]=0;
            }
        }

        // set the N bits 64-bits at a time
        // offset is the bit offset
        void set(unsigned int v, unsigned char offset) {
            if(offset > 15 || offset < 0) return;
            val[offset] = v;
        }

        void operator =(int v) {
            for(int i=0; i<16; i++) {
                val[i]=0;
            }

            val[0] = v;
        }

        UInt512 operator +(UInt512 v) {
            // do add operations
            // each iteration must check for the carry bit >>31

            for(int i=0; i<16; i++) {

            }
        }

        UInt512 operator +(long v) {
            // do add operations
            int sizet = sizeof(long);
        }

        UInt512 operator +(uint64_t v) {
            // do add operations
        }

        UInt512 operator ^(UInt512 v) {
            // simple xor operation, just loop through both
            UInt512 output;
            for(int i=0; i<16; i++) {
                output.set(val[i]^v.val[i],i);
            }

            return output;
        }

        UInt512 operator ^(uint64_t v) {
            // simple xor operation, just loop through both
            UInt512 output;

            output.set(val[0]^v,0);
            for(int i=1; i<16; i++) {
                output.set(val[i],i);
            }

            return output;
        }

        UInt512 operator |(uint64_t v) {
            // simple xor operation, just loop through both
            UInt512 output;

            output.set(val[0]|v,0);
            for(int i=1; i<16; i++) {
                output.set(val[i],i);
            }

            return output;
        }

        void operator ^=(UInt512 v) {
            // simple xor operation, just loop through both
            for(int i=0; i<16; i++) {
                val[i] ^= v.val[i],i;
            }
        }

        void operator +=(UInt512 v) {
            // add, 1 time, check to make sure that the carry bits do not overflow
        }

        UInt512 operator <<(int v) {
            //
            UInt512 output;

            for(int i=0; i<16; i++) {
                output.set(val[i],i);
            }

            return output;
        }
};

#endif
