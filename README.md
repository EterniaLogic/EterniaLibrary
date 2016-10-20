# Eternia Library #

Builds on github fully compile. This is the current build:

[![Build Status](http://eternialogic.com/jenkins/buildStatus/icon?job=Eternia Library)](http://eternialogic.com/jenkins/job/Eternia%20Library/)

**Version**: 0.9b

**Author**: Brent Clancy (EterniaLogic) &nbsp;&nbsp;*[Other authors may list themselves below]*

**Email**: brent.clancy@ttu.edu, eternialogic@gmail.com (alias> dreadslicer@gmail.com)

**Original Creation Date**: January 13, 2012

**Copyright**: Copyright 2016 Brent Clancy, no transfers will ever be allowed. (All rights reserved)

**License**: GNU v3

**Language**: C++, ASM

	This library is used for server/client back-end systems and simulations. It may also be applicable for game theory and systems emulation. The lib file (*.so, *.dll) may be used in any project to help decrease dependencies. The main goal of this library is to have zero dependencies, while also being originally flexible.


	Anybody willing to help in this project may contribute!

Documentation and Examples
--------------------------
[Documentation Index](https://github.com/EterniaLogic/EterniaLibrary/blob/master/doc/index.md "Documentation Index")

Sub-sections
------------

**Web Framework** [/WebFramework/]: (*in progress, these are the initial goals)

- HTML Engine with multi-threading (C++2011)
- Template Engine for use with HTML template files
- RESTFul API
- Backend scripting is automatically compiled under python
- MySQL or other database connector not yet planned/supported due to dependencies

**Game Logic** [/GameLogic/]:
 
 - Environments
 - Dynamic Game Logic

**Mathematics** [/Math/]:

  - Economics
  - Linear Algebra
  - Statistics

**Base Engineering** [/Engineering/]:

- Physics
- Chemistry

**Computer Science** [/Algorithm/&nbsp;&nbsp;&nbsp;/Data/]:

   - Discrete Data Structures
   - Sorting Algorithms
   - Cryptography&nbsp;&nbsp;&nbsp;&nbsp;*+ Imported for more security*
   - AI Systems

**Electrical Engineering**:

   - Emulation (MSP430 processor)
   - PWM, Clocks, Time and Frequency domain signals.

**Localization**:

   - Simple word translation between languages.

**Other**:

   - Fully working Event Handler system, useful for threading.
   - Extended string class "CharString", which automatically handles strings along with conversions.
   - Wrapper for OpenGL/SDL, other frameworks to draw windows and 2D graphics.

**Required Libraries**: 

- Included (Lib/)
	- MiniUpnpc (http://miniupnp.free.fr/)

Building:

    cmake .
    make -j 4
