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

using std::cout;
using std::cin;
using std::endl;

inline void displayGameMenu() {
    MapEditorController mapEditorController = MapEditorController();
    CampaignEditorController campaignEditorController = CampaignEditorController();
    gameController gameControllerHere = gameController();

    mapEditorController.registerCampaignEditor(&campaignEditorController);
    // campaignEditorController.registerMapEditor(&mapEditorController);

    int userChoice;
    cout << "Welcome to the JUICE Game!\n" << endl;
    cout << "Please select something:\n1: New game\n2: Resume [NOT IMPLEMENTED]\n3: Open map editor\n4: Open campaign editor\n5: Quit" << endl;
    cin >> userChoice;

    while (userChoice != 5) {
        switch (userChoice) {
            case 1: {
                gameControllerHere.displayMenu();
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
            default: {
                throw std::runtime_error("flemme de handle ce case ecris entre 1 et 5 please");
            }
        }
        Clear();
        cout << "Please select something:\n1: New game[NOT IMPLEMENTED]\n2: Resume\n3: Open map editor\n4: Open campaign editor\n5: Quit" << endl;
        cin >> userChoice;
    }
}

#endif //DRIVER_H
