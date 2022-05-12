#include "../headers/app_state.h"
#include <time.h>

State::State(int _initialState)
{
    this->p_level = 1;
    this->initialState = _initialState;
    this->start_time = std::time(&start_time);
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

    time_t current = std::time(nullptr);
    this->secondsPassed = current - this->start_time;

    return secondsPassed;
};
double State::getTimePased()
{
    return secondsPassed;
};

// }
