#include "Aes256.h"
#include <math.h>

AES256::AES256(CharString keyv){
    // convert key to uint8_t
    for(int i=0;i<keyv.getSize();i++){
        ((char*)key)[i] = keyv.get()[i];
    }
    
    aes256_init(&ctx,key);
}

AES256::AES256(uint8_t keyv[16]){
    for(int i=0;i<16;i++) key[i] = keyv[i];
    
    aes256_init(&ctx,key);
}

AES256::AES256(){
    // auto-generates key
    genKey();
    aes256_init(&ctx,key);
} 

AES256::~AES256(){
    aes256_done(&ctx);
}

 // auto-generate 256-bit key
CharString AES256::genKey(){
     srand (time(NULL));
    for(int i=0;i<16;i++){
        key[i] = (uint8_t)rand();
    }
}

// get a 256-bit key
uint8_t* AES256::getKey(){
    /*CharString ret = CharString((char*)calloc(4,32),32);
    
    for(int i=0;i<32;i++){
        ret.get()[i] = ((char*)key)[i];
    }*/
    
    
    return key;
}

using namespace std;
CharString AES256::encrypt(CharString plaintext){
    uint8_t* nbuf = (uint8_t*)malloc(16); // converting ptr
    bool odd = plaintext.getSize() % 16 != 0;
    int nlen = odd ? floor(plaintext.getSize()/16.f)*16+16 : plaintext.getSize();
    char* c = (char*)malloc(nlen);
    
    for(int i=0;i<nlen;i+=16){
        for(int j=0;j<16;j++){
            if(i+j+1 <= plaintext.getSize()) nbuf[j] = (uint8_t)plaintext.get()[i+j];
            else nbuf[j] = 0;
        }
        // encrypt
        aes256_encrypt_ecb(&ctx, nbuf);
        
        for(int j=0;j<16;j++)
            c[i+j] = (char)nbuf[j];
    }
    
    return CharString(c,nlen);
}
CharString AES256::decrypt(CharString encrypttext){
    uint8_t* nbuf = (uint8_t*)malloc(16); // converting ptr
    bool odd = encrypttext.getSize() % 16 != 0;
    int nlen = odd ? floor(encrypttext.getSize()/16.f)*16+16 : encrypttext.getSize();
    char* c = (char*)malloc(nlen);
    
    for(int i=0;i<nlen;i+=16){
        for(int j=0;j<16;j++){
            if(i+j+1 <= encrypttext.getSize()) nbuf[j] = (uint8_t)encrypttext.get()[i+j];
            else nbuf[j] = 0;
        }
        // decrypt
        aes256_decrypt_ecb(&ctx, nbuf);
        
        for(int j=0;j<16;j++)
            c[i+j] = (char)nbuf[j];
    }
    return CharString(c,nlen);
}

// native algorithm types
uint8_t* AES256::encrypt(uint8_t plaintext[16]){
    aes256_encrypt_ecb(&ctx, plaintext);
    return plaintext;
}
uint8_t* AES256::decrypt(uint8_t encrypttext[16]){
    aes256_decrypt_ecb(&ctx, encrypttext);
    return encrypttext;
}
