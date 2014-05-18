#include "SecondTick.h"


// Constructor
SecondTick::SecondTick(double Frequency, double SecondTime){
  frequency = Frequency;
  secondTime = SecondTime;
  lastTT = clock();
}
SecondTick::~SecondTick(){}

// clone this object
SecondTick* SecondTick::clone(){
  SecondTick* st = new SecondTick(frequency, secondTime);
  st->setRealTime(useTrue);
  return st;
}

// return frequency
double SecondTick::getFrequency(){
  return frequency;
}

// return secondTime
double SecondTick::getSecondTime(){
  return secondTime;
}

// return tick time expired in microseconds = time/Freq
double SecondTick::getTime(){
  if(useTrue) return getTrueTime();
  return secondTime/frequency;
}

// return tick time expired in microsends time();
double SecondTick::getTrueTime(){
  double ret = lastTT-clock();
  lastTT = clock(); // set variable for next call
  return ret;
}

void SecondTick::setRealTime(bool use){
  useTrue = use;
}