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
    // steps: 1 - check if the current item type is already worn or no
    // if not, then create the instance and set the isItemTypeWorn table to true for the current type

    string itemType;
    try {
        itemType = fighterPtr->getType();
        //itemType = this->itemType;
        if (isItemTypeWorn.at(itemType)) {
            cout << "Cannot wear this item, you are already wearing a " + itemType + "!" << endl;
            return;
        }
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
        WornItemsDecorator::isItemTypeWorn.at(itemType) = true;
    }
    this->character = fighterPtr;
}

fighter * WornItemsDecorator::getFighterPtr() { return character; }

void WornItemsDecorator::remove(WornItemsDecorator * headPtr) {
    // display the current worns items
    // asks the user which one he wanna remove
    // then play with the pointer to remove it

    string itemTypeToRemove;
    cout << "Please indicate which item you would like to remove:" << endl;
    cout << this->getTypes();
    cin >> itemTypeToRemove;
    while (!isItemTypeWorn.at(itemTypeToRemove)) {
        cout << "Please indicate a correct item to remove:" << endl;
        cin >> itemTypeToRemove;
    }

    // call remove with the string of the item to remove, also includes the first layer of the decorator
    remove(itemTypeToRemove, headPtr);
}

void WornItemsDecorator::remove(const string &itemTypeToRemove, WornItemsDecorator * headPtr) {

    // case where we want to remove the first element of the list
    if (itemTypeToRemove == itemType && headPtr == this) {
        WornItemsDecorator * tempPtr = this;
        headPtr = dynamic_cast<WornItemsDecorator *>(this->character);
        //delete tempPtr;
        isItemTypeWorn.at(itemTypeToRemove) = false;
        return;
    }
    // case where the item to remove is the last cell
    if(dynamic_cast<WornItemsDecorator *>(this->character)->character->getType() == "character" &&  dynamic_cast<WornItemsDecorator *>(this->character)->getType() == itemTypeToRemove) {
        WornItemsDecorator * tempPtr = dynamic_cast<WornItemsDecorator *>(this -> character);
        this->character = dynamic_cast<WornItemsDecorator *>(this->character)->character;
        //delete tempPtr;
        isItemTypeWorn.at(itemTypeToRemove) = false;
        return;
    } // normal case where the item to remove is not first and not last
    if (dynamic_cast<Item *>(this->character)->getType() == itemTypeToRemove) {
        WornItemsDecorator * tempPtr = dynamic_cast<WornItemsDecorator *>(this->character);
        this->character = dynamic_cast<WornItemsDecorator *>(this->character)->character;
        isItemTypeWorn.at(itemTypeToRemove) = false;
        return;
    }
    // else, it means that the item to remove is not reachable, so we call the remove(const string &itemTypeToRemove, WornItemsDecorator * headPtr) on the inner decorator
    dynamic_cast<WornItemsDecorator *>(this->character)->remove(itemTypeToRemove, headPtr);
}


WornItemsDecorator::~WornItemsDecorator() {
    delete this->character;
    character = nullptr;
}

string WornItemsDecorator::getType() {
    return itemType;
}
