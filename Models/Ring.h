//
// Created by jeanb on 24/02/2024.
//

#ifndef RING_H
#define RING_H
#include <string>

#include "Item.h"
using std::string;

class Ring: Item {
public:
    /**
     * \brief 
     * \param enchantmentType
     * \return 
     */
    static Ring createRing(const string& enchantmentType);

    /**
     * \brief 
     * \param enchantmentType
     */
    explicit Ring(const string& enchantmentType);
};

#endif //RING_H