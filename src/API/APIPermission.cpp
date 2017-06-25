#include "APIPermission.h"

APIPermission::APIPermission(APIPermType type, CharString perm){
    this->type = type;
    this->perm = perm;
}
