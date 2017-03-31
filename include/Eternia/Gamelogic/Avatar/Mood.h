//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Mood_h_
#define Mood_h_

enum MOOD {AM_Happy, AM_Sad, AM_Mad, AM_Accomplished, AM_Alone, AM_Amused, AM_Annoyed, AM_Anxious, AM_Apathetic, AM_Awake,
           AM_Bewildered, AM_Cheerful, AM_Calm, AM_Excited, AM_Cranky, AM_Content, AM_Depressed, AM_Dark, AM_Devious, AM_Disappointed,
           AM_Discontent, AM_Dorky, AM_Drained, AM_Drunk, AM_Enthralled, AM_Frustrated, AM_Flirty, AM_Giggly, AM_Gloomy, AM_Grumpy,
           AM_High, AM_Hopeful, AM_Hot, AM_Hungry, AM_Hyper, AM_Jealous, AM_Irritated, AM_Lonely, AM_Numb, AM_Peaceful, AM_Pessimistic,
           AM_Mellow, AM_Melancholy, AM_Naughty, AM_Predetory, AM_Rejected, AM_Restless, AM_Rejuvenated, AM_Relieved, AM_Rushed,
           AM_Shocked, AM_Sick, AM_Silly, AM_Sleepy, AM_Smart, AM_Stressed, AM_Supprised, AM_Sympathetic, AM_Thankful, AM_Tired,
           AM_Uncomfortable, AM_Touched
          };

#include "../../Data/Protect/PType.hpp"
#include "../../Serialization/SpecificSerializer.h"

class Mood : public SpecificSerializer {
    public:
        Mood(MOOD mood);
        bool isAllowed(); // determined if this mood is allowed in the current avatar situation
        void act(); // act out this mood (Very strong moods [>7] will do random things)
        void effect(); // place an effect on the avatar based on the mood. (i.e: Stressed will make the avatar make accuracy and intelligence mistakes, ect)

        void tick(double tps);

    private:
        PType<MOOD> mainmood;
        PType<int> strength; // strength of this mood from 1-10, 10 being completely overwhelming
};

#endif
