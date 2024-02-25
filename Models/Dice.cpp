#include <iostream>
#include <regex>
#include "Dice.h"
using namespace std;

// Definition of the method isValid to check if the expression follows the expected format
bool Dice::isValidExpression(string expression)
{
    regex pattern("\\d+d\\d+\\+\\d+");
    return regex_match(expression, pattern);
};

// Definition of the method rollDice taking an expression
int Dice::rollDice(string expression)
{

    if (isValidExpression(expression)) // enter this if statement if the expression is valid
    {
        int numberOfRolls = stoi(expression.substr(0, expression.find("d")));                   // getting the number of rolls
        int diceType = stoi(expression.substr(expression.find("d") + 1, expression.find("+"))); // getting the diceType
        int z = stoi(expression.substr(expression.find("+") + 1, expression.length()));         // value of z

        // seed random number generator
        srand(static_cast<unsigned>(time(nullptr)));

        result = 0;
        // getting the total depending on the rolls and the random number generated
        for (int i = 0; i < numberOfRolls; i++)
        {
            // random number depends on the diceType d4, d6, d8, d10, d12, d20, d100
            int random = rand() % diceType + 1;
            result += random; // adding the number to the result
        }

        // adding z to the result
        result += z;

        cout << expression << " => Rolling d" << diceType << " for " << numberOfRolls << " times and adding z : " << z << endl;
        cout << "Result: " << result << endl;

        return result;
    }
    else
    {
        cout << "Invalid Expression for the dice" << endl;
        return 0;
    }
};

// int main()
// {
//     // TEST CASES
//     Dice d;
//     d.rollDice("5d6+30");
//     cout << endl;
//     d.rollDice("4d20+100");
//     cout << endl;
//     d.rollDice("2d12+4");
//     cout << endl;
//     d.rollDice("12d4+31");
//     cout << endl;
//     // TESTING when the expression is invalid -> should return an error message
//     d.rollDice("12dd4+31");
//     d.rollDice("1s1d4e+31");
//     d.rollDice("13d4-31");

//     return 0;
// }