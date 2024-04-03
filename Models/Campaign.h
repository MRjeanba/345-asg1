//
// Created by Jean-Baptiste Garibo on 2024-03-11.
//

#ifndef CAMPAIGN_H
#define CAMPAIGN_H
#include <string>
#include <vector>
#include <cereal/types/vector.hpp>

using std::vector;
using std::string;

class Campaign {
private:
    vector<string> listOfMap;
    string campaignName;
    int currLevel = 0;
    bool objectiveFulfilled = listOfMap.size() == currLevel;
public:
    /**
     * Default constructor for the class
     */
    Campaign();

    /**
     * Constructor of class, set the campaign name
     * @param campaignName the name of the campaign the object is referring to
     */
    Campaign(const string& campaignName);

    /**
     * Constructor of class, set the campaign name and the list of vector
     * @param listOfMaps 
     * @param campaignName 
     */
    Campaign(const vector<string>& listOfMaps, const string& campaignName);

    /**
     * Add a map to the listOfMap of the current campaign instance
     * @param mapToAdd the name of the map to add to the list
     */
    void addMap(const string& mapToAdd);

    /**
     * Remove a map from the current listOfMap of the campaign instance
     * @param mapToRemove the name of the map to remove from the list
     */
    void removeMap(const string& mapToRemove);

    /**
     * Ask the user for the new order of the maps within the campaign
     */
    void reorderMaps();

    /**
     * Give information about whether or not the map name is in the listOfMaps
     * @param mapName the name of the map of which we want to verify if it is present in the list of maps of the campaign
     * @return a boolean indicating if true or not the map is in the listOfMaps
     */
    bool isMapInList(const string& mapName);

    /**
     * Get the name of the Campaign
     * @return a string representing the name of the current campaign
     */
    string getName() const;

    /**
     * loop through the listOfMaps contained within the campaign and output them
     */
    void displayListOfMap() const;

    /**
     * Gives information about the map currently loaded from the campaign
     * @return the map of the current level of the campaign
     */
    [[nodiscard]] string getCurrentMapName() const;

    /**
     * Gives information about the state of the campaign, if it is finished or not
     * @return a boolean indicating true if the campaign if finished, false otherwise
     */
    bool isFinished() const;

    /**
     * indicates that the current map door has been taken, so we increment the current level to load the next map
     * on the game
     */
    void incrementCurrLevel();

    /**
     * @brief Method used by cereal library for serializing the class
     * @tparam Archive The data type in which we want to store the data
     * @param archive the actual archive used for serialization
     */
    template<class Archive>
    void serialize(Archive & archive)
    {
        archive( listOfMap, campaignName ); // serialize type by passing it to the archive
    }
};



#endif //CAMPAIGN_H
