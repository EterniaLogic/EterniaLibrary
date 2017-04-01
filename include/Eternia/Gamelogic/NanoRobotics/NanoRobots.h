#ifndef NANOROBOTS_H_
#define NANOROBOTS_H_


// NanoRobots can be anywhere.
// They can self-replicate where there is iron and other materials.

// "Magic" can be explained with nano-robots.
// Ice magic -> enforcing low-pressure, moving hot atoms out.
// Fire magic -> compressing an area, exciting atoms.
// Water magic -> pull molecules of water out of the air.
// Death magic -> nanos kill cells ~woo.

// Demons? No.
// Pocket dimensions? No.
// Spirits? No.

// The nano-robots have to be flung by the original person, who has a mental connection
//  which is provided by a nano-controller with hive-mind like instincts.
// If the host dies during an action, the NanoRobots will become inactive.

// Magic that deals with manipulating the air does not work well... if at all in
//  space.

// NanoRobot controllers (NRCs) are expensive as they must be able to talk to
//  millions of different nano-robots on a special set of built-in encrypted
//  frequencies.

// Buildings would be slow at first to make, because NRCs are still pretty expensive
//  for any new player at first.

// No colony of nano-robots is the same.

class NanoRobots {
    public:
        NanoRobots();

        double colonySet; // Unique ID number set into each Nano.

        // hack attempt from another colony
        // hacking in this case is a "Take-over", killing other's Nanorobots.
        // This works best when another colony is expended doing other stuff.
        void hacking(NanoRobots* attemptColony);
};

#endif
