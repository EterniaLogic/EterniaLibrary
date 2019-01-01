#include "ArbitraryInteger.h"

#define CONSTRUCTOR(TPE) ArbitraryInteger::ArbitraryInteger(TPE c){ \
        data = new LinkedList<TYPET>(); \
        negative=false; \
        set<TPE>(c); \
    }

namespace Math{
    ArbitraryInteger::ArbitraryInteger(){
        //data.clear();
        data = new LinkedList<TYPET>();
        negative=false;
    }
    
    CONSTRUCTOR(long);
    CONSTRUCTOR(int);
    CONSTRUCTOR(unsigned int);

    ArbitraryInteger::~ArbitraryInteger(){
        //data.clear();
        data = 0x0;
        //cout << "AI Finalize" << endl;
    }

    // increment
    ArbitraryInteger ArbitraryInteger::operator ++(int v){
        //cout << "++ 0 " << endl;
        data->freeze();
        //cout << "++ a " << endl;
        bool c = true; // carry (initially true for adding 1)
        for(int k=0; k<data->frozenlen; k++){ // loop through bytes
            if(c){
                TYPET* d = data->frozen[k];
                long v = *d;
                if(v >= __MAXSIZET){ // carry
                    *d=0;
                }else{ // consume the carry
                    *d = v+1;
                    //cout << v << endl;
                    c=false;
                }
            }else{
                return *this;
            }
        }
        
        if(c) {
            cout << "carry addsize" << endl;
            TYPET* m = (TYPET*)malloc(sizeof(TYPET));
            m[0]=1;
            data->add(m); // carry-add '1' to beginning of the list
        }
        
        //cout << "++ d " << endl;
        return *this;
    }
    
    
    ArbitraryInteger ArbitraryInteger::operator -=(long v){
        cout << "-= long value " << toLong() << " same as ";
        resize(sizeof(long));
        cout << toLong() << endl;
    }
    
    ArbitraryInteger ArbitraryInteger::operator +=(long v){
        //cout << "+= long value " << toLong() << " same as ";
        resize(sizeof(long));
        cout << toLong() << endl;
        
        double v1 = v;
        if(v1 < 0){
            v *= -1; // cancel out negative
            return *this -= v; // perform negative version
        }
        
        LinkedList<TYPET> partsV;
        for(unsigned long k=0; k<sizeof(long)/__TYPETBytes; k++){
            TYPET a = (v & (__TYPETMASK << (k* __TYPETBits))) >> (k* __TYPETBits);
            cout << a << endl;
            partsV.add(a);
        }
        
        data->freeze();
        partsV.freeze();
        //cout << "+= a " << endl;
        unsigned long c = 0; // carry (initially true for adding 1)
        for(int k=0; k<partsV.frozenlen; k++){ // loop through bytes
            TYPET* d = data->frozen[k];
            unsigned long da = *d;
            unsigned long va = *partsV.frozen[k]; // still use ulong
            //cout << "+= b   " << (da/* << (k*__TYPETBits)*/) << " + " << (va/* << (k*__TYPETBits)*/) << "  =  " << ((da+va)/* << (k*__TYPETBits)*/) << endl;
            
            unsigned long v2 = da + va + c;
            /*unsigned long v2m = v2 & __TYPETMASK;
            unsigned long v2s = (v2 ^ __TYPETMASK) >> __TYPETBits;
            cout << "+= b  est: " << v2 << " masked: " << (v2m) << "   shifted: " << v2s << endl;*/
            if(v2 >= __MAXSIZET){ // carry
                *data->frozen[k] = v2 & __TYPETMASK;
                c = (v2 ^ __TYPETMASK) >> __TYPETBits; // get other bits for carry, then shift right
            }else{ // consume the carry
                *data->frozen[k] = v2;
                c=0;
            }
        }
        
        //cout << "+= long value ending " << toLong() << endl;
        
        //cout << "++ d " << endl;
        return *this;
    }

    ArbitraryInteger ArbitraryInteger::operator =(unsigned int v){
        ArbitraryInteger ret;
        
        
        return ret;
    }



    template<class T>
    void ArbitraryInteger::set(T val){
        resize(sizeof(T)); // make sure that this arb is at least the size of the type
        
        double v = val;
        if(v < 0){
            negative = true;
            val *= -1;
        }
        
        int sizel = sizeof(T);
        int sizeT = (data->size())*__TYPETBytes; // this bits
        cout << "set(" << (negative ? "-" : "") << val << ")    sizes" << sizel << ">=" << sizeT << endl;
        
        // set values
        int t=0;
        data->freeze();
        for(int k=0; k<data->frozenlen; k++){ // loop through bytes
            cout << "set b " << k << endl;
            TYPET* d = data->frozen[k];
            for(int j=0;j<__TYPETBits;j++){ // loop through bits
                unsigned long x = val & 1UL<<(j+t);
                cout << "x & " << (1UL<<(j+t)) << "   => " << x   <<   "      " << getBinary().get() << endl;
                
                if(x > 0)
                    *d ^= 1UL<<j;
            }
            t += __TYPETBits;
        }
        
        cout << "d" << endl;
        cout << getBinary().get() << "   " << (unsigned long)toLong() << endl;
    }



    void ArbitraryInteger::resize(int bytesx){
        int sizel = bytesx;
        int sizeT = (data->size())*__TYPETBytes; // this bits
        
        // match size in bits
        if(sizeT < sizel){
            int r = ((sizel-sizeT)/__TYPETBytes);
            cout << "resize +" << r << " of typeT" << endl;
            
            for(int i=0;i<r;i++){
                TYPET* m = (TYPET*)malloc(sizeof(TYPET));
                m[0]=0;
                data->add(m); // carry-add '1' to beginning of the list
            }
            
            //cout << "new size " << ((data->size())*__TYPETBytes*8) << " bits" << endl;
        }
    }






    CharString ArbitraryInteger::toString(){
        CharString str;
        data->freeze();
        //cout << "tostr a " << data->frozenlen << endl;
        
        
        str = getBinary();
        
        // print # bits
        str.concata(" (");
        str.concata(CharString::ConvertFromInt(getBits()));
        str.concata(")");
        
        // Print out digits
        str.concata("  ");
        str.concata(CharString::ConvertFromLong(toLong()));
        
        
        return str;
    }
    
    CharString ArbitraryInteger::getHex(){
        CharString str;
        data->freeze();
        //cout << "tostr a " << data->frozenlen << endl;
        
        
        // Print out binary
        //for(int k=data->frozenlen-1; k>=0; k--){ // loop through bytes
        for(int k=data->frozenlen-1; k>=0; k--){ // loop through bytes
            //cout << "tostr b " << k << endl;
            TYPET* d = data->frozen[k];
            //cout << "tostr b = " << data.baseNode->data << endl;
            for(int j=__TYPETBits/4-1;j>=0;j--){ // loop through bits
                int x = (*d & 0xF<<(j*4)) >> (j*4);
                //cout << "tohex c2 bit(" << j << ") = " << x << endl;
                
                switch(x){
                    case 0: str.concata("0",1); break;
                    case 1: str.concata("1",1); break;
                    case 2: str.concata("2",1); break;
                    case 3: str.concata("3",1); break;
                    case 4: str.concata("4",1); break;
                    case 5: str.concata("5",1); break;
                    case 6: str.concata("6",1); break;
                    case 7: str.concata("7",1); break;
                    case 8: str.concata("8",1); break;
                    case 9: str.concata("9",1); break;
                    case 10: str.concata("A",1); break;
                    case 11: str.concata("B",1); break;
                    case 12: str.concata("C",1); break;
                    case 13: str.concata("D",1); break;
                    case 14: str.concata("E",1); break;
                    case 15: str.concata("F",1); break;
                }
            }
        }
        
        return str;
    }
    
    
    CharString ArbitraryInteger::getBinary(){
        CharString str;
        data->freeze();
        //cout << "tostr a " << data->frozenlen << endl;
        
        
        // Print out binary
        //for(int k=data->frozenlen-1; k>=0; k--){ // loop through bytes
        for(int k=data->frozenlen-1; k>=0; k--){ // loop through bytes
            //cout << "tostr b " << k << endl;
            TYPET* d = data->frozen[k];
            //cout << "tostr b = " << data.baseNode->data << endl;
            for(int j=__TYPETBits-1;j>=0;j--){ // loop through bits
                int x = *d & 1<<(j);
                //cout << "tostr c2 bit(" << j << ") = " << x << "   " << (int)*d << " & " << (1<<(j)) << endl;
                if(x>0) str.concata("1", 1);
                else str.concata("0", 1);
            }
        }
        
        return str;
    }
    
    int ArbitraryInteger::getBits(){
        int bits=0;
        data->freeze();
         // 00000100 11000100 10110100 00000001 => 29
        int t=0;
        for(int k=0; k<data->frozenlen; k++){ // loop through bytes
            TYPET* d = data->frozen[k];
            for(int j=0;j<__TYPETBits;j++){ // loop through bits
                int x = *d & 1<<j;
                if(x>0) 
                    bits = t+((j+1));
            }
            t+=__TYPETBits;
        }
        
        
        return bits;
    }
    
    // SLOW algorithm, only returns up to int
    int ArbitraryInteger::toInt(){
        int v = 0;
        data->freeze();
        
        int t=0;
        for(int k=0; k<data->frozenlen; k++){ // loop through bytes
            TYPET* d = data->frozen[k];
            for(int j=0;j<__TYPETBits;j++){ // loop through bits
                int x = *d & 1<<j;
                if(x>0) 
                    v ^= 1<<(j+t);
            }
            t+=__TYPETBits;
        }
        
        return (negative?-1:1)*v;
    }
    
    
    
    // SLOW algorithm, only returns up to Long
    long ArbitraryInteger::toLong(){
        unsigned long v = 0;
        
        
        //cout << "toLong"  << endl;
        
/*        int maxlen = sizeof(long);
        resize(maxlen);
        int g = maxlen/__TYPETBytes;*/
        //cout << "toLong size " << g << endl;
        data->freeze();
        
        unsigned long t=0;
        for(int k=0; k<data->frozenlen; k++){ // loop through bytes
            //cout << "toLong b " << k << endl;
            TYPET* d = data->frozen[k];
            //cout << "toLong b " << *d << endl;
            long dl = *d;
            
            v ^= dl << t;
            //cout << "toLong b2 " << *d << endl;
            
            t+=__TYPETBits;
        }
        //cout << "toLong c " << endl;
        
        return v;
        //return (negative?-1L:1L)*((long)v);
    }
}
