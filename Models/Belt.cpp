//
// Created by jeanb on 24/02/2024.
//

#include "Belt.h"
#include <algorithm>
#include <stdexcept>
#include <vector>
using std::string;
using std::vector;
using std::invalid_argument;

Belt Belt::createBelt(const string& enchantmentType) {
    vector<string> validEnchantmentTypes = {"Constitution","Strength"};

    // we search in the validEnchantmentTypes vector list to verify if enchantmentType is valid
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType)
        return Belt(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the belt creation");
}
Belt::Belt(const string& enchantmentType): Item(enchantmentType) {}