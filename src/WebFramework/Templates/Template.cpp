#include "Template.h"


// pre-loads a template file
Template::Template(CharString fileloc){
    loaded=false;
    this->fileloc = fileloc;
}

Template::Template(){loaded=false;}
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
    if(!loaded){
        ifstream filex;
        fileOpen(filex, fileloc.get());
    }

    // clone data
    CharString pretext = templatetext.clone();

    // Iterate through the definitions in the file
    LinkedListIterator<TemplateDefinition> itt = templateList.getIterator();
    while(itt.hasNext()){
        TemplateDefinition td = itt.next();

        if(td.toreplace.startsWith("{copyright")){

        }else if(td.toreplace.startsWith("{url|")){

        }else if(td.toreplace.compare("{time24}",8)){

        }else if(td.toreplace.startsWith("{time12}")){

        }else if(td.toreplace.startsWith("{date}")){

        }else if(td.toreplace.startsWith("{unixtime}")){ // seconds since january 1, 1970
            uint64_t d = time(0x0);
        }else if(!td.regex){
            pretext.replace(td.toreplace.get(), td.replacer->get());
        }
    }

    return pretext;
}
