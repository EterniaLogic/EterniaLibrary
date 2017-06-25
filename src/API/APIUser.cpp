#include "APIUser.h"
APIUser::APIUser(){
    permscope=P_USER;
}
APIUser::~APIUser(){}

bool testHashedPerm(bool* val){
    if(val == 0x0) return false;
    return *val;
}

bool APIUser::hasPermission(APIPermission perm){
    // first check if the user has global perms (i.e: superuser)

    if(testHashedPerm(pGLOBAL.get(CharString("*",1)))){
        return true; // is a global user!
    }

    //TODO: test based on type, modify perm string to test all possibilities.
}

// returns false if that user does not have perms to add perms.
bool APIUser::addPermission(APIUser* user, APIPermission* perm){
    CharString permx;
    // If username is not defined, just use a wildcard requirement.
    if(name.getSize() > 0) permx.concata(this->name);
    else permx.concata("*",1);
    permx.concata(".perm.add");

    if(user->hasPermission(APIPermission(permscope,permx))){
        permissions.add(perm);

        bool* value = (bool*)malloc(sizeof(bool));
        *value = true;
        // Add to specific map.
        // address 0x0 = false, 0x1 = true.
        switch(perm->type){
            case P_GLOBAL:
                    pGLOBAL.add(perm->perm,value);
                break;
            case P_USER:
                    pUSER.add(perm->perm,value);
                break;
            case P_MOD:
                    pMOD.add(perm->perm,value);
                break;
            case P_DB:
                    pDB.add(perm->perm,value);
                break;
            case P_API:
                    pAPI.add(perm->perm,value);
                break;
        }
        return true;
    }else return false;
}

// returns false if that user does not have perms to remove perms.
bool APIUser::removePermission(APIUser* user, APIPermission* perm){
    CharString permx;
    // If username is not defined, just use a wildcard requirement.
    if(name.getSize() > 0) permx.concata(this->name);
    else permx.concata("*",1);
    permx.concata(".perm.remove");

    // TODO: Set up multiple perm lists...
    if(user->hasPermission(APIPermission(permscope,permx))){

        return true;
    }else return false;
}
