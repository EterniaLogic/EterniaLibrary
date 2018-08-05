
#ifndef FreqSignal_H_
#define FreqSignal_H_

#include "Sample.h"
#ifndef TimeSignal_H_
#include "TimeSignal.h"
#else
class TimeSignal;
#endif

// Frequency domain, use ifft to get time domain...
//  Time in this case is actually the frequency range.
class FreqSignal {
private:
    LinkedList<Sample> samples;
public:
    FreqSignal();
    virtual ~FreqSignal();

    // filter the samples, auto-calculates a filter based on inputs
    // dbm determines how fast it will drop
    void bandpassFilter(float centerFreq, float dbm); 
    void lowpassFilter(float centerFreq, float dbm);
    void highpassFilter(float centerFreq, float dbm);
    void notchFilter(float centerFreq, float dbm);
    
    FreqSignal noiseProfile(); // gets the profile for noise (use static ambient)
    void noiseFilter(FreqSignal profile, float dbm); // appends that filter

    TimeSignal IFFT(); // outputs the time domain
};

#endif
