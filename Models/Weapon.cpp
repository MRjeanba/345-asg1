//
// Created by jeanb on 24/02/2024.
//

#include "Weapon.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::invalid_argument;

Weapon Weapon::createWeapon(const string &enchantmentType) {
    vector<string> validEnchantmentTypes = {"AttackBonus","DamageBonus"};

    // we search in the validEnchantmentTypes vector list to verify if enchantmentType is valid
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType)
        return Weapon(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the belt creation");
}

Weapon::Weapon(const string& enchantmentType): Item(enchantmentType) {}