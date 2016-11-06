#include "Equation.h"
// derivative properties
// d( k^n ) = n * k^(n-1)           POWER
// d( constant ) = 0                CONSTANTS
// d( f(g(k)) ) = f(g(k))*g'(k)     CHAIN
// d( f(k) * g(k) ) = f*g' + f'*g   PRODUCT
// d( f / g ) = (f*g' - f'*g)/g^2   QUOTIENT
// d( f - g ) = f' - g'             DIFFERENCE
// d( f + g ) = f' + g'             ADDITION
// d( cf ) = c f'                   SCALAR
// d( sin ) = cos
// d( cos ) = -sin
// d( tan ) = sec^2
// d( cot ) = -csc^2
// d( sec ) = sec tan
// d( csc ) = -csc cot


// Integration properties
// i( 0 ) = 1
// i( 1 ) = x
// i( cx^n ) = (x^(n+1)) / (n/c)
// i(  )


Equation* Equation::derive(char* wrt) {

}

Equation* Equation::integrate(char* wrt) {

}

double Equation::evaluate(double a, double b) {
    //
}
