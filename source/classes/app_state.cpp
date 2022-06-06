#include "../headers/app_state.hpp"
#include <time.h>
#include <cmath>
#include "../headers/combat_state.hpp"
#include "../headers/monster.hpp"
State::State(int _initialState)
{
    this->p_level = 1;
    this->animationState = 1;
    this->isInCombat = false;
    this->maxHP = 100;
    this->HP = this->maxHP;

    this->initialState = _initialState;
    this->start_time = std::time(&start_time);
    this->start_t = clock();
    this->page = 1;
    this->combat = new combatController::CombatState((*this), content_monsters::MonsterType::blobhMonster);
};
State::~State(){};
void State::initFight(content_monsters::MonsterType mnsTyp)
{
    if (mnsTyp == content_monsters::MonsterType ::none)
    {

        return;
    }
    this->combat = new combatController::CombatState((*this), content_monsters::MonsterType::blobhMonster);
}
void State::setPage(int pageNum)
{
    if (pageNum > 0)
        this->page = pageNum;
};
void State::tik()
{
    clock_t currnetClock = clock();
    this->milisecondsPassed = ((currnetClock - start_t) * 1000) / CLOCKS_PER_SEC;

    time_t current = std::time(nullptr);
    this->secondsPassed = current - this->start_time;
    double justMiliseconds = this->milisecondsPassed;
    this->animationState = ((justMiliseconds / 10000) - std::floor(justMiliseconds / 10000)) * 10000;
    this->combat->setHighlightPosition(common::getStageClockTicks(animationState, 4, 1000));
};
double State::getTimePased()
{
    return secondsPassed;
};
long State::getMiliseconds()
{
    return milisecondsPassed;
};
int State::getSeconds()
{
    return secondsPassed;
}
void State::setMsTimer(int ms)
{
    if (ms < 5 || ms > 10000)
    {
        throw "ms duraion not right";
    }
    msTimerDuration = ms;
    msTimer = milisecondsPassed + msTimerDuration;
};
bool State::isTimerDone()
{
    if (msTimer < milisecondsPassed)
    {
        msTimer = milisecondsPassed + msTimerDuration;
        return true;
    };
    return false;
};
void State::decrementHP(int hpDelta = 1)
{
    this->HP -= hpDelta;
};
