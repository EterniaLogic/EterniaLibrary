//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "VectorBody.h"
#include <iostream>
#include <ctime>

using namespace physical::unit;
using namespace std;


VectorBody::VectorBody(double _x,double _y,double _z){
	this->x = _x;
	this->y = _y;
	this->z = _z;
}
VectorBody::VectorBody(){}

// basic physics momentum
double VectorBody::gravitate(VectorBody* body, double seconds){
	//m3 kg-1 s-2
	
	//seconds act more like a scalar.
	
	//cout << "G=" << constants::G << " thisMass=" << this->mass << " EarthMass=" << body->mass << " distance="<<this->distance(body) << endl;
	double r = this->distance(body);
	double gForce = physical::constant::G * (this->mass * body->mass) / (r*r);
	double N = (gForce*1e-6)*seconds;
	double accel = N / this->mass; // acceleration to body
	
	//get directional VectorBody towards the body
	//get the difference between this and the body. (disposition)
	VectorBody* disposition = new VectorBody();
	
	disposition->add(body);
	disposition->sub(this);
	vertex* directionVector = disposition->unitVector();
//	cout << accel << " " << N << endl;
	directionVector->scale(accel);
	this->ax += directionVector->x;
	this->ay += directionVector->y;
	this->az += directionVector->z;
	//cout << directionVector -> x << endl;
	
	
	delete disposition;
	delete directionVector;
		
	return accel*seconds;
}

void VectorBody::thrust(VectorBody* thrust){
	this->add(thrust);
}

void VectorBody::simSecond(){
	//simulates exactly (1) second. mostly for debugging.
	this->x += ax/kilometer;
	this->y += ay/kilometer;
	this->z += az/kilometer;
	//cout << "Rect Velocity: (" << ax << "," << ay << "," << az << ") POS: " << x << "," << y << "," << z << endl;
}

double ltime=0;
void VectorBody::tick(){
	// * determines gravity with other objects
	// * Applies Acceleration and figures out velocity, position, angular velo and position.
	
	double dtime = (ltime-clock())/1000000; // time diff in milliseconds
	double secondstime = dtime/1000;
	
	// do tick!

	ltime = clock();
}
