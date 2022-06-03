
#ifndef COMBAT_H
#define COMBAT_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.hpp"
#include "monster.hpp"

using namespace common;

namespace combatController
{
    const int numberOfButtons = 4;
    const int maxBattleButtonOptions = 100;

    class CombatState
    {
    private:
        int randomNumbers[101];
        int *randomNumbersPtr = randomNumbers;
        int battleOptionIndex = 0;
        CombatButtonType getRandCombatBtnRowByDifficulty(int dificculty)
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
                return CombatButtonType::Attack;
            case 4:
            case 5:
            case 6:
                return CombatButtonType::Dodge;
            case 7:
            case 8:
            case 9:
                return CombatButtonType::Block;
            case 10:
            default:
                return CombatButtonType::Attack;
            }
            //
        }
        void setCombatBtnRowByDifficulty(CombatButtonType *tempArr, int dificculty)
        {
            CombatButtonType buttonForAction = getRandCombatBtnRowByDifficulty(dificculty);
            int randPos = common::RandomInt(3);

            for (int btn = 0; btn < numberOfButtons; btn++)
            {
                tempArr[btn] = btn == randPos ? buttonForAction : CombatButtonType::noop;
            }
        }
        CombatButtonType allButtonsArray[maxBattleButtonOptions][numberOfButtons];

        void setButtonsByIndex(int i)
        {

            for (int o = 0; o < numberOfButtons; o++)
            {
                currentButtons[o] = allButtonsArray[i][o];
            }
        }

    public:
        CombatState(content_monsters::MonsterType)
        {
            // Monster monster(content_monsters::MonsterType ::blobhMonster);
            setAllCombatButtons();
            setButtonsByIndex(0);
        };
        // CombatState(Monster mnst) //: //monster(mnst)
        // {
        //     setAllCombatButtons();
        //     setButtonsByIndex(0);
        // };
        CombatButtonType currentButtons[numberOfButtons];
        char *monsterName;
        //  Monster monster;
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