#include "Sigmoid.h"



double sigmoid(double x){
    return 1 / (1 + Math::pow(Math::E,-x));
}

double sigmoid_derivative(double x){
    return x * (1 - x);
}
