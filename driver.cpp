// MAIN DRIVER
#include "driver.h"

#include <iostream>

#include "Controllers/CampaignEditorController.h"
#include "Models/Dice.cpp"
#include "Models/Armor.h"
#include "Controllers/MapEditorController.h"
#include "Models/Belt.h"
#include "Models/Helmet.h"
#include "Models/Ring.h"

int main()
{
    // Run the game menu
     displayGameMenu();
    // auto * testPtr = new Helmet("Wisdom", new Belt("Strength", new Ring("Wisdom", new fighter())));
    // //testPtr->isItemTypeWorn.at(testPtr->getType()) = true;
    // cout << "items currently worn" << endl;
    // cout << testPtr->getTypes();
    // testPtr->remove(testPtr);
    // cout << testPtr->getTypes();

    return 0;
}
