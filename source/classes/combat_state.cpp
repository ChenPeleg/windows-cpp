
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

    CombatState::CombatState(State &stt, content_monsters::MonsterType mnst) : monster(mnst), stateRef(stt)
    {

        setAllCombatButtons();
        setButtonsByIndex(0);
    };
    void CombatState::takeDamage(int dmg)
    {
        stateRef.decrementHP(dmg);
        setLastCombatEvent(LastEvent::tookDamage, dmg);
    };
    void CombatState::setLastCombatEvent(LastEvent lst, int amount)
    {
        this->lastCombatEvent = lst;
        this->timePassedFromLastEvent = this->stateRef.getMiliseconds();
    };
    bool CombatState::getShowLastEvent()
    {
        return this->timePassedFromLastEvent + 3000 > this->stateRef.getMiliseconds();
    };
    LastEvent CombatState::getLastEvent()
    {
        const bool show = getShowLastEvent();
        return show ? lastCombatEvent : LastEvent::noEvent;
    };
}

#endif