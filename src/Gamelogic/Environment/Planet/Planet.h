//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef PLANET_H_
#define PLANET_H_

//#include "../../Engineering/Chemistry/Composite.h"
#include "../../Math/struct/vertex.h"
#include "../../Data/LinkedList.hpp"
#include "../../constants.h"
#include "Ocean.h"

// SURFACE is the maximum possible closeness (i.e: <1000m)
// 1000 > x > 5000      MIP_NEAR
// 5000 > x > 65k       MIP_AIR
// 65k > x > 300k       MIP_ORBIT
// 300k > 30Mil         MIP_DOT (too small to see, just a dot)
//
enum MIPP {MIP_SURFACE,MIP_NEAR,MIP_AIR,MIP_ORBIT,MIP_FAR,MIP_DOT};

/*
 * Seed = single-template system that gets changes and converts it to a 3D Map. can only be
 * 		generated when using a TerrGen... any and all map changes will be saved to a new
 * 		seed.
 * 2-255 digits long, alphaneumeric.
 * 
 * [0] => Planet shape
 * [1] => Planet type
 * 
 * Please note that the seed system is also based on enviromental variables:
 * 		* Closeness to sun(s)
 *      * Race that controls it
 *      * # of moons & closeness (+size for gravitational shifts)
 */
class Terrain
{
	
};

class Atmosphere
{
public:
	//Composite* AtmosphericMaterials;// ppk materials, less-mass materials double up.
	double groundDensity; // density of atmosphere near ground. (M*V, km*m^3)
	double height; // max height (km)
	
	double getDensity(double relativeHeight); // returns current air density at location, relative to ground
};

class Planet : public vertex
{
    double seed; // seed for planet. (Randomly generated, or loaded from server)
public:
	Planet();
	virtual ~Planet();
	
	Atmosphere* atmosphere; // defines planetary atmosphere
	LinkedList<Terrain>* terrain; // defines terrain and oceans, ect.
	
	
	// get list of verticies based on MIPMap level
	// Used in drawing functions
	LinkedList<vertex>* listOfVerticies(int MIPLevel); 
	
	
	
	// Air friction is based on location in atmosphere the atmospheric gradient.
	// Very small number, since air is very light.
	double airFriction(vertex* object);
};

#endif /*PLANET_H_*/
