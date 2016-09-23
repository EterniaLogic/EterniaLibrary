//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef VECTORBODY_H_
#define VECTORBODY_H_
#include "../../../Math/struct/vertex.h"
#include "../../../constants.h"

class VectorBody : public vertex
{
public:
    VectorBody();
    VectorBody(double x ,double y,double z);
	double gravitate(VectorBody* body,  double time);
	void thrust(VectorBody* thrust); // applies force
		
	void tick(); // does operations that are over time (aka, Acceleration)
	void simSecond();
};

#endif /*VECTORBODY_H_*/
