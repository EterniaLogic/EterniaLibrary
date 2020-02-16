#include "IModelPart.h"


IModelPart::IModelPart(){
    indexbuffer = -1;
    vertexbuffer = -1;
    pvertex=0x0;
    indices=0x0;
    vbosize=0;
    buffered=false;
    animFrame=0;
    rendermode=0;
    rotate_angle=0;

}

IModelPart::~IModelPart(){}

void IModelPart::addVertex(Math::vertex v) {
    //debugLogm("Add Model " << this << " Vertex: (" << v.x << ", "<< v.y <<"," << v.z<<")");
    this->verticies.add(v);
}


void IModelPart::setOffset(Math::vertex offset) {
    this->offset = offset;
}

void IModelPart::setMaterial(IMaterial material) {
    this->material = material;
}

void IModelPart::setScale(Math::vertex scale) {
    this->scale = scale;
}

void IModelPart::draw(){}
void IModelPart::bufferModel(){}
