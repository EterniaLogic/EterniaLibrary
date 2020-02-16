#include "LayoutObject.h"

// STATIC inits
LinkedList<LayoutObject*> LayoutObject::mouseListenerOwners = LinkedList<LayoutObject*>();
LinkedList<LayoutObject*> LayoutObject::keyListenerOwners = LinkedList<LayoutObject*>();
LinkedList<LayoutObject*> LayoutObject::drawListenerOwners = LinkedList<LayoutObject*>();
LinkedList<LayoutObject*> LayoutObject::updateListenerOwners = LinkedList<LayoutObject*>();
bool LayoutObject::cursorReq = false;
int LayoutObject::cursorSet = 0;


LayoutObject::LayoutObject(){
    x = y = width = height = 0;
    dragoffsetx = dragoffsety = 0;
    canDrag = false;
    visible = true;
    selected = false;
    mouseOver = false;
    allowMouseEvents=true;
    dragging=false;
    parent = 0x0;
    opacity = 1.0f;
    enabled = true;
    resize=false;
    mouseLocY=mouseLocX=0;
	needCursorChange=false;

    needsDraw = true;
    needsUpdate = true;
    needsMouse = true;
    needsKeyboard = true;
    //children = new LinkedList<GObject>();

    // add event listeners to GObject listener lists
    LayoutObject::mouseListenerOwners.add(this);
    LayoutObject::keyListenerOwners.add(this);
    LayoutObject::drawListenerOwners.add(this);
    LayoutObject::updateListenerOwners.add(this);

    foreColor = vertex(255,255,255);
    backColor = vertex(0,0,0);
}


void LayoutObject::draw() {}
void LayoutObject::update() {}
void LayoutObject::handleMouse(MouseHandleEvent*) {}
void LayoutObject::handleKeyboard(KeyHandleEvent*) {}



// Pre-draw
void LayoutObject::_draw() {
    if(!visible) return;


    // comment blocked due to no GLUT in EterniaLib
    /*if(cursorSet != GLUT_CURSOR_INHERIT && !cursorReq){
        cursorSet = GLUT_CURSOR_INHERIT;
        glutSetCursor(GLUT_CURSOR_INHERIT);
    }else if(cursorReq && needCursorChange){
        glutSetCursor(cursorSet);
        needCursorChange = false;
    }*/

    if(needsDraw) draw(); // <-- draw MUST be implemented!
    children.freeze();
    for(int i; i<children.size(); i++) {
        children.frozen[i]->_draw();
    }
}


int LayoutObject::getGlobalX(){
    int _x = x;

    LayoutObject* par = parent;
    while(par != 0x0){
        _x += par->x;
        par = par->parent;
    }

    return _x;
}

int LayoutObject::getGlobalY(){
    int _y = y;

    LayoutObject* par = parent;
    while(par != 0x0){
        _y += par->y;
        par = par->parent;
    }

    return _y;
}


void LayoutObject::_update() {
    if(needsUpdate) update(); // <-- draw MUST be implemented!
    children.freeze();
    for(int i=0; i<children.size(); i++) {
        // if the localx/y are not set, only use global policy of the object
       /* if(children.frozen[i]->x != -1 && children.frozen[i]->y != -1) {
            // enforce local-based x/y policy
            children.frozen[i]->setPosition(globalx+children.frozen[i]->localx, globaly+children.frozen[i]->localy);
        }*/
        children.frozen[i]->_update();
    }
}

// handle mouse operations
void LayoutObject::_handleMouse(MouseHandleEvent* event) {
    // is the mouse in this region?
    this->mouseOver = false; // mouseover is guilty until proven innocent
    debugLog("GObject PRE Handle Mouse");

    mouseLocX = event->x;
    mouseLocY = event->y;


    if(visible) {
        if((event->x >= getGlobalX() && event->y >= getGlobalY() && event->x-getGlobalX() <= this->width && event->y-getGlobalY() <= this->height) || dragging) {
            // is the mouse over a child object? -> handle for child, not this
            // subtract position on the mouse position (Relative positioning)
            this->mouseOver = true;
            if(needsMouse) this->handleMouse(event);



            if(event->event_type == MOUSE_CLICK) {
                this->selected = true; // enforce top window
            } else if(event->event_type == MOUSE_DOWN) {
                if(event->event_button == LEFT_BUTTON) {
                    // must not be dragging the mouse to perform a drag operation
                    if(!this->dragging && selected && canDrag) {
                        this->dragging=true;
                        // set mouse offsets!
                        this->dragoffsetx = event->x - getGlobalX();
                        this->dragoffsety = event->y - getGlobalY();
                    }
                }
            } else if(event->event_type == MOUSE_UP) {
                if(event->event_button == LEFT_BUTTON) {
                    this->dragging=false;
                }
            }
        } else {
            //this->dragging = false;
        }
    }

    // Check to make sure that no children are selected and dragging
    children.freeze();
    for(int i=0; i<children.frozenlen; i++) {
        if(childSelectedMouseOver(children.frozen[i])){
            selected=false;
            dragging=false;
            return;
        }
    }

    /*if(event->event_type == MOUSE_CLICK && (!visible || !mouseOver)) {
        selected=false;
        dragging=false;
    }else if(event->event_type != MOUSE_CLICK && dragging && visible){
        selected=true;
        mouseOver=true;
        if(needsMouse) this->handleMouse(event);
    }*/
}

// Are any children dragging/selected?
bool LayoutObject::childSelectedMouseOver(LayoutObject* child){
    if(child == 0x0) return false;
    //cout << "childSelectedMouseOver A" << endl;
    if(child->dragging || child->mouseOver){
        return true;
    }else{
        //cout << "childSelectedMouseOver B" << endl;
        child->children.freeze();
        for(int i=0; i<child->children.frozenlen; i++) {
            //cout << "childSelectedMouseOver B1" << endl;
            if(child->children.frozen[i] == 0x0) continue;
            if(childSelectedMouseOver(child->children.frozen[i]))
                return true;
        }
    }

    return false;
}

//
void LayoutObject::_handleKeyboard(KeyHandleEvent* event) {
    if(selected) {
        if(needsKeyboard) handleKeyboard(event);
    }
}

void LayoutObject::addChild(LayoutObject* child) {
    children.add(child);
    child->setParent(this);
    //child->setPosition(child->x, child->y);
}

void LayoutObject::setParent(LayoutObject* parent_) {
    this->parent = parent_;
}

// basic
void LayoutObject::setPosition(int x_, int y_) {
    this->x = x_;
    this->y = y_;
}





void LayoutObject::mouseHandler(MouseHandleEvent* event) {
    LayoutObject::mouseListenerOwners.freeze();
    for(int i=0; i<LayoutObject::mouseListenerOwners.frozenlen; i++) {
        mouseListenerOwners.frozen[i]->_handleMouse(event);
    }
}

void LayoutObject::keyHandler(KeyHandleEvent* event) {
    LayoutObject::keyListenerOwners.freeze();
    for(int i=0; i<LayoutObject::keyListenerOwners.frozenlen; i++) {
        LayoutObject::keyListenerOwners.frozen[i]->_handleKeyboard(event);
    }
}

void LayoutObject::drawHandler() {
    //cout << "Draw Handler " << drawListenerOwners.size() << " " << drawListenerOwners.frozenlen << endl; cout.flush();
    LayoutObject::drawListenerOwners.freeze();
    for(int i=0; i<LayoutObject::drawListenerOwners.frozenlen; i++) {
        //cout << "Draw Listener " << i << endl; cout.flush();
        LayoutObject::drawListenerOwners.frozen[i]->_draw();
    }
}

void LayoutObject::updateHandler() {
    LayoutObject::updateListenerOwners.freeze();
    for(int i=0; i<LayoutObject::updateListenerOwners.frozenlen; i++) {
        LayoutObject::updateListenerOwners.frozen[i]->_update();
    }
}
