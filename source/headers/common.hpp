#ifndef COMMON_H
#define COMMON_H
#include <cstdlib>

namespace common
{
#define ITEMS_ENUM_DEFENITION  \
    X(NoItem, "NoItem", false) \
    X(Gold, "Gold", false)     \
    X(Sword, "Sword", false)   \
    X(Food, "Food", false)     \
    X(Water, "Water", false)   \
    X(Wand, "Wand", false)     \
    X(shield, "shield", false) \
    X(LastItem, "LastItem", false)

#define X(day, name, canBeAccumulated) day,
    enum ItemType : size_t
    {
        ITEMS_ENUM_DEFENITION
    };
#undef X

#define X(day, name, canBeAccumulated) name,
    char const *ItemName[] =
        {
            ITEMS_ENUM_DEFENITION};
#undef X

#define X(day, name, canBeAccumulated) canBeAccumulated,
    bool isItemAcumilated[]{
        ITEMS_ENUM_DEFENITION};
#undef X

    // enum ItemType
    // {
    //     noItem = 0,
    //     sword = 1,
    //     shield,
    //     wand,
    //     gold,
    //     food,
    //     water
    // };

    enum AnimationType
    {
        none = 0,
        FadeIn = 1,
        FadeOut = 2,
        Choose = 3
    };
    enum CombatActionType
    {
        noop = 0,
        Dodge = 1,
        Attack = 2,
        Block = 3,
        Special = 4,
    };
    /* from 1 to 10000 im miliseconds*/
    typedef int ClockTicksState;
    static int getStageClockTicks(common::ClockTicksState clockTicksState, int numberOfStages, int durationOfTickInMs)
    {
        double totalNumberOfTicksPreCycle = 10000 / durationOfTickInMs;
        double howManyTicksPassed = clockTicksState / (durationOfTickInMs);

        int stage = (int)howManyTicksPassed % numberOfStages;
        return stage;
    };
    const int AnimationDelay = 500;
    int string_size(const char *str)

    {

        int Size = 0;
        while (str[Size] != '\0')
            Size++;
        return Size;
    };

    static int RandomInt(int size = 100)
    {
        return rand() % size;
    }
};

#endif