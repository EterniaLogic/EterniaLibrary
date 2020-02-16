The API (Application Program Interface) allows for a programming language, User, Mod or permission to be monitored and restricted.

System enables for plug-and-play usage of connectable module programs, such as scripts. (Actual languages must be implemented as a APIMod, see [example](https://github.com/EterniaLogic/EterniaEngine/blob/master/src/Scripts/Java.h))

Plug-and-play mods run in separate containers or as an extension dll/so or a script such as Lua, python, etc.

**Usage**
See [usage](usage.md).

**Definitions**
* User - Any real person or Module which wishes to perform an action with specific permissions.
* Group - Groups of users, Like Administrators or Moderators
* Permission - A restriction or permission which prevents/enables a user to perform an action.
* Module - A separate script or library using a different programming language that is added on to the main program.
* Core - Main program, has all permissions and can monitor users.

**Permission Scope**
* USER - specific real user
* GLOBAL - global permissions for the core (i.e.: '-global.stop' command to prevent a basic user from killing the program)
* MOD - permissions for a specific mod
* FULL

**Built-in Permissions**
See [builtin-permissions](builtin-permissions.md).

**Built-in Groups**
see 
* Administrator - Has almost every permission ('*', '-global.stop', '-global.ban.admin')
* SuperAdministrator - Has all permissions ('*')
* Moderator - Only has Mute/Ban permissions (inherits User, '+chat.mute', '+global.ban')
* Module - Base module groups, limited mod-related permissions ()
* User - Has a very limited whitelist of permissions ('global.chat', 'global.login', 'user.bannable')
* Banned - Has no permissions ('-*')
