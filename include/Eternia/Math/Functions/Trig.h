//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

// These basic math libraries are bound to be inaccurate. Just use <math> instead.

// Basic trig functions, evaluated with pi.

#include "Basic.h"


namespace Math {
    double sin(double); // x - x3/3! + x5/5! - x7/7! ...
    double cos(double); //
    double tan(double); //

    //
    double sinh(double); //(e^x−e^−x)/2
    double cosh(double);
    double tanh(double);

    // arc functions, implemented as 1/sin(a)
    double asin(double);
    double acos(double);
    double atan(double);
}
