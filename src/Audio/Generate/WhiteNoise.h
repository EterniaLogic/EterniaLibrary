#ifndef WHITENOISE_H_
#define WHITENOISE_H_

// White noise is generated
#include <random>
#include <malloc.h>
#include "../../Data/LinkedList.hpp"

template<class T>
class WhiteNoise{
    public:
        WhiteNoise();
        
        LinkedList<T> getValues(int number); // grab N values.
};

#endif
