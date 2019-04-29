#include "WhiteNoise.h"


template<class T>
WhiteNoise<T>::WhiteNoise(){
    srand(time(0x0)); // make sure random is seeded.
    srand(rand()); // double-seed
}

// grab N values.
template<class T>
LinkedList<T> WhiteNoise<T>::getValues(int number){
    LinkedList<T> list;
    T* val;
    
    // generate N number of random numbers.
    for(int i=0;i<number;i++){
        val = (T*)malloc(sizeof(T));; 
        *val = (T)rand();
        list.add(val);
    }
    
    return list;
}
