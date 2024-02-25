#include <iostream>
#include "Models/Dice.cpp"

#include "Models/Armor.h"
#include "Models/Belt.h"
#include "Models/Item.h"
#include "Models/Helmet.h"
#include "Models/Shield.h"

int main()
{
    Belt test = Belt::createBelt("Constitution");
    std::cout << "Hello, World!" << std::endl;
    // TEST CASES
    Dice d;
    d.rollDice("5d6+30");
    cout << endl;
    d.rollDice("4d20+100");
    cout << endl;
    d.rollDice("2d12+4");
    cout << endl;
    d.rollDice("12d4+31");
    cout << endl;
    // TESTING when the expression is invalid -> should return an error message
    d.rollDice("12dd4+31");
    d.rollDice("1s1d4e+31");
    d.rollDice("13d4-31");
    return 0;
}