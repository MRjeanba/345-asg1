#include "Chest.h"


vector <string> Chest::removeElements() {
    return itemsNames;
}

void Chest::addElement(string itemName) {
    itemsNames.push_back(itemName);
}

bool Chest::isValidItemName(const string &itemName) {
    for (const auto &item : itemsNames) {
        if (item == itemName) {
            return true;
        }
    }
    return false;
}
