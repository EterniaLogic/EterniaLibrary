

#include "vertex.h"
//using namespace Math; // ../Math.h


#define VECOP_IMP(op) vertex vertex::operator op(vertex b) { \
    vertex v; \
    v.x = this->x op b.x; \
    v.y = this->y op b.y; \
    v.z = this->z op b.z; \
    return v; \
} \
vertex vertex::operator op(double b) { \
    vertex v; \
    v.x = this->x op b; \
    v.y = this->y op b; \
    v.z = this->z op b; \
    return v; \
}

#define VECOP_IMP_EQ(op) void vertex::operator op(vertex b) { \
    this->x op b.x; \
    this->y op b.y; \
    this->z op b.z; \
} \
void vertex::operator op(double b) { \
    this->x op b; \
    this->y op b; \
    this->z op b; \
}

#define VECOP_IMP_COMP(op) bool vertex::operator op(vertex b) { \
    return (x op b.x && y op b.y && z op b.z); \
} \
bool vertex::operator op(double b) { \
    return (x op b && y op b && z op b); \
}

namespace Math {

    // pre-defines vertex's coordinates
    vertex::vertex(double _x,double _y,double _z) {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        
        //cout << "Add vertex" << endl; cout.flush();
        clearSerial();
        addSerial(&x,"x",SSE_double);
        addSerial(&y,"y",SSE_double);
        addSerial(&z,"z",SSE_double);
    }
    vertex::vertex() {
        x=y=z=0;
        
        //cout << "Add vertex 0" << endl; cout.flush();
        clearSerial();
        addSerial(&x,"x",SSE_double);
        addSerial(&y,"y",SSE_double);
        addSerial(&z,"z",SSE_double);
    }

    vertex::~vertex() { 
        //cout << "vertex destroy..." << endl; cout.flush();
    }


    VertexObject::VertexObject(double _x,double _y,double _z) {
        this->x = _x;
        this->y = _y;
        this->z = _z;
        dimension = 0;
        
        addSerial(&velocity,"velocity",SSE_SSerializer);
        addSerial(&acceleration,"acceleration",SSE_SSerializer);
        addSerial(&mass,"mass",SSE_double);
        addSerial(&dimension,"dimension",SSE_double);
    }
    VertexObject::VertexObject() {
        x=y=z=0;
        dimension = 0;
        
        addSerial(&velocity,"velocity",SSE_SSerializer);
        addSerial(&acceleration,"acceleration",SSE_SSerializer);
        addSerial(&mass,"mass",SSE_double);
        addSerial(&dimension,"dimension",SSE_double);
    }
    VertexObject::~VertexObject() {  }


    vertex vertex::operator=(vertex b){
        this->x = b.x;
        this->y = b.y;
        this->z = b.z;
        return *this;
    }

    // Implementations via MACROs
    VECOP_IMP(+)
    VECOP_IMP(-)
    VECOP_IMP(*)
    VECOP_IMP(/)

    VECOP_IMP_EQ(+=)
    VECOP_IMP_EQ(-=)
    VECOP_IMP_EQ(*=)
    VECOP_IMP_EQ(/=)

    VECOP_IMP_COMP(==)
    VECOP_IMP_COMP(!=)



    // theta, phi in radians
    // rotate the vertex around the origin.
    void vertex::rotate(double theta_, double phi_){
        // convert rectangular to polar coordinates
        double rho = length();
        double theta = Math::atan(y/x);
        double phi = Math::atan(Math::sqrt(x*x+y*y)/z);
        
        // add theta and phi
        theta += theta_;
        phi += phi_;
        
        // convert back to rectangular.
        x = rho*Math::sin(phi)*Math::cos(theta);
        y = rho*Math::sin(phi)*Math::sin(theta);
        z = rho*Math::cos(phi);
    }


    // get the Theta based on origin
    double vertex::getTheta(){
        return Math::atan(y/x);
    }

    // get the Phi based on origin
    double vertex::getPhi(){
        return Math::atan(sqrt(x*x+y*y)/z);;
    }


    // get the dot product
    double vertex::dot(vertex v2) {
        double sum = 0;
        sum += this->x*v2.x;
        sum += this->y*v2.y;
        sum += this->z*v2.z;
        return sum;
    }

    // get the cross product
    vertex vertex::cross(vertex v2) {
        vertex rv;
        rv.x = this->y*v2.z - this->z*v2.y;
        rv.y = this->z*v2.x - this->x*v2.z;
        rv.z = this->x*v2.y - this->y*v2.x;
        return rv;
    }

    // get the magnitude (same as length)
    double vertex::magnitude() {
        return length();
    }

    // get the magnitude of the vertex
    double vertex::length() {
        return sqrt(x*x + y*y + z*z);
    }

    // get the unit vertex (len = 1)
    vertex vertex::unitVector() {
        vertex rv = *this;
        rv /= rv.length();
        return rv;
    }

    // get the angle of the vertex
    double vertex::angle(vertex w) {
        // (v.w / |w|*|w|) * w
        return (this->dot(w) / (this->length() * w.length()));
    }

    // get the distance between two vertexs.
    double vertex::distance(vertex v2) {
        vertex c =*this;
        c -= v2;
        return c.length();
    }

    // returns whether this is orthagonal.
    bool vertex::isOrthagonal(vertex v) {
        //
        return dot(v) == 0;
    }


    // linear algebra
    // abs(dot(u,v)) <= length(u)*length(v)
    bool vertex::cauchySchwarzInequality(vertex v) {
        return Math::abs(dot(v)) <= length() * v.length();
    }

    // length(u+v) <= length(u) + length(v)
    bool vertex::triangleInequality(vertex v) {
        return (*this+v).length() <= length() + v.length();
    }

    // length(u+v)^2 = length(u)^2 + length(v)^2
    bool vertex::pythagroreanInequality(vertex v) {
        return Math::pow((*this+v).length(),2) <= ((length(),2) + pow(v.length(),2));
    }

    const char* vertex::toString() {
        string str = "";
        char *buf;
        size_t sz = snprintf(NULL,0,"(%.3e, %.3e, %.3e)", x, y, z);
        buf = (char*)malloc(sz+1);
        snprintf(buf, sz+1, "(%.3e, %.3e, %.3e)", x, y, z);
        return (const char*)buf;
    }







    // tick values
    void VertexObject::tick(double second){
        // second is just a scalar
        velocity += (acceleration*second);
        *this += velocity*second;
    }

    // basic physics momentum
    double VertexObject::gravitate(VertexObject& body, double seconds) {
        //m3 kg-1 s-2

        //seconds act more like a scalar.

    //    cout << "G=" << physical::constants::G << " thisMass=" << this->mass << " EarthMass=" << body.mass << " distance="<<this->distance(body) << endl;
        double r = this->distance(body);
        double gForce = getGravity(body, r) * seconds;
        //double N = gForce * mass;

        //get directional VectorBody towards the body
        //get the difference between this and the body. (disposition)
        VertexObject disposition = body;
        disposition -= *this;
        vertex directionVector = disposition.unitVector();
        //cout << gForce << " " << N << endl;

        /**this -= directionVector*gForce;
        cout << directionVector.x << endl;*/

        this->velocity += directionVector*gForce;
        //cout << "v = " << velocity.x << ", " << velocity.y << ", " << velocity.z << " " << directionVector.x << "," << directionVector.y << "," << directionVector.z << endl;

        return gForce*seconds;
    }

    double VertexObject::getGravity(VertexObject body, double distance){
        return physical::constant::G * (body.mass) / (distance*distance);
    }

    // Place this object at a stable orbit around another.
    // inclination above 90* will be counter-clockwise
    // inclination is relative to the position of this object. 
    // If the object is directly above a planet, the inclination is 90 "for that planet"
    void VertexObject::setStableOrbit(VertexObject body, double eccentricity, bool CCW_orbit){
        // v = sqrt(gm/h)   <-- assumes eccentricity = 0
        double distance = this->distance(body);
        double apoapsis = distance/Math::sqrt(1-eccentricity*eccentricity); // b = a*sqrt(1-e^2)
        double mu = getGravity(body, distance) * body.mass;
        
        
        // eccentricity equation
        // mu = GM
        // a = distance of apoapsis
        double v = sqrt((double)(mu*(2/distance - 1/apoapsis)));
        
        // determine the vector for the orbit velocity
        vertex localvector = *this - body;
        vertex up(0,1,0); // upward vector, rotated based on local position.
        if(!CCW_orbit) up *= -1;
        
        // rotate up vector
        up.rotate(getTheta(), getPhi());
        
        // do final cross & unit value * velocity
        this->velocity = localvector.cross(up).unitVector() * v;
    }

    void VertexObject::thrust(VertexObject thrust) {
        *this += thrust;
    }

    void VertexObject::simSecond() {
        //simulates exactly (1) second. mostly for debugging.
        *this += acceleration / physical::unit::kilometer;
        //cout << "Rect Velocity: (" << ax << "," << ay << "," << az << ") POS: " << x << "," << y << "," << z << endl;
    }












    // directly convert to vertex space
    /*VectorSpace* vertex::getVectorSpace(){
        // example: <a,b,c> =
        //          [ a ]
        //          [ b ]
        //          [ c ]
        // if d == 0, height = 2 -> [[a],[b]]
        int height = 3;
        if(z == 0) height = 2;

        // get double** via vertexspace
        double** matrix = Matrix::createMatrixContainer(height, 1);
        matrix[0][0] = x;
        matrix[1][0] = y;
        if(height == 2) matrix[2][0] = z;

        return new VectorSpace(matrix,height,1);
    }*/

}

