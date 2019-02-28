#ifndef AI_H
#define AI_H

#include "AIFactory.h"
#include "AIMonarch.h"

class AI{
public:
    AI();
    
    AIMonarch monarch; // Primary consciousness for the AI
    AIFactory factory; // factory that manages the memory, wisdom, and movements for the monarch.
};

#endif
