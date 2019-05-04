#ifndef LAYOUTOBJECT_H_
#define LAYOUTOBJECT_H_

#include "../../Data/includes.h"
#include "../../Design/Events/MouseHandleEvent.h"
#include "../../Design/Events/KeyHandleEvent.h"

//#define COUT_LO_DEBUG

#ifdef COUT_LO_DEBUG
#define debugLog(s) cout << s << endl; cout.flush()
#else
#define debugLog(s)  //nothing
#endif


// The Layout object is used to reference multiple sub-objects
// These objects as an example can be buttons, dropdowns or other layouts.


// Ported from EterniaEngine from GUI/GObject.h

class LayoutObject {
public:
    bool resize;
    LinkedList<LayoutObject*> children; // children
    LayoutObject *parent; // parent object


    // x,y are local to parent
    int x, y, dragoffsetx, dragoffsety; // globalx/y are overwritten by localx/y if they are not defaulted to -1
    int mouseLocX,mouseLocY; // mouse position relative to this object.
    int width, height;
    float opacity; // reverse transparency
    bool selected, visible, mouseOver, allowMouseEvents, dragging;
    bool canDrag; // Can this object be dragged? NOTE: GObject handles basic dragging, not advanced
    bool enabled; // if false, no writing interactions can occur.
    bool needsUpdate, needsDraw, needsMouse,  needsKeyboard,
        needCursorChange;

    vertex foreColor, backColor; // colors from 0 to 255


    



    LayoutObject();
    ~LayoutObject();

    // event methods
    void _draw();                    // pre-draw event
    void _drawp(); // postdraw
    void _update(); // sends update handler to children
    void _handleMouse(MouseHandleEvent*); // handles mouse operations; BEFORE handleMouse
    void _handleKeyboard(KeyHandleEvent*); // handles mouse operations; BEFORE handleMouse

    virtual void draw(); // abstract draw method (implements OpenGL, SDL, ect.)
    virtual void update(); // updates information!
    virtual void handleMouse(MouseHandleEvent*); // Handles a mouse operation for ordinary windows (click, mousedown, mouseup, mousemove)
    virtual void handleKeyboard(KeyHandleEvent*); // Handles a keyboard operation for ordinary windows (Window must be selected)

    // Positioning
    void setPosition(int x, int y); // local x/y
    int getGlobalX(); // get position by adding parental X
    int getGlobalY(); // get position by adding parental Y

    // Child methods
    void addChild(LayoutObject* child);      // add a child
    LayoutObject* getChildren();             // get all children
    void removeChild(LayoutObject* child);   // remove a single child
    void clearChildren();                    // clears all children



    // Parent methods
    void setParent(LayoutObject* child);
    LayoutObject* getParent();


    bool childSelectedMouseOver(LayoutObject*);



    // STATIC HANDLERS / VARIABLES
    static void mouseHandler(MouseHandleEvent*);
    static void keyHandler(KeyHandleEvent*);
    static void drawHandler();
    static void updateHandler();
    
    static bool cursorReq; // request a cursor? // Not used in _draw due to no GLUT
    static int cursorSet; // GLUT cursor type GLUT_CURSOR_INHERIT
    static LinkedList<LayoutObject*> mouseListenerOwners;
    static LinkedList<LayoutObject*> keyListenerOwners;
    static LinkedList<LayoutObject*> drawListenerOwners;
    static LinkedList<LayoutObject*> updateListenerOwners;
};




#endif
