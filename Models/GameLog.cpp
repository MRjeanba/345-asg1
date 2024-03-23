//
// Created by Marilyne Nguyen on 2024-03-22.
//

#include "GameLog.h"
#include <iostream>
#include <string>
using namespace std;


void GameLog::update(const std::string& message)
{
    std::cout << "Log: " << message << std::endl;
}
