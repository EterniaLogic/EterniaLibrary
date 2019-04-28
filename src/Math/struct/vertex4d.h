#ifndef V4D_H_
#define V4D_H_

// 4-space vertex
#include "../Functions/Basic.h"
#include "../Functions/Trig.h"
#include "../../constants.h"
#include <math.h>

// declare macros for common operators
#define VE4COP_DEC(op) vertex4d operator op(vertex4d b); \
    vertex4d operator op(double b)

#define VE4COP_DEC_EQ(op) void operator op(vertex4d b); \
    void operator op(double b)

#define VE4COP_DEC_COMP(op) bool operator op(vertex4d b); \
    bool operator op(double b)

namespace Math {
class vertex4d{
public:
    double w, x,y,z;
    
    vertex4d(double w, double x, double y, double z);
    vertex4d();
    virtual ~vertex4d();
    
    double dot(vertex4d v);
    double magnitude(); // same as length
    double length(); // returns total distance between point and origin
    double distance(vertex4d v2); // distance only in 3D
    
    double magnitude4d(); // magnitude from origin in 3D
    double length4d(); // returns total distance between point and origin in 4D.
    double distance4d(vertex4d v2); // distance in 4D
    
    
    
    VE4COP_DEC(+);
    VE4COP_DEC(-);
    VE4COP_DEC(*);
    VE4COP_DEC(/);

    VE4COP_DEC_EQ(+=);
    VE4COP_DEC_EQ(-=);
    VE4COP_DEC_EQ(*=);
    VE4COP_DEC_EQ(/=);

    VE4COP_DEC_COMP(==); // vertex or double compare
    VE4COP_DEC_COMP(!=);
};
}

#endif
