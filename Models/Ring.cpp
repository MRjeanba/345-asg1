//
// Created by jeanb on 24/02/2024.
//
#include "Ring.h"
#include <algorithm>
#include <iostream>
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
        return Ring(enchantmentType, nullptr);

    throw invalid_argument("Invalid enchantment type provided for the creation of the Ring item");
}

Ring::Ring(const string &enchantmentType, fighter *decoratedInstancePtr):WornItemsDecorator(decoratedInstancePtr), Item(enchantmentType) {
    if (!isItemTypeWorn.at(itemType)) {
        isItemTypeWorn.at(itemType) = true;
    } else {
        cout << "Cannot wear this item, you are already wearing a " + itemType + "!" << endl;
        return;
    }
}

string Ring::getType() {return itemType;}

string Ring::getTypes() {
    return this->getFighterPtr()->getTypes() + "\n" + getType() + "\n";
}