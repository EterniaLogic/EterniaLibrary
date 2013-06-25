//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef VECTOR_H_
#define VECTOR_H_

//#include <math.h>
#include "../Functions/Basic.h"

/*#ifndef PLANET_H_
	#include "../objects/Planet.h"
#endif*/

class vector{
public:
	double x,y,z;
	double ax,ay,az,mass,radius,velocity; // Acceleration and resistance to momentum
	double dimension; // Current Dimension (4, XYZt is default)
	
	vector* operator =(vector* b);
	vector* operator +=(vector* b);
 	vector* operator +(vector* b);
 	vector* operator -(vector* b);
 	vector* operator *(vector* b);
 	vector* operator *(double b);
 	vector* operator *(int b);
 	vector* operator /(vector* b);
 	
 	double getRoh(vector* body);
 	double getPhi(vector* body);
 	double getTheta(vector* body);
	
	vector(double x ,double y,double z);
	vector();
	double dot(vector* v2); // Dot-product
	vector* cross(vector* v2); // Cross-product
	vector* unitVector();
	void add(vector* v2); // add with vector
	void sub(vector* v2);
	void scale(double scalar);
	void div(vector* v2);
	void mul(vector* v2);
	void set(double x, double y, double z);
	double angle(vector* v2); // angle from v2 based on 0 deg (X-direction)
	double length(); // returns total distance between point and origin.
	double length2(); // returns total distance between point and origin powered by 2
	double distance(vector* v2);
	
	// boolean functions to determine type.
	bool isOrthagonal(vector* v); // returns whether this is orthagonal.
	
	// Advanced Linear Algebra inequalities
	// These are in-place, but have no apparent use.
	bool cauchySchwarzInequality(vector* v); // abs(dot(u,v)) <= length(u)*length(v)
	bool triangleInequality(vector* V); // length(u+v) <= length(u) + length(v)
	bool pythagroreanInequality(vector* v); // length(u+v)^2 = length(u)^2 + length(v)^2
	
	
	//VectorSpace* addVectorSpace(vector* b); // gets a vector space from addition
	//VectorSpace* scaleVectorSpace(double scalar); // gets a vector space from scaling
	//VectorSpace* getVectorSpace(); // gets a vector space directly
};

#endif /*VECTOR_H_*/
