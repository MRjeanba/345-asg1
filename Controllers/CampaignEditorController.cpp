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
        throw std::runtime_error("Cannot create another instance, an instance of campaign editor already exists.");
    }
}

void CampaignEditorController::displayMenu() {
    int userChoice;
    cout << "Welcome to the campaign editor!\nWhat do you want to do?:\n1: create a campaign\n2: edit a campaign\n3: Quit the campaign editor"
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
                Campaign campaignToEdit = Campaign();
                loadCampaign(campaignToEdit, campaignName);
                updateCampaign(campaignToEdit);
                cout << "Campaign updated successfully!" << endl;
                break;
            }
            case 3: {
                Clear();
                cout << "Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Please provide a value between 1-3:" << endl;
                break;
            }
        }
        Clear();
        cout << "What do you want to do now?:\n1: create a campaign\n2: edit a campaign\n3: Quit the campaign editor" << endl;
        cin >> userChoice;
    }
}

void CampaignEditorController::createCampaign() {
    string campaignName, userChoice;
    cout << "Let's create a new campaign\nPlease provide a name for your new campaign:";
    cin >> campaignName;

    if (isValidCampaignName(campaignName)) {
        cout << "You cannot create this campaign, it already exists." << endl;
        return;
    }

    Campaign newlyCreatedCampaign = Campaign(campaignName);

    cout << "\nDo you want to add a map to this campaign right now?: Y/N" << endl;
    cin >> userChoice;
    if (userChoice == "Y") {
        updateCampaign(newlyCreatedCampaign);
    }

    cout << "Now, let's save your newly created campaign..." << endl;
    saveCampaignToFile(newlyCreatedCampaign, campaignName);

    cout << "Campaign created successfully!" << endl;
    storedCampaigns.push_back(campaignName);
}

void CampaignEditorController::updateCampaign(Campaign& campaignToUpdate) {
    int userChoice;
    cout << "Let's update " << campaignToUpdate.getName() << endl;
    cout << "Select the action that you want to perform on the campaign:\n1: add a map to the campaign\n2: remove a map from the campaign\n3: arrange the order of the campaign\n4: Do nothing" << endl;
    cin >> userChoice;

    while (userChoice != 4) {
        switch (userChoice) {
            case 1: {
                Clear();
                string mapChosen;
                cout << "Please choose a map. Here are all the available maps:" << endl;
                displayMaps();
                cout << "Choose one: " << endl;
                cin >> mapChosen;

                if (!isExistingMap(mapChosen)) {
                    throw std::runtime_error("This map does not exist.");
                }

                cout << "Adding the map to the campaign..." << endl;
                campaignToUpdate.addMap(mapChosen);
                saveCampaignToFile(campaignToUpdate, campaignToUpdate.getName());
                cout << "Map added successfully!" << endl;
                break;
            }
            case 2: {
                Clear();
                string mapToDelete;
                cout << "Please choose a map to remove from the campaign. Here are all the maps in the campaign:" << endl;
                campaignToUpdate.displayListOfMap();
                cout << "Provide the name of the map that you want to delete from the campaign:" << endl;
                cin >> mapToDelete;

                if (!campaignToUpdate.isMapInList(mapToDelete)) {
                    cout << "This map is not in the campaign. Aborting" << endl;
                    break;
                }
                campaignToUpdate.removeMap(mapToDelete);
                cout << "Map removed from campaign successfully!" << endl;
                saveCampaignToFile(campaignToUpdate, campaignToUpdate.getName());
                break;
            }
            case 3: {
                Clear();
                cout << "Let's arrange the order of the maps for your campaign!" << endl;
                campaignToUpdate.reorderMaps();
                saveCampaignToFile(campaignToUpdate, campaignToUpdate.getName());
                cout << "Campaign order updated successfully!" << endl;
                break;
            }
            default: {
                Clear();
                cout << "Please provide a value between 1-4.\n1: add a map to the campaign\n2: remove a map from the campaign\n3: arrange the order of the campaign\n4: Do nothing" << endl;
                break;
            }
        }
        cout << "What do you want to do now?\n1: add a map to the campaign\n2: remove a map from the campaign\n3: arrange the order of the campaign\n4: Do nothing" << endl;
        cin >> userChoice;
    }

}

void CampaignEditorController::saveCampaignToFile(Campaign &campaignToSave, const string &campaignName) {
    try {
        const std::string completeFileName = campaignName + ".xml";
        std::filesystem::create_directory("../CampaignsXML");
        std::ofstream os(std::filesystem::current_path() / "../CampaignsXML/" / completeFileName);
        cereal::XMLOutputArchive archive(os);
        archive(campaignToSave);
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    }
}

void CampaignEditorController::loadCampaign(Campaign &campaignToFill, const string &campaignName) {
    try {
        if (!isValidCampaignName(campaignName)) {
            throw std::runtime_error("The provided campaign name does not exist.");
        }

        const std::string completeFileName = campaignName + ".xml";
        std::ifstream is(std::filesystem::current_path() / "../CampaignsXML/" / completeFileName);
        cereal::XMLInputArchive archive(is);
        archive(campaignToFill);
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
}

bool CampaignEditorController::isValidCampaignName(const string &campaignName) {
    return (std::find(storedCampaigns.begin(), storedCampaigns.end(), campaignName) != storedCampaigns.end());
}

void CampaignEditorController::initializeExistingMaps() {
    try {
        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        for (const auto &dirEntry : recursive_directory_iterator(std::filesystem::current_path() / "../MapsXML/")) {
            string path = dirEntry.path();
            std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
            std::string::size_type const p(base_filename.find_last_of('.'));
            std::string file_without_extension = base_filename.substr(0, p);
            if (file_without_extension.length() > 1) {
                existingMaps.push_back(file_without_extension);
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    }
}

void CampaignEditorController::initializeStoredCampaign() {
    try {
        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        for (const auto &dirEntry : recursive_directory_iterator(std::filesystem::current_path() / "../CampaignsXML/")) {
            string path = dirEntry.path();
            std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
            std::string::size_type const p(base_filename.find_last_of('.'));
            std::string file_without_extension = base_filename.substr(0, p);
            if (file_without_extension.length() > 1) {
                storedCampaigns.push_back(file_without_extension);
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    }
}

void CampaignEditorController::displayMaps() {
    try {
        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        cout << "Here are all your stored maps:\n" << endl;
        for (const auto &dirEntry : recursive_directory_iterator(std::filesystem::current_path() / "../MapsXML/")) {
            string path = dirEntry.path();
            std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
            std::string::size_type const p(base_filename.find_last_of('.'));
            std::string file_without_extension = base_filename.substr(0, p);
            if (file_without_extension.length() > 1) {
                std::cout << "-" << file_without_extension << std::endl;
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    }
}

void CampaignEditorController::addMapToExistingMaps(const string &mapName) {
    existingMaps.push_back(mapName);
}

bool CampaignEditorController::isExistingMap(const string &mapName) {
    return (std::find(existingMaps.begin(), existingMaps.end(), mapName) != existingMaps.end());
}

void CampaignEditorController::displayCampaigns() {
    try {
        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        cout << "Here are all your stored campaigns:\n" << endl;
        for (const auto &dirEntry : recursive_directory_iterator(std::filesystem::current_path() / "../CampaignsXML/")) {
            string path = dirEntry.path();
            std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
            std::string::size_type const p(base_filename.find_last_of('.'));
            std::string file_without_extension = base_filename.substr(0, p);
            if (file_without_extension.length() > 1) {
                std::cout << file_without_extension << std::endl;
            }
        }
    } catch (const std::filesystem::filesystem_error &e) {
        std::cerr << "File system error: " << e.what() << std::endl;
    }
}
