#ifndef SIGMOID
#define SIGMOID

#include "Basic.h"
#include "../../constants.h"
#include "../LinkedListMath.def.h"
#include "../../Data/LinkedList.hpp"

// The Sigmoid function and it's derivative are useful for AI math operations
namespace Math {
    double sigmoid(double x);
    double sigmoid_derivative(double x);
    
    LLMATHH(sigmoid, double);
    LLMATHH(sigmoid_derivative, double);
}

#endif
