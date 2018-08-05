
#ifndef TimeSignal_H_
#define TimeSignal_H_


#include "../../../Data/includes.h"
#include "Sample.h"
#ifndef FreqSignal_H_
#include "FreqSignal.h"
#else
class FreqSignal;
#endif



// A time signal is a sampled signal from either a digital source
//      or an analog source.

// An fft can get the frequency domain.
class TimeSignal {
private:
    LinkedList<Sample> samples;
public:
    TimeSignal();
    virtual ~TimeSignal();

    // time constants and delays are factored in these functions
    void sampleDigital(bool value, float time); // sample a digital signal (0->1f)
    void sampleAnalog(float value, float time); // sample an analog signal (-1f -> 1f)
    
    // sample in real-time
    void startSample(); // sets up time offset
    void sampleDigital(bool value); // sample a digital signal (0->1f)
    void sampleAnalog(float value); // sample an analog signal (-1f -> 1f)
    
    void clearSamples();

    // math functions
    void amplify(float value);

    FreqSignal FFT(); // outputs the frequency domain, useful to apply filters
};

#endif
