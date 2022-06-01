
#ifndef MONSTER_H
#define MONSTER_H

#include "content_monsters.hpp"
#include "../images/images.cpp"
#include <string>
#include <cstring>

using namespace content_monsters;

class Monster
{
private:
    void SetMonsterData(MonsterType monsterType);
    const MonsterType typ;

public:
    int HP;
    int maxHP;
    asciiImages::ImageEnumb monsterImage;
    char name[20];
    int mosterDifficulty;
    int baseDamage;

    Monster(MonsterType monster);
    ~Monster();
};

Monster::Monster(MonsterType monsterType) : typ(monsterType)
{
    std::string monsterName = "Monster";
    switch (monsterType)
    {
    case MonsterType::blobhMonster:
        monsterName.assign("Blob Moster");
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = asciiImages::blobMonster;
        break;
    case MonsterType::clayMonster:
        monsterName.assign("Clay Moster");
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = asciiImages::blobMonster;
        break;
    case MonsterType::earthWorm:
        monsterName.assign("Earth Worm");
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = asciiImages::worm;
        break;
    case MonsterType::ghostMoster:
        monsterName.assign("Ghost Walker");
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = asciiImages::ghost;
        break;
    case MonsterType::skeletonMoster:
        monsterName.assign("Undead Skeleton");
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = asciiImages::skeleton;
        break;
    case MonsterType::skullMonster:
        monsterName.assign("Flying Skull");
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = asciiImages::skull;
        break;
    case MonsterType::stingWorm:
        monsterName.assign("Sting Worm");
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = asciiImages::worm;

        break;

    default:
        break;
    }
    std::strcpy(name, monsterName.c_str());
    name[sizeof(name) - 1] = 0;

    HP = maxHP;
}

Monster::~Monster()
{
}

#endif