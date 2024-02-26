//
// Created by jeanb on 22/02/2024.
//

#ifndef ITEM_H
#define ITEM_H
#include "EnchantmentInfo.h"

/**
 * \brief Base class for the different items in the game, items have an enchantment bonus and type
 */
class Item
{
private:
    /**
     * \brief a structure holding the enchantment bonus and type in one place
     */
 EnchantmentInfo enchantmentDetails{};
public:
    /**
     * Creates an instance of an Item, with the given enchantType
     * @param enchantType the enchantmentType provided by the user
     */
 explicit Item(const std::string& enchantType);
/**
 * Get the enchantmentDetails structure inside the item, holding the info about enchantmentBonus and type
 * @return enchantmentDetails, the structure contained within the item
 */
 EnchantmentInfo getEnchantmentInfo();
 /**
  * Helper method just to display the item at its creation to see if it is working
  */
 void outputInfos();
};



#endif //ITEM_H
