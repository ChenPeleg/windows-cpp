
#ifndef COMBAT_H
#define COMBAT_H
#include <ctime>
#include <time.h>
#include <cmath>
#include "common.h"
using namespace common;

namespace combatController
{
    const int numberOfButtons = 4;
    const int maxBattleButtonOptions = 100;
    class CombatState
    {
    private:
        int battleOptionIndex = 0;
        void setCombatBtnRowByDifficulty(CombatButtonType *tempArr, int dificculty)
        {
            int buttonForAction = common::RandomInt(3);

            for (int btn = 0; btn < numberOfButtons; btn++)
            {
                tempArr[btn] = buttonForAction == btn ? CombatButtonType::Dodge : CombatButtonType::noop;
            }
        }
        CombatButtonType allButtonsArray[maxBattleButtonOptions][numberOfButtons];

        void setButtonsByIndex(int i = 0)
        {
            if (i == 0)
            {
                i = ++battleOptionIndex;
            };
            for (int o = 0; o < numberOfButtons; o++)
            {
                currentButtons[o] = allButtonsArray[i][o];
            }
        };

    public:
        CombatState()
        {
            setAllCombatButtons();
            setButtonsByIndex();
        };
        CombatButtonType currentButtons[numberOfButtons];
        char *monsterName;
        int highlightPosition;

        // diffuculty from 1 to 10
        void
        setAllCombatButtons(int difficulty = 1)
        {
            for (int index = 0; index < maxBattleButtonOptions; index++)
            {

                setCombatBtnRowByDifficulty(allButtonsArray[index], difficulty);
            }
        };
    };
};

#endif