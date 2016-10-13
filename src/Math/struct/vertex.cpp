//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "vertex.h"

using namespace Math; // ../Math.h


#define VECOP_IMP(op) vertex vertex::operator op(vertex b) { \
    vertex v; \
    v.x = this->x op b.x; \
    v.y = this->y op b.y; \
    v.z = this->z op b.z; \
    return v; \
} \
vertex vertex::operator op(double b) { \
    vertex v; \
    v.x = this->x op b; \
    v.y = this->y op b; \
    v.z = this->z op b; \
    return v; \
}

#define VECOP_IMP_EQ(op) void vertex::operator op(vertex b) { \
    this->x op b.x; \
    this->x op b.y; \
    this->x op b.z; \
} \
void vertex::operator op(double b) { \
    this->x op b; \
    this->x op b; \
    this->x op b; \
}


// pre-defines vertex's coordinates
vertex::vertex(double _x,double _y,double _z) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
    
    addSerial(&x,SSE_double);
    addSerial(&y,SSE_double);
    addSerial(&z,SSE_double);
}
vertex::vertex() {
    x=y=z=0;
    addSerial(&x,SSE_double);
    addSerial(&y,SSE_double);
    addSerial(&z,SSE_double);
}
vertex::~vertex() {  }


VertexObject::VertexObject(double _x,double _y,double _z) {
    this->x = _x;
    this->y = _y;
    this->z = _z;
    dimension = 0;
    
    addSerial(&velocity,SSE_SSerializer);
    addSerial(&acceleration,SSE_SSerializer);
    addSerial(&mass,SSE_double);
    addSerial(&dimension,SSE_double);
}
VertexObject::VertexObject() {
    x=y=z=0;
    dimension = 0;
    
    addSerial(&velocity,SSE_SSerializer);
    addSerial(&acceleration,SSE_SSerializer);
    addSerial(&mass,SSE_double);
    addSerial(&dimension,SSE_double);
}
VertexObject::~VertexObject() {  }


// Implementations via MACROs
VECOP_IMP(+)
VECOP_IMP(-)
VECOP_IMP(*)
VECOP_IMP(/)

VECOP_IMP_EQ(+=)
VECOP_IMP_EQ(-=)
VECOP_IMP_EQ(*=)
VECOP_IMP_EQ(/=)



// tick values
void VertexObject::tick(double second){
    // second is just a scalar
    velocity += (acceleration*second);
    *this += velocity*second;
}

// basic physics momentum
double VertexObject::gravitate(VertexObject body, double seconds) {
    //m3 kg-1 s-2

    //seconds act more like a scalar.

    //cout << "G=" << constants::G << " thisMass=" << this->mass << " EarthMass=" << body->mass << " distance="<<this->distance(body) << endl;
    double r = this->distance(body);
    double gForce = physical::constant::G * (this->mass * body.mass) / (r*r);
    double N = (gForce*1e-6)*seconds;
    double accel = N / this->mass; // acceleration to body

    //get directional VectorBody towards the body
    //get the difference between this and the body. (disposition)
    VertexObject disposition = body;
    disposition -= *this;
    vertex directionVector = disposition.unitVector();
    //cout << accel << " " << N << endl;

    *this -= directionVector*accel;
    //cout << directionVector -> x << endl;


    return accel*seconds;
}

void VertexObject::thrust(VertexObject thrust) {
    *this += thrust;
}

void VertexObject::simSecond() {
    //simulates exactly (1) second. mostly for debugging.
    *this += acceleration / physical::unit::kilometer;
    //cout << "Rect Velocity: (" << ax << "," << ay << "," << az << ") POS: " << x << "," << y << "," << z << endl;
}






// Get the rotational axis Ρ in 3rd-dimentional spherical coordinates
double getRoh(vertex body) {
    return Math::sqrt(Math::pow(body.x,2)+Math::pow(body.y,2)+Math::pow(body.z,2));
}

// Get the rotational axis Φ in 3rd-dimentional spherical coordinates
double getPhi(vertex body) { // Φ
    //acossin

    return 0;
}

// Get the rotational axis Θ in 3rd-dimentional spherical coordinates
double getTheta(vertex body) { // Θ


    return 0;
}



// get the dot product
double vertex::dot(vertex v2) {
    double sum = 0;
    sum += this->x*v2.x;
    sum += this->y*v2.y;
    sum += this->z*v2.z;
    return sum;
}

// get the cross product
vertex vertex::cross(vertex v2) {
    vertex rv;
    rv.x = this->y*v2.z - this->z*v2.y;
    rv.y = this->z*v2.x - this->x*v2.z;
    rv.z = this->x*v2.y - this->y*v2.x;
    return rv;
}

// get the magnitude of the vertex
double vertex::length() {
    return Math::sqrt(x*x + y*y + z*z);
}

// get the unit vertex (len = 1)
vertex vertex::unitVector() {
    vertex rv = *this;
    rv /= rv.length();
    return rv;
}

// get the angle of the vertex
double vertex::angle(vertex w) {
    // (v.w / |w|*|w|) * w
    return (this->dot(w) / (this->length() * w.length()));
}

// get the distance between two vertexs.
double vertex::distance(vertex v2) {
    vertex c =*this;
    c -= v2;
    return c.length();
}

// returns whether this is orthagonal.
bool vertex::isOrthagonal(vertex v) {
    //
    return dot(v) == 0;
}


// linear algebra
// abs(dot(u,v)) <= length(u)*length(v)
bool vertex::cauchySchwarzInequality(vertex v) {
    return Math::abs(dot(v)) <= length() * v.length();
}

// length(u+v) <= length(u) + length(v)
bool vertex::triangleInequality(vertex v) {
    return (*this+v).length() <= length() + v.length();
}

// length(u+v)^2 = length(u)^2 + length(v)^2
bool vertex::pythagroreanInequality(vertex v) {
    return Math::pow((*this+v).length(),2) <= ((length(),2) + pow(v.length(),2));
}







// directly convert to vertex space
/*VectorSpace* vertex::getVectorSpace(){
    // example: <a,b,c> =
    //          [ a ]
    //          [ b ]
    //          [ c ]
    // if d == 0, height = 2 -> [[a],[b]]
    int height = 3;
    if(z == 0) height = 2;

    // get double** via vertexspace
    double** matrix = Matrix::createMatrixContainer(height, 1);
    matrix[0][0] = x;
    matrix[1][0] = y;
    if(height == 2) matrix[2][0] = z;

    return new VectorSpace(matrix,height,1);
}*/



