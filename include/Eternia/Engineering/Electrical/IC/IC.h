#ifndef IC_h_
#define IC_h_

#include "../Components/Component.h"
#include "../../../Data/LinkedList.hpp"

// Defines basic Integrated Circuit

class IC : private virtual Component
{
public:
  void setPins(LinkedList<PowerValue>* list); // set the initial pins list
  int getMaxPins();
  
  double getPin(int pin); // return the value on a specific pin
  void setPin(int pin, double value); // set the value on a pin
  
  
  
  void tick(SecondTick* tickTime); // operate the component
private:
  LinkedList<PowerValue>* pins;
  int maxPins;
};

#endif 
