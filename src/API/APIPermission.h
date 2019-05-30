#ifndef APIPERMISSION_H_
#define APIPERMISSION_H_

#include "../Data/CharString.h"

// What type of permission is this?
enum APIPermType {P_NONE, P_USER, P_GLOBAL, P_MOD, P_DB, P_API};

// USER permissions are for when modifying a user. USER "user.hit.fakeplayer"
// GLOBAL permissions affect the core API and server. GLOBAL "api.loadmod"
// MOD permissions allows users to use specific functionality from that mod. MOD "mod.testmod.command1"
// GLOBAL Mod restrictions '-mod.*.command.admin'   (Prevents all mods from using admin command)
// USER permissions == user.*.perm.*   (First * => username, second * = permission type)
// FULL Admin has GLOBAL '*' perm, modular admins would have "mod.testmod.*"

// Other syntax prefixes:
//  Overwrite '+':   '+mod.THISMOD.command.admin.*' overrides GLOBALs and group restrictions
//  Restrict  '-':   '-user.USERNAME.command.admin.*' overrides GLOBALs and any group given command listings


class APIPermission{
public:
    APIPermission(APIPermType type, CharString perm);
    APIPermType type;
    CharString perm;
};

#endif
