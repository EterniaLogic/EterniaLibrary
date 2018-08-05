#ifndef VECTOR_H_
#define VECTOR_H_

#include "../../Serialization/SpecificSerializer.h"
#include "../Functions/Basic.h"
#include "../Functions/Trig.h"
#include "../../constants.h"
#include <math.h>


#define NULL_VERTEX vertex(NAN,NAN,NAN)

#define VECOP_DEC(op) vertex operator op(vertex b); \
    vertex operator op(double b)

#define VECOP_DEC_EQ(op) void operator op(vertex b); \
    void operator op(double b)
  
#define VECOP_DEC_COMP(op) bool operator op(vertex b); \
    bool operator op(double b)


class vertex : public SpecificSerializer{
public:
    double x;
    double y;
    double z;

    vertex(double x,double y,double z);
    vertex();
    virtual ~vertex();

    vertex operator=(vertex b);

    VECOP_DEC(+);
    VECOP_DEC(-);
    VECOP_DEC(*);
    VECOP_DEC(/);

    VECOP_DEC_EQ(+=);
    VECOP_DEC_EQ(-=);
    VECOP_DEC_EQ(*=);
    VECOP_DEC_EQ(/=);
    
    VECOP_DEC_COMP(==);
    VECOP_DEC_COMP(!=);

    // convert to spherical coords
    double getPhi();
    double getTheta();

    double dot(vertex v2); // Dot-product
    vertex cross(vertex v2); // Cross-product
    
    vertex unitVector(); // Directional vector

    void rotate(double theta, double phi); // rotate this vector around the origin. (additive)

    double angle(vertex  v2); // angle from v2 based on 0 deg (X-direction)
    double magnitude(); // same as length
    double length(); // returns total distance between point and origin.
    double length2(); // returns total distance between point and origin powered by 2
    double distance(vertex  v2);

    // boolean functions to determine type.
    bool isOrthagonal(vertex v); // returns whether this is orthagonal.

    // Advanced Linear Algebra inequalities
    // These are in-place, but have no apparent use.
    bool cauchySchwarzInequality(vertex v); // abs(dot(u,v)) <= length(u)*length(v)
    bool triangleInequality(vertex V); // length(u+v) <= length(u) + length(v)
    bool pythagroreanInequality(vertex v); // length(u+v)^2 = length(u)^2 + length(v)^2

    const char* toString();
    
    //VectorSpace* addVectorSpace( b); // gets a vertex space from addition
    //VectorSpace* scaleVectorSpace(double scalar); // gets a vertex space from scaling
    //VectorSpace* getVectorSpace(); // gets a vertex space directly
};



class VertexObject : public vertex{
public:
    vertex velocity, acceleration;
    double dimension, mass, radius; // mass/radius for physics of basic center of mass

    VertexObject(double x,double y,double z);
    VertexObject();
    virtual ~VertexObject();

    double gravitate(VertexObject& body,  double time);
    double getGravity(VertexObject body, double height);
    
    // Place this object at a stable orbit around another.
    void setStableOrbit(VertexObject body, double eccentricity, bool CCW_orbit);
    
    void thrust(VertexObject thrust); // applies force

    void tick(double second); // tick for acceleration and velocity
    void simSecond();
};

#endif /*VECTOR_H_*/
