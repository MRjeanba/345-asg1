#include "gameController.h"
#

gameController::gameController() {
    // Load stored maps from MapsXML folder
    for (const auto& dirEntry : std::filesystem::directory_iterator(std::filesystem::current_path() / "../MapsXML/")) {
        std::string path = dirEntry.path();
        std::string baseFilename = path.substr(path.find_last_of("/\\") + 1);
        std::string::size_type const p(baseFilename.find_last_of('.'));
        std::string fileWithoutExtension = baseFilename.substr(0, p);
        if (fileWithoutExtension.length() > 1) {
            storedMaps.push_back(fileWithoutExtension);
        }
    }
}

void gameController::displayWelcomeMessage() {
    std::cout << "Are you ready to play?" << std::endl;
}

void gameController::displayMaps() {
    std::cout << "Here are the maps you created. Choose one:" << std::endl;
    for (int i = 0; i < storedMaps.size(); ++i) {
        std::cout << i + 1 << ": " << storedMaps[i] << std::endl;
    }
}

int gameController::selectMap() {
    int choice;
    std::cout << "Enter the number of the map you want to play: ";
    std::cin >> choice;
    if (choice < 1 || choice > storedMaps.size()) {
        std::cout << "Invalid map choice. Please try again." << std::endl;
        return selectMap();
    }
    return choice - 1; // Adjusting for zero-based indexing

}

void gameController::startGame() {
    displayWelcomeMessage();
    displayMaps();
    int mapChoice = selectMap();
    std::string selectedMap = storedMaps[mapChoice];
    std::cout << "You chose map: " << selectedMap << std::endl;
    // Start the game with the selected map



}

void gameController::displayMenu() {
    int userChoice = 0;
    std::cout << "Welcome to the JUICE Game!\n";
    std::cout << "What would you like to do?\n";
    std::cout << "1. Play a game\n";
    std::cout << "2. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> userChoice;

    switch (userChoice) {
        case 1: {
            startGame();
            break;
        }
        case 2: {
            std::cout << "Exiting the game. Goodbye!\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again.\n";
            displayMenu(); // Recursively call displayMenu if the choice is invalid
            break;
        }
    }
}

void displaySelectedMap(Map& selectedMap) {
    // Display the selected map here
    selectedMap.displayMap();
}

