//
// Created by jeanb on 24/02/2024.
//

#include "Armor.h"
#include <stdexcept>
#include <vector>
#include <iostream>
using std::string;
using std::vector;
using std::invalid_argument;
using std::cout;

Armor Armor::createArmor(const string& enchantmentType) {
    vector<string> validEnchantmentTypes = {"ArmorClass"};

    if (enchantmentType == validEnchantmentTypes[0])
        return Armor(enchantmentType, nullptr);

    throw invalid_argument("You provided a non valid enchantment type for the Armor Item");
}

Armor::Armor(const string& enchantmentType, fighter* decoratedInstancePtr): Item(enchantmentType) {
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

void Armor::setCharacteristics(fighter *fighterPtr) {
    fighterPtr->setArmorClass(fighterPtr->getArmorClass() + this->enchantmentDetails.enchantmentBonus);
    cout << "Increasing fighter Armor class of " << this->enchantmentDetails.enchantmentBonus << endl;
}

void Armor::removeAddedCharacteristics(fighter *fighterPtr) {
    fighterPtr->setArmorClass(fighterPtr->getArmorClass() - this->enchantmentDetails.enchantmentBonus);
    cout << "Decreasing fighter Armor class of " << this->enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
}