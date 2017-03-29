#ifndef APIPERMS_H_
#define APIPERMS_H_

#include "APIPermission.h"
#include "APIUser.h"

// The Permissions Registry allows administrators, modders, developers to have
//  better access for giving players specific permissions related to the game.

// For example, some permissions might be different between a Guild Leader and a guild member.
// Specific mods may also be limited with specific access within the API through here too.

class APIPermissionsRegistry{
private:
    LinkedList<APIUser> users;
public:
    APIPermissionsRegistry();
    virtual ~APIPermissionsRegistry();

    void registerUser(APIUser *user); // register a user if it doesn't exist.
    bool userHasPermission(APIUser *user, APIPermission perm);
};

#endif
