#include "vertex4d.h"

// standard operator implementation for add/subtract
#define VE4COP_IMP(op) vertex4d vertex4d::operator op(vertex4d b) { \
    vertex4d v; \
    v.w = this->w op b.w; \
    v.x = this->x op b.x; \
    v.y = this->y op b.y; \
    v.z = this->z op b.z; \
    return v; \
} \
vertex4d vertex4d::operator op(double b) { \
    vertex4d v; \
    v.w = this->w op b; \
    v.x = this->x op b; \
    v.y = this->y op b; \
    v.z = this->z op b; \
    return v; \
}

// += or other operation
#define VE4COP_IMP_EQ(op) void vertex4d::operator op(vertex4d b) { \
    this->w op b.w; \
    this->x op b.x; \
    this->y op b.y; \
    this->z op b.z; \
} \
void vertex4d::operator op(double b) { \
    this->w op b; \
    this->x op b; \
    this->y op b; \
    this->z op b; \
}

// compare opteration
#define VE4COP_IMP_COMP(op) bool vertex4d::operator op(vertex4d b) { \
    return (x op b.x && y op b.y && z op b.z); \
} \
bool vertex4d::operator op(double b) { \
    return (x op b && y op b && z op b); \
}



namespace Math {
    // pre-defines vertex's coordinates
    vertex4d::vertex4d(double _w, double _x,double _y,double _z) {
        this->w = _w;
        this->x = _x;
        this->y = _y;
        this->z = _z;
    }
    vertex4d::vertex4d() {
        w=x=y=z=0;
    }

    vertex4d::~vertex4d() {}

    // get the dot product
    double vertex4d::dot(vertex4d v2) {
        double sum = 0;
        sum += this->w*v2.w;
        sum += this->x*v2.x;
        sum += this->y*v2.y;
        sum += this->z*v2.z;
        return sum;
    }


    // get the magnitude (same as length)
    double vertex4d::magnitude() {
        return length();
    }

    // get the magnitude of the vertex
    double vertex4d::length() {
        return sqrt(x*x + y*y + z*z);
    }
    
    // get the magnitude in 4D
    double vertex4d::magnitude4d() {
        return length4d();
    }

    // get the magnitude of the vertex
    double vertex4d::length4d() {
        return sqrt(w*w + x*x + y*y + z*z);
    }

    // get the distance between two vertexs.
    double vertex4d::distance(vertex4d v2) {
        vertex4d c = *this;
        c -= v2;
        c.w = this->w;
        return c.length();
    }
    
    // get the distance between two vertexes in 4D.
    double vertex4d::distance4d(vertex4d v2) {
        vertex4d c = *this;
        c -= v2;
        return c.length4d();
    }
    
    
    // Implementations via MACROs
    VE4COP_IMP(+)
    VE4COP_IMP(-)
    VE4COP_IMP(*)
    VE4COP_IMP(/)

    VE4COP_IMP_EQ(+=)
    VE4COP_IMP_EQ(-=)
    VE4COP_IMP_EQ(*=)
    VE4COP_IMP_EQ(/=)

    VE4COP_IMP_COMP(==) // vertex4d or double value
    VE4COP_IMP_COMP(!=)
}
