#ifndef APIPERMISSION_H_
#define APIPERMISSION_H_

// What type of permission is this?
enum APIPermType {NONE, USER, GLOBAL, MOD, DB, API};

// USER permissions are for when modifying a user. USER "user.hit.fakeplayer"
// GLOBAL permissions affect the core API and server. GLOBAL "api.loadmod"
// MOD permissions allows users to use specific functionality from that mod. MOD "mod.testmod.command1"


// FULL Admin has '*' perm, modular admins would have "mod.testmod.*"

class APIPermission{
public:
    APIPermType type;
    CharString perm;
    
    APIPermission(APIPermType type, CharString perm);
};

#endif
