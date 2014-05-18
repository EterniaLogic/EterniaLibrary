//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef PROGRAM_LIMITATIONS_H_
#define PROGRAM_LIMITATIONS_H_
 
 // It would be great to be able to compute the roundness of the empire state building, but that is not what the entire network is for.
 // There are certain limitations to programs that users make that prevent the entire network from crashing to the ground.
 // These options limit the maximum usages on each computer so that the processing does not become noticeable.
 
 // Normal processing speed for programs: 10% of total potential (unless somebody has designated a new percentage)
 
 const double programWaittime = 800; // nanoseconds
 const double renderingWaitTime = 180; // nanoseconds
 const double hashingWaitTime = 90; // nanoseconds
 const double physicsWaitTime = 50; // nanoseconds
 const double arithmeticWaitTime = 20; // nanoseconds (arithmetic usually is for bank accounts, super-fast operations)
 
 // percentage usage
 const double max_PERCENTAGE_MEMORY_PROGRAM = 10;
 
#endif