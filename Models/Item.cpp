//
// Created by jeanb on 22/02/2024.
//
#include <iostream>
#include <utility>
#include "Item.h"
#include "EnchantmentInfo.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void Item::outputInfos() {
    cout <<  enchantmentDetails.enchantmentBonus <<
        " and here is enchantment type: " <<
            ToString(enchantmentDetails.enchantmentType) << endl;
}

Item::Item(const string& enchantmentType) {
    std::cout << "creating Item" << endl;
    // to have more random number
    srand((unsigned int)time(NULL));
    this->enchantmentDetails = {rand() % 6, stringToEnchantmentInt[enchantmentType]};
    std::cout << "Item created, here are the details: ";
    this->outputInfos();
}

EnchantmentInfo Item::getEnchantmentInfo() {
    return this->enchantmentDetails;
}



