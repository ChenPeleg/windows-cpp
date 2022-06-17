#ifndef ITEM_H
#define ITEM_H

#include "common.hpp"
using namespace common;
class Item
{
private:
public:
    ItemType itemType;
    int amount;

    Item(ItemType type, int amnt = 1);
    Item();
    ~Item();
};

Item::Item(ItemType type, int amnt)
{
    itemType = type;
    amount = amnt;
}
Item::Item()
{
    itemType = ItemType::NoItem;
    amount = 0;
}

Item::~Item()
{
}

#endif