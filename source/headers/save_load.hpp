
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
        char a;
        char b;
        char c;
        char d;
        int HP;
        int maxHP;
        int page;
        int inventory[50][2];
        int name[30];
        int time;
    };
    SaveLoad();

    static char *StructToByteArray(SaveLoadData &saveLoad)
    {
        char *byteArr = reinterpret_cast<char *>(&saveLoad);
        cout << "save bin:";

        return byteArr;
    }
    static SaveLoadData *ByteArrayToStruct(char *byteArr)
    {

        SaveLoadData *fromChar = reinterpret_cast<SaveLoadData *>(byteArr);

        return fromChar;
    }
    static char *GetByteArrayFromStateAndData(const State &stateRef, char *saveName, char charRef[sizeof(SaveLoadData)])
    {
        SaveLoadData sl; // eeee
        sl = SaveLoad::StateToStruct(stateRef, saveName);
        char *ret = new char[sizeof(SaveLoadData)];
        ret = StructToByteArray(sl);
        for (int p = 0; p < sizeof(SaveLoadData); p++)
            charRef[p] = ret[p];

        cout << "\n\n Byte array: ";
        for (int i = 0; i < sizeof(SaveLoad::SaveLoadData); i++)
        {
            cout << charRef[i];
        }
        return ret;
    }

    static SaveLoadData *SaveLoadDataFromCharArray(char *charArr)
    {
        SaveLoadData sl;

        return 0;
    }
    static SaveLoadData StateToStruct(const State &stateRef, char *saveName)
    {
        SaveLoadData saveload;
        try
        {
            saveload.a = 'O';
            saveload.b = 'K';
            saveload.c = '!';
            saveload.d = ' ';
            saveload.HP = stateRef.HP;
            saveload.maxHP = stateRef.maxHP;
            bool nameOver = false;
            for (int c = 0; c < sizeof(saveload.name); c++)
            {
                saveload.name[c] = nameOver ? saveName[c] : '\0';
                nameOver = nameOver || saveName[c] == '\0';
            }

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
        }
        catch (exception e)
        {
            std::cout << "Exception " << e.what();
        }

        return saveload;
    }
};

#endif
