#ifndef CHARACTEREDITORCONTROLLER_H
#define CHARACTEREDITORCONTROLLER_H

#include "../Models/fighter.h"

using namespace std;

class CharacterEditorController
{
public:
    CharacterEditorController()= default;         // Constructor
    fighter *createCharacter(const string name);  // returns the character
    static bool isValid(const string characterType);  // check if the type of fighter exists in the game
    static string toLower(const string str);
    static void printToTEXT(string name, string type);
};

#endif