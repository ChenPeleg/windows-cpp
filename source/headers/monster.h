#ifndef MONSTER_H
#define MONSTER_H

#include "./content/content_monsters.h"
#include "../images/images.cpp"

using namespace content_monsters;
class Monster
{
private:
    SetMonsterData(MonsterType
                   : monsterType);

public:
    int HP;
    int maxHP;
    imagesEnumb::ImageEnumb monsterImage;
    char monsterName[20];
    int mosterDifficulty;
    int baseDamage;

    Monster(MonsterType
            : monsterType);

    Monster(/* args */);

    ~Monster();
    setMonster()
    {
    }
    static Monster buildMonster(MonsterType
                                : monsterType);
};

Monster::Monster()
{
}
Monster::Monster(MonsterType
                 : monsterType)
{
    this->SetMonsterData(MonsterType);
}
Monster::SetMonsterData(MonsterType
                        : monsterType)
{
    switch (monsterType)
    {
    case MonsterType::blobhMonster:
        monsterName = "Blob Moster        ";
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = imagesEnumb::blobMonster;
        break;
    case MonsterType::clayMonster:
        monsterName = "Clay Moster        ";
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = imagesEnumb::blobMonster;
        break;
    case MonsterType::earthWorm:
        monsterName = "Earth Worm         ";
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = imagesEnumb::worm;
        break;
    case MonsterType::ghostMoster:
        monsterName = "Ghost Walker       ";
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = imagesEnumb::ghost;
        break;
    case MonsterType::skeletonMoster:
        monsterName = "Undead Skeleton    ";
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = imagesEnumb::skeleton;
        break;
    case MonsterType::skullMonster:
        monsterName = "Flying Skull       ";
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = imagesEnumb::skull;
        break;
    case MonsterType::stingWorm:
        monsterName = "Sting Worm         ";
        maxHP = 100;
        mosterDifficulty = 1;
        monsterImage = imagesEnumb::worm;

        break;

    default:
        break;
    }
    HP = maxHP;
}

Monster::~Monster()
{
}

#endif