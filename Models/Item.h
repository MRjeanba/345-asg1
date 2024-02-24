//
// Created by jeanb on 22/02/2024.
//

#ifndef ITEM_H
#define ITEM_H
#include "EnchantmentInfo.h"

/**
 * \brief
 */
class Item
{
private:
 EnchantmentInfo enchantmentDetails{};
public:
 explicit Item(const std::string& eType);
 EnchantmentInfo getEnchantmentInfo();
 void outputInfos();
};



#endif //ITEM_H
