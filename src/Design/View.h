#ifndef VIEW_H_
#define VIEW_H_

#include "../Data/LinkedList.h"
#include "Colors.h"
#include "Layout.h"

// The View is the asbstract mid-level for a design
//	it can be broken down into a window
//	the window can be broken down into a layout
//	that layout can hold multiple lower-level elements.
// This system should be able to support any library for mid-level design.

// supported bottom-level libraries: (Implemented in EterniaEngine)
//	OpenGL

// abstract::

class View{
private:
	LinkedList<Layout> *layout;

public:
	View();
	~View();

	void addLayout(Layout* layout);
};

#endif