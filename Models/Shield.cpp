//
// Created by jeanb on 24/02/2024.
//

#include "Shield.h"
#include <stdexcept>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::invalid_argument;
using std::cout;

Shield Shield::createShield(const string& enchantmentType) {

    vector<string> validEnchantmentTypes = {"ArmorClass"};

    if (enchantmentType == validEnchantmentTypes[0])
        return Shield(enchantmentType, nullptr);

    throw invalid_argument("Invalid enchantment type provided for the Shield creation");
}

Shield::Shield(const string &enchantmentType, fighter * decoratedInstancePtr): Item(enchantmentType) {}

string Shield::getType() { return "Shield"; }

string Shield::getTypes() {
    return this->getFighterPtr()->getTypes() + getType() + "\n";
}

void Shield::setCharacteristics(fighter *fighterPtr) {
    fighterPtr->setArmorClass(fighterPtr->getArmorClass() + this->enchantmentDetails.enchantmentBonus);
    cout << "Increasing fighter Armor class of " << this->enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
}

void Shield::removeAddedCharacteristics(fighter *fighterPtr) {
    fighterPtr->setArmorClass(fighterPtr->getArmorClass() - this->enchantmentDetails.enchantmentBonus);
    cout << "Decreasing fighter Armor class of " << this->enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
}