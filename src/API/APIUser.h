#ifndef API_USER_H_
#define API_USER_H_

#include "../Serialization/SpecificSerializer.h"
#include "APIPermission.h"
#include "../Data/includes.h"

class APIGroup;
#include "APIGroup.h" // Cyclic reference?

// An API User may be a player, admin, virtual script provider.
//  The use for the API user here is to enable specific permissions and deny other
//  ones.


// API User details may be stored in files or a database.
// "Raw" saving to files may also use the Specific Serializer class.

class APIUser : public SpecificSerializer{
protected:
    LinkedList<APIGroup*> group; // user-groups, inherits permissions from First to last in list. (First Group has priority over last group)
    
    LinkedList<APIPermission*> permissions; // +user.USERNAME.? ('+user.Dread.command.admin.ban' enables Dread to use a ban command)
    LinkedList<APIPermission*> restrictions; // -user.USERNAME.?  ('-user.Dread.action.use.axe' prevents Dread from using an axe)
    HashMap<bool> pGLOBAL,pUSER,pMOD,pDB,pAPI; // primary speed increases

    CharString name;
    APIPermType permscope; // APIUser uses P_USER, but a MOD uses P_MOD.
public:
    APIUser();
    APIUser(CharString name); // load from file or w/e
    virtual ~APIUser();

    bool hasPermission(APIPermission perm); // Checks groups after checking personal permissions.

    bool addPermission(APIUser* user, APIPermission* perm); // returns false if that user does not have perms to add perms to this user.
    bool removePermission(APIUser* user, APIPermission* perm); // returns false if that user does not have perms to remove perms.
};

#endif
