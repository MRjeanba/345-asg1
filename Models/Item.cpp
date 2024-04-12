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
    int randomEnchantBonus = rand() % 5 +1;
    this->enchantmentDetails = {randomEnchantBonus, enchantmentType};
    this->enchantmentDetails.enchantmentBonus = randomEnchantBonus;
    this->enchantmentDetails.enchantmentType = enchantmentType;
    this->enchantmentDetails.enchantmentTypeToBonus.insert({enchantmentType,randomEnchantBonus});
    //std::cout << "Item created, here are the details: ";
    //this->outputInfos();
}

EnchantmentInfo Item::getEnchantmentInfo() {
    return this->enchantmentDetails;
}

string Item::getItemName() {
    return this->itemName;
}