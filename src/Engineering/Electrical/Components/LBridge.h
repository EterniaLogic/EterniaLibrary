#ifndef LBridge_h_
#define LBridge_h_

#include "Component.h"

// An H-Bridge is a device that allows current to run in either direction. With a voltage.

class LBridge : private Component
{
public:
  LBridge();
  virtual ~LBridge();
  
  void tick(SecondTick* tickTime); // operate time
};

#endif 