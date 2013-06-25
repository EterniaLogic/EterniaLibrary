//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef TERRAGEN_H_
#define TERRAGEN_H_

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


class TerraGen
{
public:
	TerraGen();
	virtual ~TerraGen();
};

#endif /*TERRAGEN_H_*/
