//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "testGravity.h"

#include <iostream>

using namespace physical::unit;

using namespace std;

void testGravity(){
	VectorBody* cc = new VectorBody();
	VectorBody* Planet = new VectorBody();
	
	Planet -> mass = 5.97219e24 ; // kg
	Planet -> radius = 6371; // km
	
	int chHeight = 6371;
	
	cc -> mass = 150; // will always be in kilograms
	cc->add(new VectorBody(370000+chHeight, 0, 0));
	double cx = cc->x;
	
	double ii = 0;
	double time1 = clock()/CLOCKS_PER_SEC;
	double basetime = clock()/CLOCKS_PER_SEC;
	
	while(true){
		//cout << time1-clock() << endl;
		double ctime = clock()/CLOCKS_PER_SEC;
		if(ctime-time1 > 5*CLOCKS_PER_SEC){
			time1=ctime;
			cout << cc->ax << " m/s" << endl;
		}
		if(cc->distance(Planet) <= Planet->radius) {
			cout << "[Test Gravity] Object has successfully collided with Planet at " << cc->ax << " m/s" << endl;
			cout << "[Test Gravity] Object's starting position: ("<< (cx*kilometer) <<" meter)" << endl;
			cout << "[Test Gravity] Object1's mass: " << cc->mass << "kg, planet's mass: "<<Planet->mass <<"kg" << endl;
			cout << "[Test Gravity] Done!\n" << ii << " seconds!\n" << ii/60 << " minutes!\n" << ii/3600 << " hours!\n" << ii/(3600*24) << " days!"<< endl;
			break;
		}
		cc->gravitate(Planet,1);
		// infinitely propel object at y = 5 m/s
		//cc->thrust(new vector(0,5,0));
		cc->simSecond();
		ii++;
	}
	double totalTime = ((double)clock()/CLOCKS_PER_SEC) - basetime;
	cout << "[Test Gravity] Total Simulation Time: " << totalTime*1000 << " Milliseconds" << endl;
	cout << "[Test Gravity] Total Efficiency: " << (100-(ii/(totalTime*(double)CLOCKS_PER_SEC))*100) << "%" << endl;
}
