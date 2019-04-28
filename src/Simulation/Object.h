#ifndef OBJECT_HH_
#define OBJECT_HH_

#include "../Data/includes.h"
#include "Location.h"

enum BODY_LOCATION {BL_LFORELIMB, BL_RFORELIMB, BL_LARM, BL_RARM, BL_LHAND, BL_RHAND, // arms
    BL_HEAD, BL_NECK, BL_TORSO, BL_ABDOMEN, BL_CROTCH, // center mass
    BL_LLEG, BL_RLEG, BL_LFOOT, BL_RFOOT, // legs
    BL_LWING, BL_RWING, BL_TAIL, // non-humanoid?
    BL_HEART, BL_LUNG, BL_SKIN, BL_LIVER, BL_STOMACH, BL_APPENDIX, BL_INTESTINE, BL_BRAIN, // organs
    BL_TEETH,
    BL_LFORECLAWS, BL_RFORECLAWS, BL_LAFTCLAWS, BL_RAFTCLAWS, // beast weapons
    BL_UNKNOWN, BL_NONE}; // ???

class Object{
public:
    CharString classname; // name of the class
    Location location; // generic location
};

#endif
