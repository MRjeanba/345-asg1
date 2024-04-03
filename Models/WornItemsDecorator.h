#ifndef WORNITEMSDECORATOR_H
#define WORNITEMSDECORATOR_H
#include <map>

#include "fighter.h"
#include <string>
using std::string;

inline map<string, int> itemTypeToIntMap = {
    {"Armor", 0},
    {"Belt", 1},
    {"Boots", 2},
    {"Helmet", 3},
    {"Ring", 4},
    {"Shield", 5},
    {"Weapon", 6},
};

class WornItemsDecorator : public fighter {
public:
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

    explicit WornItemsDecorator(fighter *fighterPtr);

    virtual ~WornItemsDecorator();

    map<string, int> getEnchantmentsCharacteristics() override;

    string getTypes() override = 0;

    virtual fighter* getFighterPtr();

    WornItemsDecorator * remove(WornItemsDecorator * headPtr);

    WornItemsDecorator * remove(const string& itemTypeToRemove, WornItemsDecorator * headPtr);

private:
    fighter *character = nullptr;
    string itemType;
};

#endif //WORNITEMSDECORATOR_H
