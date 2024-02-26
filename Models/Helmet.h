//
// Created by jeanb on 24/02/2024.
//

#ifndef HELMET_H
#define HELMET_H
#include <string>
#include "Item.h"
using std::string;

class Helmet: Item {
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
     */
    explicit Helmet(const string& enchantmentType);
};



#endif //HELMET_H
