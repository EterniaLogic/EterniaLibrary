//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

// These basic math libraries are bound to be inaccurate. Just use <math> instead.

#include "Basic.h"

#define ACCURACY 0.00001
#define MAX_RUNS 200

namespace Math {
    // flips value if negative to positive
    double abs(double a) {
        if(a < 0) a=a*-1;
        return a;
    }

    // power of function, gets the exponent a^b
    double pow(double x, double b) {
        double out = 1;

        // if a fractional exponent, calculate it with a taylor's series
        if((double)floor(b) != b) {
            // Taylor series for denominator
            double val = 1;

            for(int n=1; n<=MAX_RUNS; n++) {
                out += (pow(-1+b, n)*x*pow(ln(x),n))/factorial(n);
            }
        } else {
            for(int i=0; i<abs(b); i++) {
                out *= x;
            }
            // reverse if b is negative.
            if(b < 0) out = 1/out;
        }

        return out;
    }

    // Basic power
    double powb(double x, double b) {
        double out = 1;
        for(int i=0; i<abs(b); i++) {
            out *= x;
        }
        // reverse if b is negative.
        if(b < 0) out = 1/out;

        return out;
    }

    // http://stackoverflow.com/questions/5124743/algorithm-for-simplifying-decimal-to-fractions
    int* decToFrac(double dec) {
        int n = floor(dec);
        int x = -n;
        int* t = (int*)calloc(2,sizeof(int));
        // The lower fraction is 0/1
        int lower_n = 0;
        int lower_d = 1;
        // The upper fraction is 1/1
        int upper_n = 1;
        int upper_d = 1;



        if (x < ACCURACY) {
            t[0] = n;
            t[1] = 1;
            return t;
        } else if(1 - ACCURACY < x) {
            t[0] = n+1;
            t[1] = 1;
            return t;
        }


        while(true) {
            // The middle fraction is (lower_n + upper_n) / (lower_d + upper_d)
            int middle_n = lower_n + upper_n;
            int middle_d = lower_d + upper_d;
            // If x + error < middle
            if(middle_d * (x + ACCURACY) < middle_n) {
                // middle is our new upper
                upper_n = middle_n;
                upper_d = middle_d;
                // Else If middle < x - error
            } else if(middle_n < (x - ACCURACY) * middle_d) {
                // middle is our new lower
                lower_n = middle_n;
                lower_d = middle_d;
            } else { // Else middle is our best fraction
                t[0] = n * middle_d + middle_n;
                t[1] = middle_d;
                return t;
            }
        }

    }

    // get the floor
    int floor(double val) {
        int v = 0;

        // 5.6 < 6
        if(val < (int)val && val > 0) {
            return (int)val-1;
        } else if(val > (int)val && val < 0) {
            return (int)val+1;
        }

        return (int)val;
    }


    // natural log function
    double ln(double x) {
        double out=0;


        for(int n=1; n<=MAX_RUNS; n++) {
            out += (powb(-1, n+1)/n) * powb(x-1, n);
        }

        return out;
    }

    // direct base log
    double log(double base, double x) {
        return ln(x) / ln(base);
    }

    // finds the factorial of the number
    double factorial(double x) {
        if(x <= 0) return 1;

        return x * factorial(x-1);
    }

    // ref: http://www.cs.uni.edu/~jacobson/C++/newton.html
    double sqrt(double number) {
        double lower, upper, guess;

        if (number < 1) {
            lower = number;
            upper = 1;
        } else {
            lower = 1;
            upper = number;
        }

        // Taylor's series'
        while ((upper-lower) > ACCURACY) {
            guess = (lower + upper)/2;
            if(guess*guess > number)
                upper = guess;
            else
                lower = guess;
        }
        return (lower + upper)/2;
    }
}
