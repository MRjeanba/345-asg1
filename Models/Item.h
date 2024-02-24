//
// Created by jeanb on 22/02/2024.
//

#ifndef ITEM_H
#define ITEM_H
#include "EnchantmentInfo.h"
/**
 * \brief Contains just class definition and method signature of Item class, see Item.cpp for implementation
 */
class Item
{
private:
 EnchantmentInfo enchantmentDetails{};
public:
 explicit Item(std::string eType);
 EnchantmentInfo getEnchantmentInfo();
 void outputInfos();
};



#endif //ITEM_H
