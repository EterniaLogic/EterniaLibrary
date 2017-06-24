#ifndef ORBIT_H_
#define ORBIT_H_

// Sampled orbit
#include "../../Math/struct/vertex.h"
#include "Equations.h"

// This enables orbit velocity manipulations and parameters.
//   - Not to be confused with N-body orbital simulations.
//   - Mostly used to calculate parameters between a single object and body.

//  ::: Static method for N-body simulation.


// angle and inclination are in degrees.


// REFERENCE    view-source:http://files.arklyffe.com/orbcalc.html
// https://en.m.wikipedia.org/wiki/Vis-viva_equation

class Orbit{
private:
    vertex *object, *orbitBody;
public:
    Orbit(vertex *object, vertex *orbitBody);
    
    vertex* getObject();
    vertex* getBody();
    
    
    // calculated values
    double getGravity();
    double getApoapsis(); // Apoapsis relative to distance to center of orbitBody.
    double getPeriapsis(); // Periapsis relative to distance to center of orbitBody.
    double getVelocity(); // get relative orbital velocity.
    double getEccentricity(); // 0 => perfect orbit, 1 => flying out of sphere of influence.
    double getLongitude(); // get longitude (0 -> 360 degrees)
    double getLatitude(); // get latitude (-90 to 90 degrees)
    double getInclination();
    double getOrbitAngle();
    double getOrbitPeriod(); // time in seconds for the orbit 360 degrees around the body.
    double getBodySphereOfInfluence(vertex biggerBody); // calculate maximum range on object that the body's gravity will effect the object. https://en.wikipedia.org/wiki/Sphere_of_influence_(astrodynamics)
    double getEscapeVelocity();
    
    // Global locations for nodes
    vertex getAscendingNode(); 
    vertex getDescendingNode();
    vertex getPeriapsisNode(); 
    vertex getApoapsisNode();
    vertex getDrawLoc(double orbitAngle); // draw location for orbit line if applicable. Angle relative to perpendicular of the orbit.
    
    
    
    void setVelocity(double v); // set the relative velocity of the object
    void setApoapsis(double a); // calculate relative velo from Apoapsis
    void setPeriapsis(double p); // calculate relative velo from Periapsis
    void setEccentricity(double e); // calculate relative velo from Eccentricity
    void setInclination(double inc); // move object to inclination
    void setOrbitAngle(double angle); // move object to angle in orbit
    void setEscapeVelocity();
    
    // for testing purposes unless using a single-body orbit system.
    void simulate(double seconds);
    
    
    // N-Body orbit simulation!
    static void simulateNBody(LinkedList<vertex> object, double time);
};

#endif
