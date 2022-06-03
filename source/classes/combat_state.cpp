
#ifndef COMBAT2_H
#define COMBAT2_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "../headers/combat_state.hpp"
#include "../headers/app_state.hpp"
#include "../headers/monster.hpp"
#include "../headers/common.hpp"

using namespace common;
class State;

namespace combatController
{

    CombatState::CombatState(const State &stt, content_monsters::MonsterType mnst) : monster(mnst), stateRef(stt)
    {
        // stateRef = stt;
        setAllCombatButtons();
        setButtonsByIndex(0);
    };
};

#endif