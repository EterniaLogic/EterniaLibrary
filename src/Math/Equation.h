#ifndef EQUATION_H_
#define EQUATION_H_

#include "../Data/CharString.h"
#include "../Data/LinkedList.hpp"

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

namespace Math {
    class Equation;

    enum EqType {EVar, ENumber, EOperator, EComplex, EConstant};

    class EquationNode {
            EqType mode;
            double data;
            Equation* dataeq; // subnode
    };

    class Equation {
            CharString eq;
            LinkedList<EquationNode> baseNodes; // nodes on the "Bottom Step".


        public:
            Equation();
            Equation(CharString equation);

            void set(CharString equation);
            void setVariableValue(CharString variable, CharString value); // replaces variable with variable value.

            Equation* solveForVariable(CharString variable); // algeraeically solve the equation for variable.

            double solve(CharString variable); // calls solveForVariable() and determines if it can be solved directly for an answer.
            Equation derive(CharString wrt); // derive this equation.
            Equation integrate(CharString wrt); // integrate this equation.
    };
}

#endif
