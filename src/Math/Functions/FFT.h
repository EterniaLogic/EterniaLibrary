#ifndef FFT_H_
#define FFT_H_

#include "../Complex.hpp"
#include "../../Data/LinkedList.hpp"
#define PI 3.1415926

// CooleyTukey FFT (in-place, divide-and-conquer)
void fft(LinkedList<Complex> &complexlist);
#endif
