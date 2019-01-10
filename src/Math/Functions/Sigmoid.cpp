#include "Sigmoid.h"


namespace Math {
    double sigmoid(double x){
        return 1.0 / (1.0 + Math::pow(Math::E,-x));
    }

    double sigmoid_derivative(double x){
        return x * (1.0 - x);
    }
    
    LLMATH(sigmoid, double);
    LLMATH(sigmoid_derivative, double);
}
