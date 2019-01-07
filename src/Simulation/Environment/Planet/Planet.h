#ifndef PLANET_H_
#define PLANET_H_


#include "../../../Data/includes.h"
#include "../../../constants.h"
#include "../../../Math/Random.hpp"

#include "../Space/SolarObject.h"
#include "Ocean.h"
#include "Moon.h"

// SURFACE is the maximum possible closeness (i.e: <1000m)
// 1000 > x > 5000      MIP_NEAR
// 5000 > x > 65k       MIP_AIR
// 65k > x > 300k       MIP_ORBIT
// 300k > 30Mil         MIP_DOT (too small to see, just a dot)
//
enum MIPP {MIP_SURFACE,MIP_NEAR,MIP_AIR,MIP_ORBIT,MIP_FAR,MIP_DOT};

namespace PlType {
    enum ss {Barren=1, Ice=2, Earth=3, Gas=4, Lava=5, Ocean=6, ANY=-1};
};

namespace PlSize{
    enum sss {Dwarf=1, Normal=2, Super=3, Giant=4, ANY=-1};
};


/*
 * Seed = single-template system that gets changes and converts it to a 3D Map. can only be
 *      generated when using a TerrGen... any and all map changes will be saved to a new
 *      seed.
 * 2-255 digits long, alphaneumeric.
 *
 * [0] => Planet shape
 * [1] => Planet type
 *
 * Please note that the seed system is also based on enviromental variables:
 *      * Closeness to sun(s)
 *      * Race that controls it
 *      * # of moons & closeness (+size for gravitational shifts)
 */
class Terrain {
private:
    long long seed, seed2; // seed for planet. (Randomly generated, or loaded from server)
    unsigned int radius;
    int eccentricity; // how flat is the terrain?
    LinkedList<vertex> verticies;
public:
    Terrain(long long seed, long long seed2);
    Terrain();

    // get list of verticies based on MIPMap level
    // Used in drawing functions
    int genRand(double phi, double theta);
    void generateFace(double rho, double phi, double theta, double delta, int suppress, vertex cameraloc);
    void generateRegion(int MIPLevel, double rho, double phi, double theta, double delta, int suppress, vertex cameraloc);
    void generate(int MIPLevel, double radius, vertex cameraloc);
};

class Atmosphere {
private:
    long long seed, seed2;
    double groundDensity; // density of atmosphere near ground. (M*V, km*m^3)
    double height; // max height (km)
public:
    Atmosphere(long long seed, long long seed2);
    Atmosphere();
    virtual ~Atmosphere();
    
    //Composite AtmosphericMaterials; // ppk materials, less-mass materials double up.
    

    double getDensity(double relativeHeight); // returns current air density at location, relative to ground
};



class Planet : public SolarObject {
private:
    
    Math::Random r;
    
    const double earthmass = 5.97237e24; // kg
	const double plutomass = 1.303e22; // kg
	const double uranusmass = 8.6810e25; // kg
	const double jupitermass = 1.8982e27; // kg
	const double km = 1e3; // kilometer
public:
    // two seeds of supposedly 64-bit length numbers should make for a good variation in the number of available planets.
    // note that this only works with 64-bit and a 32-bit system would lose it's advantages.
    Planet(long long seed, long long seed2, double luminosity);
    virtual ~Planet();
    
    void classifyPlanet();
    bool canTerraform();
    bool canLive();
    
    
    bool haswater, hasoxygen, hasice;
    double solarIrradiance, waterheight;
    double luminosity;
	double atmosphere; // percentage relevant to earth (Simplified, does not include elemental compositions)
	
	
    
	int type;
	int size;
    long long seed, seed2;
    
    //Atmosphere atmosphere; // defines planetary atmosphere
    Terrain terrain; // defines terrain and oceans, ect.
};

#endif /*PLANET_H_*/
