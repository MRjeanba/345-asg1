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
    srand((unsigned int)time(NULL));
    // Run the game menu
     displayGameMenu();

    return 0;
}
