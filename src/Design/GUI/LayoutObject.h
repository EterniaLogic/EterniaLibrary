#ifndef LAYOUTOBJECT_H_
#define LAYOUTOBJECT_H_

#include "../../Data/includes.h"

// The Layout object is used to reference multiple sub-objects
// These objects as an example can be buttons, dropdowns or other layouts.

class LayoutObject {
    private:
        int x,y;
        int width, height;
        bool resize, dodraw;
        LinkedList<LayoutObject> *children; // children
        LayoutObject *parent; // parent object

        void initObject(); // initialize variables

    public:
        ~LayoutObject();

        // event methods
        void _draw();                    // pre-draw event
        virtual void draw();             // abstract draw method (implements OpenGL, SDL, ect.)
        void _drawp(); // postdraw

        // Child methods
        void addChild(LayoutObject* child);      // add a child
        LayoutObject* getChildren();             // get all children
        void removeChild(LayoutObject* child);   // remove a single child
        void clearChildren();                    // clears all children



        // Parent methods
        void setParent(LayoutObject* child);
        LayoutObject* getParent();
};

#endif
