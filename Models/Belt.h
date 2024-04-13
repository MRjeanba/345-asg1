//
// Created by jeanb on 24/02/2024.
//

#ifndef BELT_H
#define BELT_H

#include <string>
#include "Item.h"
#include "WornItemsDecorator.h"
#include "cereal/types/polymorphic.hpp"

using std::string;

class Belt : public Item {
public:

    /**
     * \brief Safely create an instance of Belt if the provided enchantmentType is valid for the class.
     * \param enchantmentType the provided enchantmentType that we want for the belt.
     * \return an instance of the Belt class if the enchantmentType was valid.
     */
    static Belt * createBelt(const string &enchantmentType);

    /**
     * \brief Simply instantiate a Belt with the valid enchantment type.
     * \param enchantmentType the valid enchantment type to forward.
     * \param decoratedInstancePtr
     */
    explicit Belt(const string &enchantmentType);

    Belt() = default;

    string getType() override;

    string getTypes() override;

    void setCharacteristics(fighter *fighterPtr) override;

    void removeAddedCharacteristics(fighter *fighterPtr) override;

    /**
     * \brief serialize the Belt object
     * \tparam Archive the data type in which we want to store the data
     * \param archive the actual archive used for serialization
     */
    template<class Archive>
    void serialize(Archive &archive) {
        archive(cereal::base_class<Item>(this), itemType);
    }

private:
    string itemType = "Belt";
};

#endif //BELT_H