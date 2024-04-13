//
// Created by Jean-Baptiste Garibo on 2024-04-12.
//

#ifndef INC_345_ASG1_ITEMEDITORCONTROLLER_H
#define INC_345_ASG1_ITEMEDITORCONTROLLER_H


#include <string>
#include "../Models/Item.h"

using std::vector;
using std::string;

class ItemEditorController {
private:
    inline static int numberOfInstances;
    vector<string> storedItemNames;

public:
    /**
     * Basic constructor for the class, cannot instantiate more than one instance (Singleton). Also initialize storedItems by calling their respective init methods
     */
    ItemEditorController();

    /**
     * Ask to the user some information to create an item, once created, stores it inside of a file
     */
    void createItem();

    /**
     * Ask to the user what does he want to update on the given item, then perform the updates and finally store the updated item to a file
     * @param itemToUpdate the item we want to update
     */
    void updateItem();

    /**
     * Search through the storedItems vector to verify if the itemName given by the user exists
     * @param itemName The name of the item, entered by the user
     * @return true if we found the item, false otherwise
     */
    bool isValidItemName(const string& itemName);

    /**
     * load an item from an xml file and store it inside of the itemToFill parameter
     * @param itemToFill the item that we want to fill with the stored one
     * @param itemName the name of the item that we want to load
     */
    void loadItem(Item& itemToFill, const string& itemName);

    Item * determineItemType();

    /**
     * Load the item type from the xml file
     * @param itemType the string that will hold the item type
     * @param itemName the name of the file in which we will find the item type
     */
    void loadItemType(string& itemType, const string& itemName);
    /**
     * Save the item given as parameter to a xml file with the same name as the item
     * @param itemToSave the instance of the item we want to save
     * @param itemName the name of the file in which we will save the instance
     */
    void saveItem(Item& itemToSave, const string& itemName);

    /**
     * Initialize the storedItems vector by reading the item files names
     */
    void initializeStoredItems();

    /**
     * Display the stored items to the user
     */
    void displayStoredItems();

    /**
     * Display the menu to the user
     */
    void displayMenu();
};


#endif //INC_345_ASG1_ITEMEDITORCONTROLLER_H
