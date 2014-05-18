#ifndef Wire_h_
#define Wire_h_ 

#include "ComponentRating.h"

// Wires are used to connect components together.
// This is used like a Graph

class Wire
{
public:
  Wire(Component* A, Component* B, double Resistance);
  virtual ~Wire();
  
private:
  Component* comp_a; // First component
  Component* comp_b; // Second component
  double resist; // Resistivity of this wire
  
  
};

#endif