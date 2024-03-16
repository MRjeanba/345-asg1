//
// Created by Jean-Baptiste Garibo on 2024-03-12.
//

#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>

#include "Utilities.h"
#include "Controllers/CampaignEditorController.h"
#include "Controllers/MapEditorController.h"
#include "Controllers/CharacterEditorController.h"

using std::cin;
using std::cout;
using std::endl;

inline void displayGameMenu()
{
    MapEditorController mapEditorController = MapEditorController();
    CampaignEditorController campaignEditorController = CampaignEditorController();
    CharacterEditorController characterEditorController = CharacterEditorController();

    mapEditorController.registerCampaignEditor(&campaignEditorController);

    int userChoice;
    cout << "Welcome to the [INSERT NAME] Game!\n"
         << endl;
    cout << "Please select something:\n1: New game [NOT FULLY IMPLEMENTED]\n2: Resume [NOT IMPLEMENTED]\n3: Open map editor\n4: Open campaign editor\n5: Quit" << endl;
    cin >> userChoice;

    fighter *UserCharacter;
    while (userChoice != 5)
    {
        switch (userChoice)
        {
        case 1:
        {
            cout << "Welcome!\nCreate a your character please" << endl;
            string name;
            cout << "Enter a name for your character: \n" << endl;
            cin >> name;
            UserCharacter = characterEditorController.createCharacter(name);
            // throw std::runtime_error("NOT IMPLEMENTED YET.");
            break;
        }
        case 2:
        {
            throw std::runtime_error("NOT IMPLEMENTED YET.");
            break;
        }
        case 3:
        {
            mapEditorController.displayMenu();
            break;
        }
        case 4:
        {
            Clear();
            campaignEditorController.displayMenu();
            break;
        }
        default:
        {
            throw std::runtime_error("flemme de handle ce case ecris entre 1 et 5 please");
        }
        }
        cout << "\n\nPlease select something:\n1: New game [NOT IMPLEMENTED]\n2: Resume [NOT IMPLEMENTED]\n3: Open map editor\n4: Open campaign editor\n5: Quit" << endl;
        cin >> userChoice;
    }
}

#endif // DRIVER_H
