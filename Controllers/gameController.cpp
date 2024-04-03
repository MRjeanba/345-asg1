#include "gameController.h"
#include "../Utilities.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

gameController::gameController() {
    mapEditorController.registerCampaignEditor(&campaignEditorController);
}

void gameController::startGame() {

    string chosenCampaignName = selectCampaignName();
    loadCampaign(chosenCampaignName);


    int level = 0;
    mapEditorController.loadMap(currMap, campaign.getCurrentMapName());
    currMap.displayMap();

    std::cout << "\nLET'S BEGIN! Your character is represented by the @\nYour goal is to get to the X cell! " << std::endl;
    setMapToDefault();

    int characterRow = 0; // Initial character position row
    int characterCol = 0; // Initial character position column
    int endRow = currMap.getHeight() / 2; // Row of the end cell
    int endCol = currMap.getWidth() / 2; // Column of the end cell

    cout << "Use WASD keys to move the character. Press Q to quit." << endl;

    while (true) {
        currMap.displayMap();

        cout << "Make a move (W: up, A: left, S: down, D: right): ";
        char move;
        cin >> move;

        // Clear the previous cell occupied by the character
        currMap.setCellType(characterRow, characterCol, CellType::Empty);

        switch (move) {
            case 'W':
            case 'w':
                if (characterRow > 0 && currMap.getCellType(characterRow - 1, characterCol) != CellType::Wall) characterRow--; // Move character up if not at top edge
                break;
            case 'S':
            case 's':
                if (characterRow < currMap.getHeight() - 1 && currMap.getCellType(characterRow + 1, characterCol) != CellType::Wall) characterRow++; // Move character down if not at bottom edge
                break;
            case 'A':
            case 'a':
                if (characterCol > 0 && currMap.getCellType(characterRow, characterCol - 1) != CellType::Wall) characterCol--; // Move character left if not at left edge
                break;
            case 'D':
            case 'd':
                if (characterCol < currMap.getWidth() - 1 && currMap.getCellType(characterRow, characterCol + 1) != CellType::Wall) characterCol++; // Move character right if not at right edge
                break;
            case 'Q':
            case 'q':
                std::cout << "Game terminated." << std::endl;
                return;
            default:
                std::cout << "Invalid move. Please try again." << std::endl;
                break;
        }

        currMap.setCellType(characterRow, characterCol, CellType::Character);

        // Check if the character has reached the end cell
        if (characterRow == endRow && characterCol == endCol) {
            currMap.displayMap();
            if (campaign.isFinished()){
                Clear();
                cout << "Congratulations! You've finished the last level: " << level << "\n You finished the campaign!" << endl;
                campaign.resetCurrentLevel();
                return;
            }
            Clear();
            cout << "Congratulations! You've finished level" << level++ << "\n let's head on to level: " << level << endl;
            // load the next map, so incr currLevel of campaign and load the next campaign within the map
            campaign.incrementCurrLevel();
            currMap = Map();
            mapEditorController.loadMap(currMap, campaign.getCurrentMapName());
            cout << "Entering the new map..."<< endl;
            setMapToDefault();
            characterRow = 0;
            characterCol = 0;
            endRow = currMap.getHeight() / 2;
            endCol = currMap.getWidth() / 2;
        }
    }
}

string gameController::selectCampaignName() {
    cout << "Hi please select a campaign to play!:" << endl;
    string chosenCampaign;
    campaignEditorController.displayCampaigns();
    cout << "Please enter the name of the campaign you want to play:" << endl;
    cin >> chosenCampaign;

    while (!campaignEditorController.isValidCampaignName(chosenCampaign)){
        campaignEditorController.displayCampaigns();
        cout << "You provided a wrong campaign name, please enter it exactly as it is:" << endl;
        cin >> chosenCampaign;
    }
    return chosenCampaign;
}

void gameController::loadCampaign(string &campaignName) {
    campaignEditorController.loadCampaign(campaign, campaignName);
}

void gameController::setMapToDefault() {
    currMap.setCellType(0,0,CellType::Character);
    currMap.setCellType(currMap.getHeight()/2,currMap.getWidth()/2,CellType::End);
}