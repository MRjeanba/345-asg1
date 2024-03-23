//
// Created by Marilyne Nguyen on 2024-03-22.
//

#include "GameController.h"

void GameController::startGame() {
    notifyObservers("Game setup started.");
}

void GameController::loadMap() {
    notifyObservers("Map loading.");
}

void GameController::mapPlayerMoved()
{
    notifyObservers("Something moved.");
}


