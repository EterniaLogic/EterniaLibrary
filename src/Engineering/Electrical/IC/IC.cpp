
#include "IC.h"

void IC::setPins(LinkedList<Pin>* list) {
    pins = list;
    maxPins = list->size();
}
