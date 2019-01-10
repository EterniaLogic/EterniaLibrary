#ifndef EVAL_H_
#define EVAL_H_

#include "../Data/CharString.h"
#include "../Data/Stack.hpp"

namespace Math {
    // Pre-initialization Enumerators, enables labels and such within the source.
    enum MOperator {none=1,Less=2,Greater=3,equals=4,greaterequals=5,lessequals=6,
                    addition=7,subtraction=8,multiplication=9,division=10,Modulus=11,exponent=12
                };
    enum nxx {PrimNULL = -99999};

    // Evaluates a mathematical expression.
    CharString Eval(CharString Line);
}
#endif /*EVAL_H_*/
