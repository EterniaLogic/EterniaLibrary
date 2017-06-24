#ifndef SCRIPT_CONFIG_H_
#define SCRIPT_CONFIG_H_

// Define specific in-game script limitations for individual programming players.
// Will probably be stripped out later into a dynamic class.


// These tokens are based on % of CPU.
// 1 token = 1microsecond

// Ship gravity system =>  F=m*a  where a is provided by ship's gravity generator

// Standard = 20TPS, 50000 tokens = 100% of 1 CPU (50ms)
// file size => 1 token = 200 bytes.


// Basic Player scripts
#define SHIP_GENERIC_SYSTEM 1000 // generic system, can be attached to monitors or something...
#define SHIP_TARGET_SYSTEM 600
#define SHIP_NAV_SYSTEM 500
#define FACTORY_PROCESS 500 // single state-based factory process. (I.e: robot picking up plank, putting it down somewhere else)
#define BIO_SIM 1000 // Biological simulation
#define EE_SIM 1000 // Electrical Simulation

// University Professor script tokens (Or qualified account)
// Professor-based scripts cannot be run under normal player accounts if they are over the normal qualifications.
// Professor or qualified account can use an API out-of-game to connect to the server.
#define UP_SIM_GENERIC 20000 // Generic simulation of any kind run through OpenCL or a supported language. (BOINC-like)
#define UP_BIO_SIM 20000 
#define UP_EE_SIM 20000 // Electrical Simulation, used for state-based simulations on a large scale system.

#endif