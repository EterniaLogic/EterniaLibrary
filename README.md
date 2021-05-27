# Eternia Library #

**Version**: 1.152.6

**Author**: Brent Clancy (EterniaLogic) &nbsp;&nbsp;*[Other authors may list themselves below]*

**Email**: eternialogic@gmail.com (alias> dreadslicer@gmail.com)

**Subprojects**: https://github.com/EterniaLogic/EterniaEngine

**Original Creation Date**: January 13, 2012

**Copyright**: Copyright 2019 Brent Clancy

**License**: GNU v3

**Language**: C/C++2011, ASM, HTML, Javascript

	This library is used for server/client back-end systems and simulations. It may also be applicable for game theory and systems emulation. The lib file (*.a, *.so, *.dll) may be used in any project to help decrease dependencies. The main goal of this library is to have zero dependencies, while also being originally flexible.


	Anybody willing to help in this project may contribute!
	

**Building**:

cmake, eclipse or code-blocks (project files may not be fully up-to-date)

Linux:
- no direct dependencies besides "build-essential" and pthreads


		cd build
		cmake .
		make -j 4
		make package
		
- 'make package' generates .deb, .rpm, and .tar.gz files.
- 'make -j 50 run' runs the base console environment.
- 'make -j 50 runtest' runs the testing environment.




Windows:
- Use Code::Blocks, Visual Basics or eclipse
- libatomic.a and libws_32.a required. (usually supplied with windows)


Code Testing
--------------------------
Although EterniaLibrary is slowly becoming larger and relatively more stable with each iteration, it does not have testing for any test library.


Documentation and Examples
--------------------------
[Documentation Index](https://github.com/EterniaLogic/EterniaLibrary/blob/master/Documentation/index.md "Documentation Index")


Usage
--------------------------
example using namespaces

	#include <Eternia/eternia.h>
	#include <iostream>
	using namespace std;
		
	int main(){
        	cout << Math::sin(20) << endl;
        
        	return 0;
	}


Sub-sections
------------

**Artificial Intelligence** [/AI/]:
 - FSM AI - Finite State machine AIs follow basic brain mechanics.
 - Advanced Thinker - Comparable to FSM AIs, yet also allow for multiple inputs and outputs, the 'epoch' of self-learning AIs whether it be Sin functions all the way to image and video processing. Not necessarily more powerful than FSM AIs, only useful for specific applications.
 
 - Self-learning controller (Research specific) - sets goals and modifies the AI to meet the demands, over time will become what the user demands from a single entity.
 - Genetic controller (Application specific) - sets a user-specific goal and 'kills' off a set number of simulated AIs until the goal is met, randomly creating a set and cross-breeds the best solutions of AI cores.

**Application Program Interface** [/API/]:

- Core API system to allow multiple languages to cross-talk with shared memory
- Permissions for different users and API modules
	
	Not to be confused with a Web API, which interfaces a server's language with a client of a different language. This API is to enable multiple languages to be connected with the core program.

**Web Framework** [/WebFramework/]: (*in progress, these are the initial goals)

- HTTP Server with multi-threading (C++2011)
- Template Engine for use with HTML template files
- RESTFul HTTP Server (30%-ish)
- JSON marshal parsing (0% done)

**Business** [/Simulation/Business/]: (headers only, no implementations yet)

- Built for simulation, but could possibly be used for real
- Basic Accounting [Liabilities, Equities, Taxation]
- Tracking of assets, IP, Property, and inventory
- Tracking of employees and related transactions
- Stock tracking
- Payroll
- POS parts (excluding actual processing of credit cards, etc.)


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

- Discrete Data Structures of all varieties
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
