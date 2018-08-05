#ifndef PTYPE_H_
#define PTYPE_H_

#include "../LinkedList.hpp"
#include "../../Math/Functions/Basic.h"


#include <malloc.h>
#include <random>
#include <stdlib.h>
#include <typeinfo>
#include <float.h>


// Protect Types helps prevent memory modification.
// The goal behind these types is to protect without significant performance loss.
// This system uses a generic CRC-like comparison with runtime keygen.
// Approximate time: O(3*k) k is the speed of the type operations
// This system may also allow a class to be protected with easy CRC detection.
// Serialization is also enabled for this type.
// Heavy Macro use to help make large changes and lower stack use cost.

/// Common Usage:
/*      PType<int> money = 10;
        money.onHacked = hackettestfunc;

/// Hacker changes value through scanmem or CheatEngine ***
        
        if(money.isViolated)
            cout << "hacker voilated value!" << endl;

        
 */



#define _DBG(msg) // no output
//#define _DBG(msg) cout << msg << endl; cout.flush()

// Casting to integer
#define _COMPT(type) (sizeof(T) == sizeof(type))
#define _TCAST(x) ((T*) &x)

// Cast the value based on size:
#define _ICAST(x) (_COMPT(int) ? \
                        (*((int*)x)) : \
                            _COMPT(long long) ? \
                                (*((long long*)x)) : \
                                    _COMPT(short) ? \
                                        (*((short*)x)) : \
                                            _COMPT(char) ? \
                                                (*((char*)x)) \
                                                    : 0)
#define _TtoI(x) _ICAST(_TCAST(x))


// Casting from integer back to type T

// xor that works on any numerical type
// converts type to integer, gets xor then puts it back together to type

#define _XOR(a, b) (_TtoI(a) ^ _TtoI(b))
//#define _XORp(a, b) (_TtoI(a) ^ _ICAST(b))
#define _XORp(a, b) (_TtoI(a) ^ _ICAST(b))

// returns int...
#define _getV() _XORp(value, vec1)

// store the value, store in temporary buffer x
#define _storeV(x)  \
    tmp = x; \
    this->honeypot = tmp; \
    long long xortmp = _XORp(tmp, vec1); \
    this->value = * _TCAST(xortmp); \
    xortmp = _XORp(value, vec2); \
    this->tvalue = * _TCAST(xortmp); \
    this->printValues(); \
    this->changed = true;



//// ptype + T => ptype
#define OP_PTP_DO(op) PType<T> operator op(T v){ \
    PType<T> a; \
    a = _getV() op v; \
    return a; \
}

//// ptype + ptype => ptype
#define OP_PPP_DO(op) PType<T> operator op(PType<T> v){ \
    PType<T> a; \
    a = _getV() op v.get(); \
    return a; \
}

//// ptype += T => ptype
#define OP_PTP_DO_EQ(op,opeq) PType<T> operator opeq(T v){ \
    T tmp = get() op v; \
    _storeV(tmp); \
    return *this; \
}

//// ptype += ptype => ptype
#define OP_PPP_DO_EQ(op,opeq) PType<T> operator opeq(PType<T> v){ \
    T tmp = get() op v.get(); \
    _storeV(tmp); \
    return *this; \
}


// ptype < ptype
#define OP_COMP_DO(op) bool operator op(PType<T> v){ \
    return (get() op v.get()); \
}

// ptype < T
#define OP_COMPT_DO(op) bool operator op(T v){ \
    return (get() op v); \
}


//// Output ALL variations
#define OP_ALL(op) OP_PTP_DO(op) \
    OP_PPP_DO(op)

#define OP_EQ(op,opeq) OP_PPP_DO_EQ(op,opeq) \
    OP_PTP_DO_EQ(op,opeq)

//// Output ALL variations AND Equals variations
#define OP_ALL_EQ(op,opeq) OP_ALL(op) \
    OP_EQ(op,opeq)

#define OP_ALL_COMP(op) OP_COMP_DO(op) \
    OP_COMPT_DO(op)



/*#define STR_HELPER(x) #x
#define STR(v) STR_HELPER(v)
#pragma message STR(OP_PTP_DO_EQ(+))*/

template<class T>
class PType {
private:
    char bytesize;
    //type_info tinfo;
    long long *vec1, *vec2;
    T value; // Base value
    T tvalue; // vector to determine memory hacking
    T honeypot; // actual value, just resets every change
    // vectors declared on making this pint

    bool changed;

    


/////////////// INTERNALS ///////////////

    void printValues(){
        char* valid = "VALID";
        if(isViolated()) valid = "INVALID";
        //cout << "PTYPE: [" << get() << ", "<< honeypot <<"] (VEC: "<< *vec1 << ", "<< *vec2 << ") (VAL: " << value << ", "<< tvalue << ") " << valid << endl; cout.flush();
    }


public:
    void init(){
        // add to static list
        bytesize = sizeof(T);
        //tinfo = typeid(T);
        std::random_device rd;     // only used once to initialise (seed) engine
        std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)

        // Calculate type sizes, should help with any system size 32/64, ect.
        long long max;
        long long min;

        max = Math::pow(2, sizeof(T)*8-1);
        min = -max;

        //std::uniform_int_distribution<long> uni(min, max); // guaranteed unbiased
        std::normal_distribution<> uni(0, max/4);

        vec1 = (long long*)malloc(sizeof(long long));
        vec2 = (long long*)malloc(sizeof(long long));
        *vec1 = uni(rng);
        *vec2 = uni(rng);

        T vx= (T)0; // should be 0
        T tmp;
        _storeV(vx);

        // values->add((int*)this);
    }
    
    
    
    // Event handler, queue up for serialization, ect.
    void (*onChanged)(T* value);
    void (*onHacked)(T* value); // Hacked value detection
    

    PType(){
        init();
    }


    ~PType(){
        // remove from static list, cleanup malloc values
        //free(vec1);
        //free(vec2);
        //values.remove(this);
    }

    // Returns the number of bytes taken up by the type
    int getByteSize(){
        return bytesize;
    }

    // determine if the value has been changed.
    bool isViolated(){
        // result should become VEC2, if not memory violated.
        long val = _XOR(value, tvalue);
        bool honeypotchanged = (get() != honeypot);
        return (val != (*vec2)) || honeypotchanged;
    }

    static void detectAllViolations(){
        // loop through all ptypes
    }

    // This is used for testing purposes
    void testViolate(){
        value = 10;
    }

/////////////// BASIC OPERATIONS ///////////////
    // set this
    PType<T> operator =(T v){
        T tmp;
        _storeV(v); // store value
        return *this;
    }

    PType<T> operator =(PType<T> v){
        T tmp;
        _storeV(v.get()); // store value
        return *this;
    }

    bool getBool(){
        if(typeid(T) != typeid(bool)) return false;
        return get();
    }



    // get direct
    T get() {
        long val = _getV();
        changed=false;
        return *(_TCAST(val));
    }

    void* getPtr(){
        T* val = (T*)malloc(sizeof(T));
        *val=get();
        changed=false;
        return val;
    }
    
    // used for global value
    bool isChanged(){
        return changed;
    }

/////////////// MATH OPERATIONS ///////////////

    // These are MACROs.
    // They should suffice for most numerical types.

    // base operators
    OP_ALL_EQ(+,+=)
    OP_ALL_EQ(-,-=)
    OP_ALL_EQ(*,*=)
    OP_ALL_EQ(/,/=)

    // Comparison functions
    OP_ALL_COMP(<)
    OP_ALL_COMP(>)
    OP_ALL_COMP(<=)
    OP_ALL_COMP(>=)
    OP_ALL_COMP(==)
    OP_ALL_COMP(!=)

/////////////// SPECIAL OPERATIONS ///////////////

    // Power function, direct
    PType<T> operator ^(T v){
        PType<T> a = Math::pow(_getV(), v);
        return a;
    }
};

#endif
