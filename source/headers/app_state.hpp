
#ifndef STATE_H
#define STATE_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.hpp"
#include "combat_state.hpp"
#include "monster.hpp"
//#include "../content/content_monsters.cpp"

using namespace common;

class State
{
private:
    int p_level;
    int initialState;
    int page;
    int secondsPassed;
    int msTimer;
    int msTimerDuration;
    long milisecondsPassed;
    int highlightedBattleOption;
    time_t start_time;
    clock_t start_t;

public:
    int HP;
    int maxHP;
    AnimationType animation;
    ClockTicksState animationState;
    combatController::CombatState *combat;
    Monster *monster;

    int lastKey;
    int highLightedAns;
    int carridgePos;
    bool isInCombat;

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