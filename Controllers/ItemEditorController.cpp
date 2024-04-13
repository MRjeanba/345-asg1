//
// Created by Jean-Baptiste Garibo on 2024-04-12.
//

#include "ItemEditorController.h"
#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include <cereal/archives/xml.hpp>
#include "../Models/Armor.h"
#include "../Models/Helmet.h"
#include "../Models/Belt.h"
#include "../Models/Shield.h"
#include "../Models/Boots.h"
#include "../Models/Ring.h"
#include "../Models/Weapon.h"
#include "../Models/Chest.h"

using std::string;
ItemEditorController::ItemEditorController() {
    if (numberOfInstances == 0) {
        initializeStoredItems();
        numberOfInstances++;
    } else {
        throw std::invalid_argument("Cannot instantiate more than one ItemEditorController");
    }
}

void ItemEditorController::initializeStoredItems() {
    try {
        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        for (const auto &dirEntry : recursive_directory_iterator(std::filesystem::current_path() / "../ItemsXML/")) {
            string path = dirEntry.path();
            string base_filename = path.substr(path.find_last_of("/\\") + 1);
            string::size_type const p(base_filename.find_last_of('.'));
            string file_without_extension = base_filename.substr(0, p);
            if (!file_without_extension.empty()) {
                storedItemNames.push_back(file_without_extension);
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    }
}

bool ItemEditorController::isValidItemName(const string &itemName) {
    for (const auto &item : storedItemNames) {
        if (item == itemName) {
            return true;
        }
    }
    return false;
}

void ItemEditorController::saveItem(Item& itemToSave, const string &itemName) {
    try {
        const std::string completeFileName = itemName + ".xml";
        std::filesystem::create_directory("../ItemsXML");
        std::ofstream os(std::filesystem::current_path() / "../ItemsXML/" / completeFileName);
        cereal::XMLOutputArchive archive(os);
//        archive(itemToSave);
        archive(cereal::make_nvp("itemType", itemToSave.getType()));
        archive(cereal::make_nvp("value0", itemToSave));
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    }
}

void ItemEditorController::createItem() {
    int itemType;
    string itemName;
    Item* tempItem;
    string enchantmentType;
    int enchantType;

    std::cout << "Select a type for your new item:\n1. Armor\n2. Belt\n3. Shield\n4. Weapon\n5. Ring\n6. Boots\n7. Helmet\n8. Boots\n9. Ring\n10. Shield\n11. Weapon\n";
    std::cin >> itemType;

    while (itemType < 1 || itemType > 11) {
        std::cout << "Invalid input, please enter a number between 1 and 11" << std::endl;
        std::cin >> itemType;
    }

    switch (itemType) {
        case 1:
            cout << "Select an enchantment type for the armor:" << endl;
            cout << "1. ArmorClass\n";
            cin >> enchantType;
            while (enchantType < 1 || enchantType > 1) {
                std::cerr << "Invalid input, please enter a number between 1 and 1" << std::endl;
                cin >> enchantType;
            }
            enchantmentType = "ArmorClass";
            tempItem = Armor::createArmor(enchantmentType);
            cout << "Enter the name for this new item: ";
            cin >> itemName;
            while (isValidItemName(itemName)) {
                std::cerr << "An item with this name already exists, choose another one:" << std::endl;
                cin >> itemName;
            }
            tempItem->setItemName(itemName);
            cout << "Saving the item...";
            saveItem(*tempItem, itemName);
            storedItemNames.push_back(itemName);
            delete tempItem;
            break;
        case 2:
            cout << "Select an enchantment type for the belt:" << endl;
            cout << "1. Strength\n2. Constitution\n";
            cin >> enchantType;
            while (enchantType < 1 || enchantType > 2) {
                std::cerr << "Invalid input, please enter a number between 1 and 2" << std::endl;
                cin >> enchantType;
            }
            if (enchantType == 1) {
                enchantmentType = "Strength";
            } else {
                enchantmentType = "Constitution";
            }
            tempItem = Belt::createBelt(enchantmentType);
            cout << "Enter the name for this new item: ";
            cin >> itemName;
            while (isValidItemName(itemName)) {
                std::cerr << "An item with this name already exists, choose another one:" << std::endl;
                cin >> itemName;
            }
            tempItem->setItemName(itemName);
            cout << "Saving the item...";
            saveItem(*tempItem, itemName);
            storedItemNames.push_back(itemName);
            delete tempItem;
            tempItem = nullptr;
            break;
        case 3:
            cout << "Select an enchantment type for the shield:" << endl;
            cout << "1. ArmorClass\n";
            cin >> enchantType;
            while (enchantType < 1 || enchantType > 1) {
                std::cerr << "Invalid input, please enter a number between 1 and 1" << std::endl;
                cin >> enchantType;
            }
            enchantmentType = "ArmorClass";
            tempItem = Shield::createShield(enchantmentType);
            cout << "Enter the name for this new item: ";
            cin >> itemName;
            while (isValidItemName(itemName)) {
                std::cerr << "An item with this name already exists, choose another one:" << std::endl;
                cin >> itemName;
            }
            tempItem->setItemName(itemName);
            cout << "Saving the item...";
            saveItem(*tempItem, itemName);
            storedItemNames.push_back(itemName);
            delete tempItem;
            tempItem = nullptr;
            break;
        case 4:
            cout << "Select an enchantment type for the weapon:" << endl;
            cout << "1. DamageBonus\n2. AttackBonus\n";
            cin >> enchantType;
            while (enchantType < 1 || enchantType > 2) {
                std::cerr << "Invalid input, please enter a number between 1 and 2" << std::endl;
                cin >> enchantType;
            }
            if (enchantType == 1) {
                enchantmentType = "DamageBonus";
            } else {
                enchantmentType = "AttackBonus";
            }
            tempItem = Weapon::createWeapon(enchantmentType);
            cout << "Enter the name for this new item: ";
            cin >> itemName;
            while (isValidItemName(itemName)) {
                std::cerr << "An item with this name already exists, choose another one:" << std::endl;
                cin >> itemName;
            }
            tempItem->setItemName(itemName);
            cout << "Saving the item...";
            saveItem(*tempItem, itemName);
            storedItemNames.push_back(itemName);
            delete tempItem;
            tempItem = nullptr;
            break;
        case 5:
            cout << "Select an enchantment type for the ring:" << endl;
            cout << "1. Strength\n2. Constitution\n3. Wisdom\n4. Charisma\n 5. ArmorClass\n";
            cin >> enchantType;
            while (enchantType < 1 || enchantType > 5) {
                std::cerr << "Invalid input, please enter a number between 1 and 5" << std::endl;
                cin >> enchantType;
            }
            switch (enchantType) {
                case 1:
                    enchantmentType = "Strength";
                    break;
                case 2:
                    enchantmentType = "Constitution";
                    break;
                case 3:
                    enchantmentType = "Wisdom";
                    break;
                case 4:
                    enchantmentType = "Charisma";
                    break;
                case 5:
                    enchantmentType = "ArmorClass";
                    break;
                default:
                    break;
            }
            tempItem = Ring::createRing(enchantmentType);
            cout << "Enter the name for this new item: ";
            cin >> itemName;
            while (isValidItemName(itemName)) {
                std::cerr << "An item with this name already exists, choose another one:" << std::endl;
                cin >> itemName;
            }
            tempItem->setItemName(itemName);
            cout << "Saving the item...";
            saveItem(*tempItem, itemName);
            storedItemNames.push_back(itemName);
            delete tempItem;
            tempItem = nullptr;
            break;
        case 6:
            cout << "Select an enchantment type for the boots:" << endl;
            cout << "1. Dexterity\n 2. ArmorClass\n";
            cin >> enchantType;
            while (enchantType < 1 || enchantType > 2) {
                std::cerr << "Invalid input, please enter a number between 1 and 2" << std::endl;
                cin >> enchantType;
            }
            if (enchantType == 1) {
                enchantmentType = "Dexterity";
            } else {
                enchantmentType = "ArmorClass";
            }
            tempItem = Boots::createBoots(enchantmentType);
            cout << "Enter the name for this new item: ";
            cin >> itemName;
            while (isValidItemName(itemName)) {
                std::cerr << "An item with this name already exists, choose another one:" << std::endl;
                cin >> itemName;
            }
            tempItem->setItemName(itemName);
            cout << "Saving the item...";
            saveItem(*tempItem, itemName);
            storedItemNames.push_back(itemName);
            delete tempItem;
            tempItem = nullptr;
            break;
            break;
        case 7:
            cout << "Select an enchantment type for the helmet:" << endl;
            cout << "1. ArmorClass\n 2. Wisdom\n 3. Intelligence\n";
            cin >> enchantType;
            while (enchantType < 1 || enchantType > 3) {
                std::cerr << "Invalid input, please enter a number between 1 and 3" << std::endl;
                cin >> enchantType;
            }
            if (enchantType == 1) {
                enchantmentType = "ArmorClass";
            } else if (enchantType == 2) {
                enchantmentType = "Wisdom";
            } else {
                enchantmentType = "Intelligence";
            }
            tempItem = Helmet::createHelmet(enchantmentType);
            cout << "Enter the name for this new item: ";
            cin >> itemName;
            while (isValidItemName(itemName)) {
                std::cerr << "An item with this name already exists, choose another one:" << std::endl;
                cin >> itemName;
            }
            tempItem->setItemName(itemName);
            cout << "Saving the item...";
            saveItem(*tempItem, itemName);
            storedItemNames.push_back(itemName);
            delete tempItem;
            tempItem = nullptr;
            itemName = "Helmet";
            break;
        default:
            std::cerr << "Invalid input, please enter a number between 1 and 11" << std::endl;
            break;
    }
}

void ItemEditorController::loadItem(Item& itemToFill, const string &itemName) {
    try {
        if (!isValidItemName(itemName)) {
            throw std::runtime_error("The provided item name does not exist.");
        }
        const std::string completeFileName = itemName + ".xml";
        std::ifstream is(std::filesystem::current_path() / "../ItemsXML/" / completeFileName);
        cereal::XMLInputArchive archive(is);
        std::string itemType;
        archive(cereal::make_nvp("itemType", itemType));
        if (itemType == "Belt"){
            is.clear(); // Clear any flags
            is.seekg(0, std::ios::beg);
            itemToFill.setType(itemType);
            archive(itemToFill);
            itemToFill.setType(itemType);
            cout << itemToFill.getType();
        }
//        is.clear(); // Clear any flags
//        is.seekg(0, std::ios::beg);
//        archive(itemToFill);
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
}

Item *ItemEditorController::createCorrectType(const std::string &itemName) {
    try {
        if (!isValidItemName(itemName)) {
            throw std::runtime_error("The provided item name does not exist.");
        }
        const std::string completeFileName = itemName + ".xml";
        std::ifstream is(std::filesystem::current_path() / "../ItemsXML/" / completeFileName);
        cereal::XMLInputArchive archive(is);
        std::string itemType;
        archive(cereal::make_nvp("itemType", itemType));
        if (itemType == "Belt"){
            return new Belt();
        }
        if (itemType == "Armor"){
            return new Armor();
        }
        if (itemType == "Boots"){
            return new Boots();
        }
        if (itemType == "Helmet"){
            return new Helmet();
        }
        if (itemType == "Ring"){
            return new Ring();
        }
        if (itemType == "Shield"){
            return new Shield();
        }
        if (itemType == "Weapon"){
            return new Weapon();
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    return nullptr;
}

void ItemEditorController::loadItemType(std::string &itemType, const std::string &itemName) {
        try {
        const std::string completeFileName = itemName + ".xml";
        std::ifstream is(std::filesystem::current_path() / "../ItemsXML/" / completeFileName);
        cereal::XMLInputArchive archive(is);
        archive(cereal::make_nvp("itemType", itemType));
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
}

void ItemEditorController::updateItem() {
    string itemName;
    int updateChoice;
    Item * itemToFill;

    cout << "Here are all your stored items" << endl;
    displayStoredItems();
    cout << "Enter the name of the item you want to update: ";
    cin >> itemName;
    while (!isValidItemName(itemName)) {
        std::cerr << "The item name you entered does not exist, please enter a valid one:" << std::endl;
        cin >> itemName;
    }

    itemToFill = createCorrectType(itemName);
    loadItem(*itemToFill, itemName);
    cout << "Here are the characteristics for your item:" << endl;
    itemToFill->displayEnchantmentInfo();
    cout << "Type of item: " << itemToFill->getType() << endl;
    cout << "What do you want to update?" << endl;
    cout << "1. Enchantment bonus\n";
    cin >> updateChoice;
    while (updateChoice < 1 || updateChoice > 1) {
        std::cerr << "Invalid input, please enter a number between 1 and 1" << std::endl;
        cin >> updateChoice;
    }
    int newBonus;
    cout << "Enter the new bonus for the enchantment: ";
    cin >> newBonus;
    itemToFill->enchantmentDetails.enchantmentBonus = newBonus;
    cout << "Updating the item...";
    saveItem(*itemToFill, itemName);
    delete itemToFill;
    cout << "Item updated successfully!" << endl;
}

void ItemEditorController::displayStoredItems() {
    for (const auto &item : storedItemNames) {
        std::cout << item << std::endl;
    }
}

void ItemEditorController::displayMenu() {
    int userChoice;
    std::cout << "Welcome to the Item Editor Controller!\n" << std::endl;
    std::cout << "Please select something:\n1: Create a new item\n2: Update an existing item\n3: Display all stored items\n4: Create a chest\n5: Quit" << std::endl;
    std::cin >> userChoice;

    while (userChoice != 5) {
        switch (userChoice) {
            case 1:
                createItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                displayStoredItems();
                break;
            case 4:
                createChest();
                break;
            default:
                std::cerr << "Invalid input, please enter a number between 1 and 4" << std::endl;
                break;
        }
        std::cout << "Please select something:\n1: Create a new item\n2: Update an existing item\n3: Display all stored items\n4: Create a chest\n5: Quit" << std::endl;
        std::cin >> userChoice;
    }
    std::cout << "Exiting the Item Editor Controller..." << std::endl;
}

Item *ItemEditorController::determineItemType() {
    string itemType;
    cout << "Enter the type of the item you want to update: ";
    cin >> itemType;
    while (itemType != "Armor" && itemType != "Belt" && itemType != "Shield" && itemType != "Weapon" && itemType != "Ring" && itemType != "Boots" && itemType != "Helmet") {
        std::cerr << "Invalid input, please enter a valid item type (Armor, Belt, Shield, Weapon, Ring, Boots, Helmet)" << std::endl;
        cin >> itemType;
    }
    if (itemType == "Armor") {
        return new Armor();
    } else if (itemType == "Belt") {
        return new Belt();
    } else if (itemType == "Shield") {
        return new Shield();
    } else if (itemType == "Weapon") {
        return new Weapon();
    } else if (itemType == "Ring") {
        return new Ring();
    } else if (itemType == "Boots") {
        return new Boots();
    } else if (itemType == "Helmet") {
        return new Helmet();
    }
    return nullptr;
}

void ItemEditorController::createChest() {
    string chestName;
    cout << "Select a name for your chest: " << endl;
    cin >> chestName;
    cout << "Which items do you want to put in the chest? press x when you want to stop inserting items" << endl;
    displayStoredItems();
    string itemName;
    cin >> itemName;
    Chest ch = Chest();
    ch.chestName = chestName;
    while (itemName != "x") {
        while (!isValidItemName(itemName)) {
            std::cerr << "The item name you entered does not exist, please enter a valid one:" << std::endl;
            cin >> itemName;
        }
        ch.itemsNames.push_back(itemName);
        cin >> itemName;
    }
    cout << "Saving the chest...";
    saveChestToFile(ch, chestName);
    cout << "Chest saved successfully!" << endl;
}

void ItemEditorController::saveChestToFile(Chest &chestToSave, const std::string &fileName) {
    const std::string completeFileName = fileName + ".xml";
    std::ofstream os(std::filesystem::current_path() / "../ChestsXML/" / completeFileName);
    cereal::XMLOutputArchive archive(os);
    archive(chestToSave);
}