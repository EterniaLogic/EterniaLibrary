//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "vector.h"

using namespace Math; // ../Math.h

double ubersignificant = 1.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;

// pre-defines vector's coordinates
vector::vector(double _x,double _y,double _z){
	this->x = _x;
	this->y = _y;
	this->z = _z;
	dimension = 3;
}
vector::vector(){ dimension = 3; }

// add another vector a+=b
vector* vector::operator +=(vector* b){
	this->x += b->x;
	this->y += b->y;
	this->z += b->z;
	return new vector(this->x, this->y, this->z);
}

// add with another vector a+b
vector* vector::operator +(vector* b){
	vector* v = new vector();
	v->x = this->x + b->x;
	v->y = this->y + b->y;
	v->z = this->z + b->z;
	return v;
}

// subtract with another vector a-b
vector* vector::operator -(vector* b){
	vector* v = new vector();
	v->x = this->x - b->x;
	v->y = this->y - b->y;
	v->z = this->z - b->z;
	return v;
}

// multiply with another vector a*b
vector* vector::operator *(vector* b){
	vector* v = new vector();
	v->x = this->x * b->x;
	v->y = this->y * b->y;
	v->z = this->z * b->z;
	return v;
}

// Scalar multiply
vector* vector::operator *(double b){
	vector* v = new vector();
	v->x = this->x * b;
	v->y = this->y * b;
	v->z = this->z * b;
	return v;
}

// Scalar multiply (integer)
vector* vector::operator *(int b){
	vector* v = new vector();
	v->x = this->x * b;
	v->y = this->y * b;
	v->z = this->z * b;
	return v;
}

// Divide with another vector
vector* vector::operator /(vector* b){
	vector* v = new vector();
	v->x = this->x / b->x;
	v->y = this->y / b->y;
	v->z = this->z / b->z;
	return v;
}

// Get the rotational axis Ρ in 3rd-dimentional spherical coordinates
double getRoh(vector* body){ 
	return sqrt(pow(body->x,2)+pow(body->y,2)+pow(body->z,2));
}

// Get the rotational axis Φ in 3rd-dimentional spherical coordinates
double getPhi(vector* body){ // Φ
	//acossin

	return 0;
}

// Get the rotational axis Θ in 3rd-dimentional spherical coordinates
double getTheta(vector* body){ // Θ
	

	return 0;
}

// directly add another vector to this. v+=v2
void vector::add(vector* v2){
	this->x += v2->x;
	this->y += v2->y;
	this->z += v2->z;
}

// directly subtract another vector to this. v-=v2
void vector::sub(vector* v2){
	this->x -= v2->x;
	this->y -= v2->y;
	this->z -= v2->z;
}

// directly multiply another vector to this. v*=v2
void vector::mul(vector* v2){
	this->x *= v2->x;
	this->y *= v2->y;
	this->z *= v2->z;
}

// directly divide another vector to this. v/=v2
void vector::div(vector* v2){
	this->x /= v2->x;
	this->y /= v2->y;
	this->z /= v2->z;
}

// directly scale with a scalar.
void vector::scale(double scalar){
	this->x *= scalar;
	this->y *= scalar;
	this->z *= scalar;
}

// get the dot product
double vector::dot(vector* v2){
	double sum = 0;
	sum += this->x*v2->x;
	sum += this->y*v2->y;
	sum += this->z*v2->z;
	return sum;
}

// get the cross product
vector* vector::cross(vector* v2){
	vector* rv = new vector(0,0,0);
	rv->x = this->y*v2->z - this->z*v2->y;
	rv->y = this->z*v2->x - this->x*v2->z;
	rv->z = this->x*v2->y - this->y*v2->x;
	return rv;
}

// get the magnitude of the vector
double vector::length(){
	return sqrt(x*x + y*y + z*z);
}

// get the unit vector (len = 1)
vector* vector::unitVector(){
	vector* rv = new vector(0,0,0);
	rv->add(this);
	rv->scale(ubersignificant/rv->length());
	return rv;
}

// get the angle of the vector
double vector::angle(vector* w){
	// (v.w / |w|*|w|) * w
	return (this->dot(w) / (this->length() * w->length()));
}

// get the distance between two vectors.
double vector::distance(vector* v2){
	vector* c = new vector();
	c->add(this);
	c->sub(v2);
	double out = c->length();
	delete c;
	return out;
}

// returns whether this is orthagonal.
bool vector::isOrthagonal(vector* v){
    // 
    return dot(v) == 0;
}


// linear algebra
// abs(dot(u,v)) <= length(u)*length(v)
bool vector::cauchySchwarzInequality(vector* v){
    return abs(dot(v)) <= length() * v->length();
} 

// length(u+v) <= length(u) + length(v)
bool vector::triangleInequality(vector* v){
	vector This = *this;
    return (*this+v)->length() <= length() + v->length();
}

// length(u+v)^2 = length(u)^2 + length(v)^2
bool vector::pythagroreanInequality(vector* v){
	vector This = *this;
	return pow((*this+v)->length(),2) <= (length(),2) + pow(v->length(),2);
}







// directly convert to vector space
/*VectorSpace* vector::getVectorSpace(){
    // example: <a,b,c> = 
    //          [ a ]
    //          [ b ]
    //          [ c ]
    // if d == 0, height = 2 -> [[a],[b]]
    int height = 3;
    if(z == 0) height = 2;
    
    // get double** via vectorspace
    double** matrix = Matrix::createMatrixContainer(height, 1);
    matrix[0][0] = x;
    matrix[1][0] = y;
    if(height == 2) matrix[2][0] = z;
    
    return new VectorSpace(matrix,height,1);
}*/



