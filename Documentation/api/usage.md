

    #include "API/APICore.h"

**Core Initialize**
The Core is the interface for the main program
    
    APICore* core = new APICore("testCore", "mods", "log.txt");
    core->Init();
    
**Mod Initialize**
A mod is a polymorphic class, which requires an external library for that specific programming language.
[Here](https://github.com/EterniaLogic/EterniaEngine/tree/master/src/Scripts) is a folder of specific examples for several languages. (Not tested!)


**User Initialize**

'User logs in'
    APIUser user = APIUser("username");
    user.addPermissions(&user, "global.chat");
    // user.setGroup("SuperAdministrator"); (Not Implemented)
    
    // Test if user has a specific permission
    if(user.hasPermission(APIPermission("global.chat"))){
        cout << "can chat!" << endl;
    }
