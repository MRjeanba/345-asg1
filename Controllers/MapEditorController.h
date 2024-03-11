//
// Created by Jean-Baptiste Garibo on 2024-03-09.
//

#ifndef MAPEDITORCONTROLLER_H
#define MAPEDITORCONTROLLER_H
#include <vector>
#include "../Models/Map.h"
using std::vector;
using std::string;


/**
 * @brief Class responsible to create new maps or edit existing maps.
 */
class MapEditorController {

private:
 vector<Map> storedMaps;
 // MapBuilder mapBuilder
 inline static int numberOfInstances = 0;

public:
 /**
  * Create an instance of MapEditorController, cannot create an instance if we already have one (Singleton class)
  */
 MapEditorController();

 /**
 * Create an instance of a map class, and use the saveMapToFile method to save the newly created map.
 * @return a boolean indicating if the map has been saved correctly.
 */
 bool createMap();

 /**
  *
  * @param mapName the name of the map to load from txt files.
  * @return the instance of the map stored in the txt file.
  */
 Map loadMap(string& mapName);

 /**
  * 
  * @param mapToSave The instance of the map to save.
  * @return a boolean value indicating if the save operation executed successfully or not.
  */
 bool saveMapToFile(Map& mapToSave);

 /**
  * 
  * @param mapToUpdate the instance of the Map that we want to update
  */
 void updateMap(Map& mapToUpdate);

 /**
  * propose to the user two option, create or update a map
  */
 void displayMenu();
};



#endif //MAPEDITORCONTROLLER_H
