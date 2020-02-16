The Built-in permissions enable 

**Core**
Core permissions enable an admin or special user to load/reload/unload modules on the fly.
* core.mod.load
* core.mod.reload
* core.mod.unload
* core.memory - reports memory usage
* core.gc - perform garbage collect



**Global**
Global permissions enable very specific functionality that effects everything from a user's point of view.

***Superadmin Commands***
* global.stop  -Dangerous, superadmin only)
* global.mute  - mute everybody in a chat channel except for mod/admin/superadmin)
* global.maintenance  - prevent anybody from having permissions, except for mod/admin/superadmin)
* global.ban   - global ban, prevents user from even logging in or starting



**User**
* user.bannable - can this user be banned? (using global.ban)



**Chat**
For systems that use a chat channel. (Requires implementation)

***Commands***
* chat.mute  - admin/mod command to mute
* chat.ban   - ban from using the chat channel
* chat.unban - reverts a ban



**Modules**

***Commands***
* mod.[name].start - starts a mod if it hasn't been started
* mod.[name].restart
* mod.[name].stop

***Permissions***
* mod.[name].perm.? - permission derived from that mod on initialize
* mod.[].data - can this mod interact with another mod's variables?
