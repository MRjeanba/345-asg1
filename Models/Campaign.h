//
// Created by Jean-Baptiste Garibo on 2024-03-11.
//

#ifndef CAMPAIGN_H
#define CAMPAIGN_H
#include <string>
#include <vector>

using std::vector;
using std::string;

class Campaign {
private:
    vector<string> listOfMap;
    string campaignName;
public:
    Campaign();
    Campaign(const vector<string>& listOfMaps, const string& campaignName);
    void addMap(const string& mapToAdd);
    void removeMap(const string& mapToRemove);
    void reorderMaps();
    bool isMapInList(const string& mapName);
};



#endif //CAMPAIGN_H
