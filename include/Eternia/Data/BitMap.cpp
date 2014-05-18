#include "BitMap.h"


bmbit::bmbit(){
  r=0;
  g=0;
  b=0;
  a=0;
}

// Bitmap -> container of color bits!
BitMap::BitMap(const int wid, const int hei){
    width = wid;
    height = hei;
    
    
    // Populate bitmap! :D
    bmbit** vset = new bmbit*[hei];
    for(int i=0;i<hei;i++){
        vset[i] = new bmbit[wid];
        
        // fill in.
        /*for(int k=0;k<hei;k++){
            vset2[k] = new bmbit();
        }*/
    }
    
    map = vset;
}

BitMap::~BitMap(){
  for(int i = 0; i<height; i++){
      delete map[i];
  }
  delete map;
}