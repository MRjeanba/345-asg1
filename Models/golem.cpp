#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "golem.h"
using namespace std;

string golem::getGolemType()
{
    return golemType;
}

void golem::setGolemType()
{
    string types[3] = {"earth", "ice", "wind"};
    srand(static_cast<unsigned>(time(nullptr)));
    int typeIndex = rand() % 3;
    golemType = types[typeIndex];
}

vector<string> golem::getAttacks()
{
    return attacks;
}

void golem::setAttacks(int level)
{
    string golemType = getGolemType();

    if (golemType == "earth")
    {
        string earthAttacks[5] = {"Rock Throw", "Boulder Toss", "Stone Spikes", "Ground Pound", "Earthquake Slam"};
        for (int i = 0; i <= level; i++)
        {
            attacks.push_back(earthAttacks[i]);
        }
    }
    else if (golemType == "ice")
    {
        string iceAttacks[5] = {"Frost Breath", "Frost Nova", "Frozen Slam", "Blizzard Blast", "Ice Shard Barrage"};
        for (int i = 0; i <= level; i++)
        {
            attacks.push_back(iceAttacks[i]);
        }
    }
    else if (golemType == "wind")
    {
        string windAttacks[5] = {"Gust Slash", "Whirlwind Burst", "Air Cutter", "Cyclone Spin", "Tornado Strike"};
        for (int i = 0; i <= level; i++)
        {
            attacks.push_back(windAttacks[i]);
        }
    }
}

void golem::setHp(int level)
{
    int hpLevel[5] = {1000, 1100, 1200, 1300, 1400};
    hp = hpLevel[level];
}

golem::golem(int level) : fighter(level)
{
    setGolemType();
    setHp(level);
    setAttacks(level);
}

void golem::displayCharacter()
{
    cout << "Display of the golem: " << endl;
    cout << "Level: " << getLevel() << endl;
    cout<< "Wisdom: " << getWisdom() << endl;
    cout<< "Intelligence: " << getIntelligence() << endl;
    cout<< "Charisma: " << getCharisma() << endl;
    cout << "Strenght: " << getStrength() << endl;
    cout << "Dexterity: " << getDexterity() << endl;
    cout << "Constitution: " << getConstitution() << endl;
    cout << "Hit Points: " << getHitPoints() << endl;
    cout << "Armor Class: " << getArmorClass() << endl;
    cout << "AttackBonus: " << getAttackBonus() << endl;
    cout << "DamageBonus: " << getDamageBonus() << endl;
    cout << "HP: " << getHp() << endl;
    cout << "Golem Type: " << getGolemType() << endl;
    cout << "Golem Attacks: ";

    for (const auto &str : getAttacks())
    {
        cout << str << " ";
    }
    cout << "\nWe rolled the dice! You're a BULLY fighter! " << endl;
    cout << endl;
}

void golem::update()
{
    std::cout << "Golem received an update from Observable!" << std::endl;
}

void golem::update(const std::string &message) {
    //Observer::update(message);
}
