//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include "Atom.h"

enum STATE {solid, liquid, gas, plasma};

class AtomNode
{
public:
	AtomNode();
	Atom* atom;
	AtomNode* linkedNodes;
	int linkedNodeNum; // number of linked atomic nodes
};

class Composite
{
public:
	Composite();
	virtual ~Composite();
	
	STATE Type;
	double density; // used for stuff like atmospheres, ect.
	double totalMass; // total composite mass
};

#endif /*COMPOSITE_H_*/
