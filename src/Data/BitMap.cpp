#include "BitMap.h"


bmbit::bmbit() {
    r=0;
    g=0;
    b=0;
    a=0;
}

bmbit::bmbit(unsigned int rgba){
    a = rgba & 0xFF;
    b = rgba & 0xFF00;
    g = rgba & 0xFF0000;
    r = rgba & 0xFF000000;
}

unsigned int bmbit::getRGBA(){
    unsigned int v = a;
    v += ((b&0xFF) << 8);
    v += ((g&0xFF) << 16);
    v += ((r&0xFF) << 24);
    
    return v;
}

// Bitmap -> container of color bits!
BitMap::BitMap(const int wid, const int hei) {
    width = wid;
    height = hei;


    // Populate bitmap! :D
    bmbit** vset = new bmbit*[wid];
    for(int i=0; i<wid; i++) {
        vset[i] = new bmbit[hei];

        // fill in.
        /*for(int k=0;k<hei;k++){
            vset2[k] = new bmbit();
        }*/
    }

    map = vset;
}

BitMap::~BitMap() {
    for(int i = 0; i<width; i++) {
        delete map[i];
    }
    delete map;
}

// brighen all values in map from between 0-100. (brightness is a constant value)
// 0 -> set image to black
// 100 -> white image
void BitMap::setBrightness(double v){ 
    double brightness = (v/100.0); // simple value

    for(int x=0;x<width;x++){
        for(int y=0;y<height;y++){
            bmbit *val = &map[x][y];
            val->r = (unsigned char)((double)val->r * brightness);
            val->g = (unsigned char)((double)val->g * brightness);
            val->b = (unsigned char)((double)val->b * brightness);
            //val->a = (unsigned char)((double)val->a * brightness);
        }
    }
}

// contrast the image from 0-100. (Contrast is power2 of contrast value)
void BitMap::setContrast(double v){ 
    double contrast = Math::pow((100+v)/100, 2); // simple value

    for(int x=0;x<width;x++){
        for(int y=0;y<height;y++){
            bmbit *val = &map[x][y];
            double R = ((((double)val->r / 255.0) - 0.5)*contrast + 0.5) * 255.0;
            double G = ((((double)val->g / 255.0) - 0.5)*contrast + 0.5) * 255.0;
            double B = ((((double)val->b / 255.0) - 0.5)*contrast + 0.5) * 255.0;
            //double A = ((((double)val->a / 255.0) - 0.5)*contrast + 0.5) * 255.0;
            if(R > 255) R = 255;
            if(G > 255) G = 255;
            if(B > 255) B = 255;
            //if(A > 255) A = 255;
            
            
            val->r = (unsigned char)R;
            val->g = (unsigned char)G;
            val->b = (unsigned char)B;
            //val->a = (unsigned char)A;
        }
    }
}

// simple grayscale via averages
void BitMap::setGrayscale(){

    for(int x=0;x<width;x++){
        for(int y=0;y<height;y++){
            bmbit *val = &map[x][y];
            int valx = val->r;
            valx += val->g;
            valx += val->b;
            valx /= 3; // fastavg
            
            val->r = val->g = val->b = valx;
        }
    }
}

