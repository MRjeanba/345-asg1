//
// Created by Marilyne Nguyen on 2024-03-22.
//

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "Observable.h"
#include <iostream>
#include <string>

class GameController: public Observable{
public:
    void startGame();
    void loadMap();
    void mapPlayerMoved();
    void diceRoll();
};


#endif
