//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef EQUATION_H_
#define EQUATION_H_

#include "../MiscLib/CharString.h"

// Equation structure
// y = x^2 + x
// 0 1 2   5 6
//     *          <-- sub-equation
//     x ^ 2
//     0 1 2

// y = sqrt((x^2)/4) + 15/2
// 0 1 2             3 4
//     *
//     x^2  / 4
//     0    1 2
//     *    
//     x ^ 2
//     0 1 2

class Equation;

enum EqType {ENumber, EOperator, EComplex};

class EquationNode
{
    EqType mode;
    double data;
    Equation* dataeq;
};

class Equation
{
    CharString* eq;
    
    
public:
    Equation();
    Equation(CharString* equation);
    
    void set(CharString* equation);
    void setVariableValue(CharString* variable, CharString* value); // replaces variable with variable value.
    
    Equation* solveForVariable(CharString* variable); // algeraeically solve the equation for variable.
    
    double solve(CharString* variable); // calls solveForVariable() and determines if it can be solved directly for an answer.
    Equation* derive(); // derive this equation.
    Equation* integrate(); // integrate this equation.
};

#endif
