//
// Created by jeanb on 24/02/2024.
//

#ifndef SHIELD_H
#define SHIELD_H
#include <string>
#include "Item.h"
#include "WornItemsDecorator.h"
#include "cereal/types/polymorphic.hpp"
using std::string;

class Shield: public Item {
public:
    /**
     * \brief safely create a Shield item if the given enchantment type is valide
     * \param enchantmentType the enchantment type that we want for the shield
     * \return an instance of a Shield class if the provided enchantment type is correct
     */
    static Shield * createShield(const string& enchantmentType);

    /**
     * \brief calls the Item parent constructor to instantiate the fields
     * \param enchantmentType
     * \param decoratedInstancePtr
     */
    explicit Shield(const string& enchantmentType);

    string getType() override;

    string getTypes() override;

    void setCharacteristics(fighter *fighterPtr) override;

    void removeAddedCharacteristics(fighter *fighterPtr) override;

    /**
     * \brief serialize the Shield object
     * \tparam Archive the data type in which we want to store the data
     * \param archive the actual archive used for serialization
     */
    template<class Archive>
    void serialize(Archive &archive) {
        archive(cereal::base_class<Item>(this), itemType);
    }

private:
    string itemType = "Shield";
};

#endif //SHIELD_H
