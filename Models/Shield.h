//
// Created by jeanb on 24/02/2024.
//

#ifndef SHIELD_H
#define SHIELD_H
#include <string>
#include "Item.h"
using std::string;

class Shield: Item {
public:
    /**
     * \brief safely create a Shield item if the given enchantment type is valide
     * \param enchantmentType the enchantment type that we want for the shield
     * \return an instance of a Shield class if the provided enchantment type is correct
     */
    static Shield createShield(const string& enchantmentType);

    /**
     * \brief calls the Item parent constructor to instantiate the fields
     * \param enchantmentType
     */
    explicit Shield(const string& enchantmentType);
};

#endif //SHIELD_H
