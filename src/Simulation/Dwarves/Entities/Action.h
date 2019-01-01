#ifndef ACTION_H_
#define ACTION_H_

enum ACTION_TYPE {AT_NONE, AT_SLEEP, AT_BATHROOM, AT_ATTACK, AT_CRAFT, AT_MINE};

class Action{
public:
    ACTION_TYPE type;
};

#endif
