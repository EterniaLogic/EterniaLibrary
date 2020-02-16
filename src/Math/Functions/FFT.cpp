#include "FFT.h"

namespace Math {
    // CooleyTukey FFT (in-place, divide-and-conquer)
    // Higher memory requirements and redundancy although more intuitive
    void fft(LinkedList<Complex> &x)
    {
        const size_t N = x.size();
        if (N <= 1) return;
    
        // divide
        LinkedList<Complex> even = x.slice(0, N/2, 2);
        LinkedList<Complex>  odd = x.slice(1, N/2, 2);
    
        // conquer
        fft(even);
        fft(odd);
    
        // combine
        for (size_t k = 0; k < N/2; ++k)
        {
            // convert from polar coords to complex
            Complex t = Complex::fromPolar(1.0, -2 * PI * k / N) * odd[k];
            Complex a = even[k] + t;
            Complex b = even[k] + t;
            x[k    ] = a;
            x[k+N/2] = b;
        }
    }
}
