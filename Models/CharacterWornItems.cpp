//
// Created by jeanb on 25/02/2024.
//

#include "CharacterWornItems.h"
#include <iostream>
#include "fighter.h"
#include "Item.h"
using std::cout;
using std::endl;


CharacterWornItems::CharacterWornItems() {
    numberOfWornItems = 0;
    fighterWearingItems = nullptr;
    wornItems = nullptr;
}

void CharacterWornItems::attachFighter(fighter *fighterPtr) {
    this->fighterWearingItems = fighterPtr;
}

CharacterWornItems::CharacterWornItems(fighter *fighterPtr) {
    numberOfWornItems = 0;
    fighterWearingItems = fighterPtr;
    wornItems = nullptr;
}

// same remove than for linked list
void CharacterWornItems::removeFromWornItems() {
    string itemTypeToRemove;
    cout << "Please indicate which item you would like to remove:" << endl;
    cout << wornItems->getTypes() << endl;
    cin >> itemTypeToRemove;
    while (!isItemTypeWorn.at(itemTypeToRemove)) {
        cout << "Please indicate a correct item to remove:" << endl;
        cin >> itemTypeToRemove;
    }

    // call remove with the string of the item to remove, also includes the first layer of the decorator
    return removeItem(itemTypeToRemove);
}

void CharacterWornItems::removeItem(const string &itemTypeToRemove) {
    WornItemsDecorator * tempPtr = wornItems;
    int idx = 0;

    while(tempPtr->getType() != "character"){
        // remove first el
        if (itemTypeToRemove == tempPtr->getType() && idx == 0) {
            // move ptr to next ptr if not type fighter
            if (wornItems->getFighterPtr()->getType() == "character"){
                dynamic_cast<Item *>(wornItems)->removeAddedCharacteristics(fighterWearingItems);
                // set the ptr to null, since it means that not other items are worn by the character
                wornItems = nullptr;
                numberOfWornItems--;
                isItemTypeWorn.at(itemTypeToRemove) = false;
                cout << "removing the item..." << endl;
                cout << "Item removed!" << endl;
                return;
            } // else we just move the beginning of the list to next pointer
            else {
                isItemTypeWorn.at(itemTypeToRemove) = false;
                dynamic_cast<Item *>(wornItems)->removeAddedCharacteristics(fighterWearingItems);
                wornItems = dynamic_cast<WornItemsDecorator *>(wornItems->getFighterPtr());
                cout << "removing the item..." << endl;
                cout << "Item removed!" << endl;
                return;
            };
        } // move the ptr 2 ptr further, so to another item or to a fighter
        if (itemTypeToRemove == tempPtr->getFighterPtr()->getType() ){
            dynamic_cast<Item *>(tempPtr->getFighterPtr())->removeAddedCharacteristics(fighterWearingItems);
            wornItems->setFighterPtr(dynamic_cast<WornItemsDecorator *>(wornItems->getFighterPtr())->getFighterPtr());
            return;
        }
        idx++;
        tempPtr = dynamic_cast<WornItemsDecorator *>(tempPtr->getFighterPtr());
    }
}

void CharacterWornItems::wearItem(WornItemsDecorator * itemToWear) {
    // if no items currently worn, worn item now points to the item we want to wear.
    // and the item we want to wear point to the fighter wearing it
    if (numberOfWornItems == 0){
        this->wornItems = dynamic_cast<WornItemsDecorator *>(itemToWear);
        wornItems->setFighterPtr(fighterWearingItems);
        numberOfWornItems ++;
        itemToWear->setCharacteristics(fighterWearingItems);
        isItemTypeWorn.at(itemToWear->getType()) = true;
        return;
    }
    if (isItemTypeWorn.at(itemToWear->getType())){
        cout << "You cannot wear an item type that you are already wearing... ("<< itemToWear->getType()<<")" << endl;
    }
    else {
        // if we already have items, add the new item at the head of the "linked list"
        itemToWear->setFighterPtr(dynamic_cast<fighter * >(wornItems));
        wornItems = itemToWear;
        numberOfWornItems ++;
        itemToWear->setCharacteristics(fighterWearingItems);
        isItemTypeWorn.at(itemToWear->getType()) = true;
    }
}

void CharacterWornItems::getWornItems() {
    if (numberOfWornItems > 0){
        cout << this->wornItems->getTypes() << endl;
    }
    else{
        cout << "No items worn!" << endl;
    }
}