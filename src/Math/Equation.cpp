//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "Equation.h"

Equation::Equation(){}
Equation::Equation(CharString* equation){
    baseNodes = new LinkedList<EquationNode>();
    set(equation);
}

// set by parsing.
void Equation::set(CharString* eq){
    // parse out the equation by each element.
    // these elements become nodes
}
