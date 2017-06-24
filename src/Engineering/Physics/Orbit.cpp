#include "Orbit.h"


Orbit::Orbit(vertex *object, vertex *orbitBody){
    this->object = object;
    this->orbitBody = orbitBody;
}

vertex* Orbit::getObject(){
    return object;
}

vertex* Orbit::getBody(){
    return orbitBody;
}

double Orbit::getGravity(){
    return PhysicsEquations::getGravity(object->mass, orbitBody->mass, object->getDistance(orbitBody));
}

// Apoapsis relative to distance to center of orbitBody.
double Orbit::getApoapsis(){
    // Mu = physical::constant::G * BodyMass^2
    // E = v^2/2 - Mu/r
    // a = -Mu/(2*E)
    // ra=a(1+|e|)
    
/*  double dist = orbitBody->distance(object);
    double Mu = physical::constant::G * orbitBody->mass * orbitBody->mass;
    double E = pow(getVelocity(),2)/2 - Mu/(dist);
    double a = -Mu/(2*E);
    
    return a*(1 + getEccentricity());*/
}

// Periapsis relative to distance to center of orbitBody.
double Orbit::getPeriapsis(){
    // E = v^2/2 - Mu/r
    // a = -Mu/(2*E)
    // rp=a(1−|e|)
    
    /*  double dist = orbitBody->distance(object);
    double Mu = physical::constant::G * orbitBody->mass * orbitBody->mass;
    double E = pow(getVelocity(),2)/2 - Mu/(dist);
    double a = -Mu/(2*E);
    
    return a*(1 - getEccentricity());*/
}

// get relative orbital velocity.
double Orbit::getVelocity(){
    return object->velocity.magnitude() - orbitBody->velocity.magnitude();
}

// 0 => perfect orbit, 1 => flying out of sphere of influence.
double Orbit::getEccentricity(){
    //  e=(|v|^2*r)/Mu - ((r dot v)v)/Mu - r/|r|
}

// get longitude, assumes Poles are purely vertical...
double Orbit::getLongitude(){

}

// get latitude (-90 to 90 degrees)
double Orbit::getLatitude(){
    // calculate Latitude from object's location
}

double Orbit::getInclination(){

}

double Orbit::getOrbitAngle(){

}

// time in seconds for the orbit 360 degrees around the body.
double Orbit::getOrbitPeriod(){
    // find the circumference IF eccentricity 0 < c < 1
    
    if(getEccentricity() >= 1.0f || getEccentricity <= 0.0f) return 0.0f;
    
    // 
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

double Orbit::setEscapeVelocity(){
    setVelocity(sqrt((2.0f * physical::constant::G * orbitBody->mass * orbitBody->mass)/orbitBody->distance(*object)));
}




// for testing purposes unless using a single-body orbit system.
void Orbit::simulate(double seconds){
    object->gravitate(orbitBody, seconds);
    orbitBody->gravitate(object, seconds);
    
    // calculate positions
    object->tick(seconds);
    orbitBody->tick(seconds);
}


// N-Body orbit simulation!
// Convolution
static void Orbit::simulateNBody(LinkedList<vertex> objects, double time){
    objects.freeze();
    
    // set new velocity direction vector for objects
    for(int i=0; i<objects.frozenlen;i++){
        for(int j=0; j<objects.frozenlen;j++){
            if(i != j){
                objects.frozen[i].gravitate( objects.frozen[j], time );
            }
        }
    }
    
    // calculate new position of objects
    for(int i=0; i<objects.frozenlen;i++){
        objects.frozen[i].tick(time);
    }
}


