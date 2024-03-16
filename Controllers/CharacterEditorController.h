#ifndef CHARACTEREDITORCONTROLLER_H
#define CHARACTEREDITORCONTROLLER_H
using namespace std;

class CharacterEditorController
{
public:
    CharacterEditorController(){};         // Constructor
    fighter *createCharacter(string name); // returns the character
    string isValid(string characterType);  // check if the type of fighter exists in the game
    string toLower(string str);
};

#endif