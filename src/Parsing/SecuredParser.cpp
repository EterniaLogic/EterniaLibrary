#include "SecuredParser.h"

// initialize the parser
SecuredParser::SecuredParser(CharString* k, CharString* File){
    // copy over key
    for(int i=0;i<32;i++){
      key[i] = k->get()[i];
    }

    file = File;

    aes256_init(&ctx, key);
}

SecuredParser::~SecuredParser(){
    aes256_done(&ctx);
}

// read every single character in the file
CharString* SecuredParser::getText(){
  //aes256_decrypt_ecb(&ctx, buf);
  ifstream fileT;
  fileOpen(fileT, file->get());

  // TODO: return data?
}

// read every line in the file
LinkedList<CharString>* SecuredParser::getLines(){
  CharString* text = getText();
  LinkedList<CharString>* list = new LinkedList<CharString>();

  // TODO: loop through?

  return list;
}

// encrypt text
CharString* SecuredParser::encodeText(CharString* ss){
  aes256_encrypt_ecb(&ctx, (unsigned char*)ss->get());

  // TODO: finish aes, ecb is start here
}
