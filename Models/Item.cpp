//
// Created by jeanb on 22/02/2024.
// TODO: IMPLEMENT IT
//
#include <iostream>
#include "Item.h"
#include "EnchantmentInfo.h"

using namespace std;

/**
 * \brief Implementation of the @Item class
 */

void Item::outputInfos() {
    cout <<  enchantmentDetails.enchantmentBonus <<
        " and here is enchantment type: " <<
            ToString(enchantmentDetails.enchantmentType) << endl;
}

Item::Item() {
    std::cout << "creating Item" << endl;
    this->enchantmentDetails = {2, ArmorClass};
    std::cout << "Item created, here are the details: ";
    this->outputInfos();
}

EnchantmentInfo Item::getEnchantmentInfo() {
    return this->enchantmentDetails;
}



