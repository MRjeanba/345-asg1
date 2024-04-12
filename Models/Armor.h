//
// Created by jeanb on 24/02/2024.
//

#ifndef ARMOR_H
#define ARMOR_H
#include <string>
#include "Item.h"
#include "WornItemsDecorator.h"

class Armor: public Item {
public:
    /**
     * \brief safely create an Armor item if the given enchantment type is valid
     * \param enchantmentType the wanted enchantmentType for the Armor Item
     * \return an instance of an Armor item if the provided enchantmentType was valid
     */
    static Armor createArmor(const std::string& enchantmentType);

    /**
     * \brief Calls the parent constructor Item before creating an instance of Armor
     * \param enchantmentType the enchantmentType wanted for the Armor item
     * \param decoratedInstancePtr
     */
    explicit Armor(const std::string& enchantmentType, fighter* decoratedInstancePtr);

    string getType() override;

    string getTypes() override;

    void setCharacteristics(fighter *fighterPtr) override;

    void removeAddedCharacteristics(fighter *fighterPtr) override;

private:
    string itemType = "Armor";
};

#endif //ARMOR_H