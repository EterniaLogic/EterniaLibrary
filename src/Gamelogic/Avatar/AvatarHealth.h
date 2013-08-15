//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Avatar_health_h_
#define Avatar_health_h_

#include "../../Data/LinkedList.hpp"
#include "Disease.h"
#include "Mood.h"

enum BODYPART {BP_HEAD, BP_TORSO, BP_ABDOMEN, BP_LEFTFOOT, BP_RIGHTFOOT, BP_LEFTKNEE, BP_RIGHTKNEE, BP_LEFTHAND, BP_RIGHTHAND, BP_LEFTWRIST, BP_RIGHTWRIST, BP_LEFTARM, BP_RIGHTARM};

class AvatarHealth
{

  
private: // Health variables (Body-part based health)
  
  // VITAL
  float head;
  float torso;
  float abdomen;
  
  // Effects movement
  float leftfoot; 
  float rightfoot;
  float leftknee;
  float rightknee;
  
  // Effects accuracy and precision (you don't want to medicate somebody while you have a broken hand)
  float lefthand;
  float leftwrist;
  float leftarm;
  float righthand;
  float rightwrist;
  float rightarm;
  
  // Overall health
  LinkedList<Disease>* diseases; // list of ailments, toxins, drugs, ect.
  
  LinkedList<Mood>* moods; // Humans are complicated
  
};

#endif