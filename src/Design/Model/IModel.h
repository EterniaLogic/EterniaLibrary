#ifndef OBJMODEL_H
#define OBJMODEL_H

#include "../../Math/Math.h"
#include "../../Data/CharString.h"
#include "../../Data/LinkedList.hpp"
#include "IModelPart.h"
#include "IMaterial.h"
#include "../IAnimated.h"

class IModel : public Math::VertexObject, public IAnimated{
        friend class IMaterial;
public:
    LinkedList<IModelPart*> parts; // fragments of this model. Can be used to move individual parts.
    CharString loadedloc; // model loaded from this location
    // Verticies are loaded into this.
    
    virtual void Draw();
    
    void addPart(IModelPart* frag);
    void setOffset(Math::vertex offset);
    void setScale(Math::vertex scale);
};


#endif
