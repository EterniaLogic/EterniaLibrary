#include "APIPermissionsRegistry.h"

APIPermissionsRegistry::APIPermissionsRegistry(){

}
APIPermissionsRegistry::~APIPermissionsRegistry(){}

// register a user if it doesn't exist.
void APIPermissionsRegistry::registerUser(APIUser *user){

}

bool APIPermissionsRegistry::userHasPermission(APIUser *user, APIPermission perm){
    return user->hasPermission(perm);
}
