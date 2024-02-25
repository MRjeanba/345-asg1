//
// Created by jeanb on 24/02/2024.
//

#include "Shield.h"
#include <stdexcept>
#include <vector>
using std::string;
using std::vector;
using std::invalid_argument;

Shield Shield::createShield(const string& enchantmentType) {

    vector<string> validEnchantmentTypes = {"ArmorClass"};

    if (enchantmentType == validEnchantmentTypes[0])
        return Shield(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the Shield creation");
}

Shield::Shield(const string &enchantmentType): Item(enchantmentType) {}
