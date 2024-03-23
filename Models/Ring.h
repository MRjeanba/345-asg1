//
// Created by jeanb on 24/02/2024.
//

#ifndef RING_H
#define RING_H
#include <string>

#include "Item.h"
#include "WornItemsDecorator.h"
using std::string;

class Ring: public Item, public WornItemsDecorator {
public:
    /**
     * \brief Safely create an instance of the Ring class
     * \param enchantmentType the enchantmentType wanted for the Ring
     * \return an instance of the Ring class if the given parameter was valid
     */
    static Ring createRing(const string& enchantmentType);

    /**
     * \brief Calls the Base constructor Item to create the Ring Item
     * \param enchantmentType the enchantmentType to apply to the Ring instance
     * \param decoratedInstancePtr
     */
    explicit Ring(const string& enchantmentType, fighter * decoratedInstancePtr);

    string getType() override;

    string getTypes() override;

private:
    string itemType = "Ring";
};

#endif //RING_H