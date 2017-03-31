#ifndef WindowsDriver_h
#define WindowsDriver_h

#if defined(__linux__) || defined(__unix__)
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// the Linux driver enables this system to run under linux
// includes requirements from linux to run daemon to kernel level operations

MODULE_LICENSE("Dual BSD/GPL");

static int driver_init(void) {

}



static void driver_exit(void) {

}


module_init(driver_init);
module_exit(driver_exit);

#endif
#endif
