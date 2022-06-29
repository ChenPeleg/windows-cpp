
#ifndef STATE_H
#define STATE_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.hpp"
#include "combat_state.hpp"
#include "monster.hpp"
#include "content_pages.hpp"
#include "inventory.hpp"

using namespace common;

class State
{

private:
    int p_level;
    int page;
    int lastStoryPage;
    int secondsPassed;
    int msTimer;
    int msTimerDuration;
    long milisecondsPassed;
    int highlightedBattleOption;
    time_t start_time;
    clock_t start_t;
    Page pageObj;
    void loadGame(int page);
    void saveGame(int page);

public:
    int HP;
    int maxHP;
    AnimationType animation;
    ClockTicksState animationState;
    Inventory inventory;
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
    int getPage();
    Page &currentPage();
};

#endif