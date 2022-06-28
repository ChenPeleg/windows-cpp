
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
    static int RecordSizeInBytes = 100;

public:
    static struct SaveLoadData
    {
        int page;
        int HP;
        int maxHP;
        int inventory[50][2];
    };
    SaveLoad();
    SaveLoadData &static StateToStruct(const State &stateRef)
    {
        SaveLoadData saveload = new SaveLoadData();
        saveload.HP = stateRef.HP;
        saveload.maxHP = stateRef.maxHP;

        memset(saveload.inventory, 0, sizeof(array[0][0]) * 50 * 2);
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
