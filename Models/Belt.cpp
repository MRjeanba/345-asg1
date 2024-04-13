//
// Created by jeanb on 24/02/2024.
//

#include "Belt.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
using std::string;
using std::vector;
using std::invalid_argument;
CEREAL_REGISTER_TYPE(Belt)

Belt * Belt::createBelt(const string& enchantmentType) {
    vector<string> validEnchantmentTypes = {"Constitution","Strength"};

    // we search in the validEnchantmentTypes vector list to verify if enchantmentType is valid
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType)
        return new Belt(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the belt creation");
}
Belt::Belt(const string& enchantmentType):Item(enchantmentType) {
    if (!isItemTypeWorn.at(itemType)) {
        isItemTypeWorn.at(itemType) = true;
    } else {
        cout << "Cannot wear this item, you are already wearing a " + itemType + "!" << endl;
        throw std::runtime_error("Cannot wear another " + itemType + "!\nAborting...");
    }
}

void Belt::setCharacteristics(fighter *fighterPtr) {
    if (enchantmentDetails.enchantmentType == "Constitution"){
        fighterPtr->setConstitution(fighterPtr->getConstitution() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    } else {
        fighterPtr->setStrength(fighterPtr->getStrength() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
}

void Belt::removeAddedCharacteristics(fighter *fighterPtr) {
    if (enchantmentDetails.enchantmentType == "Constitution"){
        fighterPtr->setConstitution(fighterPtr->getConstitution() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    } else {
        fighterPtr->setStrength(fighterPtr->getStrength() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
}

string Belt::getType() { return itemType; }

string Belt::getTypes() {
    return this->getFighterPtr()->getTypes() + "\n" + getType() + "\n";
}