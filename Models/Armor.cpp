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
        return Armor(enchantmentType, nullptr);

    throw invalid_argument("You provided a non valid enchantment type for the Armor Item");
}

Armor::Armor(const string& enchantmentType, fighter* decoratedInstancePtr): Item(enchantmentType), WornItemsDecorator(decoratedInstancePtr) {
    if(!isItemTypeWorn.at(itemType)) {
        isItemTypeWorn.at(itemType) = true;
    }
}

string Armor::getType() {
    return itemType;
}

string Armor::getTypes() {
    return this->getFighterPtr()->getTypes() + "\n" + getType() + "\n";
}
