//
// Created by Jean-Baptiste Garibo on 2024-03-12.
//

#ifndef CAMPAIGNEDITORCONTROLLER_H
#define CAMPAIGNEDITORCONTROLLER_H
#include <iostream>
#include <string>

#include "MapEditorController.h"
#include "../Models/Campaign.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
class MapEditorController;

class CampaignEditorController {

private:
    inline static int numberOfInstances;
    vector<string> storedCampaigns;
    vector<string> existingMaps;
public:

    /**
     * Basic constructor for the class, cannot instantiate more than one instance (Singleton). Also initialize storedCampaigns and existingMaps by calling their respective init methods
     */
    CampaignEditorController();

    /**
     * Ask to the user some information to create a campaign, once created, store it inside of a file
     */
    void createCampaign();

    /**
     * Ask to the user what does he want to update on the given map, then perform the updates and finally store the updated campaign to a file
     * @param campaignToUpdate the campaign we want to update
     */
    void updateCampaign(Campaign& campaignToUpdate);

    /**
     * Search through the storedCampaign vector to verify if the campaignName given by the user exists
     * @param campaignName The name of the campaign, entered by the user
     * @return true if we found the campaign, false otherwise
     */
    bool isValidCampaignName(const string& campaignName);

    /**
     * load a campaign from an xml file and store it inside of the campaignToFill parameter
     * @param campaignToFill the campaign that we want to fill with the stored one
     * @param campaignName the name of the campaign that we want to load
     */
    void loadCampaign(Campaign& campaignToFill, const string& campaignName);

    /**
     * Save the campaign given as parameter to a xml file with the same name as the campaign
     * @param campaignToSave the instance of the campaign we want to save
     * @param fileName the name of the file in which we will save the instance
     */
    void saveCampaignToFile(Campaign& campaignToSave, const string& fileName);

    /**
     * Let the user choose some operations to do on campaings like:
     * 1: create a campaign
     * 2: edit a campaign
     * 3: Quit the campaign editor
     */
    void displayMenu();

    /**
     * Display all the existing campaign by looping through the CampaignsXML folder and outputting all the files
     */
    void displayCampaigns();

    /**
     * Display all the maps by looping through the MapsXML folder and outputting the files
     */
    void displayMaps();

    /**
     * search throuhgh existingMaps to verify if the map name given as paramater exists
     * @param mapName the name of the map given by the user
     * @return true if the map exists, false otherwise
     */
    bool isExistingMap(const string& mapName);

    /**
     * Add the map name given as parameter to the existingMaps vector withtin the instance
     * @param mapName the name of the new map to add to existingMaps
     */
    void addMapToExistingMaps(const string& mapName);

    /**
     * Initialize existingMaps by looping through the MapsXML folder and storing the files name
     */
    void initializeExistingMaps();

    /**
     * Initialize storedCampaigns by looping through the CampaignsXML folder and storing the files name
     */
    void initializeStoredCampaign();
};



#endif //CAMPAIGNEDITORCONTROLLER_H
