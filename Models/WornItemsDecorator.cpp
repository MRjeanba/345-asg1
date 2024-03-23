//
// Created by Jean-Baptiste Garibo on 2024-03-22.
//

#include "WornItemsDecorator.h"

#include <iostream>

#include "Item.h"
using std::cout;
using std::cerr;
using std::endl;

WornItemsDecorator::WornItemsDecorator(fighter* fighterPtr):fighter() {
    string itemType;
    try {
        itemType = fighterPtr->getType();
        //itemType = this->itemType;
    } catch (...) {
        if (itemType == "character") {
            this->character = fighterPtr;
            cout << "Decorating the character..." << endl;
            return;
        }
        cerr << " ----> An error occured while trying to access a fighterPtr variable, check for eventual memory leak..." << endl;
    }
    if (itemType == "character") {
        cout << "Decorating the character..." << endl;
    } else {
        cout << "adding the " + itemType + " on the character..." << endl;
        //WornItemsDecorator::isItemTypeWorn.at(itemType) = true;
    }
    this->character = fighterPtr;
}

fighter * WornItemsDecorator::getFighterPtr() { return character; }

WornItemsDecorator * WornItemsDecorator::remove(WornItemsDecorator * headPtr) {
    string itemTypeToRemove;
    cout << "Please indicate which item you would like to remove:" << endl;
    cout << this->getTypes();
    cin >> itemTypeToRemove;
    while (!isItemTypeWorn.at(itemTypeToRemove)) {
        cout << "Please indicate a correct item to remove:" << endl;
        cin >> itemTypeToRemove;
    }

    // call remove with the string of the item to remove, also includes the first layer of the decorator
    return remove(itemTypeToRemove, headPtr);
}

WornItemsDecorator * WornItemsDecorator::remove(const string &itemTypeToRemove, WornItemsDecorator * headPtr) {

    // case where we want to remove the first element of the list
    if (itemTypeToRemove == this->getType() && headPtr == this) {
        headPtr = dynamic_cast<WornItemsDecorator *>(this->character);
        //this = &headPtr;
        isItemTypeWorn.at(itemTypeToRemove) = false;
        return headPtr;
    }
    // case where the item to remove is the last cell
    if(dynamic_cast<WornItemsDecorator *>(this->character)->character->getType() == "character" &&  dynamic_cast<WornItemsDecorator *>(this->character)->getType() == itemTypeToRemove) {
        //WornItemsDecorator * tempPtr = dynamic_cast<WornItemsDecorator *>(this -> character);
        this->character = dynamic_cast<WornItemsDecorator *>(this->character)->character;
        //delete tempPtr;
        isItemTypeWorn.at(itemTypeToRemove) = false;
        return headPtr;
    } // normal case where the item to remove is not first and not last
    if (dynamic_cast<Item *>(this->character)->getType() == itemTypeToRemove) {
        WornItemsDecorator * tempPtr = dynamic_cast<WornItemsDecorator *>(this->character);
        this->character = dynamic_cast<WornItemsDecorator *>(this->character)->character;
        //tempPtr = nullptr;
        isItemTypeWorn.at(itemTypeToRemove) = false;
        return headPtr;
    }
    // else, it means that the item to remove is not reachable, so we call the remove(const string &itemTypeToRemove, WornItemsDecorator * headPtr) on the inner decorator
    return dynamic_cast<WornItemsDecorator *>(this->character)->remove(itemTypeToRemove, headPtr);
}


WornItemsDecorator::~WornItemsDecorator() {
    delete this->character;
    character = nullptr;
}

map<string, int> WornItemsDecorator::getEnchantmentsCharacteristics() {
    auto curr = this->character->getEnchantmentsCharacteristics();
    string enchantType = dynamic_cast<Item *>(this)->enchantmentDetails.enchantmentType;
    int bonus = dynamic_cast<Item *>(this)->enchantmentDetails.enchantmentBonus;
    cout << "adding " << bonus << " points to " << enchantType << endl;
    curr.at(enchantType) += bonus;
    return curr;
}

// string WornItemsDecorator::getType() {
//     return itemType;
// }
