#ifndef LOCALLAYOUT_H_
#define LOCALLAYOUT_H_

#include "Layout.h"

// ABSTRACT
// The Local Layout allows direct x/y cordinate values.
//  windows can be resized if the resize attribute is true.

class LocalLayout : public Layout {
    public:
        LocalLayout();
        virtual ~LocalLayout();


        // functions inherited from LayoutObject:
        //      addChild(LayoutObject* child);
};

#endif
