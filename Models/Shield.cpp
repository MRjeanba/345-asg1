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
        return Shield(enchantmentType, nullptr);

    throw invalid_argument("Invalid enchantment type provided for the Shield creation");
}

Shield::Shield(const string &enchantmentType, fighter * decoratedInstancePtr): Item(enchantmentType), WornItemsDecorator(decoratedInstancePtr) {}

string Shield::getType() { return "Shield"; }

string Shield::getTypes() {
    return this->getFighterPtr()->getTypes() + getType() + "\n";
}
