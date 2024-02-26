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
    int getSizeOfContainer();

    virtual /**
     * \brief 
     * \param itemToAdd
     */
    void addItemToContainer(Item& itemToAdd);

    explicit ItemContainer();
};



#endif //ITEMCONTAINER_H
