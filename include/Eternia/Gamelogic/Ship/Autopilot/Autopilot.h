#ifndef AUTOPILOT_H_
#define AUTOPILOT_H_

#include "../Ship.h"


class Autopilot {
    public:
        Autopilot(Ship* tship); // Ship to autopilot

        void Pilot(); // Pilot this ship

        void Scanner(); // Scan for ships to avoid. This is based on heading, size.
};

#endif
