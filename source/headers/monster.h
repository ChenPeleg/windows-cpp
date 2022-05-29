#ifndef MONSTER_H
#define MONSTER_H

#include "./content/content_monster.cpp"
#include "../images/images.cpp"

using namespace content;
class Monster
{
private:
public:
    int HP;
    int maxHP;
    imagesEnumb::ImageEnumb monsterImage;
    int mosterDifficulty;
    int baseDamage;

    Monster(/* args */);
    ~Monster();
    setMonster()
    {
    }
    static Monster buildMonster(MonsterType
                                : monsterType);
};

Monster::Monster(/* args */)
{
}

Monster::~Monster()
{
}

#endif