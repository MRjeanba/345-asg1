//
// Created by Jean-Baptiste Garibo on 2024-03-09.
//

#include "MapEditorController.h"

/**
 * Helper method to clear the screen, depending on the OS, it will use a different command
 */
void Clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

MapEditorController::MapEditorController() {

    //TODO: should also create a MabBuilder
    if (numberOfInstances < 1) {
        numberOfInstances++;
        return;
    }
    std::cout << "There already exist an instance of the map editor controller, use the existing instance";
    throw std::runtime_error("can't create a second instance of the map editor class");
}

void MapEditorController::createMap() {
    int height, width, cellType;

    std::cout << "To create a map, please provide a height for it:" << std::endl;
    std::cin >> height;
    std::cout << "Now, please provide a width for the map!!" << std::endl;
    std::cin >> width;
    Map createdMap = Map(height,width);

    updateMap(createdMap);

    Clear();

    std::string MapName;
    // now save map on file!
    std::cout << "Now, let's save this map, which name do you want to give for the map?:" << std::endl;
    std::cin >> MapName;
    Clear();
    std::cout << "Creating and saving the map..." << std::endl;
    saveMapToFile(createdMap,MapName);
    std::cout << "Map created successfully!" << std::endl;
}

Map MapEditorController::loadMap(string& NameOfMap) {
    //TODO: TO IMPLEMENT
    return Map();
}

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
                std::string userWantsToModify = "yes";
                std::cout << "Please enter the name of the map you want to update" << std::endl;
                Map mapToUpdate = loadMap(nameOfMapToUpdate);
                updateMap(mapToUpdate);
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

void MapEditorController::updateMap(Map &mapToUpdate) {
    std::string userChoice;
    std::cout << "Do you want to modify some of the cells ? currently the map is empty. Y/N?" << std::endl;
    std::cin >> userChoice;

    while (userChoice != "N") {
        int row, col;
        int cellType;

        std::cout << "Enter the row of the cell that you want to modify (start from 0)" << std::endl;
        std::cin >> row;
        std::cout << "Now, enter the row of the cell that you want to modify (start from 0)" << std::endl;
        std::cin >> col;
        std::cout << "Now, please choose a type for the given cell\n0:Empty\n1:Wall" << std::endl;
        std::cin >> cellType;
        try {
            switch (cellType) {
                case 0:
                    mapToUpdate.setCellType(row,col,CellType::Empty);
                break;
                case 1:
                    mapToUpdate.setCellType(row,col,CellType::Wall);
                break;
                default:
                    std::cout << "Please provide a valid type as mentionned above... the current choice has not been taken into account.";
                break;
            }
        } catch (...) {
            std::cout << "Wrong input, please enter as stated above 0 or 1 for the cell type!"  << std::endl;
        }

        std::cout << "Do you want to modify another cell? answer with Y/N:";
        std::cin >> userChoice;
    }
}