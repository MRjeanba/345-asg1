#include "CharacterEditorController.h"
#include <iostream>
#include <string>
#include <cctype> // for std::tolower
#include "../Models/fighter.cpp"
#include "../Models/golem.cpp"
#include "../Models/healer.cpp"
#include "../Models/knight.cpp"
#include "../Models/wizard.cpp"
using namespace std;

CharacterEditorController ::CharacterEditorController()
{
    cout << "Creation of character...";
};

fighter *CharacterEditorController ::createCharacter(string name)
{
    string choiceCharacter;
    cout << "Welcome " << name;
    cout << "\n1. Choose your character (fighter, golem, healer, knight or wizard) \n";
    cin >> choiceCharacter;
    string validCharacterChosen = isValid(choiceCharacter);
    if (validCharacterChosen == "fighter")
    {
        fighter *myFighter = new fighter(0); // new game means the character's level is set to 0
        myFighter->displayCharacter();
        return myFighter;
    }
    else if (validCharacterChosen == "golem")
    {
        golem *myGolem = new golem(0); // new game means the character's level is set to 0
        myGolem->displayCharacter();
        return myGolem;
    }
    else if (validCharacterChosen == "healer")
    {
        healer *myHealer = new healer(0); // new game means the character's level is set to 0
        myHealer->displayCharacter();
        return myHealer;
    }
    else if (validCharacterChosen == "knight")
    {
        knight *myKnight = new knight(0, 100); // new game means the character's level is set to 0
        myKnight->displayCharacter();
        return myKnight;
    }
    else if (validCharacterChosen == "wizard")
    {
        wizard *myWizard = new wizard(0); // new game means the character's level is set to 0
        myWizard->displayCharacter();
        return myWizard;
    }
};

string CharacterEditorController ::isValid(string characterType)
{
    string chosen = toLower(characterType);
    bool accepted = true;

    while (!accepted)
    {
        if (chosen == "fighter" || chosen == "golem" || chosen == "healer" ||
            chosen == "knight" || chosen == "wizard")
        {
            accepted = true;
        }
        else
        {
            cout << "Please enter a valid character type...\n";
            cin >> chosen;
        }
    }
    return chosen;
};

string CharacterEditorController::toLower(string str)
{
    string inputString;
    inputString.reserve(str.size());

    for (char ch : str)
    {
        inputString.push_back(tolower(ch));
    }
    return inputString;
};