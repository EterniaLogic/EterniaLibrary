//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "vertex.h"

using namespace Math; // ../Math.h

float ubersignificant = 1.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000f;

// pre-defines vertex's coordinates
vertex::vertex(float _x,float _y,float _z){
	this->x = _x;
	this->y = _y;
	this->z = _z;
	dimension = 3;
}
vertex::vertex(){ dimension = 3; }

// add another vertex a+=b
vertex* vertex::operator +=(vertex* b){
	this->x += b->x;
	this->y += b->y;
	this->z += b->z;
	return new vertex(this->x, this->y, this->z);
}

// add with another vertex a+b
vertex* vertex::operator +(vertex* b){
	vertex* v = new vertex();
	v->x = this->x + b->x;
	v->y = this->y + b->y;
	v->z = this->z + b->z;
	return v;
}

// subtract with another vertex a-b
vertex* vertex::operator -(vertex* b){
	vertex* v = new vertex();
	v->x = this->x - b->x;
	v->y = this->y - b->y;
	v->z = this->z - b->z;
	return v;
}

// multiply with another vertex a*b
vertex* vertex::operator *(vertex* b){
	vertex* v = new vertex();
	v->x = this->x * b->x;
	v->y = this->y * b->y;
	v->z = this->z * b->z;
	return v;
}

// Scalar multiply
vertex* vertex::operator *(float b){
	vertex* v = new vertex();
	v->x = this->x * b;
	v->y = this->y * b;
	v->z = this->z * b;
	return v;
}

// Scalar multiply (integer)
vertex* vertex::operator *(int b){
	vertex* v = new vertex();
	v->x = this->x * b;
	v->y = this->y * b;
	v->z = this->z * b;
	return v;
}

// Divide with another vertex
vertex* vertex::operator /(vertex* b){
	vertex* v = new vertex();
	v->x = this->x / b->x;
	v->y = this->y / b->y;
	v->z = this->z / b->z;
	return v;
}

// Get the rotational axis Ρ in 3rd-dimentional spherical coordinates
float getRoh(vertex* body){ 
	return sqrt(pow(body->x,2)+pow(body->y,2)+pow(body->z,2));
}

// Get the rotational axis Φ in 3rd-dimentional spherical coordinates
float getPhi(vertex* body){ // Φ
	//acossin

	return 0;
}

// Get the rotational axis Θ in 3rd-dimentional spherical coordinates
float getTheta(vertex* body){ // Θ
	

	return 0;
}

// directly add another vertex to this. v+=v2
void vertex::add(vertex* v2){
	this->x += v2->x;
	this->y += v2->y;
	this->z += v2->z;
}

// directly subtract another vertex to this. v-=v2
void vertex::sub(vertex* v2){
	this->x -= v2->x;
	this->y -= v2->y;
	this->z -= v2->z;
}

// directly multiply another vertex to this. v*=v2
void vertex::mul(vertex* v2){
	this->x *= v2->x;
	this->y *= v2->y;
	this->z *= v2->z;
}

// directly divide another vertex to this. v/=v2
void vertex::div(vertex* v2){
	this->x /= v2->x;
	this->y /= v2->y;
	this->z /= v2->z;
}

// directly scale with a scalar.
void vertex::scale(float scalar){
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

// get the dot product
float vertex::dot(vertex* v2){
	float sum = 0;
	sum += this->x*v2->x;
	sum += this->y*v2->y;
	sum += this->z*v2->z;
	return sum;
}

// get the cross product
vertex* vertex::cross(vertex* v2){
	vertex* rv = new vertex(0,0,0);
	rv->x = this->y*v2->z - this->z*v2->y;
	rv->y = this->z*v2->x - this->x*v2->z;
	rv->z = this->x*v2->y - this->y*v2->x;
	return rv;
}

// get the magnitude of the vertex
float vertex::length(){
	return sqrt(x*x + y*y + z*z);
}

// get the unit vertex (len = 1)
vertex* vertex::unitVector(){
	vertex* rv = new vertex(0,0,0);
	rv->add(this);
	rv->scale(ubersignificant/rv->length());
	return rv;
}

// get the angle of the vertex
float vertex::angle(vertex* w){
	// (v.w / |w|*|w|) * w
	return (this->dot(w) / (this->length() * w->length()));
}

// get the distance between two vertexs.
float vertex::distance(vertex* v2){
	vertex* c = new vertex();
	c->add(this);
	c->sub(v2);
	float out = c->length();
	delete c;
	return out;
}

// returns whether this is orthagonal.
bool vertex::isOrthagonal(vertex* v){
    // 
    return dot(v) == 0;
}


// linear algebra
// abs(dot(u,v)) <= length(u)*length(v)
bool vertex::cauchySchwarzInequality(vertex* v){
    return abs(dot(v)) <= length() * v->length();
} 

// length(u+v) <= length(u) + length(v)
bool vertex::triangleInequality(vertex* v){
	vertex This = *this;
    return (*this+v)->length() <= length() + v->length();
}

// length(u+v)^2 = length(u)^2 + length(v)^2
bool vertex::pythagroreanInequality(vertex* v){
	vertex This = *this;
	return pow((*this+v)->length(),2) <= (length(),2) + pow(v->length(),2);
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
    
    // get float** via vertexspace
    float** matrix = Matrix::createMatrixContainer(height, 1);
    matrix[0][0] = x;
    matrix[1][0] = y;
    if(height == 2) matrix[2][0] = z;
    
    return new VectorSpace(matrix,height,1);
}*/



