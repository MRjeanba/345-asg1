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

/**
 * \brief This method is used instead of the constructor, it will ensure that the provided enchantment type is valid before calling the constructor
 * \param enchantmentType the enchantment provided for this helmet
 * \return a new instance of a helmet
 */
Helmet Helmet::createHelmet(const string& enchantmentType) {
    vector<string> validEnchantmentTypes = {"Intelligence","Wisdom","ArmorClass"};

    // we search in the validEnchantmentTypes vector list if we have the value given as param (enchantmentType)
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType){
        return Helmet(enchantmentType, nullptr);
    }
    throw invalid_argument("The enchantment type provided does not match with the accepted enchantment types");
}

/**
 * \brief Calls the Item constructor to build the Helmet
 * \param enchantmentType At this stage, the enchantmentType is valid so we proceed to create the Item
 * \param decoratedInstancePtr
 */
Helmet::Helmet(const string& enchantmentType, fighter * decoratedInstancePtr): WornItemsDecorator(decoratedInstancePtr), Item(enchantmentType) {
    if (!isItemTypeWorn.at(itemType)) {
        isItemTypeWorn.at(itemType) = true;
    } else {
        cout << "Cannot wear this item, you are already wearing a " + itemType + "!" << endl;
        throw std::runtime_error("Cannot wear another " + itemType + "!\nAborting...");
        return;
    }
}

string Helmet::getType() { return itemType; }

string Helmet::getTypes() {
    return getFighterPtr()->getTypes() + "\n" + getType() + "\n";
}