#include "Planet.h"

 Terrain::Terrain(long long seed, long long seed2) {
    this->seed = seed;
    this->seed2 = seed2;
    
     // generate radius
    std::seed_seq seedx{seed};
    std::mt19937 rng(seedx);    // random-number engine used 
    
    std::uniform_int_distribution<long> uni(1000, 300000); // radius of planet
    this->radius = uni(rng);
    
    // generate terrain eccentricity based on planet radius
    std::normal_distribution<> uni2(0, radius/140);
    this->eccentricity = uni2(rng);
}

Terrain::Terrain() {}

int Terrain::genRand(double phi, double theta){
    std::seed_seq seedx{(long long)seed, (long long)seed2, (long long)phi, (long long)theta};
    std::mt19937 rng(seedx);    // random-number engine used 
    std::normal_distribution<> uni(0, eccentricity);
    
    return uni(rng);
}

// Generate a single face, then save it.
void Terrain::generateFace(double rho, double phi, double theta, double delta, int suppress, vertex cameraloc){
    double rho2,phi2,theta2;
    
    // Generate face counter-clockwise
    theta2 = theta-delta;
    phi2 = phi-delta;
    
    rho2 = rho+genRand(phi, theta) / suppress;
    verticies.add(new vertex(rho2*Math::sin(phi)*Math::cos(theta), 
                            rho2*Math::sin(phi)*Math::sin(theta), 
                            rho2*Math::cos(phi)));
    
    rho2 = rho+genRand(phi, theta2) / suppress;
    verticies.add(new vertex(rho2*Math::sin(phi)*Math::cos(theta2), 
                            rho2*Math::sin(phi)*Math::sin(theta2), 
                            rho2*Math::cos(phi)));
    
    rho2 = rho+genRand(phi2, theta2) / suppress;
    verticies.add(new vertex(rho2*Math::sin(phi2)*Math::cos(theta2), 
                            rho2*Math::sin(phi2)*Math::sin(theta2), 
                            rho2*Math::cos(phi2)));
    
    rho2 = rho+genRand(phi2, theta) / suppress;
    verticies.add(new vertex(rho2*Math::sin(phi2)*Math::cos(theta), 
                            rho2*Math::sin(phi2)*Math::sin(theta), 
                            rho2*Math::cos(phi2)));
}

// Generate a region
// MIPLevel
// rho
void Terrain::generateRegion(int MIPLevel, double rho, double phi, double theta, double delta, int suppress, vertex cameraloc){
    
    if(MIPLevel <= 0) {
        generateFace(rho, phi, theta, delta, suppress, cameraloc);
    }else{
        // calculate 4 points for each face
        generateRegion(MIPLevel-1, rho, phi, theta, suppress+1, delta/2, cameraloc);
        generateRegion(MIPLevel-1, rho, phi, theta+delta, suppress+1, delta/2, cameraloc);
        generateRegion(MIPLevel-1, rho, phi+delta, theta+delta, suppress+1, delta/2, cameraloc);
        generateRegion(MIPLevel-1, rho, phi+delta, theta, suppress+1, delta/2, cameraloc);
    }
}

// get list of verticies based on MIPMap level
// Used in drawing functions
// MIPLevel determines the max depth to draw faces
void Terrain::generate(int MIPLevel, double radius, vertex cameraloc) {
    double pi2 = 2*physical::units::pi;
    double pid = pi2/16;
    double x,y,z, rho;
    
    //std::random_device rd;     // only used once to initialise (seed) engine
    

    // As you get closer to the planet, rand() will redraw the verticies.
    // redrawn verticies are relative to loc.


    // step through 0 to 2pi twice
    for(int phi=0; phi<pi2; phi+=pid) {
        for(int theta=0; theta<pi2; theta+=pid) {
            generateRegion(MIPLevel-1, radius, phi, theta, pid, 0, cameraloc);
        }
    }

    // perform smooth pass
}
