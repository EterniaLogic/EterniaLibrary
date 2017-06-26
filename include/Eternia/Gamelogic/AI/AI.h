//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef AIMain_h_
#define AIMain_h_

enum AIACTION {};
enum AIDECISION {};

// Ah, abstraction!
class AI {
    public:
        AI();
        void decide(); // make a decision to do something
        void addInteractable(); // add an object that the AI can interact with

    private:
        // back-end tracking variables
        // Order from higher commander

        // AI Attributes (Percentages assigned at random to define a personality)
        double stuborness; // does not want to follow orders (100% for true enemy)
        double taint; // how often will this AI betray you? (100% for true enemy)
        double sailor_mouth; // how often will this AI curse?
        double smarts; // this combined with taint will completely obliterate you
        double predictability; // how predictable is this AI? (i.e: randomness of the AI, 0% for insane)
        double strength; // how "Tough" is this AI? (0% for a total wimp, 100% for a Tychus)
};

#endif