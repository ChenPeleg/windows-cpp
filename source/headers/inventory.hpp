#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "item.hpp"

class Inventory
{
private:
    std::vector<Item> items;
    int getPos(ItemType);

public:
    Inventory();
    ~Inventory();
    void printItems();
    void remove(ItemType, int quantity = 1);
    void add(ItemType, int quantity = 1);
    bool has(ItemType);
    int count(ItemType);
};

Inventory::Inventory(/* args */)
{
    Item gold(ItemType::Gold, 0);
    items.push_back(gold);
}

Inventory::~Inventory()
{
    // delete items;
}
void Inventory::printItems()
{
    cout << "List Of Items: \n\n";
    int num = 1;
    for (auto it = std::begin(items); it != std::end(items); ++it)
    {
        const char *iName = ItemName[it->itemType];
        char *fill = ViewEngine::duplicateChar(' ', 15 - common::string_size(iName));
        cout << num++ << "." << iName << " " << fill << it->amount << "\n\n";
    }
}
/**
 * Gets the position of an element.
 * Returns -1 if no element Exists.
 * @typ ItemType ().
 * @return the position as int or -1 if none exist.
 */
int Inventory::getPos(ItemType typ)
{
    for (auto it = std::begin(items); it != std::end(items); ++it)
    {
        if (it->itemType == typ)
        {
            return it - std::begin(items);
        }
    }
    return -1;
}
void Inventory::remove(ItemType typ, int quantity)
{
    int pos = getPos(typ);
    if (pos < 0)
    {
        return;
    }
    items[pos].amount -= quantity;
    if (items[pos].amount < 1)
    {
        items.erase(items.begin() + pos);
    }
}
void Inventory::add(ItemType typ, int quantity)
{
    int pos = getPos(typ);
    if (pos > -1)
    {
        items[pos].amount += quantity;
    }
    else
    {
        Item newItem(typ, quantity);
        items.push_back(newItem);
    }
}
bool Inventory::has(ItemType typ)
{
    return getPos(typ) > -1;
}
int Inventory::count(ItemType typ)
{
    int pos = getPos(typ);
    if (pos > -1)
    {
        return items[pos].amount;
    }

    return 0;
}

#endif