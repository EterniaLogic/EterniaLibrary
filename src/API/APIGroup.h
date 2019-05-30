#ifndef APIGROUP_H_
#define APIGROUP_H_

#include "../Serialization/SpecificSerializer.h"
#include "APIPermission.h"
#include "../Data/includes.h"

class APIUser;
#include "APIUser.h" // Cyclic dependencies

// API Groups are inherrited by either mods or users. The groups are like templates
//  where all user permissions or restrictions are inherrited.

class APIGroup : public SpecificSerializer{
private:
    LinkedList<APIGroup*> group; // Sub-group inherited permissions/restrictions
    
    LinkedList<APIPermission*> permissions; // +user.USERNAME.? ('+user.Dread.command.admin.ban' enables Dread to use a ban command)
    LinkedList<APIPermission*> restrictions; // -user.USERNAME.?  ('-user.Dread.action.use.axe' prevents Dread from using an axe)
    HashMap<bool> pGLOBAL,pUSER,pMOD,pDB,pAPI; // primary speed increases
    
    APIPermType permscope; // APIGroup User group uses P_USER, but an APIGroup MOD group uses P_MOD.
public:
    
    APIGroup();
    APIGroup(CharString name);
    
    bool hasPermission(APIPermission perm); // Checks groups after checking personal permissions.

    // a user can use a command to add perms to a group. (The GLOBAL is the all-seeing eye so it doesn't need permissions to do so)
    bool addPermission(APIUser* user, APIPermission* perm); // returns false if that user does not have perms to add perms to this user.
    bool removePermission(APIUser* user, APIPermission* perm); // returns false if that user does not have perms to remove perms.
};

#endif
