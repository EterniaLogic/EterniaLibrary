#include "IModel.h"


void IModel::addPart(IModelPart* frag){
    parts.add(frag);
}

void IModel::setOffset(Math::vertex offset) {
    parts.freeze();
    for(int i=0; i<parts.frozenlen; i++) {
        parts.frozen[i]->setOffset(offset);
    }
}

void IModel::setScale(Math::vertex scale) {
    parts.freeze();
    for(int i=0; i<parts.frozenlen; i++) {
        parts.frozen[i]->setScale(scale);

    }
}
