

#include "Equation.h"
namespace Math {
    Equation::Equation() {}
    Equation::Equation(CharString* equation) {
        baseNodes = new LinkedList<EquationNode>();
        set(equation);
    }

    // set by parsing.
    void Equation::set(CharString* eq) {
        // parse out the equation by each element.
        // these elements become nodes
    }
}
