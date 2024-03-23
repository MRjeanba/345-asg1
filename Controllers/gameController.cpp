#include "gameController.h"

inline void loadMap(Map &mapToFill, const std::string &filename)
{
    const std::string completeFileName = filename + ".xml";
    std::ifstream is(std::filesystem::current_path() / "../MapsXML/" / completeFileName);
    cereal::XMLInputArchive archive(is);
    archive(mapToFill);
    archive(mapToFill);
}

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

//void gameController::displayWelcomeMessage() {
//    std::cout << "Are you ready to play?" << std::endl;
//
//
//}

void gameController::displayMaps() {
    std::cout << "\nHere are the maps you created. Choose one:" << std::endl;
    for (int i = 0; i < storedMaps.size(); ++i) {
        std::cout << i + 1 << ": " << storedMaps[i] << std::endl;
    }
}

int gameController::selectMap() {
    int choice;
    std::cout << "\nEnter the number of the map you want to play: ";
    std::cin >> choice;
    if (choice < 1 || choice > storedMaps.size()) {
        std::cout << "Invalid map choice. Please try again." << std::endl;
        return selectMap();
    }
    return choice - 1; // Adjusting for zero-based indexing

}

void gameController::startGame() {
//    displayWelcomeMessage();

    displayMaps();
    int mapChoice = selectMap();
    std::string selectedMap = storedMaps[mapChoice];
    std::cout << "You chose map: " << selectedMap << std::endl;
    // Start the game with the selected map
    Map mapToDisplay;
    loadMap(mapToDisplay, selectedMap); // Load the selected map
    mapToDisplay.displayMap();

    std::cout << "\nLET'S BEGIN! Your character is represented by the @\nYour goal is to get to the X cell! " << std::endl;
    mapToDisplay.setCellType(0,0,CellType::Character);
    mapToDisplay.setCellType(mapToDisplay.getWidth()/2,mapToDisplay.getWidth()/2,CellType::End);

    int characterRow = 0; // Initial character position row
    int characterCol = 0; // Initial character position column
    int endRow = mapToDisplay.getHeight() / 2; // Row of the end cell
    int endCol = mapToDisplay.getWidth() / 2; // Column of the end cell

    std::cout << "Use WASD keys to move the character. Press Q to quit." << std::endl;

    while (true) {
        mapToDisplay.displayMap(); // Display the map

        // Ask the user to make a move
        std::cout << "Make a move (W: up, A: left, S: down, D: right): ";
        char move;
        std::cin >> move;

        // Clear the previous cell occupied by the character
        mapToDisplay.setCellType(characterRow, characterCol, CellType::Empty);

        switch (move) {
            case 'W':
            case 'w':
                if (characterRow > 0) characterRow--; // Move character up if not at top edge
                break;
            case 'S':
            case 's':
                if (characterRow < mapToDisplay.getHeight() - 1) characterRow++; // Move character down if not at bottom edge
                break;
            case 'A':
            case 'a':
                if (characterCol > 0) characterCol--; // Move character left if not at left edge
                break;
            case 'D':
            case 'd':
                if (characterCol < mapToDisplay.getWidth() - 1) characterCol++; // Move character right if not at right edge
                break;
            case 'Q':
            case 'q':
                std::cout << "Game terminated." << std::endl;
                return;
            default:
                std::cout << "Invalid move. Please try again." << std::endl;
                break;
        }

        // Update the character's position on the map
        mapToDisplay.setCellType(characterRow, characterCol, CellType::Character);

        // Check if the character has reached the end cell
        if (characterRow == endRow && characterCol == endCol) {
            mapToDisplay.displayMap();
            std::cout << "Congratulations! You've reached the end cell. You win!" << std::endl;
            return;
        }
    }



}



//void gameController::displayMenu() {
//    int userChoice = 0;
//    std::cout << "Welcome to the JUICE Game!\n";
//    std::cout << "What would you like to do?\n";
//    std::cout << "1. Play a game\n";
//    std::cout << "2. Exit\n";
//    std::cout << "Enter your choice: ";
//    std::cin >> userChoice;
//
//    switch (userChoice) {
//        case 1: {
//            startGame();
//            break;
//        }
//        case 2: {
//            std::cout << "Exiting the game. Goodbye!\n";
//            break;
//        }
//        default: {
//            std::cout << "Invalid choice. Please try again.\n";
//            displayMenu(); // Recursively call displayMenu if the choice is invalid
//            break;
//        }
//    }
//}



