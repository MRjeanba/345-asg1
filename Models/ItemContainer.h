//
// Created by jeanb on 25/02/2024.
//

#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H
#include <vector>
#include "Item.h"
using std::vector;


class ItemContainer {
private:
    vector<Item> containedItems;
public:
    /**
     * \brief Get an Item in the container
     * \param position an integer representing a position in the container
     * \return The Item located at the given position
     */
    Item getItemAtPosition(int& position);

    /**
     * Get the size of the container
     * @return an integer value representing the size of the container
     */
    int getSizeOfContainer();

    virtual /**
     * \brief Add the given item to the container
     * \param itemToAdd the item we want to add to the container
     */
    void addItemToContainer(Item& itemToAdd);

    /**
     * Base constructor to create a container
     */
    explicit ItemContainer();
};



#endif //ITEMCONTAINER_H
