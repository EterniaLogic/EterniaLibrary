#ifndef Inverter_h_
#define Inverter_h_

#include "Component.h"

// The inverter switches DC to AC

class Inverter : private Component
{
public:
  Inverter(double Frequency);
  virtual ~Inverter();
  
  void tick(SecondTick* tickTime); // operate time
  
private:
  double frequency; // frequency at which the inverter converts DC to.
};

#endif  