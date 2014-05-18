//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef AI_Decide_h_
#define AI_Decide_h_

// Think

class AIDecide
{
public:
  AIDecide();
  void plot(); // AI will plot (Strategize) if in command or tainted/smart.
  void stuff(); // AI will do stuff if he/she is not commanded or is bored.
  void command(); // AI will command squad or group
  
  void tick(); // game time tick
  
private:
  
};

#endif