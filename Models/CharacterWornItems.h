//
// Created by jeanb on 25/02/2024.
//

#ifndef INC_345_ASG1_CHARACTERWORNITEMS_H
#define INC_345_ASG1_CHARACTERWORNITEMS_H


#include <map>
#include <string>
#include "EnchantmentInfo.h"
using std::map;
using std::string;
class WornItemsDecorator;
class fighter;
/**
 * Container class, which holds the worn items of a character
 */
class CharacterWornItems {
public:
    CharacterWornItems();
    explicit CharacterWornItems(fighter * fighterPtr);

    void getWornItems();
    friend class fighter;
    void attachFighter(fighter * fighterPtr);
    void removeFromWornItems();
    void removeItem(const string& itemTypeToRemove);

    void wearItem(WornItemsDecorator * itemToWear);

    inline static map<string,bool> isItemTypeWorn = {
            {"Armor", false},
            {"Belt", false},
            {"Boots", false},
            {"Helmet", false},
            {"Ring", false},
            {"Shield", false},
            {"Weapon", false},
            {"character", false},
    };

private:
    WornItemsDecorator * wornItems;
    fighter * fighterWearingItems;
    int numberOfWornItems;
};

#endif //INC_345_ASG1_CHARACTERWORNITEMS_H
