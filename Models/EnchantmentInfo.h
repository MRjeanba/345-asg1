//
// Created by jeanb on 24/02/2024.
//

#ifndef ENCHANTMENTINFO_H
#define ENCHANTMENTINFO_H
#include <map>
#include <string>

using std::string;

/**
 * \brief Structure defined in order to get the enchantment bonus and enchantment type from a same place
 * The structure holds two variables: enchantmentBonus and enchantmentType
 */
struct  EnchantmentInfo {
    int enchantmentBonus;
    string enchantmentType;
    std::map<string,int> enchantmentTypeToBonus = {};
};


#endif //ENCHANTMENTINFO_H