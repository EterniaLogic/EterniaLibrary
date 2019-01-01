#ifndef COMPLEXNUM_H_
#define COMPLEXNUM_H_

#include <math.h>
// Complex Number!


#define OPEQ_Real(op, typex) Complex operator op(typex val){ \
    this->real=val; \
    return *this; \
}

#define OPEQ_Imag(op, typex) Complex operator op(typex val){ \
    this->imaginary=val; \
    return *this; \
}

#define OP_MATH(op, typex, isreal) Complex operator op(typex val){ \
    if(isreal) this->real = this->real op val; \
    else this->imaginary = this->imaginary op val; \
    return *this; \
}

#define OPIM_MATH(op, opx, typex, isreal) Complex operator op(typex val){ \
    if(isreal) this->real = this->real opx val; \
    else this->imaginary = this->imaginary opx val; \
    return *this; \
}

#define OPI_MATH(op, typex) Complex operator op(typex val){ \
    float tmp = real; \
    real=imaginary; \
    imaginary=-real; \
    real = real op val; \
    imaginary = imaginary op val; \
    return *this; \
}

namespace Math {
    class Complex{
    public:
        Complex(){
            real=imaginary=0.f;
        }
        Complex(float real, float imaginary){
            this->real=real;
            this->imaginary=imaginary;
        }
        ~Complex(){}
        
        float real, imaginary;
        
        Complex operator =(Complex val){
            *this = val;
            return val;
        }
        
        Complex operator +(Complex val){
            this->real += val.real;
            this->imaginary += val.imaginary;
            return *this;
        }
        
        Complex operator -(Complex val){
            this->real -= val.real;
            this->imaginary -= val.imaginary;
            return *this;
        }
        
        Complex operator *(Complex val){
            real = real*val.real - imaginary*val.imaginary;
            imaginary = imaginary*val.real + real*val.imaginary;
            return *this;
        }
        
        Complex operator /(Complex val){
            real = real*val.real + imaginary*val.imaginary;
            real /= pow(val.real,2.f) + pow(val.imaginary,2.f);
            imaginary = imaginary*val.real - real*val.imaginary;
            imaginary /= pow(val.real,2.f) + pow(val.imaginary,2.f);
            return *this;
        }
        
        
        // only set real part.
        // Complex operator =(Complex);
        OPEQ_Real(=, int);
        OPEQ_Real(=, float);
        OPEQ_Real(=, long);
        
        // direct set imaginary part
        OPEQ_Imag(&=, int);
        OPEQ_Imag(&=, float);
        OPEQ_Imag(&=, long);
        
        // complex = complex + real;
        OP_MATH(+, int, true);
        OP_MATH(+, float, true);
        OP_MATH(+, long, true);
        OP_MATH(-, int, true);
        OP_MATH(-, float, true);
        OP_MATH(-, long, true);
        OP_MATH(*, int, true); // multiply by real just scales
        OP_MATH(*, float, true);
        OP_MATH(*, long, true);
        OP_MATH(/, int, true); // divide by real just scales
        OP_MATH(/, float, true);
        OP_MATH(/, long, true);
        
        // complex = complex += imag;
        OPIM_MATH(+=,+, int, false);
        OPIM_MATH(+=,+, float, false);
        OPIM_MATH(+=,+, long, false);
        OPIM_MATH(-=,-, int, false);
        OPIM_MATH(-=,-, float, false);
        OPIM_MATH(-=,-, long, false);
        // multiply/divide by imaginary swaps real with imag. real switches signs.
        OPI_MATH(*=, int); // imaginary multiply by scalar
        OPI_MATH(*=, float);
        OPI_MATH(*=, long);
        OPI_MATH(/=, int); // imaginary divide by scalar
        OPI_MATH(/=, float);
        OPI_MATH(/=, long);
        
        float getMagnitude(){
            return sqrt(pow(real,2.f)+pow(imaginary,2.f));
        }
        
        
        // return a complex from polar coordinates
        static Complex fromPolar(float r, float theta){
            Complex ret;
            
            ret.real = r*cos(theta);
            ret.imaginary = r*sin(theta);
            
            return ret;
        }
    };
}

#endif
