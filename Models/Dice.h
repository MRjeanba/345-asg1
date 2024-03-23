#ifndef DICE_H
#define DICE_H
#include <string>
#include <random>
#include "Observable.h"
using std::string;
/**
Dice class that can create Dice objects that can roll
and generates a result for the game
Included string and random librairies
- string: for the method isValidExpression, some methods from that library are necessary (parsing, text processing)
- random: to produce random numbers
*/
class Dice: public Observable
{
private:
    int result; // result of the roll
public:
    /**
    rollDice
    rollDice is the method used to roll a dice in order generate a number
    Taking an expression following this format xdy[+z]
    x: number of rolls of the same dice type
    y: dice type
    z: modifier
    @param param1 string expression
    @return int result -> result of rolling the dice depending on the expression xdy[+z]
    */
    int rollDice(string expression); // action of rolling the dice

    /**
    isValidExpression is a function returning a boolean value
    It checks if the expression given is correct
    It should not start with a 0, it checks if the dice types are d4, d6, d8, d10, d12, d20 or d100
    It checks that the numbers, the + symbol and the letter d are at their right position
    @param param1 string expression
    @return boolean value true if the expression is following this format xdy+z
    */
    bool isValidExpression(string expression); // checking if the expression respects the format xdy+z
    void roll(int result);
};

#endif