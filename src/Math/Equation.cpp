//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Equation.h"

Equation::Equation(){}
Equation::Equation(CharString* equation){
    set(equation);
}

// set by parsing.
void Equation::set(CharString* eq){
    // parse out the equation by each element.
}


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

Equation* derive(){
    
}

// Integration properties
// i( 0 ) = 1
// i( 1 ) = x
// i( cx^n ) = (x^(n+1)) / (n/c)
// i(  )
Equation* integrate(){
    
}
