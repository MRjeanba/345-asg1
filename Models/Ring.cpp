//
// Created by jeanb on 24/02/2024.
//
#include "Ring.h"
#include <algorithm>
#include <stdexcept>
#include <vector>
using std::vector;
using std::string;
using std::invalid_argument;

Ring Ring::createRing(const string& enchantmentType) {
    vector<string> validEnchantmentTypes = {"ArmorClass","Strength","Constitution","Wisdom","Charisma"};

    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType)
        return Ring(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the creation of the Ring item");
}
Ring::Ring(const string& enchantmentType): Item(enchantmentType){}
