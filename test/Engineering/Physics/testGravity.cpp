

#include "testGravity.h"

#include <iostream>
#include <ctime>

using namespace physical::unit;

using namespace std;

void testGravity() {
    /*cout << "test [GravityTest]" << endl;
    cout << " -- Test Object going towards a planet (no atmosphere)" << endl;
    VertexObject cc;
    VertexObject Planet;

    Planet.mass = 5.97219e24 ; // kg
    Planet.radius = 6371; // km

    int chHeight = 6371;

    cc.mass = 150; // will always be in kilograms
    cc += vector(100000+chHeight, 0, 0); // meters away
    double cx = cc.x;

    double ii = 0;
    double time1 = clock()/CLOCKS_PER_SEC;
    double basetime = clock()/CLOCKS_PER_SEC;

    while(true) {
        //cout << time1-clock() << endl;
        double ctime = clock()/CLOCKS_PER_SEC;
        if(ctime-time1 > CLOCKS_PER_SEC) {
            time1=ctime;
            cout << "Accel: " << cc->ax << " m/s^2 --- Pos: " << cc->x << endl;
        }
        //cout << "Accel: " << cc->ax << " m/s^2 --- Pos: " << cc->x << endl;
        if(cc->distance(Planet) <= Planet->radius) {
            cout << "[Test Gravity] Object has successfully collided with Planet at " << cc->ax << " m/s" << endl;
            cout << "[Test Gravity] Object's starting position: ("<< (cx*kilometer) <<" meter)" << endl;
            cout << "[Test Gravity] Object1's mass: " << cc.mass << "kg, planet's mass: "<<Planet.mass <<"kg" << endl;
            cout << "[Test Gravity] Done!\n" << ii << " seconds!\n" << ii/60 << " minutes!\n" << ii/3600 << " hours!\n" << ii/(3600*24) << " days!"<< endl;
            break;
        }
        cc->gravitate(Planet,1); // 1 = 1 second of gravity
        cc->simSecond(); // do gravitation simulation
        ii++;
    }
    double totalTime = ((double)clock()/CLOCKS_PER_SEC) - basetime;
    cout << "[Test Gravity] Total Simulation Time: " << totalTime*1000 << " Milliseconds" << endl;
    cout << "[Test Gravity] Total Efficiency: " << (100-(ii/(totalTime*(double)CLOCKS_PER_SEC))*100) << "%" << endl;*/
}
