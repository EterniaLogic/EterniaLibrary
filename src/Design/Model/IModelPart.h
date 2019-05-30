#ifndef OBJMODELFRAGMENT_H_
#define OBJMODELFRAGMENT_H_

#include "../../Math/Math.h"
#include "../../Data/CharString.h"
#include "../../Data/LinkedList.hpp"

#include "IMaterial.h"

// Fragments are singular 'Models' in an OBJ file
class IModelPart{
public:
    IModelPart();
    virtual ~IModelPart(){}

    LinkedList<Math::vertex> verticies, normals, textureCoordinates;
    IMaterial material;
    CharString name, matname;

    int rendermode;
    int animFrame; // frame that the animation is on
    CharString animNum; // which animation is playing? (there can be many)

    Math::vertex offset, rotate_axis, scale;
    float rotate_angle;

    bool buffered; // using VBOs?
    unsigned int indexbuffer, vertexbuffer; // GLuint
    unsigned int vbosize;

    unsigned int *indices; // GLuint
    float *pvertex; // GLfloat




    virtual void draw();
    virtual void bufferModel(); // Buffer this model in the graphics card


    void addVertex(Math::vertex v);
    void setOffset(Math::vertex offset);
    void setScale(Math::vertex scale);
    void setMaterial(IMaterial material);

};

#endif
