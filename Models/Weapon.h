//
// Created by jeanb on 24/02/2024.
//

#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Item.h"
using std::string;

class Weapon: Item {
public:
    /**
     * \brief Safely create an instance of Weapon if the provided enchantmentType is valid for the class.
     * \param enchantmentType the provided enchantmentType that we want for the weapon.
     * \return an instance of the Belt class if the enchantmentType was valid.
     */
    static Weapon createWeapon(const string& enchantmentType);

    /**
     * \brief Simply instantiate a Belt with the valid enchantment type.
     * \param enchantmentType the valid enchantment type to forward.
     */
    explicit Weapon(const string& enchantmentType);
};



#endif //WEAPON_H
