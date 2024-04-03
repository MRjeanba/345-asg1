//
// Created by Jean-Baptiste Garibo on 2024-03-09.
//

#include "MapEditorController.h"
#include "../Utilities.h"

void MapEditorController::loadMap(Map &mapToFill, const std::string &filename) {
    const std::string completeFileName = filename + ".xml";
    std::ifstream is(std::filesystem::current_path() / "../MapsXML/" / completeFileName);
    cereal::XMLInputArchive archive(is);
    archive(mapToFill);
}

MapEditorController::MapEditorController() {

    //TODO: should also create a MabBuilder
    if (numberOfInstances < 1) {
        numberOfInstances++;
        initStoredMaps();
        return;
    }
    std::cout << "There already exist an instance of the map editor controller, use the existing instance";
    throw std::runtime_error("can't create a second instance of the map editor class");
}

void MapEditorController::createMap() {
    int height, width;

    std::cout << "To create a map, please provide a height for it:" << std::endl;
    std::cin >> height;
    std::cout << "Now, please provide a width for the map!!" << std::endl;
    std::cin >> width;
    Map createdMap = Map(height,width);

    Clear();

    std::string mapName;
    // now save map on file!
    std::cout << "Now, let's save this map, which name do you want for this map?:" << std::endl;
    std::cin >> mapName;
    Clear();
    updateMap(createdMap, mapName);

    std::cout << "Creating and saving the map..." << std::endl;
    saveMapToFile(createdMap,mapName);
    storedMaps.push_back(mapName);
    notifyCampaignEditor(mapName);
    std::cout << "Map created successfully!" << std::endl;
}

void MapEditorController::notifyCampaignEditor(const string& newMapAdded) const {
    campaignEditorControllerPtr->addMapToExistingMaps(newMapAdded);
}

// Map MapEditorController::loadMap(string& NameOfMap) {
//     //TODO: TO IMPLEMENT
//     return Map();
// }

void MapEditorController::saveMapToFile(Map &mapToSave, const std::string& fileName) {
    const std::string completeFileName = fileName + ".xml";
    std::ofstream os(std::filesystem::current_path() / "../MapsXML/" / completeFileName);
    cereal::XMLOutputArchive archive(os);
    archive( mapToSave ); // serialize and store the current instance to the file
}

void MapEditorController::displayMenu() {
    int userChoice = 0;
    std::cout << "Welcome to the Map editor!\nWhat do you want to do?\n1: Create a map\n2: Update an existing map\n3: Nothing" << std::endl;
    std::cin >> userChoice;

    while (userChoice != 3) {
        switch (userChoice) {
            case 1: {
                Clear();
                createMap();
                break;
            }
            case 2: {
                Clear();
                std::string nameOfMapToUpdate;

                std::cout << "Please enter the name of the map you want to update" << std::endl;
                std::cout << "To help you here is the list of map that you currently have in the system" << std::endl;
                displayMaps();
                std::cout << "Enter the name of the map you want to update:" << std::endl;
                std::cin >> nameOfMapToUpdate;

                if (!isValidMapName(nameOfMapToUpdate)) {
                    std::cout << "The provided mapName does not exist! Aborting" << std::endl;
                }

                Map mapToUpdate = Map();
                loadMap(mapToUpdate, nameOfMapToUpdate);
                updateMap(mapToUpdate, nameOfMapToUpdate);
                break;
            }
            default: {
                break;
            }
        }
        std::cout << " What do you want to do now?\n1: Create a map\n2: Update an existing map\n3: Nothing" << std::endl;
        std::cin >> userChoice;
    }
    Clear();
    std::cout << "GoodBye!";
}

void MapEditorController::displayMaps() {
    // loop through MapsXML folder, print all the files inside
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

    std::cout << "Here are all your stored maps:" << std::endl;
    for (const auto &dirEntry: recursive_directory_iterator(std::filesystem::current_path() / "../MapsXML/")) {
        string path = dirEntry.path();
        // transform the full path in file name only
        std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
        // get the substring from last / till the end
        std::string::size_type const p(base_filename.find_last_of('.'));
        // get the index of the last . in file name (to remove extension)
        std::string file_without_extension = base_filename.substr(0, p);
        // substring from begginning to . in order to remove the extension
        std::cout << file_without_extension << std::endl;
    }
}

void MapEditorController::initStoredMaps() {
    // loop through MapsXML folder, store all the maps in the campaign editor controller
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

    for (const auto &dirEntry: recursive_directory_iterator(std::filesystem::current_path() / "../MapsXML/")) {
        string path = dirEntry.path();
        // transform the full path in file name only
        std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
        // get the substring from last / till the end
        std::string::size_type const p(base_filename.find_last_of('.'));
        // get the index of the last . in file name (to remove extension)
        std::string file_without_extension = base_filename.substr(0, p);
        // substring from begginning to . in order to remove the extension
        if (file_without_extension.length() > 1) {
            storedMaps.push_back(file_without_extension);
        }
    }
}

bool MapEditorController::isValidMapName(const string& mapNameToVerify) {
    // we search in the existingMaps vector to verify if mapName is present, return true or false depending of if the map name is valid or not
    return (std::find(
                storedMaps.begin(),
                storedMaps.end(),
                mapNameToVerify) != storedMaps.end());
}

void MapEditorController::registerCampaignEditor(CampaignEditorController *campaignEditorPtr) {
    campaignEditorControllerPtr = campaignEditorPtr;
}

void MapEditorController::updateMap(Map &mapToUpdate, const string& mapName) {
    std::string userChoice;
    std::cout << "Currently the map looks like this:" << std::endl;
    mapToUpdate.displayMap();
    std::cout << "Do you want to modify some of the cells? (Y/N)" << std::endl;
    std::cin >> userChoice;

    while (userChoice != "N") {
        int row, col;
        int cellType;

        std::cout << "Enter the row of the cell that you want to modify (starting from 0):" << std::endl;
        std::cin >> row;
        std::cout << "Now, enter the column of the cell that you want to modify (starting from 0):" << std::endl;
        std::cin >> col;

        if (row == 0 && col == 0) {
            std::cout << "This is your begin cell! You cannot insert here." << std::endl;
            continue; // Skip the rest of the loop and start again
        }

        std::cout << "Now, please choose a type for the given cell:\n0: Empty\n1: Wall" << std::endl;
        std::cin >> cellType;

        try {
            switch (cellType) {
                case 0:
                    mapToUpdate.setCellType(row, col, CellType::Empty);
                    break;
                case 1:
                    mapToUpdate.setCellType(row, col, CellType::Wall);
                    break;
                default:
                    std::cout << "Please provide a valid type as mentioned above. The current choice has not been taken into account." << std::endl;
                    break;
            }
            saveMapToFile(mapToUpdate, mapName);
            std::cout << "Map updated successfully!" << std::endl;
        } catch (...) {
            std::cout << "Wrong input. Please enter 0 or 1 for the cell type." << std::endl;
        }

        std::cout << "Do you want to modify another cell? (Y/N)" << std::endl;
        mapToUpdate.displayMap();
        std::cin >> userChoice;
    }
}
