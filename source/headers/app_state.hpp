
#ifndef STATE_H
#define STATE_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.hpp"
#include "combat_state.hpp"
#include "monster.hpp"
#include "content_pages.hpp"

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
    // Page *pagePtr;

public:
    int HP;
    int maxHP;
    AnimationType animation;
    ClockTicksState animationState;
    combatController::CombatState *combat;

    int lastKey;
    int highLightedAns;
    int carridgePos;

    void setPage(int);
    void setMsTimer(int ms);
    void initFight(content_monsters::MonsterType);

    bool isTimerDone();

    State(int _initialState);
    ~State();
    void tik();
    double getTimePased();
    long getMiliseconds();
    int getSeconds();
    void decrementHP(int);
    void combatWon();
};

#endif