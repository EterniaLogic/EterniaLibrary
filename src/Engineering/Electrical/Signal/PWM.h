#ifndef PWM_H
#define PWM_H

#include "Signal.h"
#include <time.h>

// note: to get a good duty cycle output,
//      at least 20x the frequency is needed. Accuracy
//      increases as the input speed ratio increases.


class PWM : public Signal {
private:
    float duty, tickinterval;
    int frequency, count, tickRes, autoTickfind, lastClock;
    bool value;
    void (*func)(bool);
public:
    PWM();
    void tick(); // manual tick

    void autoTick(); // attempts to affix to a planned tick interval automatically

    void setDuty(float value); // duty from 0 to 1
    void setFrequency(int frequency); // set frequency from 1 to 10 MHz
    void setTickInterval(float seconds); // how many seconds expected per tick?
    void setPWMEvent(void (*function)(bool)); // enable an interrupt-like event

    float getDuty(); // duty from 0 to 1
    int getFrequency(); // set frequency from 1 to 10 MHz
    float getTickInterval(); // how many seconds expected per tick?

    bool getPWMValue(); // output the PWM value!
    bool getSlow(); // is the input tick too slow to saturate the duty?
};

#endif
