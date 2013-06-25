//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef LANGCONTROLLER_H_
#define LANGCONTROLLER_H_

#include "../MiscLib/CharString.h"

// english, spanish, french, german, chinese, Bulgarian, Russian, Swedish, Italian, Japanese
enum LANG {En, Sp, Fr, Gr, Ch, Bu, Ru, Sw, It, Jp};

class langController
{
public:
	langController();
	void addTranslation(CharString* english, CharString* );
	
	CharString* translateWord(CharString* word);
	CharString* translateString(CharString* sentence);
	
} *lang;

#endif /*LANGCONTROLLER_H_*/
