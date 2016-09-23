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

class vertex{
public:
	double x;
        double y;
        double z;
	double ax; // Acceleration of x
        double ay; // Acceleration of y
        double az; // Acceleration of z
        double mass; // for use with physics
        double radius; // useful for sperical collision detection
        double velocity;
	long dimension; // Current Dimension (4, XYZt is default)

	vertex(double x,double y,double z);
        vertex();
        virtual ~vertex();

	vertex* operator =(vertex* b);
	vertex* operator +=(vertex* b);
 	vertex* operator +(vertex* b);
 	vertex* operator -(vertex* b);
 	vertex* operator *(vertex* b);
 	vertex* operator *(double b);
 	vertex* operator *(int b);
 	vertex* operator /(vertex* b);

        // convert to spherical coords
 	double getRoh(vertex* body);
 	double getPhi(vertex* body);
 	double getTheta(vertex* body);

	double dot(vertex* v2); // Dot-product
	vertex* cross(vertex* v2); // Cross-product
	vertex* unitVector(); // Directional vector
	void add(vertex* v2); // add with vertex
	void sub(vertex* v2);
	void scale(double scalar);
	void div(vertex* v2);
	void mul(vertex* v2);
	void set(double x, double y, double z);
	double angle(vertex* v2); // angle from v2 based on 0 deg (X-direction)
	double length(); // returns total distance between point and origin.
	double length2(); // returns total distance between point and origin powered by 2
	double distance(vertex* v2);

	// boolean functions to determine type.
	bool isOrthagonal(vertex* v); // returns whether this is orthagonal.

	// Advanced Linear Algebra inequalities
	// These are in-place, but have no apparent use.
	bool cauchySchwarzInequality(vertex* v); // abs(dot(u,v)) <= length(u)*length(v)
	bool triangleInequality(vertex* V); // length(u+v) <= length(u) + length(v)
	bool pythagroreanInequality(vertex* v); // length(u+v)^2 = length(u)^2 + length(v)^2


	//VectorSpace* addVectorSpace(vertex* b); // gets a vertex space from addition
	//VectorSpace* scaleVectorSpace(double scalar); // gets a vertex space from scaling
	//VectorSpace* getVectorSpace(); // gets a vertex space directly
};

#endif /*VECTOR_H_*/
