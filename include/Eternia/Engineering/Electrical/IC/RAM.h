#ifndef ICRAM_h_
#define ICRAM_h_

#include "IC.h"

// Direct RAM access.

class ICRAM: private IC
{
public:
  ICRAM(double size); // defines maximum size of this RAM.
  virtual ~ICRAM();
  
  void setPower(PowerValue value); // Sets the input power value
};

#endif  