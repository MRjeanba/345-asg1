//
// Created by Jean-Baptiste Garibo on 2024-03-09.
//

#ifndef MAPEDITORCONTROLLER_H
#define MAPEDITORCONTROLLER_H
#include <vector>

#include "CampaignEditorController.h"
#include "../Models/Map.h"
using std::vector;
using std::string;

class CampaignEditorController;
/**
 * @brief Class responsible to create new maps or edit existing maps.
 */
class MapEditorController {

private:
 vector<string> storedMaps;
 // MapBuilder mapBuilder
 inline static int numberOfInstances = 0;
 CampaignEditorController* campaignEditorControllerPtr;

public:
 /**
  * Create an instance of MapEditorController, cannot create an instance if we already have one (Singleton class)
  * the storedMap field is initialized by looping through the MapsXML folder and adding each file found to the vector of the class
  */
 MapEditorController();

 /**
 * Create an instance of a map class, and use the saveMapToFile method to save the newly created map.Also use the notifyCampaignEditor to notify the campaign editor
 * about the creation of this new map
 */
 void createMap();

 /**
  * Add the newly created map to the existingMaps vector contained within the CampaignEditorController class
  * @param newMapAdded the name of the map to add to the campaignEditorController
  */
 void notifyCampaignEditor(const string& newMapAdded) const;

  /**
   *
   * @param mapName the name of the map to load from txt files.
   * @return the instance of the map stored in the txt file.
   */
  void loadMap(Map &mapToFill, const std::string &filename);

 /**
  * Save the creared map inside the MapsXML folder into its own file, the name of the file is the name of the map
  * @param mapToSave The instance of the map to save.
  * @param fileName The name of the file in which we want to save the given mapToSave
  */
 void saveMapToFile(Map& mapToSave,const std::string& fileName);

 /**
  * Ask the user to perform operation on the map, after the execution of the operation, the updated map is saved
  * @param mapToUpdate the instance of the Map that we want to update
  * @param mapName the name of the map so that we can retrieve its file
  */
 void updateMap(Map& mapToUpdate, const string& mapName);

 /**
  * Propose to the user the option that he has, either create a map, edit a map or exit the MapEditor
  */
 void displayMenu();

 /**
  * Display to the user all the map located under MapsXML/
  */
 void displayMaps();

 /**
  * During instantiation of the object, read all the maps from MapsXML and add them one by one to the storedMaps vector
  */
 void initStoredMaps();

 /**
  * Verify that the map name provided by the user exists by checking into the storedMaps vector if we find the provided map name given by the user
  * @param mapNameToVerify The name provided by the user
  * @return true if mapNameToVerify is in the stored maps
  */
 bool isValidMapName(const string& mapNameToVerify);

 /**
  * Register the campaign editor to the MapEditorController class, that way, whenerver we add a map, we can update the campaignEditor maps too
  * @param campaignEditorPtr the address of the campaign editor instance
  */
 void registerCampaignEditor(CampaignEditorController* campaignEditorPtr);
};



#endif //MAPEDITORCONTROLLER_H
