//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

// These basic math libraries are bound to be inaccurate. Just use <math> instead.

#ifndef MATHBASIC_H_
#define MATHBASIC_H_

#include <malloc.h>

namespace Math {
    const double E = 2.71828182845904523536028747135266249775724709369995;
    const double PI = 3.14159265358979323846264338327950288419716939937510;

    // basic functions
    double abs(double a); // flips value if negative to positive
    double pow(double a, double b); // power of function, gets the exponent a^b
    double powb(double x, double b); // Cheap and easy power for integers of b

    int* decToFrac(double dec);
    int floor(double val);

    double ln(double x); // natural log function
    double log(double base, double x); // log_b(x)

    double factorial(double a); // finds the factorial of the numberex−e−x2

    double sqrt(double x);
}

#endif /*MATHBASIC_H_*/
