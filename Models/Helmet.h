//
// Created by jeanb on 24/02/2024.
//

#ifndef HELMET_H
#define HELMET_H
#include <string>
#include "Item.h"
#include "WornItemsDecorator.h"
using std::string;

class Helmet: public Item {
public:
    /**
     * \brief safely instantiate a Helmet object if the provided enchantmentType is valid
     * \param enchantmentType the provided enchantmentType that we want for the Helmet.
     * \return an instance of Helmet if the enchantment type is valid
     */
    static Helmet createHelmet(const string& enchantmentType);

    /**
     * \brief instantiate an Object of the Helmet class by calling the parent class
     * \param enchantmentType the valid enchantment type for the Helmet class
     * \param decoratedInstancePtr
     */
    explicit Helmet(const string& enchantmentType);

    string getType() override;

    string getTypes() override;

    void setCharacteristics(fighter *fighterPtr) override;

    void removeAddedCharacteristics(fighter *fighterPtr) override;

private:
    string itemType = "Helmet";
};



#endif //HELMET_H
