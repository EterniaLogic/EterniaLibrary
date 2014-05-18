#ifndef MOSFET_h_
#define MOSFET_h_

#include "Component.h"

// A mosfet is useful for Amplification or Switching signals (transistor)
// High gate impedance

class Mosfet : private Component
{
public:
  Mosfet(double impedance);
  virtual ~Mosfet();
  
  void tick(SecondTick* tickTime); // operate time
  
private:
  // pinB (declared in component) used as Base
  PowerValue* pinG; // Gate Pin
  PowerValue* pinD; // Drain pin
  
  double impedance; // Gate impedance
};

#endif  
