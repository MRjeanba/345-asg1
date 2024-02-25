//
// Created by jeanb on 24/02/2024.
//

#include "Armor.h"

#include <stdexcept>
#include <vector>
using std::string;
using std::vector;
using std::invalid_argument;

Armor Armor::createArmor(const string& enchantmentType) {
    vector<string> validEnchantmentTypes = {"ArmorClass"};

    if (enchantmentType == validEnchantmentTypes[0])
        return Armor(enchantmentType);

    throw invalid_argument("You provided a non valid enchantment type for the Armor Item");
}

Armor::Armor(const string& enchantmentType):Item(enchantmentType) {}