#include "gameController.h"
#include "../Utilities.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

gameController::gameController() {
    mapEditorController.registerCampaignEditor(&campaignEditorController);
}

void gameController::attachPlayer(fighter *pFighter) {
    player = pFighter;
}

void gameController::startGame() {
    string chosenCampaignName = selectCampaignName();
    loadCampaign(chosenCampaignName);

    int level = 0;
    mapEditorController.loadMap(currMap, campaign.getCurrentMapName());
    currMap.displayMap();

    std::cout << "\nLET'S BEGIN! Your character is represented by the @\nYour goal is to get to the X cell! "
              << std::endl;
    setMapToDefault();

    int characterRow = 0; // Initial character position row
    int characterCol = 0; // Initial character position column
    int cursorRow = 0;     // Initial cursor position row
    int cursorCol = 0;     // Initial cursor position column
    int endRow = currMap.getHeight() / 2; // Row of the end cell
    int endCol = currMap.getWidth() / 2;  // Column of the end cell

    // 2D array to store original cell types
    std::vector<std::vector<CellType>> originalCellTypes(currMap.getHeight(),
                                                         std::vector<CellType>(currMap.getWidth(), CellType::Empty));

    while (true) {
        currMap.displayMap();
        int moveChoice;
        cout << "\nDo you want to\n1: Make a move\n2: View your inventory\n3: Wear an item\n4: Take off an item\n";
        cin >> moveChoice;
        switch (moveChoice) {
            case 1: {
                cout << "Make a move (WASD to move character, IJKL to move cursor, Q to quit): ";
                char move;
                cin >> move;

                // Clear the previous cell occupied by the character and cursor
                currMap.setCellType(characterRow, characterCol, CellType::Empty);

                if (cursorRow == endRow && cursorCol == endCol) {
                    currMap.setCellType(endRow, endCol, CellType::End);
                } else {
                    currMap.setCellType(cursorRow, cursorCol, CellType::Empty);
                }


                // Clear ValidTarget cells around the previous character position
                for (int r = std::max(0, characterRow - 1);
                     r <= std::min(currMap.getHeight() - 1, characterRow + 1); ++r) {
                    for (int c = std::max(0, characterCol - 1);
                         c <= std::min(currMap.getWidth() - 1, characterCol + 1); ++c) {
                        if (!(r == characterRow && c == characterCol) && currMap.getCellType(r, c) != CellType::Chest) { // Exclude the character cell itself
                            currMap.setCellType(r, c, CellType::Empty);
                        }
                    }
                }


                switch (move) {
                    case 'W':
                    case 'w':
                        if (characterRow > 0 &&
                            currMap.getCellType(characterRow - 1, characterCol) != CellType::Wall)
                            characterRow--; // Move character up if not at top edge
                        break;
                    case 'S':
                    case 's':
                        if (characterRow < currMap.getHeight() - 1 &&
                            currMap.getCellType(characterRow + 1, characterCol) != CellType::Wall)
                            characterRow++; // Move character down if not at bottom edge
                        break;
                    case 'A':
                    case 'a':
                        if (characterCol > 0 &&
                            currMap.getCellType(characterRow, characterCol - 1) != CellType::Wall)
                            characterCol--; // Move character left if not at left edge
                        break;
                    case 'D':
                    case 'd':
                        if (characterCol < currMap.getWidth() - 1 &&
                            currMap.getCellType(characterRow, characterCol + 1) != CellType::Wall)
                            characterCol++; // Move character right if not at right edge
                        break;
                    case 'I':
                    case 'i':
                        if (cursorRow > 0) cursorRow--; // Move cursor up if not at top edge
                        break;
                    case 'K':
                    case 'k':
                        if (cursorRow < currMap.getHeight() - 1) cursorRow++; // Move cursor down if not at bottom edge
                        break;
                    case 'J':
                    case 'j':
                        if (cursorCol > 0) cursorCol--; // Move cursor left if not at left edge
                        break;
                    case 'L':
                    case 'l':
                        if (cursorCol < currMap.getWidth() - 1) cursorCol++; // Move cursor right if not at right edge
                        break;
                    case 'Q':
                    case 'q':
                        std::cout << "Game terminated." << std::endl;
                        return;
                    default:
                        std::cout << "Invalid move. Please try again." << std::endl;
                        break;
                }

                currMap.setCellType(endRow, endCol, CellType::End);

                if (currMap.getCellType(characterRow, characterCol) != CellType::Chest) {
                    currMap.setCellType(characterRow, characterCol, CellType::Character);
                } else {
                    Chest ch = currMap.getChest(characterRow, characterCol);
                    currMap.setCellType(characterRow, characterCol, CellType::Character);
                    player->addItemsToInventory(ch.itemsNames);
                    ch.itemsNames.clear();
                }
                if (currMap.getCellType(cursorRow, cursorCol) != CellType::Chest ||
                    currMap.getCellType(cursorRow, cursorCol) != CellType::Chest) {
                    currMap.setCellType(cursorRow, cursorCol, CellType::Cursor);
                }


                // Check if the character has reached the end cell
                if (characterRow == endRow && characterCol == endCol) {
                    currMap.displayMap();
                    if (campaign.isFinished()) {
                        Clear();
                        cout << "Congratulations! You've finished the last level: " << level
                             << "\nYou finished the campaign!" << endl;
                        campaign.resetCurrentLevel();
                        return;
                    }
                    Clear();
                    cout << "Congratulations! You've finished level " << level++ << "\nLet's head on to level: "
                         << level << endl;
                    // load the next map, so incr currLevel of campaign and load the next campaign within the map
                    campaign.incrementCurrLevel();
                    currMap = Map();
                    mapEditorController.loadMap(currMap, campaign.getCurrentMapName());
                    cout << "Entering the new map..." << endl;
                    setMapToDefault();
                    characterRow = 0;
                    characterCol = 0;
                    cursorRow = 0;
                    cursorCol = 0;
                    endRow = currMap.getHeight() / 2;
                    endCol = currMap.getWidth() / 2;
                }

                // Mark cells surrounding the character as ValidTarget
                for (int r = std::max(0, characterRow - 1);
                     r <= std::min(currMap.getHeight() - 1, characterRow + 1); ++r) {
                    for (int c = std::max(0, characterCol - 1);
                         c <= std::min(currMap.getWidth() - 1, characterCol + 1); ++c) {
                        if (r != characterRow || c != characterCol) {
                            if (currMap.getCellType(r, c) != CellType::Wall &&
                                currMap.getCellType(r, c) != CellType::End &&
                                currMap.getCellType(r, c) != CellType::Cursor &&
                                currMap.getCellType(r, c) != CellType::Chest) {
                                currMap.setCellType(r, c, CellType::ValidTarget);
                            }
                        }
                    }
                }
                break;
            }
            case 2:
                player->displayInventory();
                break;
            case 3:{
                string choice;
                cout << "Choose an item to wear from your inventory:" << endl;
                player->displayInventory();
                cout << "Choose one:" << endl;
                cin >> choice;
                Item * item;
                item = itemEditorController.createCorrectType(choice);
                itemEditorController.loadItem(*item, choice);
                player->wearItem(item);
            }
        }

    }
}




string gameController::selectCampaignName() {
    cout << "Hi please select a campaign to play!:" << endl;
    string chosenCampaign;
    campaignEditorController.displayCampaigns();
    cout << "Please enter the name of the campaign you want to play:" << endl;
    cin >> chosenCampaign;

    while (!campaignEditorController.isValidCampaignName(chosenCampaign)) {
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
    currMap.setCellType(0, 0, CellType::Character);
    currMap.setCellType(currMap.getHeight() / 2, currMap.getWidth() / 2, CellType::End);
}