#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <iostream>
#include <vector>
#include "../Models/Map.h"

class gameController {
private:
    std::vector<std::string> storedMaps;

    void displayWelcomeMessage();
    void displayMaps();
    int selectMap();
    void displaySelectedMap(Map& selectedMap);

public:
    gameController();
    void displayMenu();
    void keepGoingGame();
    void startGame();
};

#endif // GAMECONTROLLER_H


