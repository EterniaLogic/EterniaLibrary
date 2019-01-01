#include "Arbitrary.h"

namespace Math {
    Arbitrary::Arbitrary(){
        clear();
    }

    Arbitrary::~Arbitrary(){
        clear();
    }
    
    void Arbitrary::clear(){
        exponent.clear();
        mantissa.clear();
        negative=false;
    }
    

    // calculates # of bits used
    int Arbitrary::bitcalc(){
        int v = 0;
        
        return v;
    }
    
    Arbitrary Arbitrary::operator =(int v){
        clear();
        
        
        return *this;
    }
    
    Arbitrary Arbitrary::operator +=(int v){
        LinkedList<uint8_t> t;
        
        // go through and convert integer to ieee754 of ??? size.
        int man=0, exp=0;
        
        return *this;
    }
}
