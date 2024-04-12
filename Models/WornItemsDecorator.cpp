//
// Created by Jean-Baptiste Garibo on 2024-03-22.
//

#include "WornItemsDecorator.h"

#include <iostream>

#include "Item.h"
using std::cout;
using std::cerr;
using std::endl;

fighter * WornItemsDecorator::getFighterPtr() { return character; }

WornItemsDecorator::~WornItemsDecorator() {
    character = nullptr;
}

string WornItemsDecorator::getType() {
    return dynamic_cast<Item *>(this)->getType();
}

void WornItemsDecorator::setFighterPtr(fighter *fighterPtr) {
    this->character = fighterPtr;
}

WornItemsDecorator::WornItemsDecorator() {
    character = nullptr;
}