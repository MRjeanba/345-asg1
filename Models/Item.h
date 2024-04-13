//
// Created by jeanb on 22/02/2024.
//

#ifndef ITEM_H
#define ITEM_H

#include "EnchantmentInfo.h"
#include "WornItemsDecorator.h"
#include <string>
#include <cereal/types/polymorphic.hpp>
/**
 * \brief Base class for the different items in the game, items have an enchantment bonus and type
 */
class Item : public WornItemsDecorator {
public:
    string itemType;
    vector<string> validEnchantmentTypes;
    virtual ~Item() = default;

    /**
        * Creates an instance of an Item, with the given enchantType
        * @param enchantType the enchantmentType provided by the user
        */
    explicit Item(const std::string &enchantType);

    Item() = default;

/**
 * Get the enchantmentDetails structure inside the item, holding the info about enchantmentBonus and type
 * @return enchantmentDetails, the structure contained within the item
 */
    EnchantmentInfo getEnchantmentInfo();

    /**
     * Helper method just to display the item at its creation to see if it is working
     */
    void outputInfos();

    /**
     * Return the type of the current item
     */
    virtual string getType() = 0;

    /**
     * Return the type of the current item + all the decorated items
     */
    virtual string getTypes() = 0;

    /**
     * \brief Display the enchantment type and bonus of the item
     */
    void displayEnchantmentInfo();

    /**
     * \brief a structure holding the enchantment bonus and type in one place
     */
    EnchantmentInfo enchantmentDetails{};


    virtual void removeAddedCharacteristics(fighter *fighterPtr) = 0;

    string getItemName();

    void setItemName(const string& name);

    template<class Archive>
     void serialize(Archive &archive) {
        archive(cereal::make_nvp("enchantmentDetails", enchantmentDetails),
                cereal::make_nvp("itemName", itemName),
                cereal::make_nvp("itemType", this->getType())
        );
    }

private:
    string itemName;
};


#endif //ITEM_H
