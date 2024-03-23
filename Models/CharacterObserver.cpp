#include "CharacterObserver.h"
#include <iostream>

CharacterObserver::CharacterObserver(fighter* character) : character(character) {}

void CharacterObserver::update(const std::string& message) {

    std::cout << "Observer: Fighter attributes have been updated.\n";
    std::cout << "Level: " << character->getLevel() << std::endl;
    std::cout << "Strength: " << character->getStrength() << std::endl;

}

