#include "Regex.h"

Regex::Regex(CharString regexstr){
    this->regexstr = regexstr;
}

// output filter using input string
CharString Regex::filter(CharString input){
    return ""; // TODO
}

// replace
CharString Regex::replace(CharString input, CharString replaceregex){
	return ""; // TODO
}





// STATIC
CharString Regex::filter(CharString stringx, CharString regex){
    Regex r = Regex(regex);
    return r.filter(stringx);
}

CharString Regex::replace(CharString stringx, CharString regex, CharString output){
    Regex r = Regex(regex);
    return r.replace(stringx, output);
}
