//
// Created by Jean-Baptiste Garibo on 2024-03-11.
//

#include "Campaign.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Campaign::Campaign() = default;

Campaign::Campaign(const vector<string>& listOfMaps, const string& campaignName) {
    this->listOfMap = listOfMaps;
    this->campaignName = campaignName;
}

void Campaign::addMap(const string& mapToAdd) {
    // verify that map is not already in campaign
    if (isMapInList(mapToAdd)) {
        cout << "Cannot add this map, it is already present in the campaign...";
        return;
    }
    // verify that map exists
    // TODO: CampaignEditorController::isExistingMap(string& MapName)
    // then add the map name to the list
    listOfMap.push_back(mapToAdd);
}

void Campaign::removeMap(const string& mapToRemove) {
    // verify that the map is present in the vector
    // if yes, then remove the map
    if (isMapInList(mapToRemove)) {
        cout << "Removing the map from the campaign..." << endl;
        listOfMap.erase(std::remove(listOfMap.begin(), listOfMap.end(), mapToRemove), listOfMap.end());
        cout << "Map removed successfully." << endl;
    } else {
        cout << "This map is not in the campaign, can't remove it..." << endl;
    }
}

void Campaign::reorderMaps() {
    // gives map and indexes and allow the user to modify them
    // TODO: output vector + idx and tells the user to reorder the vector with the indexes a:1 b:2 c:3 -> 2-1-3
    cout << "Here is all of the map in the campaign with their index:" << endl;
    int idx = 0;
    for (const auto& map: listOfMap) {
        cout << map << ":" << idx<< endl;
    }
    string newOrder;
    cout << "please input the order in which you want the maps for your campaign (only use the index e.g '231' for 3 maps reordered )" << endl;
    cin >> newOrder;
    vector<string> newListOfMap;

    // loop through the string given by the user. This string corresponds to the new sequence for the map, each character is an index of listOfMap. We create a new list by inserting to this new list listOfMap[character]
    for (auto charac: newOrder) {
        int characterInteger = charac - '0'; // we convert the character to the integer explanation: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c#:~:text=to%20convert%20the,0%20and%209%20*/
        newListOfMap.push_back(listOfMap[characterInteger]);
    }

    // then replace listOfMap by newListOfMap
    listOfMap = newListOfMap;
}

bool Campaign::isMapInList(const string& mapName) {
    // we search in the listOfMaps vector to verify if mapName is present, represent if true or not it is present
    return (std::find(
        listOfMap.begin(),
        listOfMap.end(),
        mapName) != listOfMap.end());
}
