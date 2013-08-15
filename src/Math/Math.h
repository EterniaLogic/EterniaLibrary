//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef MATH_H_
#define MATH_H_

// includes all functions and mathematical constants.

// namespace Math
#include "Functions/Basic.h" // Basic functions such as abs, root, exponent, ect. NAMESPACE Basic
#include "Functions/Trig.h" // sin, cos, tan, (asin, sinh, ...) NAMESPACE Math::Trig


// no namespace

// Mathematical Structures
#include "struct/Matrix.h" // supports Matrix operations
#include "struct/VectorSpace.h" // supports VectorSpaces
#include "struct/vertex.h" // supports Vectors and their inner functions

// Trig.h requires Basic.h, so Basic.h is only referenced here to be used as a path finder.


// algebra and evaluations
#include "Eval.h" // direct evalutation with no variables.
#include "Equation.h" // equation with variables and equal signs.

#endif /*MATH_H_*/
