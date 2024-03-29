//
// Created by jeanb on 24/02/2024.
//

#ifndef BELT_H
#define BELT_H
#include <string>
#include "Item.h"
#include "WornItemsDecorator.h"
using std::string;

class Belt: public Item, public WornItemsDecorator {
public:

    /**
     * \brief Safely create an instance of Belt if the provided enchantmentType is valid for the class.
     * \param enchantmentType the provided enchantmentType that we want for the belt.
     * \return an instance of the Belt class if the enchantmentType was valid.
     */
    static Belt createBelt(const string& enchantmentType);

    /**
     * \brief Simply instantiate a Belt with the valid enchantment type.
     * \param enchantmentType the valid enchantment type to forward.
     * \param decoratedInstancePtr
     */
    explicit Belt(const string& enchantmentType, fighter * decoratedInstancePtr);

    string getType() override;

    string getTypes() override;

private:
    string itemType = "Belt";
};

#endif //BELT_H