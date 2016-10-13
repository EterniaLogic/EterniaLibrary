#include "PWM.h"

PWM::PWM() {
    // set defaults
    duty = 0.5f; // 50% duty
    frequency=1E3; // 1kHz
    setTickInterval(1/(256*frequency));
    lastClock = clock();
}

// manual tick
void PWM::tick() {
    // each tick is from 0 .. tickRes
    // tickRes is automatically figure out when a tick invertal is set.

    // enable interrupt-like events (for toggling pins, ect.)
    if(value != (count < tickRes*duty))
        (func)((count < tickRes*duty));

    value = (count < tickRes*duty); // set 1 or 0
    count = (count >= tickRes) ? 0 : count+1;
}


void PWM::autoTick() {
    // automatically find the tick interval via nano system time
    setTickInterval(1.0f/((float)(clock()-lastClock)));
    lastClock = clock();
    tick();
}

// duty from 0 to 1
void PWM::setDuty(float value) {
    duty = value;
}

// set frequency from 1 to 500 MHz
void PWM::setFrequency(int freq) {
    this->frequency = freq;
}

// how many seconds expected per tick?
void PWM::setTickInterval(float seconds) {
    // tick res is the # of ticks per the original frequency
    tickinterval = seconds;
    tickRes = 1/(frequency*seconds);
}

// duty from 0 to 1
float PWM::getDuty() {
    return duty;
}


// set frequency from 1 to 10 MHz
int PWM::getFrequency() {
    return frequency;
}

// how many seconds expected per tick?
float  PWM::getTickInterval() {
    return tickinterval;
}

bool PWM::getPWMValue() {
    return value;
}


// is the input tick too slow to saturate the duty?
bool PWM::getSlow() {
    return (tickRes < 20);
}

void setPWMEvent(void (function)(bool)) {
    func = function;
}
