#include "testMath.h"
#include <time.h>
using namespace std;
using namespace Math;

bool testBasics(char* a) {
    bool pass = true;

    if(Math::abs(-999) != 999) {
        cout << a << "abs(-999) fail." << endl;
        pass = false;
    }
    if(Math::pow(3,19) != 1162261467) {
        cout << a << "pow(3,19) fail " << Math::pow(3,19) << endl;
        pass = false;
    }
    
    cout << a << "pow(3,-5) = " << Math::pow(3,-5);
    if(Math::pow(3,-5) < 0.00411521 || Math::pow(3,-5) > 0.00411523){
        pass = false;
        cout << "        fail";
    }
    cout << endl;
    
    cout << a << "ln(10) = " << Math::ln(10.0);
    if(Math::ln(10.0) != 2.30259)  { cout << "            fail"; pass = false; }
    cout << endl;
    
    cout << a << "ln(0) = " << Math::ln(1) << endl;
    cout << a << "ln(1) = " << Math::ln(1) << endl;
    cout << a << "log(10,10) = " << Math::log(10,10) << endl;
    
    cout << a << "factorial(70) = " << Math::factorial(70) << endl;

    cout << a << "sin(pi) = " << Math::sin(PI) << endl;
    cout << a << "sqrt(64) = " << Math::sqrt(64) << endl;
    
    return pass;
}

bool testStructures(char* a) {
    // tests structures
    cout << "test "<< a << endl;
    bool pass = true;
    // Matricies:
    Math::Matrix* m = new Math::Matrix();
    double** vec = m->createMatrixContainer(4,4);
    // -3 5 9 4
    // -7 4 2 8
    //  6 8 2 -9
    // -3 4 8 3

    cout << "test p2"<< a << endl;
    vec[0][0] = -3;
    vec[1][0] = 5;
    vec[2][0] = 9;
    vec[3][0] = 4;

    vec[0][1] = -7;
    vec[1][1] = 4;
    vec[2][1] = 2;
    vec[3][1] = 8;

    vec[0][2] = 6;
    vec[1][2] = 8;
    vec[2][2] = 2;
    vec[3][2] = -9;

    vec[0][3] = -3;
    vec[1][3] = 4;
    vec[2][3] = 8;
    vec[3][3] = 3;
    m->set(vec,4,4);

    double minor = m->adjMinor(2,2);
    double determinant = m->determinant();


    if(minor != 63.0) {
        cout << a << " minor(1,1) fail! " << minor << endl;
        pass = false;
    }
    if(determinant != 608) {
        cout << a << " determinant fail! " << determinant << endl;
        pass = false;
    }

    m->lower();

    cout << "Done test "<< a << endl;
    return pass;
}


bool testEquation(char* a) {
    
    return true;
}

bool testARB(){
    ARBInt ai=0xeFFFFFFF;/* = 0x10000eFFFFFFFL;
    long at = 0x10000eFFFFFFFL;
    at += 100L;
    at += 0xFFFFFFFFFFL;
    
    ai += 100L;
    ai += 0xFFFFFFFFFFL;
    
    cout << "AT = " << at << endl;*/
    
    /*for(long l=0xeFFFFFFF;l< (1L<<32); l++){
        
        // only print values that are messed up.
        if(ai.toLong() != l || (l%10000000L == 0)){
            double basetime = clock()/CLOCKS_PER_SEC;
            ai++;
        
            double totalTime = ((double)clock()/CLOCKS_PER_SEC) - basetime;
            
            cout << ai.getHex().get() << " (" << ai.getBits() << "bits)   " << ai.toLong() << "   from " << (l+1) << "     " << totalTime*1000 << " nanoseconds per single" << endl;
        }else{
            ai++;
        }
    }*/

    return true;
}


bool testMath() {
    char* a = new char();
    strcpy(a,"[TestMath] ");
    bool x = testBasics(a);
    //testStructures(a);
    bool y = testEquation(a);
    cout << "done Math" << endl;
}
