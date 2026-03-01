

#include "CharString.h"

#define SIZEOFA(x) (sizeof(x) / sizeof(x[0]))


CharString CS_TAB = CharString("\t\0",1); // add \0 at the end just in case?
CharString CS_NL = CharString("\n\0",1);

using namespace std;



// pre-initialize
CharString::CharString() {
    set("\0");
}

CharString::~CharString(){
    /*if(stringx != 0x0)
        delete [] stringx;*/
    stringx = 0x0;
}

template<std::size_t N>
CharString::CharString(const char (&stringg)[N]){
	stringx=0x0;
	len=0;
	this->set(stringg);
}

CharString::CharString(const char* stringg, const int length) {
	stringx=0x0;
	len=0;
    
    this->set((char*)stringg,length);
}

CharString::CharString(const char* stringg) {
    set((char*)stringg);
}

// populate charString and initialize it with data.
CharString::CharString(char* stringg, int length) {
	stringx=0x0;
	len=0;
    this->set((char*)stringg, length);
}

// populate charString and initialize it.
// pre-determine what the length is.
CharString::CharString(char* stringg) {
	stringx=0x0;
	len=0;
    this->set(stringg);
}

CharString::CharString(string &stringg) {
    stringx = (char*)stringg.c_str();
    len = stringg.length();
    *this = clone(); // since strings might 'dissapear' due to freeing resources
}

CharString::CharString(const std::string &stringg) {
    stringx = (char*)stringg.c_str();;
    len = stringg.length();
    *this = clone(); // since strings might 'dissapear' due to freeing resources
}

CharString CharString::operator =(char* stringg) {
    set(stringg);
    return *this;
}

bool CharString::isValidCharString() {
    if(this == 0x0) return false;
    if(this->stringx == 0x0) return false;

    return true;
}

// checks for "0-9, -, ."
bool CharString::isValidNumber(){
    if(!isValidCharString()) return false;

    // loop through string, find non-numbers
    //  Floats have e or E for exponent for scientific numbers
    for(int i=0;i<len;i++){
        if(stringx[i] > '9' && stringx[i] < '0' && stringx[i] != '-' && stringx[i] != '.'){
            return false;
        }else if((stringx[i] != 'e' || stringx[i] != 'E') && i < 0 && i >= len-1){
            return false;
        }
    }

    return true;
}

// checks for a valid scientific number (or infinity / NaN)
bool CharString::isValidScientific(){
    bool hasE = false;
    bool hasPeriod = false;

    if(len < 6) return false; // number has to have at least 6 digits: 1.0e+1

    for(int i=0;i<len;i++){
        // search for e,
        if(stringx[i] == '.'){
            hasPeriod=true;
        }else if((stringx[i] == 'e' || stringx[i] == 'E') && i > 0 && i < len-1){
            hasE=true;
        }
    }

    return hasE && hasPeriod;
}

/* Desc: Takes data from a string and splits it using a splitter
* Input: String str, it's length, single-character splitter
* Output: SplitResult from the splitting
*/
LinkedList<CharString> CharString::split(char splitter,char stopper) {
    LinkedList<CharString> sr;
    int i=0,j=0,carrot1=0,carrot2=0,commaplace=0; // positions for exclusive selection
    char* cc;
    int temp = 0;

    if(!isValidCharString()) return sr;

    // loop through
    for(i=0; i<len; i++) {
        // if this is the stopper
        if(stringx[i] == stopper) {
            if(commaplace >= 4) commaplace = 0; // reset it!
            carrot2++;
            commaplace++;
        }
        // else make sure that the carrot is in place and populate.
        else if(stringx[i] == splitter && (commaplace >= 3 || commaplace == 0)) { // Is same as splitter?
            cc = (char*)calloc(carrot2-carrot1+1, sizeof(char));
            for(j=carrot1; j<carrot2; j++) cc[j-carrot1] = stringx[j]; // populate charString

            cc[carrot2-carrot1] = '\0';
            sr.add(CharString(cc,carrot2-carrot1)); // add data!
            carrot1 = i+1;
            carrot2 = i+1;

        } else {
            // else, just increment.
            carrot2++;
        }
    }

    // If size is greater then override, and there is a change in carrots
    if(carrot2 > carrot1) {
        cc = (char*)calloc(carrot2-carrot1+1, sizeof(char));
        for(j=carrot1; j<carrot2; j++) cc[j-carrot1] = stringx[j]; // populate charString
        cc[carrot2-carrot1] = '\0';
        //cout << "splitcarrot " << carrot1 << "->" << carrot2 << " =" << cc << endl;
        sr.add(CharString(cc,carrot2-carrot1)); // Add to split result
    }

    return sr;
}


/* Desc: Takes data from a string and splits it using a splitter
* Input: String str, it's length, single-character splitter
* Output: SplitResult from the splitting
*/
LinkedList<CharString> CharString::split(CharString splitter) {
    LinkedList<CharString> sr;
    int i=0,carrot=0; // positions for exclusive selection
    int spliti=0; // used when comparing string with splitter.
    bool splitstart=false;
    char* tmp;

    if(!isValidCharString()) return sr;

    // loop through!
    for(i=0;i<getSize();i++){
        if(i+1 >= getSize() && i-carrot > 0){ // Add the end of the string
            //cout << "SPLIT:: EOS " << endl;
            sr.add(substr(getSize()-1-(i-carrot), 1+i-carrot));
        }
        
        
        if(stringx[i] == splitter.get()[spliti] && (splitstart || spliti==0)){
            splitstart = true;
            if(spliti+1 >= splitter.getSize()){
                // split done!
                sr.add(substr(carrot, i-splitter.getSize()+1-carrot));
                splitstart = false;
                spliti=0;
                carrot = i+1;
            }else spliti++;
        }
    }

    return sr;
}


/*
* Replaces needle a with object b inside the haystack.
* Target: this
* Input: 2 char* strings used as needles
* Output: none
*/
void CharString::replace(char* a, char* b) {
    if(!isValidCharString()) return;
    // resizes charString if required. Also shifts charString upon resize.
    // for(int i=copyx;i<len;i++){ out[i-copyx] = stringx[i]; }

    // ok, now we will convert a and b into charStrings.
    CharString A = CharString(a);
    CharString B = CharString(b);

    // special case, Singly repeated (lengths 1, 0)
    if(B.getSize() == 0) {
        // store result temporarily
        int tlen = 0;
        char* tt = clone().get();
        // filter out all results
        for(int i=0; i<this->len; i++) {
            // find all that are not occurences
            if(stringx[i] != *a) {
                tt[tlen] = stringx[i];
                tlen++;
            }
        }
        stringx = tt;
        len=tlen;
    } else {

        // find occurences and auto-patch them.
        int iniX = -1, endX=-1;
        for(int i=0; i<this->len; i++) {
            int lenAwe = endX-iniX;
            if(stringx[i] == a[lenAwe]) {
                if(lenAwe+1 >= A.getSize()) {
                    // patch it up!
                    if(A.getSize() == B.getSize()) {
                        // same sizes, don't do anything special. Just a copy-over.
                        for(int i=0; i<A.getSize(); i++) stringx[iniX+i] = b[i];
                    } else if(A.getSize() > B.getSize()) {
                        // downsize the string.
                        int change = A.getSize() - B.getSize();
                        // downsize.
                        for(int i=endX-change; i<len-1; i++) {
                            stringx[i] = stringx[i+1];
                        }
                        len--;
                        // replace.
                        for(int i=0; i<B.getSize(); i++) stringx[iniX+i] = b[i];
                    } else if(A.getSize() < B.getSize()) {
                        // upsize the string.
                        int change = B.getSize() - A.getSize();
                        for(int i=endX+change; i<len-1; i++) {
                            stringx[i] = stringx[i+1];
                        }
                        len++;
                        // replace.
                        for(int i=0; i<B.getSize(); i++) stringx[iniX+i] = b[i];
                    }
                } else {
                    // set initial vertex if possible.
                    iniX = (iniX==1) ? i : iniX;

                    // quite not there yet... lets increase endX
                    endX = i;
                }
            } else {
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
char* CharString::shiftLeft(const int x) {
    if(!isValidCharString()) return (char*)"";
    const int lenx = len-x;
    if(lenx < 0) return (char*)"";
    
    char* out = new char[lenx+1];

    for(int i=x; i<len; i++) {
        out[i-x] = stringx[i];
    }
    out[lenx] = 0x0;
    stringx = out;
    return stringx;
}

// grabs a new string of size len, copy it over
CharString CharString::substr(int index, int lenx){
    char* returnstr = new char[lenx+1];
    for(int i=0;i<lenx+1;i++){
        returnstr[i] = 0;
    }
    
    int copylen = ((index+lenx) > len) ? len-(lenx+index) : lenx;
    
    if(lenx < 0) return CharString();
    
    for(int i=index;i< index+lenx;i++){
        returnstr[i-index] = stringx[i]; 
    }
    
    return CharString(returnstr, lenx);
}

// basic function that returns the string's value
char* CharString::get() {
    // prevents any extra endings to stringx
    //stringx[len] = '\0';
    
    if(this == 0x0 || stringx == 0x0) return (char*)"";
    return stringx;
}

// returns the size.
int CharString::getSize() {
    return len;
}

//allows you to set the size of the string
void CharString::setSize(int i) {
    len = i;
}


long CharString::getLong() {
    if(!isValidNumber()) return 0;
    int size=len; // size from CharString len

    if(contains(".")) return (long)getFloat();


    long out = 0;
    bool neg = false;
    if(stringx[0] == '-') {
        neg=true;    // removes sign
        stringx = shiftLeft(1);
        len--;
    }

    if(stringx[0] == '+') {
        stringx = shiftLeft(1);
        len--;
    }

    for(int i=0; i<size; i++) {
        long c = (long)(stringx[i])-48;
        if(c == -48) continue; // prevents annoying bug :/
        long digit = size-(i+1);

        //get exponent of 10.
        long exp = 1;
        for(long j=0; j<digit; j++) exp*=10; // expotentiate

        out += exp * c;
    }
    if(neg) out*=-1;
    //cout << out << endl;
    return out;
}


/* Desc: converts entire character string to an integer
*  Input: char* list of characters, length automatically detected.
*  output: integer converted from char* list.
*/
int CharString::getInt() {
    if(!isValidNumber()) return 0;
    int size=len; // size from CharString len

    if(contains(".")) return (int)getFloat();


    int out = 0;
    bool neg = false;
    if(stringx[0] == '-') {
        neg=true;    // removes sign
        stringx = shiftLeft(1);
        len--;
    }

    if(stringx[0] == '+') {
        stringx = shiftLeft(1);
        len--;
    }

    for(int i=0; i<size; i++) {
        int c = (int)(stringx[i])-48;
        if(c == -48) continue; // prevents annoying bug :/
        int digit = size-(i+1);

        //get exponent of 10.
        int exp = 1;
        for(int j=0; j<digit; j++) exp*=10; // expotentiate

        out += exp * c;
    }
    if(neg) out*=-1;
    //cout << out << endl;
    return out;
}

// returns a scientific float value
// string must contain "e" or "E" between two numbers
float CharString::getScientific(float val){
    // get location of E
    int eloc = -1;
    int sloc = -1; // Sign location
    int js = 0;
    int i=0;
    CharString cval;
    float vale = 0.0;
    char *valg = 0x0;
    int sizeE = 0;

    for(int i=len-1; i>=0; i--) {
        if(stringx[i] == 'e' || stringx[i] == 'E'){
            eloc = i;
        }
    }

    if(eloc == -1) return val; // location of the e value

    // get value into a CharString
    sizeE = len-eloc-2;
    valg = (char*)calloc(sizeE+2, sizeof(char));

    // copy the data over
    for(i=eloc+1; i < len; i++) {
        valg[js] = stringx[i];
        js++;
    }

    cval.set(valg);

    // use power
    vale = Math::pow(10,cval.getInt());

    return val*vale;
}

/* Desc: converts entire character string to an float
*  Input: char* list of characters, length automatically detected.
*  output: float converted from char* list.
*/
float CharString::getFloat() {
    if(!isValidNumber()) return 0;

    int sizey=len; // size from CharString len
    float c=0;
    int digit = 0;
    int periodloc = -1;
    float exp;
    float out = 0.0;
    bool neg = false;
    int i = 0;

    if(stringx[0] == '-') {
        neg=true;    // removes sign
        stringx = shiftLeft(1);
        sizey--;
    }


    // Find period (if doesnt exist, just do getInt() and return float)
    for(i=sizey-1; i>=0; i--) {
        if(stringx[i] == '.'){
            periodloc = i;
            i=-1;
        }
    }

    if(periodloc == -1) return (float)getInt();

    // 0.0001  <-- digit = -4, len=6
    // -12038.22828282302012031929319 <-- digit = -24

    for(i=0; i<sizey; i++) {
        if(stringx[i] == 0x0 || stringx[i] == '.') continue; // 0x0 '\0' value, ignore
        c = (int)(stringx[i])-48;
        digit = periodloc-i+((periodloc-i > 0) ? -1 : 0); // 5-30 = -25

        exp = Math::pow(10, digit);

        out += exp * c;
    }
    if(neg) out *= -1;

    if(isValidScientific()) return getScientific(out);

    return out;
}

std::string CharString::getString(){
	return string(get());
}

template<std::size_t N>
void CharString::set_(const char(&val)[N]){
	stringx = val;
	len = N;
}

// takes input and changes current
void CharString::set_(const char* stringg, const int length) {
    if(length < 1){
        stringx = 0x0;
        len = length;
        return;
    }

    int clen = SIZEOFA(stringg);
    char* cc = (char*)calloc(length+1, sizeof(char));
    strcpy(cc, stringg);

    stringx = cc;
    len = length;
}

// takes input and changes current
void CharString::set(char* stringg, int length) {
    stringx = stringg;
    len = length;
}

template<std::size_t N>
void CharString::set(const char(&val)[N]){
	stringx = (char*)val;
	len = N;
}

// takes input and changes current
void CharString::set(char* stringg) {
    // set the data into place.
    len=0;
    if(stringg == 0x0) {
        this->set((char*)malloc(1),0);
    }else{
        //while(stringg[len] > 0) len++;
        
        // assume that \0 or NULL is the end of said string.
        std::string str(stringg);
        
        //this->set(stringg,SIZEOFA(stringg));
        this->set(stringg,str.length());
        *this=clone();
    }
}


template<std::size_t N>
void CharString::setPtr(const char(&val)[N]){
	stringx = val;
	len = N;
}

void CharString::setPtr(char* data, int length) { // sets a raw pointer, no changes or copying.
    stringx = data;
    len = length;
}


void CharString::set(CharString stringg){
    set(stringg.get(), stringg.getSize());
}





bool CharString::equals(CharString b){
    return compare(b);
}


template<std::size_t N>
bool CharString::compare(const char(&val)[N]){
	return compare(val, N);
}

/* Desc: direct compare with a char string
*  Input: char* and it's length
*  Output: boolean
*/
bool CharString::compare(char* b,int lenx) {
    return compare((const char*)b, lenx);
}


bool CharString::compare(const char* b,int lenx) {
    if(!isValidCharString()) return false;
    if(b == 0x0) return false;
    if(lenx != getSize()) return false;
    bool r = true;

    // else, loop through the string
    for(int i=0; i<lenx; i++) {
        if(this->stringx[i] != b[i]) {
            r=false;
        }
    }

    return r;
}

// compare where case is useless
bool CharString::compareNoCase(char* b,int lenx) {
    if(!isValidCharString()) return false;
    bool r = true;

    for(int i=0; i<lenx; i++) {
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
bool CharString::compare(CharString b) {
    return compare(b.get(),b.getSize());
}

// high-speed string comparison
bool CharString::compare(CharString b, bool useCase) {
    if(useCase) {
        return compare(b.get(),b.getSize());
    } else {
        return compareNoCase(b.get(),b.getSize());
    }
}

// Compares with another string to determine placement in a sorting scheme.
SortType CharString::SortCompare(CharString str) {
    if(!isValidCharString()) return SortType();
    SortType ret = SSame;
    // if str is "longer" then this, than it is more "precise".

    int minlen = len < str.getSize() ? len : str.getSize();
    char* c = str.get();
    // compare visible lengths. Note: if this is shorter then str, then it may be much less.
    // AABB
    // AABBc
    // AABBCC
    // aabb
    //cout << "COMPARE: " << stringx << " with " << c << endl;
    for(int i=0; i<minlen; i++) {
        //cout << (stringx[i] > c[i]) << " - " << (stringx[i] < c[i]) << endl;
        if(stringx[i] > c[i]) {
            ret = SAfter;
        } else if(stringx[i] < c[i]) {
            ret = SBefore;
        }
    }

    // if they are the same at length then:
    if(ret == SSame && len < str.getSize()) {
        // str is greater.
        ret = SBefore;
    } else if(ret == SSame && len > str.getSize()) {
        // this is greater.
        ret = SAfter;
    }
    //cout << ret << endl;
    return ret;
}

// contains single character?
bool CharString::contains(char* c) {
    if(!isValidCharString()) return false;
    // test to make sure this is not null
    if(this == 0x0) return false;

    // test to make sure that the string is usable
    if(this->stringx == 0x0) return false;

    // loop through length
    for(int i=0; i<this->len; i++) {
        // does string contain this EXACT single character?
        if(stringx[i] == *c) {
            return true;
        }
    }
    return false;
}

bool CharString::contains(const char* c){
	return contains((char*)c);
}


void CharString::concata_(const char* str, const int lenx) {
    if(!isValidCharString()) return;
    char* cc = new char();
    strcpy(cc,str);
    concata(cc, lenx);
}

template<std::size_t N>
void CharString::concata(char const (val)[N]){
    char* v = (char*)val;
	concata(v,(int)N);
}


// Combine CharStrings after the current charString.=
void CharString::concata(char* str, int lenx) {
    // initialize variables
    if(this->len == 0){
        stringx = str;
        len = lenx;
        return;
    }

    if(lenx == 0) return;
    
    char* tmp = new char[len+lenx+1];

    for(int i=0; i<len+lenx+1; i++) {
        tmp[i] = '\0';
    }

    // add original to the beginning.
    for(int i=0; i<len; i++) {
        tmp[i] = stringx[i];
    }

    // append after beginning.
    for(int i=0; i<lenx; i++) {
        tmp[i+len] = str[i];
    }

    // imprint changes
    //cout << "CONCAT(" << len+lenx << "): " << tmp << endl;
    //if(stringx != 0x0 && len>0) delete [] stringx;
    this->stringx = tmp;
    this->len = len+lenx;
}

/* Combine CharStrings after the current charString.
*/
void CharString::concata(CharString str) {
    concata(str.get(),str.getSize());
}

template<std::size_t N>
void CharString::concatb(const char(&val)[N]){
	concatb(val,N);
}

// Combine CharStrings before the current charString.=
void CharString::concatb(char* str, int lenx) {
    // initialize variables
    if(!isValidCharString() || !CharString(str,len).isValidCharString()) return;
    int lena = lenx;
    int lenb = len;
    const int lenab = lena+lenb;
    char* tmp = new char[lenab+1];

    for(int i=0; i<lenab+1; i++) {
        tmp[i] = '\0';
    }

    // add to the beginning.
    for(int i=0; i<lena; i++) {
        tmp[i] = str[i];
    }

    // append after beginning.
    for(int i=0; i<lenb; i++) {
        tmp[i+(lena)] = stringx[i];
    }

    //cout << "tmp: '" << tmp << "' (" << lena << "," << lenb << "="<< lenab <<")" << endl;
    // imprint changes
    delete[] stringx; // added [] to remove undefined behavior and malloc crashes
    this->set(tmp,lenab);
}

// Combine CharStrings before the current charString.
void CharString::concatb(CharString str) {
    concatb(str.get(),str.getSize());
}

//shortcut for Compare command, must use * before each to use :/
bool CharString::operator==(CharString ins) {
    return compare(ins);
}

// determines if the CharString is Empty
bool CharString::isEmpty() {
    if(!isValidCharString()) return false;
    return (stringx[0] == 0x0 || len == 0);
}

CharString CharString::clone() {
    if(!isValidCharString()) return CharString();
    char* cc = (char*)malloc(len);
    for(int i=0; i<=len; i++) cc[i] = '\0';
    for(int i=0; i<len; i++) {
        cc[i] = stringx[i];
    }

    return CharString(cc,len);
}

bool CharString::startsWith(CharString starter) {
    if(!isValidCharString()) return false;
    int lenx = starter.getSize();
    if(lenx > len) return false; // cannot start with something that is bigger!
    // compare each
    for(int l = 0; l<lenx; l++) {
        if(stringx[l] != starter.get()[l]) return false;
    }
    return true;
}
bool CharString::endsWith(CharString ender) {
    if(!isValidCharString()) return false;
    int lenx = ender.getSize();
    if(lenx > len) return false; // cannot end with something that is bigger!
    // compare each
    for(int l = 0; l<lenx; l++) {
        int tat = (len-l)-1; // location to start at for compare
        if(stringx[tat] != ender.get()[lenx-l-1]) return false;
    }
    return true;
}

// remove character at index.
void CharString::removeChar(int index){
    
    // bounds tests
    if(index < 0) return;
    if(index > len-1) return;
    
    if(index == 0){ // first char
        // Just shift left
        shiftLeft(1);
    }else if(index == len-1){ // last char
        // do substring
        set(substr(0,len-1));
    }else{
        // in-between, harder to do, requires substrings and concats
        CharString a = substr(0,index);
        CharString b = substr(index+1, len-(index+1));
        a.concata(b);
        set(a);
    }
}

void CharString::fixZeroing(char replacement){
    if(!isValidCharString()) return;
    for(int i=0;i<len;i++){
        if(stringx[i] == '\0')
            stringx[i] = replacement;
    }
}



ostream& operator << (ostream &out, const CharString &c){
	out << c.stringx;
	return out;
}

istream& operator >> (istream &in,  CharString &c){
	in >> c.stringx;
	return in;
}

CharString CharString::operator =(CharString str){
	set(str);
	return *this;
}

template<std::size_t N>
CharString CharString::operator +=(const char(&val)[N]){
    concata(val, N);
    return *this;
}

CharString CharString::operator +=(const char *val){
    concata(CharString(val));
    return *this;
}

CharString CharString::operator +(const char *val){
    CharString s(val);
    s.concatb(*this);
    return s;
}

template<std::size_t N>
CharString CharString::operator +(const char(&val)[N]){
    CharString s(val, N);
    s.concatb(*this);
    return s;
}


CharString CharString::operator +=(CharString val){
    concata(val);
    return *this;
}

CharString CharString::operator +(CharString){
    CharString s = this->clone();
    s.concata(*this);
    return s;
}

CharString CharString::operator +=(long val){
    CharString a = ConvertFromLong(val);
    concata(a);
    return *this;
}

CharString CharString::operator +=(int val){
    CharString a = ConvertFromInt(val);
    concata(a);
    return *this;
}

CharString CharString::operator +=(double val){
    CharString a = std::to_string(val);
    concata(a);
    return *this;
}

template<std::size_t N>
bool CharString::operator ==(const char(&val)[N]){
	return compare(val,N);
}

