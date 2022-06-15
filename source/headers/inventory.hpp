#ifndef INVENTORY_H
#define INVENTORY_H

#include "item.hpp"
#include <iostream>
#include <vector>

class Inventory
{
private:
    std::vector<Item> items;

public:
    Inventory();
    ~Inventory();
    getItems();
};

Inventory::Inventory(/* args */)
{
}

Inventory::~Inventory()
{

    std::cout << items.at(0).amount;
}
Inventory::getItems()
{
    int i = items.at(0).amount;
}

#endif