#ifndef IDLECAT_H_
#define IDLECAT_H_

#include "IdleJob.h"
#include "../../../Data/includes.h"

// A Category contains a listing of jobs/actions which are staggered in the interdependencies.
class IdleCategory{
public:
    LinkedList<IdleJob> jobs;
};

#endif
