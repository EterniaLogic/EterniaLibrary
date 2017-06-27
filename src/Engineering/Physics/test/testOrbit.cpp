#include "testOrbit.h"

void testOrbit(){
    
    VertexObject* body = new VertexObject(0,0,0);
    body->radius = 6371000; // meters
    body->mass = 5.97219e24; // something like earth
    
    VertexObject* obj = new VertexObject(-(350000+body->radius), 10, 10);
    obj->radius = 20;
    obj->mass = 1; // 100kg
    
    Orbit orbit = Orbit(obj, body);
    
    orbit.printOut();
    
    orbit.circularize();
    
    //orbit.printOut();
    
    for(int i=0;i<1000;i++){
        orbit.simulate(1);
        orbit.printOut();
    }
}
