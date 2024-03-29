#include <iostream>
#include <string>
#include <vector>
#include "MapBuilder.h"
#include "Map.cpp"
#include <fstream>
#include <filesystem>
#include <cereal/archives/xml.hpp>
#include "Controllers/MapEditorController.cpp"

void MapBuilder::buildMap(string filename)
{
    // look in MapsXML for the filename.xml -> put all content into mapToFill
    const std::string completeFileName = filename + ".xml";
    std::ifstream is(std::filesystem::current_path() / "../MapsXML/" / completeFileName);
    cereal::XMLInputArchive archive(is);
    archive(mapToFill);
}

void MapGamePlayBuilder::buildMap(string filename)
{
    Map mapToFill;

    // create map for the different levels of characters (1 to 5)
    // for characters with higher level -> add more walls or enemies
    // for characters with low level -> easy map
}

// inline void loadMap(Map &mapToFill, const std::string &filename)
// {
//     const std::string completeFileName = filename + ".xml";
//     std::ifstream is(std::filesystem::current_path() / "../MapsXML/" / completeFileName);
//     cereal::XMLInputArchive archive(is);
//     archive(mapToFill);
// }