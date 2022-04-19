
#ifndef STATE_H
#define STATE_H
#include <ctime>

namespace app_state
{
    class State
    {
    private:
        /* data */
        int p_level;
        int initialState;
        time_t start_time;

    public:
        State(int _initialState)
        {
            this->p_level = 1;
            this->initialState = _initialState;
            this->start_time = std::time(&start_time);
            // can also pass pinter to start time
        };
        ~State(){};
        int getSecondsPassed()
        {
            time_t current = std::time(nullptr);

            return this->start_time - current;
        };
    };

}
#endif