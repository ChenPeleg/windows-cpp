
#ifndef STATE_H
#define STATE_H
#include <ctime>

class State
{
private:
    int p_level;
    int initialState;
    int page;
    time_t start_time;

public:
    int lastKey;
    int highLightedAns;
    int carridgePos;
    State(int _initialState);
    ~State();
    int getSecondsPassed();
};

#endif