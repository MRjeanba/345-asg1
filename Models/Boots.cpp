//
// Created by jeanb on 24/02/2024.
//

#include "Boots.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::invalid_argument;

Boots Boots::createBoots(const string &enchantmentType) {
    vector<string> validEnchantmentTypes = {"ArmorClass", "Dexterity"};

    // we search in the validEnchantmentTypes vector list to verify if enchantmentType is valid
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType)
        return Boots(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the Boots creation");
}
Boots::Boots(const string &enchantmentType): Item(enchantmentType) {}