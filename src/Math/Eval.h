//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef EVAL_H_
#define EVAL_H_

#include "../Data/CharString.h"
#include "../Data/Stack.h"

// Pre-initialization Enumerators, enables labels and such within the source.
enum MOperator {none=1,Less=2,Greater=3,equals=4,greaterequals=5,lessequals=6,
                addition=7,subtraction=8,multiplication=9,division=10,Modulus=11,exponent=12
               };
enum nxx {PrimNULL = -99999};

// Evaluates a mathematical expression.
CharString* Eval(CharString* Line);

#endif /*EVAL_H_*/
