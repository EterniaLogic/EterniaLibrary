#ifndef LAYOUT_H_
#define LAYOUT_H_

#include "LayoutObject.h"

// The layout is the generic type for objects in it.
//  Several layout types are available.
// In general, the most used layout is the local-location container
//  however relational containers are also available.


// Layouts specify how objects are placed when sizing, etc.



class Layout : public LayoutObject {
public:
    Layout();
};

#endif
