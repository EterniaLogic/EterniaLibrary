//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef PLANET_H_
#define PLANET_H_

#include "../../Engineering/Chemistry/Composite.h"
#include "../../Math/struct/vector.h"
#include "Ocean.h"
#include "TerraGen.h"



class Terrain
{
	
};

class Atmosphere
{
public:
	Composite* AtmosphericMaterials;// ppk materials, less-mass materials float up.
	double groundDensity; // density of atmosphere near ground. (M*V, km*m^3)
	double height; // max height (km)
	
	double getDensity(double relativeHeight); // returns current air density at location, relative to ground
	
};

class Planet : public vector
{
public:
	Planet();
	virtual ~Planet();
	
	Atmosphere* atmosphere; //
	Terrain* terrain; // defines terrain and oceans, ect.
	vector* Objects; // any and all objects on planet (or at least the ones in view range)
	
	
	// Air friction is based on location in atmosphere the atmospheric gradient.
	double airFriction(vector* object);
};

#endif /*PLANET_H_*/
