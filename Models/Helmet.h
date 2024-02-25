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
    explicit Helmet(const string& enchantmentType);
    static Helmet createHelmet(const string& enchantmentType);
};



#endif //HELMET_H
