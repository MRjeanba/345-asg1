//
// Created by jeanb on 24/02/2024.
//

#include "Helmet.h"
#include <utility>
#include <vector>
#include "Item.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>
using std::string;
using std::vector;
using std::invalid_argument;
CEREAL_REGISTER_TYPE(Helmet)

/**
 * \brief This method is used instead of the constructor, it will ensure that the provided enchantment type is valid before calling the constructor
 * \param enchantmentType the enchantment provided for this helmet
 * \return a new instance of a helmet
 */
Helmet * Helmet::createHelmet(const string& enchantmentType) {
    vector<string> validEnchantmentTypes = {"Intelligence","Wisdom","ArmorClass"};

    // we search in the validEnchantmentTypes vector list if we have the value given as param (enchantmentType)
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType){
        return new Helmet(enchantmentType);
    }
    throw invalid_argument("The enchantment type provided does not match with the accepted enchantment types");
}

/**
 * \brief Calls the Item constructor to build the Helmet
 * \param enchantmentType At this stage, the enchantmentType is valid so we proceed to create the Item
 * \param decoratedInstancePtr
 */
Helmet::Helmet(const string& enchantmentType): Item(enchantmentType) {
}

string Helmet::getType() { return itemType; }

string Helmet::getTypes() {
    return this->getFighterPtr()->getTypes() + "\n" + this->getType() + "\n";
}

void Helmet::setCharacteristics(fighter *fighterPtr) {
    if (this->enchantmentDetails.enchantmentType == "Intelligence"){
        fighterPtr->setIntelligence(fighterPtr->getIntelligence() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Wisdom"){
        fighterPtr->setWisdom(fighterPtr->getWisdom() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    else {
        fighterPtr->setArmorClass(fighterPtr->getArmorClass() + enchantmentDetails.enchantmentBonus);
        cout << "Increasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
}

void Helmet::removeAddedCharacteristics(fighter *fighterPtr) {
    if (enchantmentDetails.enchantmentType == "Intelligence"){
        fighterPtr->setIntelligence(fighterPtr->getIntelligence() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
    if (enchantmentDetails.enchantmentType == "Wisdom"){
        fighterPtr->setWisdom(fighterPtr->getWisdom() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
    else {
        fighterPtr->setArmorClass(fighterPtr->getArmorClass() - enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the " << enchantmentDetails.enchantmentType << " of the character of "<< enchantmentDetails.enchantmentBonus << " pts by removing " << this->getItemName() << endl;
    }
}