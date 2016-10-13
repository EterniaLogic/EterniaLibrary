#ifndef LAYOUTOBJECT_H_
#define LAYOUTOBJECT_H_

#include "../Data/LinkedList.h"
#include "../Events/EventHandler.h"

// The Layout object is used to reference multiple sub-objects
// These objects as an example can be buttons, dropdowns or other layouts.

class LayoutObject {
    private:
        int x,y;
        int width, height;
        bool resize, draw;
        LinkedList<LayoutObject> *children; // children
        LayoutObject *parent; // parent object

        private initObject(); // initialize variables

    public:
        ~LayoutObject();

        // event methods
        public void _draw();                    // pre-draw event
        public virtual void draw();             // abstract draw method (implements OpenGL, SDL, ect.)
        public void draw_();

        // Child methods
        public void addChild(LayoutObject* child);      // add a child
        public LayoutOjbect* getChildren();             // get all children
        public void removeChild(LayoutObject* child);   // remove a single child
        public void clearChildren();                    // clears all children



        // Parent methods
        public void setParent(LayoutObject* child);
        public LayoutObject* getParent();
};

#endif
