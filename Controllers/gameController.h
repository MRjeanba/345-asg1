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
    // reference to a player or embedded player character??
    void displayWelcomeMessage();
    void displayMaps();
    int selectMap();
    void displaySelectedMap(Map& selectedMap);

public:
    gameController();
    void displayMenu();
    void keepGoingGame();

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

    MapEditorController mapEditorController;
    CampaignEditorController campaignEditorController;
};

#endif // GAMECONTROLLER_H


