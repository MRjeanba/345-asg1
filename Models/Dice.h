#ifndef DICE_H
#define DICE_H
#include <string>
#include <random>

using namespace std;

class Dice
{
private:
    int result; // result of the roll
public:
    int rollDice(string expression);           // action of rolling the dice
    bool isValidExpression(string expression); // checking if the expression respects the format xdy+z
};

#endif