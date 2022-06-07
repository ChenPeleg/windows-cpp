
#ifndef COMBAT2_H
#define COMBAT2_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "../headers/combat_state.hpp"
#include "../headers/app_state.hpp"
#include "../headers/monster.hpp"
#include "../headers/common.hpp"
#include "../headers/constants.hpp"

using namespace common;
class State;

namespace combatController
{

    CombatState::CombatState(State &stt, content_monsters::MonsterType mnst) : monster(mnst), stateRef(stt)
    {

        setAllCombatButtons();
        setButtonsByIndex(0);
        setLastCombatEvent(LastEvent::noEvent, 0);
        this->timePassedFromLastEvent -= constants::TIME_FOR_COMBAT_MESSAGE;
    };
    void CombatState::takeDamage(int dmg)
    {
        stateRef.decrementHP(dmg);
        setLastCombatEvent(LastEvent::tookDamage, dmg);
    };
    void CombatState::setLastCombatEvent(LastEvent lst, int amount)
    {
        this->lastCombatEvent = lst;
        this->lastEventInNumber = amount;
        this->timePassedFromLastEvent = this->stateRef.getMiliseconds();
        if (this->monster.HP <= 0)
        {
            this->monster.HP = 0;
            this->lastCombatEvent = LastEvent::combatWon;
        }
        else if (this->stateRef.HP <= 0)
        {
            this->stateRef.HP = 0;
            this->lastCombatEvent = LastEvent::combatLost;
        }
    };
    bool CombatState::isLastEventAnimationRunning()
    {
        int timeForAnimationToRun = constants::TIME_FOR_COMBAT_MESSAGE;
        if (this->lastCombatEvent == LastEvent::combatWon)
        {
            timeForAnimationToRun = constants::TIME_FOR_WIN_MESSAGE;
        }
        return this->timePassedFromLastEvent + timeForAnimationToRun > this->stateRef.getMiliseconds();
    };
    LastEvent CombatState::getLastEvent()
    {
        const bool show = isLastEventAnimationRunning();
        // return lastCombatEvent;
        return show ? lastCombatEvent : LastEvent::noEvent;
    };
}

#endif