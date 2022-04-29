#include "../headers/app_state.h"

State::State(int _initialState)
{
    this->p_level = 1;
    this->initialState = _initialState;
    this->start_time = std::time(&start_time);
    this->page = 1;
};
State::~State(){};
int State::getSecondsPassed()
{
    time_t current = std::time(nullptr);

    return current - this->start_time;
};

// }
