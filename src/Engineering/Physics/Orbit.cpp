#include "Orbit.h"


Orbit::Orbit(VertexObject *object, VertexObject *orbitBody){
    this->object = object;
    this->orbitBody = orbitBody;
}

VertexObject* Orbit::getObject(){
    return object;
}

VertexObject* Orbit::getBody(){
    return orbitBody;
}

// set the velocity based on distance to body
void Orbit::circularize(){
    // Mu = r*v^2
    // v = sqrt(Mu/r)
    // v = sqrt(G*M / r)
    
    double Mu = physical::constant::G * orbitBody->mass;
    double distance = object->distance(*orbitBody);
    
    setVelocity(sqrt(Mu / distance));
}


double Orbit::getGravity(){

    double distance = object->distance(*orbitBody);
    double g = PhysicsEquations::getGravity(object->mass, orbitBody->mass, distance);
    return g;
}

// Apoapsis relative to distance to center of orbitBody.
double Orbit::getApoapsis(){
    // Mu = physical::constant::G * orbitBody->mass
    // r = (object - orbitBody).magnitude();
    // E = v^2/2 - Mu/r
    // a = -Mu/(2*E)
    // ra=a(1+|e|)
    
    
    return getSemiMajorAxis() * (1 + Math::abs(getEccentricity()));
}

// Periapsis relative to distance to center of orbitBody.
double Orbit::getPeriapsis(){
    // Mu = physical::constant::G * orbitBody->mass
    // r = (object - orbitBody).magnitude();
    // E = v^2/2 - Mu/r
    // a = -Mu/(2*E)
    // ra=a(1+|e|)

    return getSemiMajorAxis() * (1 - Math::abs(getEccentricity()));
}

// get relative orbital velocity.
double Orbit::getVelocity(){
    return object->velocity.magnitude() - orbitBody->velocity.magnitude();
}

// 0 => perfect orbit, 1 => flying out of sphere of influence.
double Orbit::getEccentricity(){
    double Mu = physical::constant::G * orbitBody->mass;
    //  e=(|v|^2*r)/Mu - ((r dot v)v)/Mu - r/|r|
    
    vertex r = getLocalPosition();
    vertex v = object->velocity - orbitBody->velocity;
    
    vertex e1 = (r * pow(getVelocity(),2));
    vertex e2 = (v * r.dot(v)) / Mu;
    vertex e3 = r / r.magnitude();
    
    vertex e = e1 - e2 - e3;
    
    return e.magnitude();
}


double Orbit::getInclination(){
    // 1/tan(h.z/|h|)
    //      https://en.wikipedia.org/wiki/Orbital_inclination#Calculation
    
    vertex loc = *object - *orbitBody;
    double t = 1.0f/tan(loc.z/loc.magnitude());
    t *= 180;
    t /= Math::PI; // convert to degrees
    return t;
}

double Orbit::getOrbitAngle(){
    // somewhat simple spherical coordinates.
    vertex loc = *object - *orbitBody;
    double t = 1.0f/tan(loc.y/loc.x);
    t *= 180;
    t /= Math::PI; // convert to degrees
    return t;
}

// time in seconds for the orbit 360 degrees around the body.
double Orbit::getOrbitPeriod(){
    // determine if the eccentricity is shooting the object out of the SOI.
    if(getVelocity() > getEscapeVelocity()) return std::numeric_limits<double>::infinity();
    
    if(getEccentricity() >= 1.0f || getEccentricity() <= 0.0f) return std::numeric_limits<double>::infinity();
    
    // Mu = 4pi^2 * a^3 / T^2
    // 1/Mu = T^2 / (4pi^2*a^3)
    // T = sqrt((4pi^2*a^3)/Mu)
    
    double Mu = physical::constant::G * orbitBody->mass;
    double x = 4*pow(Math::PI,2) * pow(getSemiMajorAxis(),3);
    double T = sqrt(x / Mu);
    return T;
}

// calculate maximum range on object that the body's gravity will effect the object.
//  The sun is used here because it's relative gravity to earth is less than the gravity of the earth on an object close to earth.
//  https://en.wikipedia.org/wiki/Sphere_of_influence_(astrodynamics)
double Orbit::getBodySphereOfInfluence(vertex biggerBody){
    // a = semimajor axis (apoapsis?)
    // m/M = masses (object/body)
    // r_soi = a*(m/M)^(2/5)
    
    //              dist to sun   earth mass / sun mass  
    // EARTH SOI = 149600000 * ((5.97219×10^24) / (1.989×10^30))^(2÷5) = 924551 km
    // SUN SOI = 1000000000000000000×(((1.989×10^30)÷(   ))^(2÷5) = ????      ---- reference to milky way black hole
}

double Orbit::getSemiMajorAxis(){
    double Mu = physical::constant::G * orbitBody->mass;
    vertex r = getLocalPosition();
    vertex v = object->velocity - orbitBody->velocity;
    
    double E = pow(getVelocity(),2)/2.f - Mu/r.x - Mu/r.y - Mu/r.z; // energy
    return -Mu/(2*E); // Semi-Major Axis
}

vertex Orbit::getLocalPosition(){
    return *object - *orbitBody;
}

vertex Orbit::getAscendingNode(){

}

vertex Orbit::getDescendingNode(){

}

vertex Orbit::getPeriapsisNode(){

}

vertex Orbit::getApoapsisNode(){

}

double Orbit::getEscapeVelocity(){
    return sqrt((2 * physical::constant::G * orbitBody->mass * orbitBody->mass)/orbitBody->distance(*object));
}

// draw location for orbit line if applicable. Angle relative to perpendicular of the orbit.
vertex Orbit::getDrawLoc(double orbitAngle){

}







// set the relative velocity of the object
void Orbit::setVelocity(double v){
    // get object's relative unit vector * relative velocity
    vertex vel = object->unitVector() * v;
    
    // add global velocity of body
    object->velocity = vel + orbitBody->velocity;
}

// calculate relative velo from Apoapsis
void Orbit::setApoapsis(double a){
    // E = v^2/2 - Mu/r
    // a = -Mu/(2*E)
    // rp=a(1−|e|)
    
    // e=(|v|^2*r)/Mu - ((r dot v)v)/Mu - r/|r|
    
    double periapsis = getPeriapsis();
    
    if(a < periapsis) setPeriapsis(a);
    else{
    
    }
}

// calculate relative velo from Periapsis
void Orbit::setPeriapsis(double p){
    
    double apoapsis = getApoapsis();
    if(p > apoapsis) setApoapsis(p);
    else{
        
    }
}

// calculate relative velo from Eccentricity
void Orbit::setEccentricity(double e){
    
}

void Orbit::setInclination(double inc){
    
}

void Orbit::setOrbitAngle(double angle){
    
}

void Orbit::setEscapeVelocity(){
    setVelocity(sqrt((2.0f * physical::constant::G * orbitBody->mass * orbitBody->mass)/orbitBody->distance(*object)));
}




// for testing purposes unless using a single-body orbit system.
void Orbit::simulate(double seconds){
    object->gravitate(*orbitBody, seconds);
    orbitBody->gravitate(*object, seconds);
    
    // calculate positions
    object->tick(seconds);
    orbitBody->tick(seconds);
}


// N-Body orbit simulation!
// Convolution
void Orbit::simulateNBody(LinkedList<VertexObject> objects, double time){
    objects.freeze();
    
    // set new velocity direction vector for objects, simulate gravity
    for(int i=0; i<objects.frozenlen;i++){
        for(int j=0; j<objects.frozenlen;j++){
            if(i != j){
                VertexObject* body = objects.frozen[j];
                objects[i].gravitate(*body, time);
            }
        }
    }
    
    // calculate new position of objects
    for(int i=0; i<objects.frozenlen;i++){
        objects[i].tick(time);
    }
}


