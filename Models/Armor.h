//
// Created by jeanb on 24/02/2024.
//

#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include "Item.h"

class Armor: Item {
public:
    /**
     * \brief 
     * \param enchantmentType 
     * \return 
     */
    static Armor createArmor(const std::string& enchantmentType);
    

    /**
     * \brief 
     * \param enchantmentType
     */
    explicit Armor(const std::string& enchantmentType);
};

#endif //ARMOR_H