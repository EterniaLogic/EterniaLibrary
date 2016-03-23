//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#include "CharString.h"
//#include "SplitResult.h"

using namespace std;

// pre-initialize
CharString::CharString(){
      stringx = new char();
      len = 0;
}

CharString::CharString(const char* stringg, const int length){
      //const int lenc = length+1;
  //char cc[lenc];
  char* cc = new char();
  std::strcpy(cc, stringg);

  stringx = cc;
  len = length;
}

CharString::CharString(const char* stringg){
  int c = 0;
  // quick loop through to find exact size c.
  while(stringg[c] != 0x0 /* || stringg[c] > 32 */){c++;}

  char cc[(unsigned int)c];
  strcpy(cc, stringg);

  stringx = cc;
  len = c;
}

// populate charString and initialize it with data.
CharString::CharString(char* stringg, int length){
      stringx = stringg;
      len = length;
}

// populate charString and initialize it.
// pre-determine what the length is.
CharString::CharString(char* stringg){
      this->set(stringg);
}

CharString::CharString(string &stringg){
  stringx = (char*)stringg.c_str();
  len = stringg.length();
}

CharString::CharString(const std::string &stringg){
  stringx = (char*)stringg.c_str();;
  len = stringg.length();
}

void CharString::operator =(char* stringg){
  set(stringg);
}

bool CharString::isValidCharString(){
    if(this == 0x0) return false;
    if(this->stringx == 0x0) return false;

    return true;
}

/* Desc: Takes data from a string and splits it using a splitter
* Input: String str, it's length, single-character splitter
* Output: SplitResult from the splitting
*/
SplitResult* CharString::split(char splitter,char stopper){
      if(!isValidCharString()) return new SplitResult(0);

      SplitResult* sr = new SplitResult(100);

      int carrot1=0,carrot2=0,commaplace=0; // positions for exclusive selection
  // loop through
      for(int i=0;i<len;i++){
              // if this is the stopper
              if(stringx[i] == stopper){
                      if(commaplace >= 4) commaplace = 0; // reset it!
                      carrot2++;
                      commaplace++;
              }
      // else make sure that the carrot is in place and populate.
              else if(stringx[i] == splitter && (commaplace >= 3 || commaplace == 0)){ // Is same as splitter?
                      const int slen = carrot2-carrot1;
                      char* cc = new char[slen];
                      for(int j=carrot1;j<carrot2;j++) cc[j-carrot1] = stringx[j]; // populate charString

                      sr->add(cc,slen); // add data!
                      carrot1 = i+1;
                      carrot2 = i+1;

              }else{
          // else, just increment.
                      carrot2++;
              }
      }

      // If size is greater then override, and there is a change in carrots
      if(carrot2 > carrot1){
              const int slen = carrot2-carrot1; // length of split
              char* cc = new char[slen]; // use up some space
              for(int j=carrot1;j<carrot2;j++) cc[j-carrot1] = stringx[j]; // populate charString

              sr->add(cc,slen); // Add to split result
      }

      return sr;
}

/*
* Replaces needle a with object b inside the haystack.
* Target: this
* Input: 2 char* strings used as needles
* Output: none
*/
void CharString::replace(char* a, char* b){
    if(!isValidCharString()) return;
    // resizes charString if required. Also shifts charString upon resize.
    // for(int i=copyx;i<len;i++){ out[i-copyx] = stringx[i]; }

    // ok, now we will convert a and b into charStrings.
    CharString* A = new CharString(a);
    CharString* B = new CharString(b);

    // special case, Singly repeated (lengths 1, 0)
    if(B->getSize() == 0){
        // store result temporarily
        int tlen = 0;
        char* tt = clone()->get();
        // filter out all results
        for(int i=0;i<this->len;i++){
            // find all that are not occurences
            if(stringx[i] != *a){
              tt[tlen] = stringx[i];
              tlen++;
            }
        }
        stringx = tt;
        len=tlen;
    }else{

        // find occurences and auto-patch them.
        int iniX = -1, endX=-1;
        for(int i=0;i<this->len;i++){
            int lenAwe = endX-iniX;
            if(stringx[i] == a[lenAwe]){
                if(lenAwe+1 >= A->getSize()){
                    // patch it up!
                    if(A->getSize() == B->getSize()){
                        // same sizes, don't do anything special. Just a copy-over.
                        for(int i=0;i<A->getSize();i++) stringx[iniX+i] = b[i];
                    }
                    else if(A->getSize() > B->getSize()){
                        // downsize the string.
                        int change = A->getSize() - B->getSize();
                        // downsize.
                        for(int i=endX-change;i<len-1;i++){ stringx[i] = stringx[i+1]; }
                        len--;
                        // replace.
                        for(int i=0;i<B->getSize();i++) stringx[iniX+i] = b[i];
                    }
                    else if(A->getSize() < B->getSize()){
                        // upsize the string.
                        int change = B->getSize() - A->getSize();
                        for(int i=endX+change;i<len-1;i++){ stringx[i] = stringx[i+1]; }
                        len++;
                        // replace.
                        for(int i=0;i<B->getSize();i++) stringx[iniX+i] = b[i];
                    }
                }else{
                    // set initial vertex if possible.
                    iniX = (iniX==1) ? i : iniX;

                    // quite not there yet... lets increase endX
                    endX = i;
                }
            }else{
                // no go!
                iniX = endX = -1;
            }
        }
    }
}

/*
* Moves all characters in a string to the left. This cuts off characters from the beginning of string
* Input: the start of the cutting head.
* output: Modified char* string of end size
*/
char* CharString::shiftLeft(const int lenh){
      if(!isValidCharString()) return (char*)"";
      const int lenx = len-lenh;
      char* out = new char[lenx];

      int copyx = lenh; // start of move location
      for(int i=copyx;i<len;i++){ out[i-copyx] = stringx[i]; }
      return out;
}

// basic function that returns the string's value
char* CharString::get(){
  // prevents any extra endings to stringx
      //stringx[len] = '\0';
      return stringx;
}

// returns the size.
int CharString::getSize(){
      return len;
}

//allows you to set the size of the string
void CharString::setSize(int i){
      len = i;
}

/* Desc: converts entire character string to an integer
*  Input: char* list of characters, length automatically detected.
*  output: integer converted from char* list.
*/
int CharString::getInt(){
      if(!isValidCharString()) return 0;
      int size=len; // size from CharString len


      int out = 0;
      bool neg = false;
      if(stringx[0] == '-') { neg=true; stringx = shiftLeft(1); size--; } // removes sign
      for(int i=0;i<size;i++){
              int c = (int)(stringx[i])-48;
              if(c == -48) continue; // prevents annoying bug :/
              int digit = size-(i+1);

              //get exponent of 10.
              int exp = 1;
              for(int j=0;j<digit;j++) exp*=10; // expotentiate

              out += exp * c;
      }
      if(neg) out*=-1;
      //cout << out << endl;
      return out;
}

// takes input and changes current
void CharString::set_(const char* stringg, const int length){
  char* cc = new char();
  strcpy(cc, stringg);
  stringx = cc;
  len = length;
}

// takes input and changes current
void CharString::set(char* stringg, int length){
      stringx = stringg;
      len = length;
}

// takes input and changes current
void CharString::set(char* stringg){
      int c = 0;
  // quick loop through to find exact size c.
      while(stringg[c] != 0x0 || stringg[c] > 32){c++;}
  // set the data into place.
      this->set(stringg,c);
}

// fun thing to write :D

// Desc:  Custom function to convert integers to a list of characters (string)
// Input:  Integer (int)
// return: character string (CharString)
CharString* CharString::ConvertFromInt(int integer){
      return ConvertFromLong((long)integer);
}

CharString* CharString::ConvertFromLong(long integer){
    const int ASCIIOffset = 48; // offset on the ASCII chart

    // gets the digits based on modulus (to the 5th digit, [+-]32k is max/min)
    int len = 0;
    bool neg = false;

    // is negative?
    if(integer < 0) neg = true;
    if(neg) integer = integer*(-1); // remove negative sign, we know the negation. :D

    // determine # of digits
    for(int i=0;i<20;i++){
        int exp = 1;
        for(int j=0;j<i;j++) exp *= 10; // set exponent 10^i => exp
        if((integer % (exp)) != integer) len++; // if integer mod exp is not equal to self, it is a digit (10/1000 = 10)
    }

    const int tlen = len + (neg ? 1 : 0); // constify length, if negative, add digit.
    char* out = new char[tlen];

    int t=0; // temp var used to store modulus digit addifier
    int kk = neg ? 1 : 0;
    int offset = neg ? -2 : -1; // offsets char based on neg
    if(neg) out[0] = '-';
    for(int i = tlen+offset; i >= 0; i--){
        int exp = 1;
        for(int j=0;j<i;j++) exp *= 10; // set exponent 10^i => exp
        int digit = integer / exp -(t*10);
        t *= 10; // shift all digits in t left 1
        t += digit; // enter digit into very last slot of t
        out[kk] = (char)(digit+ASCIIOffset);
        kk++; // increment out digit
    }
    CharString* g = new CharString();
    g->set(out,tlen);
    return g;


      /*if(integer == 0){
          char* c = new char[2];
          strcpy(c,"0");
          CharString* g = new CharString();
          g->set(c,1);
          return g;
      }else{
          // gets the digits based on modulus (to the 5th digit, [+-]32k is max/min)
          int len = 0;
          bool neg = false;

          // is negative?
          if(integer < 0) neg = true;
          if(neg) integer = integer*(-1); // remove negative sign, we know the negation. :D

          // determine # of digits
          do {
          integer /= 10;
          len++;
      } while (integer > 0);


          /*for(int i=0;i<30;i++){
                  int exp = 1;
                  for(int j=0;j<i;j++) exp *= 10; // set exponent 10^i => exp
                  if((integer % (exp)) != integer) len++; // if integer mod exp is not equal to self, it is a digit (10/1000 = 10)
          }* /

          const int tlen = len + (neg ? 1 : 0); // constify length, if negative, add digit.
          char* out = new char[tlen];

          int t=0; // temp var used to store modulus digit addifier
          int kk = neg ? 1 : 0;
          int offset = neg ? -2 : -1; // offsets char based on neg
          if(neg) out[0] = '-';
          for(int i = tlen+offset; i >= 0; i--){
                  int exp = 1;
                  for(int j=0;j<i;j++) exp *= 10; // set exponent 10^i => exp
                  int digit = integer / exp -(t*10);
                  t *= 10; // shift all digits in t left 1
                  t += digit; // enter digit into very last slot of t
                  out[kk] = (char)(digit+ASCIIOffset);
                  kk++; // increment out digit
          }
          CharString* g = new CharString();
          g->set(out,tlen);
          return g;
      }*/
}


/* Desc: direct compare with a char string
*  Input: char* and it's length
*  Output: boolean
*/
bool CharString::Compare(char* b,int lenx){
      if(!isValidCharString()) return false;
      bool r = true;

      // else, loop through the string
      for(int i=0;i<lenx;i++){
              if(this->stringx[i] != b[i]) {
                      r=false;
              }
      }

      return r;
}

// compare where case is useless
bool CharString::CompareNoCase(char* b,int lenx){
      if(!isValidCharString()) return false;
      bool r = true;

      for(int i=0;i<lenx;i++){
              char char1 = this->stringx[i], char2 = b[i];
              bool c1 = char1 == char2;
              bool c2 = ((((int) char1) < 123) && char1+32 == char2); // char1 is lower case?
              bool c3 = ((((int) char1) > 64) && char1 == char2+32); // char1 is upper case?
              if(c1 || c2 || c3) {
                      r=false;
              }
      }

      return r;
}

// high-speed string comparison
bool CharString::Compare(CharString* b){
      return Compare(b->get(),b->getSize());
}

// high-speed string comparison
bool CharString::Compare(CharString* b, bool useCase){
      if(useCase){
              return Compare(b->get(),b->getSize());
      }else{
              return CompareNoCase(b->get(),b->getSize());
      }
}

// Compares with another string to determine placement in a sorting scheme.
SortType CharString::SortCompare(CharString* str){
      if(!isValidCharString()) return *(new SortType());
      SortType ret = SSame;
      // if str is "longer" then this, than it is more "precise".

      int minlen = len < str->getSize() ? len : str->getSize();
      char* c = str->get();
      // compare visible lengths. Note: if this is shorter then str, then it may be much less.
      // AABB
      // AABBc
      // AABBCC
      // aabb
      //cout << "COMPARE: " << stringx << " with " << c << endl;
      for(int i=0;i<minlen;i++){
              //cout << (stringx[i] > c[i]) << " - " << (stringx[i] < c[i]) << endl;
              if(stringx[i] > c[i]){
                      ret = SAfter;
              }else if(stringx[i] < c[i]){
                      ret = SBefore;
              }
      }

      // if they are the same at length then:
      if(ret == SSame && len < str->getSize()){
              // str is greater.
              ret = SBefore;
      }else if(ret == SSame && len > str->getSize()){
              // this is greater.
              ret = SAfter;
      }
      //cout << ret << endl;
      return ret;
}

// contains single character?
bool CharString::contains(char* c){
      if(!isValidCharString()) return false;
      // test to make sure this is not null
      if(this == 0x0) return *(new SortType());

      // test to make sure that the string is usable
      if(this->stringx == 0x0) return *(new SortType());

      bool co=false;
  // loop through length
      for(int i=0;i<this->len;i++){
      // does string contain this EXACT single character?
              if(stringx[i] == *c){
                      co=true;
              }
      }
      return co;
}


void CharString::concata_(const char* str, const int lenx){
  if(!isValidCharString()) return;
  char* cc = new char();
      std::strcpy(cc,str);
  concata(cc, lenx);
}

// Combine CharStrings after the current charString.=
void CharString::concata(char* str, int lenx){
      // initialize variables
      if(!isValidCharString()) return;
      int lena = len;
      int lenb = lenx;
      const int lenab = lena+lenb;
      char* tmp = new char[lenab+1];

      for(int i=0;i<lenab+1;i++){
              tmp[i] = '\0';
      }

      // add to the beginning.
      for(int i=0;i<lena;i++){
              tmp[i] = stringx[i];
      }

      // append after beginning.
      for(int i=0;i<lenb;i++){
              tmp[i+(lena)] = str[i];
      }

      // imprint changes
      this->set(tmp,lenab);
}

/* Combine CharStrings after the current charString.
*/
void CharString::concata(CharString* str){
      concata(str->get(),str->getSize());
}

// Combine CharStrings before the current charString.=
void CharString::concatb(char* str, int lenx){
      // initialize variables
      if(!isValidCharString()) return;
      int lena = lenx;
      int lenb = len;
      const int lenab = lena+lenb;
      char* tmp = new char[lenab+1];

              for(int i=0;i<lenab+1;i++){
                      tmp[i] = '\0';
              }

      // add to the beginning.
      for(int i=0;i<lena;i++){
              tmp[i] = str[i];
      }

      // append after beginning.
      for(int i=0;i<lenb;i++){
              tmp[i+(lena)] = stringx[i];
      }

      //cout << "tmp: '" << tmp << "' (" << lena << "," << lenb << "="<< lenab <<")" << endl;
      // imprint changes
      this->set(tmp,lenab);
}

// Combine CharStrings before the current charString.
void CharString::concatb(CharString* str){
      concatb(str->get(),str->getSize());
}

//shortcut for Compare command, must use * before each to use :/
bool CharString::operator==(CharString* ins){
      return Compare(ins);
}

// determines if the CharString is Empty
bool CharString::isEmpty(){
      if(!isValidCharString()) return false;
      return (stringx[0] == 0x0 || len == 0);
}

CharString* CharString::clone(){
      if(!isValidCharString()) return new CharString();
      char* cc = new char();
      for(int i=0;i<=len;i++) cc[i] = '\0';
      for(int i=0;i<len;i++){
              cc[i] = stringx[i];
      }

      return new CharString(cc,len);
}

bool CharString::startsWith(CharString* starter){
  if(!isValidCharString()) return false;
  int lenx = starter->getSize();
  if(lenx > len) return false; // cannot start with something that is bigger!
  // compare each
  for(int l = 0;l<lenx; l++){
      if(stringx[l] != starter->get()[l]) return false;
  }
  return true;
}
bool CharString::endsWith(CharString* ender){
  if(!isValidCharString()) return false;
  int lenx = ender->getSize();
  if(lenx > len) return false; // cannot end with something that is bigger!
  // compare each
  for(int l = 0;l<lenx; l++){
      int tat = (len-lenx)-1; // location to start at for compare
      if(stringx[tat] != ender->get()[l]) return false;
  }
  return true;
}

