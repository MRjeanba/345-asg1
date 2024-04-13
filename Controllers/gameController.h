#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <iostream>
#include <vector>
#include "../Models/Map.h"
#include "MapEditorController.h"
class gameController {
private:
    std::vector<std::string> storedMaps;
    Campaign campaign;
    Map currMap;
    fighter * player;

public:
    /**
     * Default constructor, instantiate the gameController and the campaignEditor and mapEditor aswell
     */
    gameController();

    void attachPlayer(fighter * pFighter);

    /**
     * Set the exit of the currMap on the center of the map, set the character location on the first cell aswell
     */
    void setMapToDefault();

    /**
     * Start the game by first asking to the user which campaign he wants to play
     */
    void startGame();

    /**
     * Display all the campaigns to the user and make him choose a valid one
     * @return the name of the campaign chosen
     */
    string selectCampaignName();

    /**
     * initialize the campaign stored within the gameController, to do so, it uses the campaignEditorController
     * load method.
     * @param campaignName the name of the campaign that we want to load
     */
    void loadCampaign(string& campaignName);

    // made public to access them in the driver.h file, but we may later move the driver.h logic within this class
    MapEditorController mapEditorController;
    CampaignEditorController campaignEditorController;
    ItemEditorController itemEditorController;
};

#endif // GAMECONTROLLER_H


