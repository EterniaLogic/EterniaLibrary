#ifndef OBJ_H
#define OBJ_H

// OBJ file generated by Blender or other rendering software
#include "../../Math/Math.h"
#include "../CharString.h"
#include "../LinkedList.hpp"
#include "../../Parsing/SimpleParser.h"
#include "../../Design/Model/IModel.h"
#include "../../Design/Model/IModelPart.h"
#include "../../Design/Model/IMaterial.h"

#include "MTL.h"


//#define COUT_MODEL_DEBUG

#ifdef COUT_MODEL_DEBUG
#define debugLogm(s) cout << s << endl; cout.flush()
#else
#define debugLogm(s)  //nothing
#endif

namespace OBJ{
IModel* loadFromFile(CharString fileloc);
}


#endif
