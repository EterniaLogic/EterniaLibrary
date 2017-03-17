#ifndef API_USER_H_
#define API_USER_H_

#include "../Serialization/SpecificSerializer.h"
#include "APIPermission.h"

// An API User may be a player, admin, virtual script provider.
//  The use for the API user here is to enable specific permissions and deny other
//  ones.


// API User details may be stored in files or a database.
// "Raw" saving to files may also use the Specific Serializer class.

class APIUser : public SpecificSerializer{
private:
    LinkedList<APIPermission> permissions;
public:
    APIUser();
    
    bool hasPermission(APIPermission* perm);
    
    bool addPermission(APIUser* user, APIPermission* perm); // returns false if that user does not have perms to add perms.
    bool removePermission(APIUser* user, APIPermission* perm); // returns false if that user does not have perms to remove perms.
};

#endif
