
#ifndef SAVELOAD_H
#define SAVELOAD_H

#include <fstream>
#include <iostream>
#include "app_state.hpp"
#include "inventory.hpp"
using namespace std;

class SaveLoad
{
private:
    /**
     * @brief This should be the about the maximum size of inventory * 2 + 3 properies
     *
     */

public:
    struct SaveLoadData
    {
        int page;
        int HP;
        int maxHP;
        int inventory[50][2];
    };
    SaveLoad();
    static int *StructToIntArray(SaveLoadData &saveLoad, bool reverse = false)
    {
        int *intArr = new int[SAVE_RECORD_SIZE_BYTES];

        intArr[0] = saveLoad.page;
        intArr[1] = saveLoad.HP;
        intArr[2] = saveLoad.maxHP;
        int invC = 0;
        for (int i = 3; i < SAVE_RECORD_SIZE_BYTES - 1; i += 2)
        {
            intArr[i] = saveLoad.inventory[invC][0];
            intArr[i + 1] = saveLoad.inventory[invC][1];
            invC++;
        }

        return intArr;
    }

    static int *GetIntArrayFromStateClass(const State &stateRef)
    {
        SaveLoadData sl = StateToStruct(stateRef);
        return StructToIntArray(sl);
    }
    static SaveLoadData StateToStruct(const State &stateRef)
    {
        SaveLoadData saveload;
        saveload.HP = stateRef.HP;
        saveload.maxHP = stateRef.maxHP;

        memset(saveload.inventory, 0, sizeof(saveload.inventory[0][0]) * 50 * 2);
        int countCells = 0;
        for (int intItem = ItemType::NoItem; intItem != ItemType::LastItem; intItem++)
        {
            ItemType itemEnum = static_cast<ItemType>(intItem);
            if (itemEnum != ItemType::NoItem &&
                itemEnum != ItemType::LastItem)
            {
                int amount = stateRef.inventory.count(itemEnum);
                if (amount == 0)
                {
                    continue;
                }
                else
                {
                    saveload.inventory[countCells][0] = intItem;
                    saveload.inventory[countCells][1] = amount;
                    countCells++;
                }
            }
        }
        return saveload;
    }
};

#endif
