//
// Created by jeanb on 24/02/2024.
//

#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include "Item.h"

class Armor: Item {
public:
    static Armor createArmor(const std::string& enchantmentType);
    explicit Armor(const std::string& enchantmentType);
};

#endif //ARMOR_H