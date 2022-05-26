
#ifndef COMBAT_H
#define COMBAT_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.h"
using namespace common;

namespace combatController
{

    class CombatState
    {
    private:
    public:
        CombatState(){};
        char *monsterName;

        int highlightPosition;
        // CombatButtonType *[4] getCombatStateButtons()
        // {
        //     return CombatButtonType * [4]
        //     { CombatButtonType::none, }
        // };
        void setCombatButtons(int difficulty = 1)
        {
        }
    };
};

#endif