
#ifndef MONSTER_H
#define MONSTER_H

#include "content_monsters.hpp"
#include "../images/images.cpp"

using namespace content_monsters;

class Monster
{
private:
    void SetMonsterData(MonsterType monsterType);
    MonsterType typ;

public:
    int HP;
    int maxHP;
    imagesEnumb::ImageEnumb monsterImage;
    char monsterName0[20];
    int mosterDifficulty;
    int baseDamage;

    Monster(MonsterType monster);

    // Monster(/* args */);

    ~Monster();
};

Monster::Monster(MonsterType monsterType)
{
    this->SetMonsterData(monsterType);
}
void Monster::SetMonsterData(MonsterType monsterType)
{
    char *monsterName;
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