#ifdef LAYOUT_H_
#define LAYOUT_H_

#include "LayoutObject.h"

// The layout is the generic container for objects in it.
//	Several layout types are available.
// In general, the most used layout is the local-location container
//	however relational containers are also available.



class Layout : public LayoutObject{
public: 
	Layout();
};

#endif
