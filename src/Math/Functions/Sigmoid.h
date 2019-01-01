#ifndef SIGMOID
#define SIGMOID

#include "Basic.h"
#include "../../constants.h"

// The Sigmoid function and it's derivative are useful for AI math operations
namespace Math {
    double sigmoid(double x);
    double sigmoid_derivative(double x);
}

#endif
