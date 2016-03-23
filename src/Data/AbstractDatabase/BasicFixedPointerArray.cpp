#include "AbstractDB.h"

BasicFixedPointerArray::BasicFixedPointerArray(int size){
	arr = (void**)calloc(size, sizeof(void*));
	length = size;
}

BasicFixedPointerArray::~BasicFixedPointerArray(){
	for (int i = 0; i < length; i++){
		if (arr[i] != 0x0)
			free(arr[i]);
	}
	free(arr);
}

void* BasicFixedPointerArray::get(int index){
	if (index >= length) return NULL;
	return arr[index];
}

// sets a value to an index.
// returns true if value was set
bool BasicFixedPointerArray::set(int index, void* value){
	if (index >= length) return false;

	arr[index] = value;

	return true;
}