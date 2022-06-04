
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

    class CombatState
    {
    private:
        State &stateRef;
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
                takeDamage();
                break;
            case CombatActionType::Dodge:
                evadeDamage();
                break;
            case CombatActionType::Block:
                evadeDamage();
                break;
            case CombatActionType::Special:
                takeDamage();
                break;
            case CombatActionType::noop:
            default:
                takeDamage();
                break;
            }
        };

        void takeDamage(int dmg = 10);
        void inflictDamage()
        {
            this->monster.HP -= 5;
        }

        void evadeDamage()
        {
            takeDamage(2);
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
        CombatState(State &stt, content_monsters::MonsterType mnst);
        void combatKeyPressed(char key)
        {
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

        CombatActionType currentButtons[numberOfButtons];
        char *monsterName;

        int highlightPosition;
        void setHighlightPosition(int pos)
        {
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