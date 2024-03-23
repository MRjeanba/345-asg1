//
// Created by jeanb on 24/02/2024.
//

#ifndef BOOTS_H
#define BOOTS_H
#include <string>
#include "Item.h"
#include "WornItemsDecorator.h"
using std::string;

class Boots: public Item, WornItemsDecorator {
public:
    /**
     * \brief safely instantiate a Boots object if the provided enchantmentType is valid
     * \param enchantmentType the provided enchantmentType that we want for the Boots.
     * \return an instance of Boots if the enchantment type is valid
     */
    static Boots createBoots(const string& enchantmentType);

    /**
     * \brief instantiate an Object of the Boots class
     * \param enchantmentType the valid enchantment type for the Boots class
     * \param decoratedInstancePtr
     */
    explicit Boots(const string& enchantmentType, fighter * decoratedInstancePtr);

    string getType() override;

    string getTypes() override;

private:
    string itemType = "Boots";
};

#endif //BOOTS_H