//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "test.h"

using namespace std;
using namespace Math;
using namespace Math::Trig;

void testBasics(char* a){
    if(abs(-999) != 999) { cout << a << "abs(-999) fail." << endl; }
    if(pow(3,19) != 1162261467) { cout << a << "pow(3,19) fail " << pow(3,19) << endl; }
    //if(pow(3,-5) != 0.00411523) { cout << a << "pow(3,-5) fail " << pow(3,-5) << endl; }
    //if(ln(10) != 2.30259) cout << a << "ln(10) fail " << ln(10) << endl;
    //cout << a << "factorial(70) = " << factorial(70) << endl;
    
    //cout << a << "sin(pi) = " << sin(PI) << endl;
    //cout << a << "sqrt(64) = " << sqrt(64) << endl;
}

void testStructures(char* a){
    // tests structures
    
    // Matricies:
    Matrix* m = new Matrix();
    double** vec = m->createMatrixContainer(4,4);
    // -3 5 9 4
    // -7 4 2 8
    //  6 8 2 -9
    // -3 4 8 3
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
    
    double minor = m->adjMinor(1,1);
    double determinant = m->determinant();
    
    if(minor != 63.0) { 
        cout << a << " minor(1,1) fail! " << minor << endl; 
    }
    if(determinant != 608) { 
        cout << a << " determinant fail! " << determinant << endl; 
    }
    
    m->lower();
}


void testEquation(char* a){
    
}


void testMath(){
    char a[12];
    strcpy(a,"[TestMath] ");
    testBasics(a);
    testStructures(a);
    testEquation(a);
    cout << "done Math" << endl;
}
