
#ifndef COMBAT_H
#define COMBAT_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.hpp"
#include "monster.hpp"
#include "app_state.hpp"

using namespace common;
class State;

namespace combatController
{
    const int numberOfButtons = 4;
    const int maxBattleButtonOptions = 100;
    const long timeInMsToshowCombatLog = 2000;
    enum LastEvent
    {
        noEvent,
        tookDamage,
        dodgeDamage,
        blockedDamage,
        inflictedDamage

    };

    class CombatState
    {
    private:
        State &stateRef;
        LastEvent lastCombatEvent;
        long timePassedFromLastEvent = 5000;

        int randomNumbers[101];
        int *randomNumbersPtr = randomNumbers;
        int battleOptionIndex = 0;
        CombatActionType getRandCombatBtnRowByDifficulty(int dificculty)
        {
            int rand = common::RandomInt(100);
            *randomNumbersPtr = rand;
            ++randomNumbersPtr;
            switch (rand / 10)
            {
            case 0:
            case 1:
            case 2:
            case 3:
                return CombatActionType::Attack;
            case 4:
            case 5:
            case 6:
                return CombatActionType::Dodge;
            case 7:
            case 8:
            case 9:
                return CombatActionType::Block;
            case 10:
            default:
                return CombatActionType::Attack;
            }
            //
        }
        void setCombatBtnRowByDifficulty(CombatActionType *tempArr, int dificculty)
        {
            CombatActionType buttonForAction = getRandCombatBtnRowByDifficulty(dificculty);
            int randPos = common::RandomInt(3);

            for (int btn = 0; btn < numberOfButtons; btn++)
            {
                tempArr[btn] = btn == randPos ? buttonForAction : CombatActionType::noop;
            }
        }
        CombatActionType allButtonsArray[maxBattleButtonOptions][numberOfButtons];
        void combatActionHandler(CombatActionType btn)
        {
            switch (btn)
            {
            case CombatActionType::Attack:
                inflictDamage();
                break;
            case CombatActionType::Dodge:
                evadeDamage(LastEvent::dodgeDamage);
                break;
            case CombatActionType::Block:
                evadeDamage(LastEvent::blockedDamage);
                break;
            case CombatActionType::Special:
                inflictDamage();
                break;
            case CombatActionType::noop:
            default:
                takeDamage();
                break;
            }
        };

        void takeDamage(int dmg = 10);
        void inflictDamage(int dmg = 10)
        {
            this->monster.HP -= dmg;
            setLastCombatEvent(LastEvent::inflictedDamage, dmg);
        }
        void setLastCombatEvent(LastEvent lst, int amount);

        void evadeDamage(LastEvent lst)
        {
            // int dmg = 2;
            // takeDamage(dmg);
            setLastCombatEvent(lst, 0);
        }
        void setButtonsByIndex(int i)
        {

            for (int o = 0; o < numberOfButtons; o++)
            {
                currentButtons[o] = allButtonsArray[i][o];
            }
        }

    public:
        Monster monster;
        int lastEventInNumber = 0;
        CombatState(State &stt, content_monsters::MonsterType mnst);
        void combatKeyPressed(char key)
        {
            if (isLastEventAnimationRunning())
            {
                return;
            }
            combatActionHandler(getOptionFromKeyPressed(key));
        }
        CombatActionType getOptionFromKeyPressed(char key)
        {
            int keyAsInt = key - '0';
            if (keyAsInt > 0 && keyAsInt < numberOfButtons + 1 && highlightPosition == keyAsInt - 1)
            {
                return currentButtons[keyAsInt - 1];
            }

            return CombatActionType::noop;
        }
        bool isLastEventAnimationRunning();
        LastEvent getLastEvent();
        CombatActionType currentButtons[numberOfButtons];
        char *monsterName;

        int highlightPosition;
        void setHighlightPosition(int pos)
        {
            if (isLastEventAnimationRunning())
            {
                return;
            }
            if (pos < highlightPosition)
            {

                setButtonsByIndex(++battleOptionIndex);
            }
            highlightPosition = pos;
        }

        // diffuculty from 1 to 10
        void
        setAllCombatButtons(int difficulty = 1)
        {
            for (int index = 0; index < maxBattleButtonOptions; index++)
            {
                if (index % 2 == 0)
                {
                    setCombatBtnRowByDifficulty(allButtonsArray[index], difficulty);
                }
                else
                {
                    for (int btn = 0; btn < numberOfButtons; btn++)
                    {
                        allButtonsArray[index][btn] =
                            allButtonsArray[index - 1][btn];
                    }
                }
            }
        };
    };

};

#endif