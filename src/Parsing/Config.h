#ifndef CONFIG_H_
#define CONFIG_H_

#include "../Data/HashMap.hpp"
#include "../Data/CharString.h"
#include "SimpleParser.h"
#include <unordered_map>

class Config {
    public:
        Config();

        void Load(CharString* fileLoc);
        //HashMap<CharString>* items; // items that are loaded
        unordered_map<std::string,CharString> items;

};

#endif
