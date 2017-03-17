#include "Template.h"


// pre-loads a template file
Template::Template(CharString fileloc){
    
}

Template::Template(){}
Template::~Template(){}

// the replace is a pointer string, so it can be changed later with replacer->set("");

// Add a regex definition, occurs every single time during a render
void Template::addRegexDefinition(CharString toreplace, CharString replacer){
    // following Regex rules
}

// Add a replacing definition, occurs every single time during a render
void Template::addReplacingDefinition(CharString toreplace, CharString replacer){
    // direct replacement definition
}

// must be called to have default definitions like {date}, {page}
void Template::addDefaultDefinitions(){
    
}


// Finalizes the template for usage
CharString Template::render(){
    // loop through definitions
}
