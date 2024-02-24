//
// Created by jeanb on 24/02/2024.
//

#ifndef HELMET_H
#define HELMET_H
#include <string>

#include "Item.h"


class Helmet : Item {
public:
    explicit Helmet(std::string enchantmentType);
    static Helmet CreateHelmet(std::string enchantmentType);
};



#endif //HELMET_H
