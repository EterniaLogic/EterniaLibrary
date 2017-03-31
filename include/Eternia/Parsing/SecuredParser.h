//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef SECUREDPARSER_H_
#define SECUREDPARSER_H_

// The secured parser implements AES-256 and several other security features to prevent manipulation. Keys can even include Md5 of a client computer's hardware id, ect to prevent cross-client access.

#include "SimpleParser.h"
#include "../Algorithm/Cryptography/Aes256.h"
#include "../Data/LinkedList.hpp"

class SecuredParser {
    public:
        SecuredParser(CharString* k, CharString* File);
        virtual ~SecuredParser();

        // read every single character in the file
        CharString* getText();

        // read every line in the file
        LinkedList<CharString>* getLines();

        // read every line in the file, split them by character
        LinkedList<CharString>* getLinesSplit(char splitter);

        // Generate a hashmap from split line pairs
        LinkedList<CharString>* getMap(char splitter);

        // Encrypt text-
        CharString* encodeText(CharString* ss);

    private:
        uint8_t key[32];
        aes256_context ctx;
        CharString* file;
};

#endif
