//
// Created by Jean-Baptiste Garibo on 2024-03-12.
//

#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>

#include "Utilities.h"
#include "Controllers/CampaignEditorController.h"
#include "Controllers/MapEditorController.h"
#include "Controllers/gameController.h"
#include "Controllers/CharacterEditorController.h"
#include "Controllers/ItemEditorController.h"
#include "Models/Belt.h"
#include "Models/Helmet.h"
#include "Models/Ring.h"
#include "Models/Boots.h"
#include "Models/Armor.h"
#include "Models/Shield.h"
#include "Models/Weapon.h"
#include "Models/WornItemsDecorator.h"
#include "Models/CharacterWornItems.h"
using std::cin;
using std::cout;
using std::endl;

inline void displayGameMenu() {
    CharacterEditorController characterEditorController = CharacterEditorController();
    gameController gameControllerHere = gameController();
    ItemEditorController itemEditorController = ItemEditorController();
    int userChoice;
    cout << "Welcome to the JUICE Game!\n" << endl;
    cout << "Please select something:\n1: New game\n2: Resume [NOT IMPLEMENTED]\n3: Open map editor\n4: Open campaign editor\n5: Test the CharacterWornItems as Decorators\n6: Open the ItemEditorController \n7: Quit" << endl;
    cin >> userChoice;
    fighter *UserCharacter;

    while (userChoice != 7) {
        switch (userChoice) {
            case 1: {
                cout << "\nCreate a your character please" << endl;
                string name;
                cout << "Enter a name for your character: \n" << endl;
                cin >> name;
                UserCharacter = characterEditorController.createCharacter(name);
                gameControllerHere.startGame();
                break;
            }
            case 2: {
                throw std::runtime_error("NOT IMPLEMENTED YET.");
                break;
            }
            case 3: {
                gameControllerHere.mapEditorController.displayMenu();
                break;
            }
            case 4: {
                Clear();
                gameControllerHere.campaignEditorController.displayMenu();
                break;
            }
            case 5: {
                Clear();
                string name;
                cout << "Enter a name for your character: \n" << endl;
                cin >> name;
                UserCharacter = characterEditorController.createCharacter(name);
                CharacterWornItems w = CharacterWornItems();
                w.attachFighter(UserCharacter);
                UserCharacter->setWornItemsPtr(&w);

                cout << "items currently worn by the character:" << endl;
                UserCharacter->getWornItems();

                Helmet * h = Helmet::createHelmet("Wisdom");
                Weapon * w1 = Weapon::createWeapon("DamageBonus");

                cout << "Wisdom before wearing the item:" << endl;
                cout << UserCharacter->getWisdom() << endl;
                cout << "Strength before wearing the item:" << endl;
                cout << UserCharacter->getDamageBonus() << endl;
                UserCharacter->wearItem(w1);
                cout << UserCharacter->getDamageBonus() << endl;
                UserCharacter->removeItem();
                cout << UserCharacter->getDamageBonus() << endl;
                delete h;
                delete w1;
                delete UserCharacter;
                h = nullptr;
                w1 = nullptr;
                UserCharacter = nullptr;
                break;
            }
            case 6: {
                Clear();
                itemEditorController.displayMenu();
                break;
            }
            default: {
                throw std::runtime_error("flemme de handle ce case ecris entre 1 et 5 please");
            }
        }
        cout << "Please select something else to do:\n1: New game\n2: Resume [NOT IMPLEMENTED]\n3: Open map editor\n4: Open campaign editor\n5: Test the CharacterWornItems as Decorators\n6: Open the ItemEditorController \n7: Quit" << endl;
        cin >> userChoice;
    }
}

#endif //DRIVER_H
