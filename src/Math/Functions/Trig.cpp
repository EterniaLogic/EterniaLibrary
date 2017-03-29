//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

// These basic math libraries are bound to be inaccurate. Just use <math> instead.

#include "Trig.h"


// increasing the accuracy could result in some questionably long solutions.
#define ACCURACY 200

namespace Math {
    // x - x3/3! + x5/5! - x7/7! ...
    double sin(double x) {
        double sum = x;

        // Taylor's Series of accuracy 10
        bool neg=true;
        for(int i=3; i<ACCURACY*2+3; i+=2) {
            sum += (neg ? -1 : 1) * (pow(x,i)/factorial(i));
            neg=!neg;
        }

        return sum;
    }

    double cos(double x) {
        double sum = 1;

        // Taylor's Series of accuracy 10
        bool neg=true;
        for(int i=2; i<ACCURACY*2; i+=2) {
            sum += (neg ? -1 : 1) * (pow(x,i)/factorial(i));
            neg=!neg;
        }

        return sum;
    }

    double tan(double x) {
        // TODO: add actual implementation.
        return sin(x)/cos(x);
    }

    // Hyperbolic functions
    //(e^x−e^−x)/2
    double sinh(double x) {
        return (pow(E,x)-pow(E,-x))/2;
    }

    // (e^x+e^-x)/2
    double cosh(double x) {
        return (pow(E,x)+pow(E,-x))/2;
    }

    // (e^x-e^-x)/(e^x+e^-x)
    double tanh(double x) {
        return (pow(E,x)-pow(E,-x))/(pow(E,x)+pow(E,-x));
    }

    // arc functions, implemented as 1/sin(a)
    double asin(double x) {
        return 1/sin(x);
    }

    double acos(double x) {
        return 1/cos(x);
    }

    double atan(double x) {
        return 1/tan(x);
    }
}
