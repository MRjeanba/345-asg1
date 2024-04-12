//
// Created by jeanb on 24/02/2024.
//
#include "Ring.h"
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
        return Ring(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the creation of the Ring item");
}

Ring::Ring(const string &enchantmentType): Item(enchantmentType) {
    if (!isItemTypeWorn.at(itemType)) {
        isItemTypeWorn.at(itemType) = true;
    } else {
        cout << "Cannot wear this item, you are already wearing a " + itemType + "!" << endl;
        throw std::runtime_error("Cannot wear another " + itemType + "!\nAborting...");
        return;
    }
}

string Ring::getType() {return itemType;}

string Ring::getTypes() {
    return this->getFighterPtr()->getTypes() + "\n" + getType() + "\n";
}

void Ring::setCharacteristics(fighter *fighterPtr) {
    if (enchantmentDetails.enchantmentType == "ArmorClass"){
        fighterPtr->setArmorClass(fighterPtr->getArmorClass() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Wisdom"){
        fighterPtr->setWisdom(fighterPtr->getWisdom() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Strength"){
        fighterPtr->setStrength(fighterPtr->getStrength() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Constitution"){
        fighterPtr->setConstitution(fighterPtr->getConstitution() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    else {
        fighterPtr->setCharisma(fighterPtr->getCharisma() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
}

void Ring::removeAddedCharacteristics(fighter *fighterPtr) {
    if (enchantmentDetails.enchantmentType == "ArmorClass"){
        fighterPtr->setArmorClass(fighterPtr->getArmorClass() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Wisdom"){
        fighterPtr->setWisdom(fighterPtr->getWisdom() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Strength"){
        fighterPtr->setStrength(fighterPtr->getStrength() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Constitution"){
        fighterPtr->setConstitution(fighterPtr->getConstitution() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
    else {
        fighterPtr->setCharisma(fighterPtr->getCharisma() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
}