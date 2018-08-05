#ifndef COLLISION_H_
#define COLLISION_H_
#include "../../../Math/struct/vertex.h"

class Collision1D {
    public:
        Collision1D();
        VertexObject a1, b1; // two objects to collide.

        double* getPurelyElasticVelo(); // gets the resultant velocities.
        double getPurelyInelasticVelo(); // gets velocity of inelastic collision.

        double* getVelo(); // assumes that there is no pureness, get velo.
};

#endif /*COLLISION_H_*/
