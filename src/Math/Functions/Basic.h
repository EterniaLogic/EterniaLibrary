

// These basic math libraries are bound to be inaccurate. Just use <math> instead.
#ifndef MATHBASIC_H_
#define MATHBASIC_H_

#include <malloc.h>
#include "../LinkedListMath.def.h"
#include "../../Data/LinkedList.hpp"

namespace Math {
    const double E = 2.71828182845904523536028747135266249775724709369995;
    const double PI = 3.14159265358979323846264338327950288419716939937510;

    // basic functions
    double abs(double x); // flips value if negative to positive
    double pow(double x, double b); // power of function, gets the exponent a^b
    double powb(double x, double b); // Cheap and easy power for integers of b O(N)

    int* decToFrac(double dec);
    int floor(double val);

    double ln(double x); // natural log function
    double log(double base, double x); // log_b(x)
    double log10(double x); // log10(x)

    double factorial(double x); // finds the factorial of the numberex−e−x2

    double sqrt(double x);
    
    double min(double a, double b);
    double max(double a, double b);
    
    // enable linkedLists to be used here
    LLMATHH(abs, double);
    LLMATHH_B(pow, double, double);
    LLMATHH_B(powb, double, double);
    LLMATHH(floor, double);
    LLMATHH(ln, double);
    LLMATHH_A(log, double, double);
    LLMATHH(log10, double);
    LLMATHH(factorial, double);
    LLMATHH(sqrt, double);
    LLMATHH_B(min, double, double);
    LLMATHH_B(max, double, double);
}

#endif /*MATHBASIC_H_*/
