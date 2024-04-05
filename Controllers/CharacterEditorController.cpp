#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "../Models/fighter.h"
#include "../Models/golem.h"
#include "../Models/healer.h"
#include "../Models/knight.h"
#include "../Models/wizard.h"

#include "CharacterEditorController.h"

using namespace std;

void CharacterEditorController::printToTEXT(std::string name)
{
        ofstream outfile("Characters.txt");
        if (outfile.is_open())
        {
            outfile << "New fighter created named ";
            cout<< "Character successfully saved in text file...";
        }
        else
        {
            cerr<<"Error opening file! \n";
        }

        outfile.flush();
        outfile.close();
}

fighter *CharacterEditorController::createCharacter(const string name) {
    string choiceCharacter;
    cout << "Welcome " << name;
    cout << "\n1. Choose your character (fighter, golem, healer, knight or wizard) \n";
    cin >> choiceCharacter;
    bool canCreateCharacter = isValid(choiceCharacter);

    while (!canCreateCharacter) {
        cout << "Please enter a valid character type (fighter, golem, healer, knight or wizard)";
        cin >> choiceCharacter;
        canCreateCharacter = isValid(choiceCharacter);
    }

    choiceCharacter = toLower(choiceCharacter);

    fighter *myFighter;
    if (choiceCharacter == "fighter") {
        myFighter = new fighter(0);
        printToTEXT(name);
    }
    if (choiceCharacter == "golem") {
        myFighter = new golem(0);

    }
    if (choiceCharacter == "healer") {
        myFighter = new healer(0);

    }
    if (choiceCharacter == "knight") {
        myFighter = new knight(0, 5);

    }
    if (choiceCharacter == "wizard") {
        myFighter = new wizard(0);

    }

    myFighter->displayCharacter();
    return myFighter;
}

bool CharacterEditorController::isValid(const string characterType) {
    vector<string> validTypes = {"fighter", "golem", "healer", "knight", "wizard"};
    string chosenCharacterType = toLower(characterType);
    bool found = false;
    for(int i = 0; i < 4; i++ )
    {
        if(chosenCharacterType == validTypes[i])
        {
            found = true;
            break;
        }
    }
    return found;
}

string CharacterEditorController::toLower(const string str) {
    string inputString;
    inputString.reserve(str.size());

    for (char ch: str) {
        inputString.push_back(tolower(ch));
    }
    return inputString;
}
