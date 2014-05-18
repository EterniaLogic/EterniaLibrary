#include "IC.h"

void IC::setPins(LinkedList<PowerValue>* list){
  pins = list;
  maxPins = list->size();
}