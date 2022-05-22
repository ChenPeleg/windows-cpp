
#ifndef COMBAT_H
#define COMBAT_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.h"

namespace combatController
{

    class CombatState
    {
    private:
    public:
        CombatState(){};
        char *monsterName;
        int highlightPosition;
    };

};

#endif