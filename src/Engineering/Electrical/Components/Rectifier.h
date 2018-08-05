#ifndef _h_
#define _h_

#include "Component.h"

//

class Rectifier : private Component {
    public:
        Rectifier();
        virtual ~Rectifier();

        void tick(SecondTick* tickTime); // operate time

};

#endif
