// //
// // Created by jeanb on 25/02/2024.
// //
//
 #include "ItemContainer.h"
#include <stdexcept>
#include <iostream>
using std::invalid_argument;
using std::cout;

 Item ItemContainer::getItemAtPosition(int& position) {

    // verify that the position is valid
     if (position < this->containedItems.max_size() && position >= 0){
         Item itemToReturn = this->containedItems.at(position);
         this->containedItems.erase(this->containedItems.begin() + position);
         cout << "item inserted at positon 0" << std::endl;
         return itemToReturn;
     }
     throw invalid_argument("Position asked is out of range for this container");
 }

 void ItemContainer::addItemToContainer(Item &itemToAdd) {
    this->containedItems.push_back(itemToAdd);
 }

int ItemContainer::getSizeOfContainer() {
    return static_cast<int>(this->containedItems.size());
}

ItemContainer::ItemContainer() = default;
