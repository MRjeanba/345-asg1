//
// Created by jeanb on 24/02/2024.
//

#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include "Item.h"

class Armor: public Item {
public:
    /**
     * \brief safely create an Armor item if the given enchantment type is valid
     * \param enchantmentType the wanted enchantmentType for the Armor Item
     * \return an instance of an Armor item if the provided enchantmentType was valid
     */
    static Armor createArmor(const std::string& enchantmentType);
    

    /**
     * \brief Calls the parent constructor Item before creating an instance of Armor
     * \param enchantmentType the enchantmentType wanted for the Armor item
     */
    explicit Armor(const std::string& enchantmentType);
};

#endif //ARMOR_H