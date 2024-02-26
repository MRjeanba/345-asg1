//
// Created by jeanb on 24/02/2024.
//

#ifndef BOOTS_H
#define BOOTS_H
#include <string>
#include "Item.h"
using std::string;

class Boots: Item {
public:
    /**
     * \brief safely instantiate a Boots object if the provided enchantmentType is valid
     * \param enchantmentType the provided enchantmentType that we want for the Boots.
     * \return an instance of Boots if the enchantment type is valid
     */
    static Boots createBoots(const string& enchantmentType);

    /**
     * \brief instantiate an Object of the Boots class
     * \param enchantmentType the valid enchantment type for the Boots class
     */
    explicit Boots(const string& enchantmentType);
};

#endif //BOOTS_H