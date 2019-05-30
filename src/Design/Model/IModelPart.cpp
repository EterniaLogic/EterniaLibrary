#include "IModelPart.h"


IModelPart::IModelPart(){
    indexbuffer = -1;
    vertexbuffer = -1;
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
