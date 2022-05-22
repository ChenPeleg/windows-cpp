
#ifndef STATE_H
#define STATE_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.h"

using namespace common;

class State
{
private:
    int HP;
    int maxHP;
    int p_level;
    int initialState;
    int page;
    int secondsPassed;
    int msTimer;
    int msTimerDuration;
    long milisecondsPassed;
    time_t start_time;
    clock_t start_t;

public:
    AnimationType animation;
    AnimState animationState;

    int lastKey;
    int highLightedAns;
    int carridgePos;

    void setPage(int);
    void setMsTimer(int ms);
    bool isTimerDone();

    State(int _initialState);
    ~State();
    void tik();
    double getTimePased();
    long getMiliseconds();
    int getSeconds();
};

#endif