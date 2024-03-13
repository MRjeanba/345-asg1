#include <iostream>
#include <string>
#include <vector>
#include "MapBuilder.h"
#include "Map.cpp"
#include <fstream>
#include <filesystem>
#include <cereal/archives/xml.hpp>

// create five maps

// level 1
Map MapForCharacterLevel1(5, 5);
// level 2
Map MapForCharacterLevel2(9, 9);
// level 3
Map MapForCharacterLevel3(11, 11);
// level 4
Map MapForCharacterLevel4(13, 13);
// level 5
Map MapForCharacterLevel5(15, 15);
// MapForCharacterLevel5.setCellType(3, 3, CellType::Wall);
// MapForCharacterLevel5.setCellType(13, 1, CellType::Occupied);
// MapForCharacterLevel5.setCellType(2, 13, CellType::Wall);
// MapForCharacterLevel5.setCellType(4, 1, CellType::Occupied);

void MapBuilder::buildMap()
{
    // Assuming "mapToFill" is a member of the MapBuilder class representing the map being built

    // Check if filename is provided or set it to a default value
    std::string filename = "lol"; // Change this to your desired default filename

    mapToFill = Map();

    // Call the loadMap function with appropriate parameters
    loadMap(MapBuilder::mapToFill, filename);
}

void MapGamePlayBuilder::buildMap()
{
    Map mapToFill;

    // create map for the different levels of characters (1 to 5)
    // for characters with higher level -> add more walls or enemies
    // for characters with low level -> easy map
}

inline void loadMap(Map &mapToFill, const std::string &filename)
{
    const std::string completeFileName = filename + ".xml";
    std::ifstream is(std::filesystem::current_path() / "../MapsXML/" / completeFileName);
    cereal::XMLInputArchive archive(is);
    archive(mapToFill);
}
