#include "../headers/app_state.h"
#include <time.h>

State::State(int _initialState)
{
    this->p_level = 1;

    this->initialState = _initialState;
    this->start_time = std::time(&start_time);
    this->start_t = clock();
    this->page = 1;
};
State::~State(){};
void State::setPage(int pageNum)
{
    if (pageNum > 0)
        this->page = pageNum;
};
int State::secondsClock()
{
    clock_t currnetClock = clock();
    this->milisecondsPassed = ((currnetClock - start_t) * 1000) / CLOCKS_PER_SEC;

    time_t current = std::time(nullptr);
    this->secondsPassed = current - this->start_time;

    return secondsPassed;
};
double State::getTimePased()
{
    return secondsPassed;
};
long State::getMiliseconds()
{
    return milisecondsPassed;
};
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
