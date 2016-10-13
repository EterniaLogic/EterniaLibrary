#ifndef DriverCore
#define DriverCore

// The Driver core is used to help make supplementary drivers for hardware.

#if WIN
#include "WinDriver.h"
#elseif MacOSX
#include "OSXDriver.h"
#elseif Linux
#include "LinuxDriver.h"
#endif


#endif
