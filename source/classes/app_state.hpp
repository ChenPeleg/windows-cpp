
#ifndef STATE_H
#define STATE_H
#include <ctime>

namespace app_state
{
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
        State(int _initialState)
        {
            this->p_level = 1;
            this->initialState = _initialState;
            this->start_time = std::time(&start_time);
            this->page = 1;
            // can also pass pinter to start time
        };
        ~State(){};
        int getSecondsPassed()
        {
            time_t current = std::time(nullptr);

            return current - this->start_time;
        };
    };

}
#endif