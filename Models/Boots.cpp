//
// Created by jeanb on 24/02/2024.
//

#include "Boots.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream>
using std::string;
using std::vector;
using std::invalid_argument;
using std::cout;

Boots Boots::createBoots(const string &enchantmentType) {
    vector<string> validEnchantmentTypes = {"ArmorClass", "Dexterity"};

    // we search in the validEnchantmentTypes vector list to verify if enchantmentType is valid
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType)
        return Boots(enchantmentType, nullptr);

    throw invalid_argument("Invalid enchantment type provided for the Boots creation");
}
Boots::Boots(const string &enchantmentType, fighter * decoratedInstancePtr): Item(enchantmentType) {}

string Boots::getType() { return "Boots"; }

string Boots::getTypes() {
    return this->getFighterPtr()->getTypes() + "\n" + getType() + "\n";
}

void Boots::setCharacteristics(fighter *fighterPtr) {
    if (enchantmentDetails.enchantmentType == "ArmorClass"){
        fighterPtr->setArmorClass(fighterPtr->getArmorClass() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    } else {
        fighterPtr->setDexterity(fighterPtr->getDexterity() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
}

void Boots::removeAddedCharacteristics(fighter *fighterPtr) {
    if (enchantmentDetails.enchantmentType == "ArmorClass"){
        fighterPtr->setArmorClass(fighterPtr->getArmorClass() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character by "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    } else {
        fighterPtr->setDexterity(fighterPtr->getDexterity() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character by "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
}