#include "Forth.h"

Forth::Forth(){
    initWords();
}

Forth::~Forth(){}

void Forth::initWords(){
    // TODO: Perhaps make a better setup for word initializers?
    
    // NOTE: putting pseudo-code into a string is ripe for injection hacking....
    ForthWords.add("@","MemoryAccessFetch :: @ {ADDR} :--: return m[{ADDR}];");
    ForthWords.add("!","MemoryAccessStore :: ! {VAL} {ADDR} :--: m[{ADDR}]={VAL};");
    ForthWords.add("+!","MemoryAccessAddStore :--: m[{ADDR}]=m[{ADDR}]+{VAL};");
    ForthWords.add("c@","MemoryAccessCFetch :: c@ {ADDR} :--: return (char)m[{ADDR}];");
    ForthWords.add("c!","MemoryAccessCStore :: c! {VAL} {ADDR} :--: m[{ADDR}]=(char){VAL};");
    ForthWords.add("2@","MemoryAccess2Fetch :: 2@ {ADDR} :--: return [m[{ADDR}], m[{ADDR}+1];");
    ForthWords.add("2!","MemoryAccess2Store :--: ");
    ForthWords.add("f@","MemoryAccessFloatFetch :--: ");
    ForthWords.add("f!","MemoryAccessFloatStore :--: ");
    ForthWords.add("sf@","MemoryAccessSingleFloatFetch :--: ");
    ForthWords.add("sf!","MemoryAccessSingleFloatStore :--: ");
    // TODO: add more words
}
