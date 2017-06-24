# Eternia Library #

**Version**: 1.05b

**Author**: Brent Clancy (EterniaLogic) &nbsp;&nbsp;*[Other authors may list themselves below]*

**Email**: brent.clancy@ttu.edu, eternialogic@gmail.com (alias> dreadslicer@gmail.com)

**Original Creation Date**: January 13, 2012

**Copyright**: Copyright 2016 Brent Clancy, GPL-3+

**License**: GNU v3

**Language**: C/C++, ASM

	This library is used for server/client back-end systems and simulations. It may also be applicable for game theory and systems emulation. The lib file (*.a, *.so, *.dll) may be used in any project to help decrease dependencies. The main goal of this library is to have zero dependencies, while also being originally flexible.


	Anybody willing to help in this project may contribute!

Documentation and Examples
--------------------------
[Documentation Index](https://github.com/EterniaLogic/EterniaLibrary/blob/master/doc/index.md "Documentation Index")

Sub-sections
------------

**Application Program Interface** [/API/]:

- Core API system to allow multiple languages to cross-talk with shared memory
- Permissions for different users and API modules
	
	Not to be confused with a Web API, which interfaces a server's language with a client of a different language. This API is to enable multiple languages to be connected with the core program.

**Web Framework** [/WebFramework/]: (*in progress, these are the initial goals)

- HTTP Server with multi-threading (C++2011)
- Template Engine for use with HTML template files
- RESTFul HTTP Server
- JSON

**Mathematics** [/Math/]:

  - Economics
  - Linear Algebra
  - Statistics

**Audio & Frequency manipulaiton** [/Audio/&nbsp;&nbsp;&nbsp;/Engineering/Electrical/Signal/]:

  - Time to Frequency conversion using FFT (TimeSignal.h)
  - Frequency to Time conversion using IFFT (FreqSignal.h)
  - White Noise generator
  - Frequency Window generation / Audio filtering *Planned*


**Base Engineering** [/Engineering/]:

- Physics
- Chemistry
- Electrical

**Computer Science** [/Algorithm/&nbsp;&nbsp;&nbsp;/Data/&nbsp;&nbsp;&nbsp;/Programming]:

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

	
**Building**:

Linux:
- no direct dependencies besides "build-essential"
- cmake .
- make -j 4

Windows:
- Use the Code::Blocks project file
- libatomic.a and libws_32.a required.
