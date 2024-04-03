//
// Created by Jean-Baptiste Garibo on 2024-03-11.
//

#include "Campaign.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Campaign::Campaign() = default;

Campaign::Campaign(const string &campaignName) { this->campaignName = campaignName; }

Campaign::Campaign(const vector<string>& listOfMaps, const string& campaignName) {
    this->listOfMap = listOfMaps;
    this->campaignName = campaignName;
}

void Campaign::addMap(const string& mapToAdd) {
    if (isMapInList(mapToAdd)) {
        cout << "Cannot add this map, it is already present in the campaign...";
        return;
    }
    listOfMap.push_back(mapToAdd);
}

void Campaign::removeMap(const string& mapToRemove) {
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
    // output vector + idx and tells the user to reorder the vector with the indexes a:1 b:2 c:3 -> 2-1-3
    cout << "This is all of the map in the campaign with their index:" << endl;
    int idx = 0;
    for (const auto& map: listOfMap) {
        cout << map << ":" << idx<< endl;
        idx++;
    }

    string newOrder;
    cout << "please input the order in which you want the maps for your campaign (only use the index e.g '231' for 3 maps reordered )" << endl;
    cin >> newOrder;
    vector<string> newListOfMap;

    // loop through the string given by the user. This string corresponds to the new sequence for the map, each character is an index of listOfMap. We create a new list by inserting to this new list listOfMap[character]
    for (auto charac: newOrder) {
        int characterInteger = charac - '0'; // we convert the character to the integer explanation: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c#:~:text=to%20convert%20the,0%20and%209%20*/

        // verify that each index is in bound of the vector
        if (characterInteger > listOfMap.size() - 1 || characterInteger < 0) {
            cout << "You provided one or more invalid index, please try again later." << endl;
            return;
        }
        newListOfMap.push_back(listOfMap[characterInteger]);
    }
    cout << "New order for the campaign:" << endl;
    int i = 0;
    for (const auto& map: newListOfMap) {
        cout << map << ":" << i<< endl;
        i++;
    }
    // then replace listOfMap by newListOfMap
    listOfMap = newListOfMap;
    cout << "Saving the new order..." << endl;
}

bool Campaign::isMapInList(const string& mapName) {
    // we search in the listOfMaps vector to verify if mapName is present, represent if true or not it is present
    return (std::find(
        listOfMap.begin(),
        listOfMap.end(),
        mapName) != listOfMap.end());
}

string Campaign::getName() const { return campaignName; }

void Campaign::displayListOfMap() const {
    for (const auto& map: listOfMap) {
        cout << map << endl;
    }
}

string Campaign::getCurrentMapName() const {
    return listOfMap[currLevel];
}

bool Campaign::isFinished() const {
    return listOfMap.size() - 1 == (currLevel);
}

void Campaign::incrementCurrLevel() { currLevel++; }

void Campaign::resetCurrentLevel() { currLevel = 0; }