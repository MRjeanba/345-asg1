//
// Created by jeanb on 22/02/2024.
//
#include <iostream>
#include "Item.h"
#include "EnchantmentInfo.h"
#include <cstdlib>

using namespace std;

void Item::outputInfos() {
    cout <<  enchantmentDetails.enchantmentBonus <<
        " and here is enchantment type: " <<
            enchantmentDetails.enchantmentType << endl;
}


Item::Item(const string& enchantmentType):WornItemsDecorator() {
    int enchantBonus;
    cout << "Enter the bonus to assign for this item: ";
    cin >> enchantBonus;
    cout << "Crafting the item...";
    this->enchantmentDetails = {enchantBonus, enchantmentType};
    this->enchantmentDetails.enchantmentBonus = enchantBonus;
    this->enchantmentDetails.enchantmentType = enchantmentType;
    this->enchantmentDetails.enchantmentTypeToBonus.insert({enchantmentType,enchantBonus});
    cout << "Item crafted successfully!" << endl;
}

EnchantmentInfo Item::getEnchantmentInfo() {
    return this->enchantmentDetails;
}

string Item::getItemName() {
    return this->itemName;
}

void Item::displayEnchantmentInfo() {
    cout << "The enchantment type is: " << enchantmentDetails.enchantmentType << endl;
    cout << "The enchantment bonus is: " << enchantmentDetails.enchantmentBonus << endl;
}

void Item::setItemName(const string &name) {
    this->itemName = name;
}

void Item::setType(std::string type) {
    itemType = type;
}