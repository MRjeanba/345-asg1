//
// Created by Jean-Baptiste Garibo on 2024-04-13.
//

#ifndef INC_345_ASG1_CHEST_H
#define INC_345_ASG1_CHEST_H


#include "Item.h"
#include <vector>
#include <cereal/archives/xml.hpp>
#include <cereal/types/vector.hpp>
using std::vector;

class Chest {

public:
    vector<string> itemsNames;
    string chestName;
/**
     * \brief Default constructor for the Chest class
     */
    Chest() = default;

    vector<string> removeElements();

    void addElement(string itemName);

    bool isValidItemName(const string &itemName);

    template<class Archive>
    void serialize(Archive &archive) {
        archive(cereal::make_nvp("itemsNames", itemsNames), cereal::make_nvp("chestName", chestName));
    }
};


#endif //INC_345_ASG1_CHEST_H
