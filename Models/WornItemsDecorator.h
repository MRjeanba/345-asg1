#ifndef WORNITEMSDECORATOR_H
#define WORNITEMSDECORATOR_H
#include <map>
#include "fighter.h"
#include <string>
using std::string;
using std::map;

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

    WornItemsDecorator();

    virtual ~WornItemsDecorator();

    string getTypes() override = 0;

    virtual string getType() override = 0;

    virtual void setCharacteristics(fighter * fighterPtr) = 0;

    virtual fighter* getFighterPtr();

    virtual void setFighterPtr(fighter * fighterPtr);

private:
    fighter *character;
};

#endif //WORNITEMSDECORATOR_H
