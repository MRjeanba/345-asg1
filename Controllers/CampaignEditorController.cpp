//
// Created by Jean-Baptiste Garibo on 2024-03-12.
//

#include "CampaignEditorController.h"
#include <string>
#include <filesystem>
#include <fstream>
#include <cereal/archives/xml.hpp>

#include "../Utilities.h"

using std::string;
using std::cout;
using std::cin;

CampaignEditorController::CampaignEditorController() {
    if (numberOfInstances < 1) {
        numberOfInstances++;
        initializeExistingMaps();
        initializeStoredCampaign();
    } else {
        throw std::runtime_error("Cannot create another instance, an instance of campaign editor already exist.");
    }
}

void CampaignEditorController::displayMenu() {
    // ask the user to 1: create a campaign, 2: edit a campaign
    int userChoice;
    cout <<
            "Welcome to the campaign editor!\nWhat do you want to do?:\n1: create a campaign\n2: edit a campaign\n3: Quit the campaign editor"
            << endl;
    cin >> userChoice;

    while (userChoice != 3) {
        switch (userChoice) {
            case 1: {
                Clear();
                createCampaign();
                break;
            }
            case 2: {
                Clear();
                if (storedCampaigns.empty()) {
                    cout << "You don't have any campaigns, please create one first." << endl;
                    break;
                }
                string campaignName;
                cout << "Please enter the name of the campaign you want to edit:" << endl;
                displayCampaigns();
                cin >> campaignName;

                if (!isValidCampaignName(campaignName)) {
                    cout << "You provided a wrong campaign name. Aborting!";
                    break;
                }
                // load the campaign and pass it to the updateCampaign method
                Campaign campaignToEdit = Campaign();
                loadCampaign(campaignToEdit, campaignName);
                updateCampaign(campaignToEdit);
                cout << "Campaign updated successfully!" << endl;
                break;
            }
            case 3: {
                Clear();
                cout << "GoodBye!" << endl;
                break;
            }
            default: {
                cout << "Please provide a value between 1-3:" << endl;
                cin >> userChoice;
                break;
            }
        }
        Clear();
        cout << "What do you want to do now?:\n1: create a campaign\n2:edit a campaign\n3: Quit the campaign editor" << endl;
        cin >> userChoice;
    }
}


void CampaignEditorController::createCampaign() {
    string campaignName, userChoice;
    // ask for campaign name
    cout << "Let's create a new campaign\nPlease provide a name for your new campaign:";
    cin >> campaignName;

    // verify if the campaign already exist, if yes, we cannot create it
    if (isValidCampaignName(campaignName)) {
        cout << "You cannot create this campaign, it already exists." << endl;
        return;
    }

    // create the campaign
    Campaign newlyCreatedCampaign = Campaign(campaignName);

    // ask the user if he wants to update/ add maps inside or do nothing for now
    cout << "\nDo you want to add a map to this campaign right now?: Y/N" << endl;
    cin >> userChoice;
    if (userChoice == "Y") {
        updateCampaign(newlyCreatedCampaign);
    }

    // save the campaign
    cout << "Now, let's save you newly created campaign..." << endl;
    saveCampaignToFile(newlyCreatedCampaign, campaignName);

    // add the new campaign to storedCampaigns and exit
    cout << "Campaign created successfully!";
    storedCampaigns.push_back(campaignName);
}

void CampaignEditorController::updateCampaign(Campaign& campaignToUpdate) {
    // Ask the user if either want to add a map, remove a map, or reorder the order of the maps
    int userChoice;
    cout << "let's update " << campaignToUpdate.getName() << endl;
    cout <<
            "Select the action that you want to perform on the campaign:\n1: add a map to the campaign\n2: remove a map from the campaign"
            "\n3: arrange the order of the campaign\n4:Do nothing" << endl;
    cin >> userChoice;
    while (userChoice != 4) {
        switch (userChoice) {
            case 1: {
                Clear();
                string mapChosen;
                cout << "Please choose map, here are all the available map:" << endl;
                displayMaps();
                cout << "choose one: " << endl;
                cin >> mapChosen;

                if (!isExistingMap(mapChosen)) {
                    throw std::runtime_error("This map does not exists");
                }

                // then add the map to the campaign
                cout << "Adding the map to the campaign..." << endl;
                campaignToUpdate.addMap(mapChosen);
                cout << "Map added successfully!" << endl;
                cout << "What do you want to do now?\n1: add a map to the campaign\n2: remove a map from the campaign"
                        "\n3: arrange the order of the campaign\n4:Do nothing" << endl;
                cin >> userChoice;
                break;
            }
            case 2: {
                Clear();
                string mapToDelete;
                cout << "Please choose map to remove from the campaign, here are all the maps in the campaign:" << endl;
                campaignToUpdate.displayListOfMap();
                cout << "Provide the name of the map that you want to delete from the campaign:" << endl;
                cin >> mapToDelete;

                if (!campaignToUpdate.isMapInList(mapToDelete)) {
                    cout << "This map is not in the campaign. Aborting" << endl;
                    break;
                }
                campaignToUpdate.removeMap(mapToDelete);
                cout << "Map removed from campaign successfully!" << endl;
                cout << "What do you want to do now?\n1: add a map to the campaign\n2: remove a map from the campaign"
                        "\n3: arrange the order of the campaign\n4:Do nothing" << endl;
                cin >> userChoice;
                break;
            }
            case 3: {
                Clear();
                cout << "Let's arrange the order of the maps for your campaign!" << endl;
                campaignToUpdate.reorderMaps();
                saveCampaignToFile(campaignToUpdate, campaignToUpdate.getName());
                cout << "What do you want to do now?\n1: add a map to the campaign\n2: remove a map from the campaign"
                        "\n3: arrange the order of the campaign\n4:Do nothing" << endl;
                cin >> userChoice;
                break;
            }
            case 4: {
                Clear();
                cout << "Exiting...";
                cin >> userChoice;
                break;
            }
            default: {
                Clear();
                cout <<
                        "Please provide a value between 1-4.\n1: add a map to the campaign\n2: remove a map from the campaign"
                        "\n3: arrange the order of the campaign\n4:Do nothing" << endl;
                cin >> userChoice;
                break;
            };
        }
    }
}

void CampaignEditorController::saveCampaignToFile(Campaign &campaignToSave, const string &campaignName) {
    const std::string completeFileName = campaignName + ".xml";
    std::ofstream os(std::filesystem::current_path() / "../CampaignsXML/" / completeFileName);
    cereal::XMLOutputArchive archive(os);
    archive(campaignToSave); // serialize and store the current instance to the file
}

void CampaignEditorController::loadCampaign(Campaign &campaignToFill, const string &campaignName) {
    if (!isValidCampaignName(campaignName)) {
        throw std::runtime_error("The provided campaign name does not exists.");
    }

    // load the map using cereal library, and exit
    const std::string completeFileName = campaignName + ".xml";
    std::ifstream is(std::filesystem::current_path() / "../CampaignsXML/" / completeFileName);
    cereal::XMLInputArchive archive(is);
    archive(campaignToFill);
}


bool CampaignEditorController::isValidCampaignName(const string &campaignName) {
    // we search in the storedCampaign vector to verify if campaignName is present, returns true if yes, else false
    return (std::find(
                storedCampaigns.begin(),
                storedCampaigns.end(),
                campaignName) != storedCampaigns.end());
}

void CampaignEditorController::displayCampaigns() {
    // loop through CampaignsXML folder, print all the files inside
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

    cout << "Here are all your stored campaigns:\n" << endl;
    for (const auto &dirEntry: recursive_directory_iterator(std::filesystem::current_path() / "../CampaignsXML/")) {
        string path = dirEntry.path();
        // transform the full path in file name only
        std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
        // get the substring from last / till the end
        std::string::size_type const p(base_filename.find_last_of('.'));
        // get the index of the last . in file name (to remove extension)
        std::string file_without_extension = base_filename.substr(0, p);
        // substring from begginning to . in order to remove the extension
        if (file_without_extension.length() > 1) {
            std::cout << file_without_extension << std::endl;
        }
    }
}

void CampaignEditorController::displayMaps() {
    // loop through MapsXML folder, print all the files inside
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

    cout << "Here are all your stored maps:maps\n" << endl;
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
            std::cout << "-" << file_without_extension << std::endl;
        }
    }
}

bool CampaignEditorController::isExistingMap(const string &mapName) {
    // we search in the existingMaps vector to verify if mapName is present, return true or false depending of if the map name is valid or not
    return (std::find(
                existingMaps.begin(),
                existingMaps.end(),
                mapName) != existingMaps.end());
}

void CampaignEditorController::addMapToExistingMaps(const string &mapName) {
    existingMaps.push_back(mapName);
}

void CampaignEditorController::initializeExistingMaps() {
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
            existingMaps.push_back(file_without_extension);
        }
    }
}

void CampaignEditorController::initializeStoredCampaign() {
    // loop through MapsXML folder, store all the maps in the campaign editor controller
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

    for (const auto &dirEntry: recursive_directory_iterator(std::filesystem::current_path() / "../CampaignsXML/")) {
        string path = dirEntry.path();
        // transform the full path in file name only
        std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
        // get the substring from last / till the end
        std::string::size_type const p(base_filename.find_last_of('.'));
        // get the index of the last . in file name (to remove extension)
        std::string file_without_extension = base_filename.substr(0, p);
        // substring from begginning to . in order to remove the extension
        if (file_without_extension.length() > 1) {
            storedCampaigns.push_back(file_without_extension);
        }
    }
}

// void CampaignEditorController::registerMapEditor(MapEditorController *mapEditorPtr) {
//     mapEditorControllerPtr = mapEditorPtr;
// }
