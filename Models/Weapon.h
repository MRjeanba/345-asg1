//
// Created by jeanb on 24/02/2024.
//

#ifndef WEAPON_H
#define WEAPON_H
#include <string>
#include "Item.h"
#include "WornItemsDecorator.h"
#include "cereal/types/polymorphic.hpp"
using std::string;

class Weapon: public Item {
public:
    /**
     * \brief Safely create an instance of Weapon if the provided enchantmentType is valid for the class.
     * \param enchantmentType the provided enchantmentType that we want for the weapon.
     * \return an instance of the Weapon class if the enchantmentType was valid.
     */
    static Weapon * createWeapon(const string& enchantmentType);

    /**
     * \brief Simply instantiate a Weapon with the valid enchantment type.
     * \param enchantmentType the valid enchantment type to forward.
     * \param decoratedInstancePtr
     */
    explicit Weapon(const string& enchantmentType);

    Weapon() = default;
    string getType() override;

    string getTypes() override;

    void setCharacteristics(fighter *fighterPtr) override;

    void removeAddedCharacteristics(fighter *fighterPtr) override;

    /**
     * \brief serialize the Weapon object
     * \tparam Archive the data type in which we want to store the data
     * \param archive the actual archive used for serialization
     */
    template<class Archive>
    void serialize(Archive &archive) {
        archive(cereal::base_class<Item>(this), itemType);
    }

private:
    string itemType = "Weapon";
};

#endif //WEAPON_H
