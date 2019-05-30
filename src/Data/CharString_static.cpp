#include "CharString.h"


// fun thing to write :D
// Desc:  Custom function to convert integers to a list of characters (string)
// Input:  Integer (int)
// return: character string (CharString)
CharString CharString::ConvertFromInt(int integer) {
    return ConvertFromLong((long)integer);
}

CharString CharString::ConvertFromLong(long integer) {
    /*const int ASCIIOffset = 48; // offset on the ASCII chart

    if(integer == 0) return CharString("0");
    
    // gets the digits based on modulus (to the 5th digit, [+-]32k is max/min)
    int len = 0;
    bool neg = false;

    // is negative?
    if(integer < 0) neg = true;
    if(neg) integer = integer*(-1); // remove negative sign, we know the negation. :D

    // determine # of digits
    for(int i=0; i<32; i++) {
        int exp = 1;
        for(int j=0; j<i; j++) exp *= 10; // set exponent 10^i => exp
        if((integer % (exp)) != integer) len++; // if integer mod exp is not equal to self, it is a digit (10/1000 = 10)
    }

    

    const int tlen = len + (neg ? 1 : 0); // constify length, if negative, add digit.
    char* out = new char[tlen+1];

    int t=0; // temp var used to store modulus digit addifier
    int kk = neg ? 1 : 0;
    int offset = neg ? -2 : -1; // offsets char based on neg
    
    //cout << "CFL: " << tlen << " " << offset << endl;
    
    if(neg) out[0] = '-';
    for(int i = tlen+offset; i >= 0; i--) {
        int exp = 1;
        for(int j=0; j<i; j++) exp *= 10; // set exponent 10^i => exp
        int digit = integer / exp -(t*10);
        t *= 10; // shift all digits in t left 1
        t += digit; // enter digit into very last slot of t
        //cout << "out["<<kk<<"] =" <<  (char)(digit+ASCIIOffset) << endl;
        if(kk >= 0) out[kk] = (char)(digit+ASCIIOffset);
        kk++; // increment out digit
    }

    out[tlen]='\0';
    CharString cx = CharString(out,tlen);
    cx.fixZeroing(' ');
    return cx;*/
    
    
    std::string s = std::to_string(integer);
    return CharString(s);
}


CharString CharString::ConvertFromDouble(double d) {
    /*const int ASCIIOffset = 48; // offset on the ASCII chart
    double dig = Math::pow(10, digits);
    int len=0;
    if(d == 0) return CharString("0.0");
    
    // contains E or e?
    
    bool neg = false;
    if(d<0) neg = true;
    if(neg) d *= (-1.);
    
    if(d >= 1.e6){ // output in scientific (+5 digits:   1.12345e10
        
    }else if(d < 1.e-6){
    
    }else{ // standard double output
        
    }
    
    
    const int tlen = len + (neg ? 1 : 0); // constify length, if negative, add digit.
    char* out = new char[tlen+1];
    if(neg) out[0] = '-';
    
    CharString cstr = CharString(out, tlen);*/
    
    
    std::string s = std::to_string(d);
    cout << "dbl to str = " << s << " " << CharString(s) << endl;
    return CharString(s);
}
