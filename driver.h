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
#include "Models/Belt.h"
#include "Models/Helmet.h"
#include "Models/Ring.h"
#include "Models/WornItemsDecorator.h"
using std::cin;
using std::cout;
using std::endl;

inline void displayGameMenu() {
    MapEditorController mapEditorController = MapEditorController();
    CampaignEditorController campaignEditorController = CampaignEditorController();
    CharacterEditorController characterEditorController = CharacterEditorController();
    gameController gameControllerHere = gameController();
    mapEditorController.registerCampaignEditor(&campaignEditorController);

    int userChoice;
    cout << "Welcome to the JUICE Game!\n" << endl;
    cout << "Please select something:\n1: New game\n2: Resume [NOT IMPLEMENTED]\n3: Open map editor\n4: Open campaign editor\n5 Test the CharacterWornItems as Decorators\n6: Quit" << endl;
    cin >> userChoice;
    fighter *UserCharacter;

    while (userChoice != 6) {
        switch (userChoice) {
            case 1: {
                cout << "\nCreate a your character please" << endl;
                string name;
                cout << "Enter a name for your character: \n" << endl;
                cin >> name;
                UserCharacter = characterEditorController.createCharacter(name);
                // throw std::runtime_error("NOT IMPLEMENTED YET.");
//                gameControllerHere.displayMenu();
                gameControllerHere.startGame();
                break;
            }
            case 2: {
                throw std::runtime_error("NOT IMPLEMENTED YET.");
                break;
            }
            case 3: {
                mapEditorController.displayMenu();
                break;
            }
            case 4: {
                Clear();
                campaignEditorController.displayMenu();
                break;
            }
            case 5: {
                Clear();
                int uChoice;
                WornItemsDecorator * testPtr = new Helmet("Wisdom", new Belt("Strength", new Ring("Wisdom", new fighter())));
                cout << "items currently worn by the character:" << endl;
                cout << testPtr->getTypes();
                cout << "Do you want to remove an item (1) or see the augmented characteristics? (2):" << endl;
                cin >> uChoice;
                if (uChoice == 1) {
                    testPtr = testPtr->remove(testPtr);
                    cout << "Items after remove operation:" << endl;
                    cout << testPtr->getTypes();
                } else {
                    Clear();
                    auto m = testPtr->getEnchantmentsCharacteristics();
                    for (const auto & [key, value] : m)
                        std::cout << key << ":" << value << std::endl;
                }
                break;
            }
            default: {
                throw std::runtime_error("flemme de handle ce case ecris entre 1 et 5 please");
            }
        }
        cout << "Please select something else to do:\n1: New game\n2: Resume [NOT IMPLEMENTED]\n3: Open map editor\n4: Open campaign editor\n5 Test the CharacterWornItems as Decorators\n6: Quit" << endl;
        cin >> userChoice;
    }
}

#endif //DRIVER_H
