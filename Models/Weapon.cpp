//
// Created by jeanb on 24/02/2024.
//

#include "Weapon.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::invalid_argument;
using std::cout;

Weapon * Weapon::createWeapon(const string &enchantmentType) {
    vector<string> validEnchantmentTypes = {"AttackBonus","DamageBonus"};

    // we search in the validEnchantmentTypes vector list to verify if enchantmentType is valid
    bool isValidEnchantmentType = (std::find(
        validEnchantmentTypes.begin(),
        validEnchantmentTypes.end(),
        enchantmentType) != validEnchantmentTypes.end());

    if (isValidEnchantmentType)
        return new Weapon(enchantmentType);

    throw invalid_argument("Invalid enchantment type provided for the Weapon creation");
}

Weapon::Weapon(const string& enchantmentType): Item(enchantmentType) {}

string Weapon::getType() { return "Weapon"; }

string Weapon::getTypes() {
    return this->getFighterPtr()->getTypes() + "\n" + getType() + "\n";
}

void Weapon::setCharacteristics(fighter *fighterPtr) {
    if (this->enchantmentDetails.enchantmentType == "AttackBonus"){
        fighterPtr->setAttackBonus(fighterPtr->getAttackBonus() + this->enchantmentDetails.enchantmentBonus);
        cout << "Increasing the fighter " <<enchantmentDetails.enchantmentType << " of" << this->enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    else {
        fighterPtr->setDamageBonus(fighterPtr->getDamageBonus() + this->enchantmentDetails.enchantmentBonus);
        cout << "Increasing the fighter " <<enchantmentDetails.enchantmentType << " of" << this->enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
}

void Weapon::removeAddedCharacteristics(fighter *fighterPtr) {
    if (this->enchantmentDetails.enchantmentType == "AttackBonus"){
        fighterPtr->setAttackBonus(fighterPtr->getAttackBonus() - this->enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the fighter " <<enchantmentDetails.enchantmentType << " of" << this->enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
    else {
        fighterPtr->setDamageBonus(fighterPtr->getDamageBonus() - this->enchantmentDetails.enchantmentBonus);
        cout << "Decreasing the fighter " <<enchantmentDetails.enchantmentType << " of" << this->enchantmentDetails.enchantmentBonus << " pts with the " << this->getItemName() << endl;
    }
}