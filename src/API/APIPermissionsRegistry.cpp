#include "APIPermissionsRegistry.h"

APIPermissionsRegistry::APIPermissionsRegistry(){

}
APIPermissionsRegistry::~APIPermissionsRegistry(){}

// register a user if it doesn't exist.
void APIPermissionsRegistry::registerUser(APIUser *user){
    // TODO: check if user can be registered or not, then register

	users.add(user);
}

bool APIPermissionsRegistry::userHasPermission(APIUser *user, APIPermission perm){
    return user->hasPermission(perm);
}
