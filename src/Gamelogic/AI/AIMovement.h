#ifndef AI_Movement_h_
#define AI_Movement_h_

#include "../../Math/struct/vertex.h"
#include "../../Data/LinkedList.hpp"

// Move

// Controls how the AI Moves based on inquiry, command, ect.
// can only be calculated on a client computer.
class AIMovement
{
public:
  AIMovement();
  void pathTo(vertex* location); // tell AI to goto this location. (Direct and pure order)
  LinkedList<vertex>* solvePath(); // solve path, AI predictability is accounted for. (Lee Algorithm)
  bool isBlocked(vertex* loc); // is a location blocked? (Bad terrain)
  
private:
  // Pathing variables
  vertex* current; // current location for reference
  LinkedList<vertex>* togo; // verticies to go through
};

#endif