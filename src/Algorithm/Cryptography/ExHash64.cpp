#include "ExHash64.h"

// Steps
// 0: separate into N blocks of bitsize
// 1: Padding to given bits, get extra blocks
// 2: compute N extra 64-bit words (The real digest part, ie: sha256 has 64 words of 32-bits or 2048)
// 3: Total Compression to 'bitsize'



// Sha256  s0 = (w[i-15] rightrotate 7) xor (w[i-15] rightrotate 18) xor (w[i-15] rightshift 3)
// Sha256  s1 = (w[i- 2] rightrotate 17) xor (w[i- 2] rightrotate 19) xor (w[i- 2] rightshift 10)
// Sha256  E0=ROTR(2) xor ROTR(13) xor ROTR(22)
// Sha256  E1=ROTR(6) xor ROTR(11) xor ROTR(25)
// Sha256  W2=o0(t)
// Sha256  W9=?
// Sha256  W14=o1(t)
// Sha256  W16=o1(t-2)+(t-7)+o0(t-15)+(t-16)              w[i] = w[i-16] + s0 + w[i-7] + s1


// directly converts the selected 64-bits for a string into a block
LinkedList<uint64> str2Block(CharString str, int starti, int blocksize){
    // split string into 8 character sets to equate to a 64-bit value
    LinkedList<uint64> block;
    
    // calculate starting position and length based on blocksize
    int startx = starti*8;
    int char64len = blocksize/8;
    
    // loop through every 8 characters to make a 64-bit number
    // TODO: actually test?
    for(int j=0; j<char64len; j++){
        int starty = startx*j;
        uint64 val = 0L;
        for(int i=starty; i<starty+8; i++){
            int v = i-starty;
            if(str.getSize() > i+1){ // prevent over-reading
                // shift right inverse 8 by i number
                val += str.get()[i] << (64-8*v);
            }
        }
        block.add(val);
    }
    
    
    
    return block;
}

// adds extra 0s to end of a block that is too short
LinkedList<uint64> padBlock(LinkedList<uint64> block, int bits){
    int padsize = bits-block.size();
    int added = padsize/64;
    int ix = block.size()-1;
    
    // add blank 64-bit values
    for(int i=0;i<added;i++){
        block.add(0L);
    }
    
    // xor in original message size
    block[ix] = block[ix] ^ block.size();
    
    return block;
}


// standard xor with salt and block, sprinkle it in!
LinkedList<uint64> saltBlock(LinkedList<uint64> block, CharString salt){
    // TODO: Salt

    return block;
}



LinkedList<LinkedList<uint64>> padSplitBlocks(CharString str, CharString salt, int bits){
    LinkedList<LinkedList<uint64>> blocklists;

    if(str.getSize() < bits){
        // pre-padded length
        int zlen = str.getSize()/64;
        
        // add padded bits
        LinkedList<uint64> padded = padBlock(str2Block(str,0,zlen),bits);
        blocklists.add(saltBlock(padded,salt));
    }else if(str.getSize() > bits){
        // split blocks, then re-run through padSplitBlocks(this)
        // TODO multi-block splits
        
    }else{
        // perfect size
        blocklists.add(saltBlock(str2Block(str,0,bits),salt));
    }
    
    return blocklists;
}


// Shift right with 'looping'   (John Regehr's Implementation)
uint64 RotR(uint64 val, unsigned int n){
    uint64 mask = CHAR_BIT*sizeof(val)-1; // char mask
    n &= mask;
    return (val >> n) | (val<<((-n)&mask));
}

// first digest calculation
uint64 a1(uint64 val){
    //return RotR(val,3) ^ RotR(val,13) ^ RotR(val,46) ^ RotR(val,55);
    return RotR(val,3) ^ RotR(val,13) ^ RotR(val,55) ^ RotR(val, 61) ^ val>>4;
}

// second digest calculation
uint64 a2(uint64 val){
    return RotR(val,7) ^ RotR(val,17) ^ RotR(val,35) ^ RotR(val, 56) ^ val>>13;
}




// Generate and calculate words   (bits/64 * 2)
LinkedList<uint64> calcWords(LinkedList<uint64> block, int bits){
    // initial word values from blocks
    LinkedList<uint64> word = block; // copy over
    
    int wordsx = bits/64*4; // 4* the number of words of 64
    
    // loop through words and calculate message schedule
    for(int i=16;i<wordsx;i++){
        // Sha 256-like digest, but modified a1/a2 (or s0/s1 in sha256)
        //word[i] = word[i-16] + a1([i-15]) + word[i-6] + a2(word[i-2]);
        word.add(word[i-16] + a1(word[i-15]) + word[i-6] + a2(word[i-2]));
    }
    
    
    
    return word;
}


// compression using original compression words
LinkedList<uint64> compressWords(LinkedList<uint64> prevcompresed, LinkedList<uint64> wordlist, int bits){
    // TODO
}


LinkedList<uint64> initDigest(int bits){
    LinkedList<uint64> digest;
    int i=2;
    
    digest.add(ExHash::hconst[0]);
    for(int i=2;i<=16;i++){
        // TODO: assert max constant bitlength > given bit size
        if(bits>=64*i) 
            digest.add(ExHash::hconst[i-1]);
    }
    
    return digest;
}

CharString digestToString(LinkedList<uint64> digest){
    // TODO
}


// Main hash digest
CharString exHash2(CharString str, CharString salt, int bits){
    // pad and salt all blocks, blocksize is bits
    LinkedList<LinkedList<uint64>> blocks = padSplitBlocks(str, salt, bits);
    
    // initial value for compression digest is pre-generated from h1 to h16 (based on block bitsize)
    LinkedList<uint64> finaldigest = initDigest(bits);
    
    // loop through padded blocks
    for(int i=0;i<blocks.size();i++){
        LinkedList<uint64> block = blocks[i];
        
        // generate word list (and calculate new information using message schedule method)
        LinkedList<uint64> words = calcWords(block, bits);
        
        // compress
        finaldigest = compressWords(finaldigest, words, bits);
    }
    
    // convert finaldigest into a direct string (hex digest using other function)
    return digestToString(finaldigest);
}



CharString exHash256(CharString str, CharString salt){
    return exHash2(str,salt,256);
}

CharString exHash512(CharString str, CharString salt){
    return exHash2(str,salt,512);
}

CharString exHash1024(CharString str, CharString salt){
    return exHash2(str,salt,1024);
}






// generate 64-bit constant values
uint64 calcConst(int prime){
    uint64 v1 = std::pow(2,32)*std::cbrt(prime)*Math::E;
    uint64 v2 = std::pow(2,32)*std::cbrt(prime)*Math::PI;
    uint64 v3 = v1 << 32;
    v3 += v2;
    return v3;
}

void printLargeNumber(uint64 value){
    //cout << std::hexfloat << value << endl;
    cout<<"0x"<<hex<< *reinterpret_cast<uint64 *>(&value) << endl;
}

void exHash2ComputeConstants(){
    printLargeNumber(calcConst(2));
    printLargeNumber(calcConst(3));
    printLargeNumber(calcConst(5));
    printLargeNumber(calcConst(7));
    printLargeNumber(calcConst(11));
    printLargeNumber(calcConst(13));
    printLargeNumber(calcConst(17));
    printLargeNumber(calcConst(19));
    printLargeNumber(calcConst(23));
    printLargeNumber(calcConst(29));
    printLargeNumber(calcConst(31));
    printLargeNumber(calcConst(37));
    printLargeNumber(calcConst(41));
    printLargeNumber(calcConst(43));
    printLargeNumber(calcConst(47));
    printLargeNumber(calcConst(53));
    
    // TODO more constants for larger bit sizes (or possibly just generate on the fly?)
}
