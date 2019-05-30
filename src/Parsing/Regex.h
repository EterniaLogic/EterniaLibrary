#ifndef REGEX_H_
#define REGEX_H_

// NOTE: NOT FULLY IMPLEMENTED!

class CharString;
#include "../Data/CharString.h"

// base definition for REGEX calculation.


class Regex{
private:
    CharString regexstr;
public:
    Regex(CharString regexstr);
    
    CharString filter(CharString input); // output filter using input string
    CharString replace(CharString input, CharString replaceregex); // regex replace
    
    static CharString filter(CharString stringx, CharString regex);
    static CharString replace(CharString stringx, CharString regex, CharString replaceregex); // regex replace throughout string
};

#endif
