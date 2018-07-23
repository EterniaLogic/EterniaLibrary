#ifndef CRCDATA_H_
#define CRCDATA_H_

#include "../Algorithm/Cryptography/crc32.h"

template<class T>
class CRCData{
private:
    CRCData(){val=0x0; same=false; crc=0;}
public:
    T* val;
    uint32_t crc;
    bool same;
    
    T* get(){ return val; }
    void set(T* v) { val = v; }
    
    void verify(){
        crc = doCRC();
        same = true;
    }
    
    bool changed(){
        uint32_t _crc = doCRC();
        return crc != _crc;
    }
    
    uint32_t doCRC(){
        // do CRC
        int l = sizeof(T);
        void *buf = (void *)val;
        return crc32(0, buf, l);
    }
    
    static CRCData<T> get(T* d){
        CRCData<T> r = new CRCData<T>();
        r.val = d;
    }
};

#endif
